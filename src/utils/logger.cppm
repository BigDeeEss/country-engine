/// @file logger.cppm
/// @brief Implementation of the CLogger class for logging messages to the
/// console.
/// @author GenAI

module;

#include <chrono>
#include <format>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <string_view>

export module logger;

namespace CountryEngine::Utills {


    /// @brief A simple thread-safe logger class that supports logging to both
    /// console and file with timestamp and log levels.
    export class Logger {
      public:
        /// @brief Log levels for categorizing log messages.
        enum class Level { Info, Warning, Error };


        /// @brief Initializes logger with the specified file and reset option.
        /// @param [filename] The path to the log file.
        /// @param [reset_file] If true, the log file will be cleared on
        /// initialization.
        static void init(std::string_view filename, bool reset_file);


        /// @brief Logs a message with the specified level and format.
        /// @tparam [...Args] Variadic template parameters for format arguments.
        /// @param [level] The log level.
        /// @param [fmt] The format string.
        /// @param [...args] The arguments for the format string.
        template <typename... Args>
        static void log(
            Level level, std::format_string<Args...> fmt, Args &&...args);

      private:
        /// @brief Gets THE mutex for synchronizing log access across threads.
        /// @return A reference to a mutex.
        static std::mutex &get_mutex();


        /// @brief Gets THE file stream for logging.
        /// @return A reference to THE file stream.
        /// @note The file stream is lazily initialized and shared across all
        /// log calls.
        /// @note Lazy initialization achieved through a static local variable.
        static std::ofstream &get_file_stream();


        /// @brief Converts log level enum to string for output.
        /// @param [level] The log level to convert.
        /// @return A string_view representing the log [level].
        constexpr static std::string_view to_string(Level level);
    };




    void Logger::init(std::string_view filename, bool reset_file = true) {

        // Ensure thread-safe initialization of the log file stream.
        std::lock_guard<std::mutex> lock(get_mutex());

        // Get/initialize file stream.
        auto &stream = get_file_stream();

        if (stream.is_open()) {
            stream.close();
        }

        // Open file stream in mode based on reset_file flag.
        stream.open(
            std::string(filename), reset_file ? std::ios::out : std::ios::app);
    }




    template <typename... Args>
    void Logger::log(
        Level level, std::format_string<Args...> fmt, Args &&...args) {

        // Ensure thread-safe logging.
        std::lock_guard<std::mutex> lock(get_mutex());

        // Generate timestamp.
        auto now = std::chrono::system_clock::now();
        std::string timestamp = std::format("{:%Y-%m-%d %H:%M:%S}", now);

        // Format user's message.
        std::string user_msg = std::format(fmt, std::forward<Args>(args)...);

        // Assemble string for logging.
        std::string full_msg = std::format(
            "[{}] [{}] {}\n", timestamp, to_string(level), user_msg);

        // Thread-safe output to console, achieved via mutex [lock] and the fact
        // this is the only logging statment.
        if (level == Level::Error) {
            std::cerr << full_msg;
        } else {
            std::cout << full_msg;
        }

        // Output to file if initialized.
        auto &stream = get_file_stream();
        if (stream.is_open()) {
            stream << full_msg;
            stream.flush(); // Ensure data hits disk immediately
        }
    }




    std::mutex &Logger::get_mutex() {

        // Lazy initialization of THE mutex ensures creation only once and only
        // when needed. The mutex is shared across all log calls without
        // the overhead of dynamic memory allocation or manual management.
        static std::mutex mtx;
        return mtx;
    }




    std::ofstream &Logger::get_file_stream() {

        // Lazy initialization of THE file stream ensures creation only
        // once and only when needed (i.e., when init is called). This allows
        // the logger to be used without file output if desired, and also
        // ensures that the file stream is shared across all log calls without
        // the overhead of dynamic memory allocation or manual management.
        static std::ofstream stream;
        return stream;
    }




    constexpr std::string_view Logger::to_string(Level level) {

        // Convert log level enum to string for output. This is a simple mapping
        // that allows log messages to include human-readable log levels.
        switch (level) {
            case Level::Info: return "INFO";
            case Level::Warning: return "WARN";
            case Level::Error: return "ERROR";
        }
        return "UNKNOWN";
    }


} // namespace CountryEngine::Utills
