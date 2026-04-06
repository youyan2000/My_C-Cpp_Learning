#ifndef LOG_H
#define LOG_H

class Log{
  private:
    int m_Level = INFO;
  public:
    const static int ERROR = 0;
    const static int WARNING = 1;
    const static int INFO = 2;
    void SetLevel(int level);
    void Warn(const std::string& message);
    void Info(const std::string& message);
    void Error(const std::string& message);

};

#endif 