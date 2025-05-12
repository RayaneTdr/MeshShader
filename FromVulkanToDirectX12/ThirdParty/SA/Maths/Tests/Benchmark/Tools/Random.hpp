// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_RANDOM_BENCHMARK_GUARD
#define SAPPHIRE_MATHS_RANDOM_BENCHMARK_GUARD

#include <ctime>
#include <cstdlib>

namespace SA::Benchmark
{
    static bool randomInit = []() { srand((unsigned int)time(nullptr)); return true; }();

    /**
    *   Ensure no division by 0.
    */

    template <typename T>
    static T Rand(T _min = T(1), T _max = T(100))
    {
        return _min + static_cast<T>(rand()) / (static_cast<T> (RAND_MAX / (_max - _min)));
    }
}

#endif // GUARD
