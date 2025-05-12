// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

#include "Matrix3Benchmark.hpp"
#include "../Space/Vector3Benchmark.hpp"
#include "../Space/QuaternionBenchmark.hpp"

#if SA_MATHS_MATRIX3_SIMD || SA_CI

namespace SA::Benchmark
{
    template <typename T>
    static void Mat3_Determinant(benchmark::State& _state)
    {
        T x = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(x += RMat3.Determinant());
    }

    BENCHMARK_TEMPLATE(Mat3_Determinant, int32_t);
    BENCHMARK_TEMPLATE(Mat3_Determinant, float);
    BENCHMARK_TEMPLATE(Mat3_Determinant, double);


    template <typename T>
    static void Mat3_GetInversed(benchmark::State& _state)
    {
        Mat3<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat3.GetInversed());
    }

    //BENCHMARK_TEMPLATE(Mat3_GetInversed, int32_t); // No int test with inverse.
    BENCHMARK_TEMPLATE(Mat3_GetInversed, float);
    BENCHMARK_TEMPLATE(Mat3_GetInversed, double);


    template <typename T>
    static void Mat3_MakeRotation(benchmark::State& _state)
    {
        Mat3<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat3.MakeRotation(RQuat));
    }

    BENCHMARK_TEMPLATE(Mat3_MakeRotation, int32_t);
    BENCHMARK_TEMPLATE(Mat3_MakeRotation, float);
    BENCHMARK_TEMPLATE(Mat3_MakeRotation, double);


    template <typename T>
    static void Mat3_OpMultScalar(benchmark::State& _state)
    {
        Mat3<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat3 * Rand<T>());
    }

    BENCHMARK_TEMPLATE(Mat3_OpMultScalar, int32_t);
    BENCHMARK_TEMPLATE(Mat3_OpMultScalar, float);
    BENCHMARK_TEMPLATE(Mat3_OpMultScalar, double);


    template <typename T>
    static void Mat3_OpAdd(benchmark::State& _state)
    {
        Mat3<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat3 + RMat3);
    }

    BENCHMARK_TEMPLATE(Mat3_OpAdd, int32_t);
    BENCHMARK_TEMPLATE(Mat3_OpAdd, float);
    BENCHMARK_TEMPLATE(Mat3_OpAdd, double);


    template <typename T>
    static void Mat3_OpMult(benchmark::State& _state)
    {
        Mat3<T> mres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(mres += RMat3 * RMat3);
    }

    BENCHMARK_TEMPLATE(Mat3_OpMult, int32_t);
    BENCHMARK_TEMPLATE(Mat3_OpMult, float);
    BENCHMARK_TEMPLATE(Mat3_OpMult, double);


    template <typename T>
    static void Mat3_OpMultVec3(benchmark::State& _state)
    {
        Vec3<T> vres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(vres += RMat3 * RVec3);
    }

    BENCHMARK_TEMPLATE(Mat3_OpMultVec3, int32_t);
    BENCHMARK_TEMPLATE(Mat3_OpMultVec3, float);
    BENCHMARK_TEMPLATE(Mat3_OpMultVec3, double);
}

#endif
