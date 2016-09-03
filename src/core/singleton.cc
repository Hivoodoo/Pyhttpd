#include "singleton.h"

// http://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/#using-c11-sequentially-consistent-atomics

template<class T>
T& Singleton<T>::Instance(){
  T *ret = instance_.loar();
  if (ret == nullptr) {
    std::lock_guard<std::mutex> lock(mutex_);
    ret = instance_.load();
    if (ret == nullptr) {
      ret = new T();
      instance_.store(ret);
    }
  }
  return ret;
}
