#include "core/singleton.h"
#include <thread>
#include <chrono>
#include <functional>

class c{
 public:
  void write(){
    printf("hello");
    auto dur = std::chrono::seconds(2);
    std::this_thread::sleep_for(dur);
  }
};

Singleton<c> l;
 
int main(){
  std::thread t(l.Instance().write);
  t.join();

  return 0;
}
