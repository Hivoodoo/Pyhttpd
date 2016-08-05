#include "singleton.h"

// http://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/#using-c11-sequentially-consistent-atomics
template<class T>
T& Singleton<T>::Instance(){
  T *tmp = instance_.loar();
  if (tmp == nullptr) {
    std::lock_guard<std::mutex> lock(mutex_);
    tmp = instance_.load();
    if (tmp == nullptr) {
      tmp = new T();
      instance_.store(tmp);
    }
  }
  return tmp;
}
