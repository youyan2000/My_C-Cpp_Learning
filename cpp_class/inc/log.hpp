#ifndef LOG_H
#define LOG_H

class Log{
  public:
    enum Level{
      ERROR,
      WARNING,
      INFO
    };
  private:
    Level m_Level = INFO;
  public:
    void SetLevel(Level level);
    void Warn(const std::string& message);
    void Info(const std::string& message);
    void Error(const std::string& message);

};

#endif 