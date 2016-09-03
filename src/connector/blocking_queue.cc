#include "connector/blocking_queue.h"

namespace NetServer
{

template<typename value_type>
void BlockingQueue<value_type>::push (const value_type& task)
{
  std::lock_guard<std::mutex> lock (mMutex);
	mQueue.push_back (task);
}

// this is time-out-blocking wait
template<typename value_type>
template<class Rep, class Period >
int BlockingQueue<value_type>::pop (value_type &task,
	const std::chrono::duration<Rep, Period>& time)
{
  std::unique_lock<std::mutex> lock (mMutex);
	mCondVar.wait_for(lock, time, [this]{
		return !mQueue.empty();
	});
	if (mQueue.empty())
		return -1;
	task = mQueue.front();
	mQueue.pop_front ();
	return 0;
}

template<typename value_type>
int BlockingQueue<value_type>::pop (value_type &task)
{
  std::unique_lock<std::mutex> lock (mMutex);
	while (mQueue.empty())
		mCondVar.wait(lock);
	if (mQueue.empty()){
		return -1;
	}
	task = mQueue.front();
	mQueue.pop_front ();
	return 0;
}

template<typename value_type>
size_t BlockingQueue<value_type>::size() const
{
  std::lock_guard<std::mutex> lock (mMutex);
	return mQueue.size();
}

} // namespace NetServer 
