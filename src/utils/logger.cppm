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
        enum class Level { Info, Warning, Error };

        // Initializes the logger. Clears the previous file if reset_file is
        // true.
        static void init(std::string_view filename, bool reset_file = true) {

            std::lock_guard<std::mutex> lock(get_mutex());
            auto &stream = get_file_stream();

            if (stream.is_open()) {
                stream.close();
            }

            stream.open(std::string(filename),
                reset_file ? std::ios::out : std::ios::app);
        }

        // Core log function using modern C++ format syntax
        template <typename... Args>
        static void log(
            Level level, std::format_string<Args...> fmt, Args &&...args) {
            std::lock_guard<std::mutex> lock(get_mutex());

            // 1. Generate timestamp
            auto now = std::chrono::system_clock::now();
            std::string timestamp = std::format("{:%Y-%m-%d %H:%M:%S}", now);

            // 2. Format the user's message
            std::string user_msg =
                std::format(fmt, std::forward<Args>(args)...);

            // 3. Assemble the full message string
            std::string full_msg = std::format(
                "[{}] [{}] {}\n", timestamp, to_string(level), user_msg);

            // 4. Thread-safe output to console
            if (level == Level::Error) {
                std::cerr << full_msg;
            } else {
                std::cout << full_msg;
            }

            // 5. Output to file if initialized
            auto &stream = get_file_stream();
            if (stream.is_open()) {
                stream << full_msg;
                stream.flush(); // Ensure data hits disk immediately
            }
        }

      private:
        // Meyers Singleton to guarantee thread-safe static initialization order
        static std::mutex &get_mutex() {
            static std::mutex mtx;
            return mtx;
        }

        static std::ofstream &get_file_stream() {
            static std::ofstream stream;
            return stream;
        }

        constexpr static std::string_view to_string(Level level) {
            switch (level) {
            case Level::Info:
                return "INFO";
            case Level::Warning:
                return "WARN";
            case Level::Error:
                return "ERROR";
            }
            return "UNKNOWN";
        }
    };


} // namespace CountryEngine::Utills
