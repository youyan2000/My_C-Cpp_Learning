#include "worker.hpp"
#include <iostream>
#include <thread>

int main(){
  std::cout << "Main thread starts.\n";

  Worker w;
  w.start();

  std::cout << "Press Enter to stop the worker thread...\n";
  std::cin.get();

  w.stop();
  w.wait(); 
  std::cout << "Worker thread has finished (joined).\n";

  std::thread t2([]()
                 {
        for (int i = 0; i < 3; ++i) {
            std::cout << "Detached thread running, step " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
        std::cout << "Detached thread finished!" << std::endl; });
  t2.detach();

  std::cout << "Main thread ends. Detached thread may still be running...\n";

  std::this_thread::sleep_for(std::chrono::seconds(3));
  return 0;
}
