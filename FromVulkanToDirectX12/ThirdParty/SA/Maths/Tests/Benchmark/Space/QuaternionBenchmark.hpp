// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_QUATERNION_BENCHMARK_GUARD
#define SAPPHIRE_MATHS_QUATERNION_BENCHMARK_GUARD

#include <SA/Maths/Space/Quaternion.hpp>

#include "../Tools/Random.hpp"

namespace SA::Benchmark
{
    template <typename T>
    static Quat<T> Quat_Random()
    {
        return Quat<T>(Rand<T>(), Rand<T>(), Rand<T>(), Rand<T>());
    }

    #define RQuat Quat_Random<T>()
}

#endif // GUARD
