#ifndef __BLOCKING_QUEUE_H__
#define __BLOCKING_QUEUE_H__

// thread synchronization
#include <mutex>
#include <condition_variable>
#include <chrono>

// container_type
#include <list>

// just exception
#include "ServerException.h"


namespace
{
	using namespace std;
	template<typename value_type>
	class BlockingQueue
	{
		using container_type = list<value_type>;

		container_type mQueue;
		mutex mMutex;
		condition_variable mCondVar;

	public:
		BlockingQueue () : mMutex (), mQueue () {}

		void push (const value_type& task)
		{
			lock_guard<mutex> lock (mMutex);
			mQueue.push_back (task);
		}

		// this is time-out-blocking wait
		template< class Rep, class Period >
		int pop (value_type &task,
			const chrono::duration<Rep, Period>& time)
			throw()
		{
			unique_lock<mutex> lock (mMutex);
			mCondVar.wait_for(lock, time, [this]{
				return !mQueue.empty();
			});
			if (mQueue.empty())
				return -1;
			task = mQueue.front();
			mQueue.pop_front ();
			return 0;
		}

		int pop (value_type &task)
			throw (ServerException)
		{
			unique_lock<mutex> lock (mMutex);
			while (mQueue.empty())
				mCondVar.wait(lock);
			if (mQueue.empty()){
				throw ServerException(4);
				return -1;
			}
			task = mQueue.front();
			mQueue.pop_front ();
			return 0;
		}


		size_t size() const
		{
			lock_guard<mutex> lock (mMutex);
			return mQueue.size();
		}
	// Can also extend NonCopyable
	private:
		BlockingQueue ( const BlockingQueue& );
		const BlockingQueue& operator= ( const BlockingQueue& );
	};
}

#endif
