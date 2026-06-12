// module;
// #include <string>

// module;
// import <string>;
// import std;

export module logger;

// #include <memory>
// #include <string>
// import std;
// import <string>;

namespace CountryEngine::Utills {

export class CLogger {
public:
  CLogger();
  ~CLogger();

  CLogger(const CLogger &) = delete;
  CLogger &operator=(const CLogger &) = delete;

  // void info(const std::string &message);
  // void warn(const std::string &message);
  // void error(const std::string &message);

private:
  //   struct Impl;
  //   std::unique_ptr<Impl> impl_;
};

} // namespace CountryEngine::Utills
