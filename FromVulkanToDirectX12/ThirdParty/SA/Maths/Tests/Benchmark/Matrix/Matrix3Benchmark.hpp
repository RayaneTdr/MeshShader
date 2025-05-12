// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_MATRIX3_BENCHMARK_GUARD
#define SAPPHIRE_MATHS_MATRIX3_BENCHMARK_GUARD

#include <SA/Maths/Matrix/Matrix3.hpp>

#include "../Tools/Random.hpp"

namespace SA::Benchmark
{
    template <typename T, MatrixMajor major = MatrixMajor::Default>
    static Mat3<T, major> Mat3_Random()
    {
        return Mat3<T, major>(
            Rand<T>(), Rand<T>(), Rand<T>(),
            Rand<T>(), Rand<T>(), Rand<T>(),
            Rand<T>(), Rand<T>(), Rand<T>()
        );
    }

#define RMat3 Mat3_Random<T>()
}

#endif // GUARD
