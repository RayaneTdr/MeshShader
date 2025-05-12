// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_MATRIX4_BENCHMARK_GUARD
#define SAPPHIRE_MATHS_MATRIX4_BENCHMARK_GUARD

#include <SA/Maths/Matrix/Matrix4.hpp>

#include "../Tools/Random.hpp"

namespace SA::Benchmark
{
    template <typename T, MatrixMajor major = MatrixMajor::Default>
    static Mat4<T, major> Mat4_Random()
    {
        return Mat4<T, major>(
            Rand<T>(), Rand<T>(), Rand<T>(), Rand<T>(),
            Rand<T>(), Rand<T>(), Rand<T>(), Rand<T>(),
            Rand<T>(), Rand<T>(), Rand<T>(), Rand<T>(),
            Rand<T>(), Rand<T>(), Rand<T>(), Rand<T>()
        );
    }

    #define RMat4 Mat4_Random<T>()
}

#endif // GUARD
