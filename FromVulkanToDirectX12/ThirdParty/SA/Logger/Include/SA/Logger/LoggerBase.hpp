// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_BASE_GUARD
#define SAPPHIRE_LOGGER_LOGGER_BASE_GUARD

#include <list>

#include <SA/Logger/Streams/ALogStream.hpp>
#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file LoggerBase.hpp
*
*	\brief <b>Logger</b> base class implementation.
*
*	\ingroup Logger
*	\{
*/


namespace SA
{
	/**
	*	\brief Logger base class implementation.
	*/
	class LoggerBase
	{
	protected:

	//{ Streams

		/// Registered output streams.
		std::list<ALogStream*> mStreams;

		/**
		*	\brief Process log to output.
		* 
		*	\param[in] _log		Log to process.
		*	\param[in] _bForce	Should force log process. Default is false.
		*/
		virtual void ProcessLog(const SA::Log& _log, bool _bForce = false);

		/**
		*	\brief Register a stream to output.
		* 
		*	\param[in] _stream	Stream to register.
		*/
		virtual void RegisterStream(ALogStream* _stream);

		/**
		*	\brief Unregister a stream from output.
		*
		*	\param[in] _stream	Stream to unregister.
		*
		*	\return true on success.
		*/
		virtual bool UnregisterStream(ALogStream* _stream);

	//}

	public:
		/**
		*	\brief Destructor
		*	Destroy all created log streams.
		*/
		virtual ~LoggerBase();

		/**
		*	\brief Push a new log in logger.
		* 
		*	\param[in] _log		Log to push.
		*/
		virtual void Log(SA::Log _log);

		/**
		*	\brief Process exception.
		*
		*	Log assertion on success, otherwise throw exception.
		*	Use SA_ASSERT as helper call.
		*
		*	\tparam ExcepT		Exception type.
		*	\param[in] _exc		exception to process.
		*/
		template <typename ExcepT>
		void Assert(ExcepT _exc);


	//{ Streams

		/**
		*	\brief Create a new stream to output in.
		* 
		*	\tparam StreamT 	Type of stream to create.
		*	\tparam Args...		Argument variadic types to construct stream.
		*	\param[in] _args	Arguments to construct stream.
		*
		*	\return Newly created stream.
		*/
		template <typename StreamT, typename... Args>
		StreamT& CreateSteam(Args&&... _args);

		/**
		 * \brief Destroy a previously created stream.
		 * 
		 * \tparam StreamT 	Type of stream to destroy.
		 * \param _stream 	Stream variable to destroy.
		 * \param _bFlush 	Should flush stream before destroy.
		 * 
		 * \return true on destroy success.
		 */
		template <typename StreamT>
		bool DestroyStream(StreamT& _stream, bool _bFlush = true);


		/**
		*	Destroy all streams.
		* 
		*	\param _bFlush 	Should flush stream before destroy.
		*/
		virtual void ClearStreams(bool _bFlush = true);


		/**
		*	\brief Force logger to flush all streams.
		*/
		virtual void Flush();


		/**
		*	\brief \e Enable \b LogLevel for all registered streams.
		* 
		*	\param[in] _level		Level to enable.
		*/
		virtual void EnableLogLevel(LogLevel _level);

		/**
		*	\brief \e Disable \b LogLevel for all registered streams.
		*
		*	\param[in] _level		Level to disable.
		*/
		virtual void DisableLogLevel(LogLevel _level);


		/**
		*	\brief \e Enable \b LogChannel for all registered streams.
		* 
		*	\param[in] _channel		Channel to enable.
		*/
		virtual void EnableLogChannel(const std::wstring& _channel);

		/**
		*	\brief \e Disable \b LogChannel for all registered streams.
		*
		*	\param[in] _channel		Channel to disable.
		*/
		virtual void DisableLogChannel(const std::wstring& _channel);

	//}


	//{ Frame Num

		/// Increment current registered frame number.
		virtual void IncrementFrameNum() = 0;

		/// Get current registered frame number.
		virtual uint32_t GetFrameNum() const = 0;

	//}
	};
}

#include <SA/Logger/LoggerBase.inl>


/** \} */

#endif // SAPPHIRE_LOGGER_LOGGER_BASE_GUARD
