#include <mutex>
#include <atomic>

template <class T>
class Singleton
{
 public:
  T& Instance();
  Singleton();

 private:
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);

  std::atomic<T> instance_;
  std::mutex mutex_;
};
