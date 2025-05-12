// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_VECTOR3_BENCHMARK_GUARD
#define SAPPHIRE_MATHS_VECTOR3_BENCHMARK_GUARD

#include <SA/Maths/Space/Vector3.hpp>

#include "../Tools/Random.hpp"

namespace SA::Benchmark
{
    template <typename T>
    static Vec3<T> Vec3_Random()
    {
        return Vec3<T>(Rand<T>(), Rand<T>(), Rand<T>());
    }

    #define RVec3 Vec3_Random<T>()
}

#endif // GUARD
