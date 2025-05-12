// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

#include "Matrix4Benchmark.hpp"
#include "../Space/Vector3Benchmark.hpp"
#include "../Space/QuaternionBenchmark.hpp"

#if SA_MATHS_MATRIX4_SIMD || SA_CI

namespace SA::Benchmark
{
    template <typename T>
    static void Mat4_Determinant(benchmark::State& _state)
    {
        T x = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(x += RMat4.Determinant());
    }

    BENCHMARK_TEMPLATE(Mat4_Determinant, int32_t);
    BENCHMARK_TEMPLATE(Mat4_Determinant, float);
    BENCHMARK_TEMPLATE(Mat4_Determinant, double);


    template <typename T>
    static void Mat4_GetInversed(benchmark::State& _state)
    {
        Mat4<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat4.GetInversed());
    }

    //BENCHMARK_TEMPLATE(Mat4_GetInversed, int32_t); // No int test with inverse.
    BENCHMARK_TEMPLATE(Mat4_GetInversed, float);
    BENCHMARK_TEMPLATE(Mat4_GetInversed, double);


    template <typename T>
    static void Mat4_MakeRotation(benchmark::State& _state)
    {
        Mat4<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat4.MakeRotation(RQuat));
    }

    BENCHMARK_TEMPLATE(Mat4_MakeRotation, int32_t);
    BENCHMARK_TEMPLATE(Mat4_MakeRotation, float);
    BENCHMARK_TEMPLATE(Mat4_MakeRotation, double);


    template <typename T>
    static void Mat4_OpMultScalar(benchmark::State& _state)
    {
        Mat4<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat4 * Rand<T>());
    }

    BENCHMARK_TEMPLATE(Mat4_OpMultScalar, int32_t);
    BENCHMARK_TEMPLATE(Mat4_OpMultScalar, float);
    BENCHMARK_TEMPLATE(Mat4_OpMultScalar, double);


    template <typename T>
    static void Mat4_OpAdd(benchmark::State& _state)
    {
        Mat4<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat4 + RMat4);
    }

    BENCHMARK_TEMPLATE(Mat4_OpAdd, int32_t);
    BENCHMARK_TEMPLATE(Mat4_OpAdd, float);
    BENCHMARK_TEMPLATE(Mat4_OpAdd, double);


    template <typename T>
    static void Mat4_OpMult(benchmark::State& _state)
    {
        Mat4<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat4 * RMat4);
    }

    BENCHMARK_TEMPLATE(Mat4_OpMult, int32_t);
    BENCHMARK_TEMPLATE(Mat4_OpMult, float);
    BENCHMARK_TEMPLATE(Mat4_OpMult, double);


    template <typename T>
    static void Mat4_OpMultVec3(benchmark::State& _state)
    {
        Vec3<T> vres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(vres += RMat4 * RVec3);
    }

    BENCHMARK_TEMPLATE(Mat4_OpMultVec3, int32_t);
    BENCHMARK_TEMPLATE(Mat4_OpMultVec3, float);
    BENCHMARK_TEMPLATE(Mat4_OpMultVec3, double);
}

#endif
