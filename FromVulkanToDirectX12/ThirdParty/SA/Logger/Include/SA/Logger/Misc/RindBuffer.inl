// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

namespace SA
{
	template <typename T>
	RingBuffer<T>::RingBuffer(uint32_t _capacity) :
		mCapacity { _capacity }
	{
		mHandleBuffer = static_cast<T*>(::operator new(_capacity * sizeof(T)));
		mPushCompleted = new std::atomic<bool>[_capacity];
	}

	template <typename T>
	RingBuffer<T>::~RingBuffer()
	{
		::operator delete(mHandleBuffer);
		delete[] mPushCompleted;
	}


	template <typename T>
	void RingBuffer<T>::Push(T&& _obj)
	{
		// Reserve index.
		uint64_t index = mPushCursor++;

		/**
		 * Check is full
		 * Can be out of mCapacity range for index queue.
		*/
		while(index - mPopCursor >= mCapacity)
			std::this_thread::yield();

		// Get actual position in ring buffer.
		index = index % mCapacity;

		new(&mHandleBuffer[index]) T(std::move(_obj));
		mPushCompleted[index] = true;
	}

	template <typename T>
	bool RingBuffer<T>::Pop(T& _obj, std::atomic<bool>& _bIsRunning)
	{
		while(IsEmpty())
		{
			if(!_bIsRunning)
				return false;

			std::this_thread::yield();
		}

		const uint32_t index = mPopCursor % mCapacity;

		while(!mPushCompleted[index])
			std::this_thread::yield();

		_obj = std::move(mHandleBuffer[index]);

		mHandleBuffer[index].~T();

		// Reset for next use.
		mPushCompleted[index] = false;

		++mPopCursor;

		return true;
	}


	template <typename T>
	uint32_t RingBuffer<T>::Size() const noexcept
	{
		return static_cast<uint32_t>(mPushCursor - mPopCursor);
	}

	template <typename T>
	uint32_t RingBuffer<T>::Capacity() const noexcept
	{
		return mCapacity;
	}

	
	template <typename T>
	bool RingBuffer<T>::IsEmpty() const noexcept
	{
		return Size() == 0;
	}
}
