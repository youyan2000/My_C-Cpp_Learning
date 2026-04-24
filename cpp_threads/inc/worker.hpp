#ifndef WORKER_HPP
#define WORKER_HPP

#include <atomic>
#include <thread>
#include <iostream>
#include <chrono>

class Worker{
  public:
    Worker();
    ~Worker();

    void start();

    void stop();

    void wait();

  private:
    void doWork(); 

    std::atomic<bool> finished;
    std::thread workerThread;
};

#endif
