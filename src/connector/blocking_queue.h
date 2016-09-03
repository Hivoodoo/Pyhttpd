#ifndef __BLOCKING_QUEUE_H__
#define __BLOCKING_QUEUE_H__

// thread synchronization
#include <mutex>
#include <condition_variable>
#include <chrono>

// container_type
#include <list>

namespace NetServer
{

template<typename value_type>
class BlockingQueue
{
	using container_type = std::list<value_type>;

	container_type mQueue;
  std::condition_variable mCondVar;
  std::mutex mMutex;

 public:
	BlockingQueue () : mMutex (), mQueue () {}

	void push (const value_type& task);

	// this is time-out-blocking wait
	template< class Rep, class Period >
	int pop (value_type &task,
           const std::chrono::duration<Rep, Period>& time);
	int pop (value_type &task);

	size_t size() const;
private:
  // Can also extend NonCopyable
	BlockingQueue ( const BlockingQueue& );
	const BlockingQueue& operator= ( const BlockingQueue& );
};

} // namespace NetServer 

#endif
