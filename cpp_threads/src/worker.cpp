#include "worker.hpp"

Worker::Worker() : finished(false) {}

Worker::~Worker(){
  if (workerThread.joinable()){
    stop();
    wait();
  }
}

void Worker::start(){
  workerThread = std::thread(&Worker::doWork, this);
}

void Worker::stop(){
  finished = true;
}

void Worker::wait(){
  if (workerThread.joinable()){
    workerThread.join();
  }
}

void Worker::doWork(){
  while (!finished){
    std::cout << "Working in thread...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
  }
}
