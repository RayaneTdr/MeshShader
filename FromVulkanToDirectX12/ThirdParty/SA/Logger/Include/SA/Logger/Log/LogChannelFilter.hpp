// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_CHANNEL_FILTER_GUARD
#define SAPPHIRE_LOGGER_LOG_CHANNEL_FILTER_GUARD

#include <string>
#include <unordered_map>

/**
*	\file LogChannelFilter.hpp
* 
*	\brief Channel filter implementation.
* 
*	\ingroup Logger
*	\{
*/


namespace SA
{
	/**
	*	Log Channel filter class implementation.
	* 
	*	Filter channels and sub-channels availability.
	* 
	*	ex: "SA/TEST/Chan" is enabled only if "SA", "SA/TEST" and "SA/TEST/Chan" channels are enabled.
	*/
	class LogChannelFilter
	{
		/// Registered channels.
		std::unordered_map<std::wstring, bool> mChannels;

		bool IsSingleChannelEnabled(const std::wstring& _chanName) const;

	public:
		/**
		*	Whether a channel is currently enabled or not.
		* 
		*	A channel is enabled only if all parent channel are enabled.
		*
		*	\param[in] _chanName	Channel name to filter.
		*	\param[in] _offset		Current offset to check (internal use only).
		*/
		bool IsChannelEnabled(const std::wstring& _chanName, size_t _offset = 0u) const;

		/**
		*	Enable/Disable a channel.
		*	Only the channel itself is enabled/disabled (not the parent channels).
		* 
		*	\param[in] _chanName	Channel name to enable/disable.
		*	\param[in] _bEnabled	Whether to enable or disable the channel.
		*/
		void SetChannelEnabled(const std::wstring& _chanName, bool _bEnabled);
	};
}


/** \} */

#endif // GUARD
