// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_COMPONENT_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_COMPONENT_GUARD

/**
 * @file TransformComponent.hpp
 * 
 * @brief Transform Component base helper definition
 * 
 * @ingroup Maths_Transform
 * @{
 */


namespace SA
{
	/// Helper macro for transform HasComponent check in templated functions.
	#define TrTHasComponent(_trT) _trT::template HasComponent

	/// Helper macro for transform HasComponent check in templated functions.
	#define TrHasComponent Tr<T, TrArgs...>::template HasComponent
}

/** @} */

#endif // GUARD
