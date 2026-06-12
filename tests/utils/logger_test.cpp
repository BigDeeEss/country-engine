import logger;

#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;
using CountryEngine::Utills::Logger;

class LoggerTest : public ::testing::Test {
  protected:
    void SetUp() override {
        file_path = fs::temp_directory_path() / "countryengine_logger_test.log";
        std::error_code cleanup_error;
        fs::remove(file_path, cleanup_error);
        Logger::init(file_path.string(), true);
    }

    void TearDown() override {
        std::error_code cleanup_error;
        fs::remove(file_path, cleanup_error);
    }

    std::string capture_stdout(std::function<void()> action) {
        std::ostringstream buffer;
        auto *old_buf = std::cout.rdbuf(buffer.rdbuf());
        action();
        std::cout.rdbuf(old_buf);
        return buffer.str();
    }

    std::string capture_stderr(std::function<void()> action) {
        std::ostringstream buffer;
        auto *old_buf = std::cerr.rdbuf(buffer.rdbuf());
        action();
        std::cerr.rdbuf(old_buf);
        return buffer.str();
    }

    std::string read_log_file() const {
        std::ifstream stream(file_path);
        std::ostringstream contents;
        contents << stream.rdbuf();
        return contents.str();
    }

    fs::path file_path;
};

static void assert_log_message(const std::string &output,
    const std::string &expected_level, const std::string &expected_message) {
    ASSERT_TRUE(output.starts_with("["));

    const std::string level_token = "] [" + expected_level + "] ";
    auto level_location = output.find(level_token);
    ASSERT_NE(level_location, std::string::npos);
    EXPECT_TRUE(output.ends_with("\n"));
    EXPECT_NE(output.find(expected_message), std::string::npos);
}

TEST_F(LoggerTest, LogInfoWritesToStdoutAndFile) {
    const std::string message = "Test info message";

    std::string stdout_output = capture_stdout(
        [&] { Logger::log(Logger::Level::Info, "{}", message); });

    EXPECT_FALSE(stdout_output.empty());
    assert_log_message(stdout_output, "INFO", message);

    std::string file_contents = read_log_file();
    EXPECT_FALSE(file_contents.empty());
    assert_log_message(file_contents, "INFO", message);
}

TEST_F(LoggerTest, LogWarningWritesToStdoutAndFile) {
    const std::string message = "Be careful";

    std::string stdout_output = capture_stdout(
        [&] { Logger::log(Logger::Level::Warning, "{}", message); });

    EXPECT_FALSE(stdout_output.empty());
    assert_log_message(stdout_output, "WARN", message);

    std::string file_contents = read_log_file();
    EXPECT_FALSE(file_contents.empty());
    assert_log_message(file_contents, "WARN", message);
}

TEST_F(LoggerTest, LogErrorWritesToStderrAndFile) {
    const std::string message = "Something failed";

    std::string stderr_output = capture_stderr(
        [&] { Logger::log(Logger::Level::Error, "{}", message); });

    EXPECT_FALSE(stderr_output.empty());
    assert_log_message(stderr_output, "ERROR", message);

    std::string file_contents = read_log_file();
    EXPECT_FALSE(file_contents.empty());
    assert_log_message(file_contents, "ERROR", message);
}

TEST_F(LoggerTest, InitWithResetTrueClearsPreviousContents) {
    Logger::log(Logger::Level::Info, "First message");

    Logger::init(file_path.string(), true);
    Logger::log(Logger::Level::Info, "Second message");

    std::string file_contents = read_log_file();
    EXPECT_EQ(file_contents.find("First message"), std::string::npos);
    assert_log_message(file_contents, "INFO", "Second message");
}

TEST_F(LoggerTest, InitWithResetFalseAppendsToExistingFile) {
    Logger::log(Logger::Level::Info, "First message");

    Logger::init(file_path.string(), false);
    Logger::log(Logger::Level::Info, "Second message");

    std::string file_contents = read_log_file();
    EXPECT_NE(file_contents.find("First message"), std::string::npos);
    EXPECT_NE(file_contents.find("Second message"), std::string::npos);
    assert_log_message(file_contents, "INFO", "Second message");
}
