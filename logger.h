#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


using namespace std;

class BaseLogger {
 public:
  BaseLogger(){};
  virtual ~BaseLogger(){};
  template<typename ... Args> virtual void info(Args ... args){};
  virtual void warn(string text){};
  virtual void error(string text){};
};

class TextLogger final : public BaseLogger {
 public:

  TextLogger(string logfile) {
    f_logfile_.open(logfile, fstream::app);
  }

  ~TextLogger() override {
    f_logfile_.close();
  }

  template<typename ... Args>
  void info(Args ... args) override {
    f_logfile_ << CatString(AddPrefix("info"), args...) << endl;
  }

  void warn(string text) override {
    f_logfile_ << AddPrefix("warn") << text << endl;
  }

  void error(string text) override {
    f_logfile_ << AddPrefix("error") << text << endl;
  }

 private:

  template <typename T>
  string CatString(T s) {
    ostringstream out;
    out << s;
    return out.str();
  }

  template <typename T, typename ... Rest>
  string CatString(T s, Rest ... rest) {
    return s + CatString(rest...);
  }

  template<typename T>
  string handleValue(T arg) {
    ostringstream s;
    s << arg;
    return s.str();
  }

  string AddPrefix(string level) {
    ostringstream s;
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    s << "[" << level << "][" << put_time(localtime(&now), "%F %T") << "]";
    return s.str();
  }

  ofstream f_logfile_;
};
