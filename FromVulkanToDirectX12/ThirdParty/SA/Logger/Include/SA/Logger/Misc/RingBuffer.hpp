// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_RING_BUFFER_GUARD
#define SAPPHIRE_LOGGER_RING_BUFFER_GUARD

#include <atomic>
#include <thread>

/**
*	\file RingBuffer.hpp
*
*	\brief \b Thread-safe \e RingBuffer class implementation.
*	Multiple producers, single consumer implementation.
*
*	\ingroup Logger_Misc
*	\{
*/


namespace SA
{
	/**
	* \brief RingBuffer class implementation
	* 
	*	\tparam ExcepT		Object's type to buffer.
	*/
	template <typename T>
	class RingBuffer
	{
		/// Handled objects
		T* mHandleBuffer = nullptr;

		/// Push completed state array.
		std::atomic<bool>* mPushCompleted = nullptr;

		const uint32_t mCapacity = 0;

		std::atomic<uint64_t> mPushCursor = 0u;
		std::atomic<uint64_t> mPopCursor = 0u;

	public:
		/**
		*	\brief \e Value constructor
		* 
		*	\param[in] _capacity	RingBuffer capacity.
		*/
		RingBuffer(uint32_t _capacity = 32);

		/**
		*	Destructor
		*	Does \b NOT check for remaining size before destroy.
		*/
		~RingBuffer();

		/**
		*	\brief Push an object to the queue
		*	Yield current thread if queue is full.
		* 
		*	\param[in,out] _obj		Object to move to the queue.
		*/
		void Push(T&& _obj);

		/**
		*	\brief Pop an object from the queue.
		*	Yield current thread if queue is empty.
		* 
		*	\param[out] _obj		Object to pop from the queue.
		*	\param[in] _bIsRunning	Current running thread state.
		*/
		bool Pop(T& _obj, std::atomic<bool>& _bIsRunning);

		/// Current size of the queue.
		uint32_t Size() const noexcept;

		/// Maximum capacity of the queue.
		uint32_t Capacity() const noexcept;

		/// Whether the queue is empty.
		bool IsEmpty() const noexcept;
	};
}


/** \}*/

#include "RindBuffer.inl"

#endif // SAPPHIRE_LOGGER_RING_BUFFER_GUARD
