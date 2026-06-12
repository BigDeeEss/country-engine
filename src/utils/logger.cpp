// module ce.logger;

// import <string>;
// import <memory>;
// import <iostream>;
// import <mutex>;
// import <chrono>;
// import <iomanip>;
// import <ctime>;

// namespace ce {

// export class CLogger {
// public:
//   CLogger();
//   ~CLogger();

//   CLogger(const CLogger &) = delete;
//   CLogger &operator=(const CLogger &) = delete;

//   void info(const std::string &message);
//   void warn(const std::string &message);
//   void error(const std::string &message);

// private:
//   struct Impl;
//   std::unique_ptr<Impl> impl_;
// };

// struct CLogger::Impl {
//   void log(const std::string &level, const std::string &message) {
//     std::lock_guard<std::mutex> lock(mutex_);
//     auto now = std::chrono::system_clock::now();
//     auto time = std::chrono::system_clock::to_time_t(now);
//     std::tm tm;
// #if defined(_MSC_VER)
//     localtime_s(&tm, &time);
// #else
//     localtime_r(&time, &tm);
// #endif
//     std::cout << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << " [" << level
//               << "] " << message << std::endl;
//   }

//   std::mutex mutex_;
// };

// CLogger::CLogger() : impl_(std::make_unique<Impl>()) {}

// CLogger::~CLogger() = default;

// void CLogger::info(const std::string &message) { impl_->log("INFO", message);
// }

// void CLogger::warn(const std::string &message) { impl_->log("WARN", message);
// }

// void CLogger::error(const std::string &message) {
//   impl_->log("ERROR", message);
// }

// } // namespace ce
