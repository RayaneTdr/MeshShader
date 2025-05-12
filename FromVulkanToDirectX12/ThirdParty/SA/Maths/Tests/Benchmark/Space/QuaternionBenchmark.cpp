// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <benchmark/benchmark.h>

#include "QuaternionBenchmark.hpp"
#include "Vector3Benchmark.hpp"

#if SA_MATHS_QUATERNION_SIMD || SA_CI

namespace SA::Benchmark
{
    template <typename T>
    static void Quat_SqrLength(benchmark::State& _state)
    {
        T x = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(x += RQuat.SqrLength());
    }

    BENCHMARK_TEMPLATE(Quat_SqrLength, float);
    BENCHMARK_TEMPLATE(Quat_SqrLength, double);


    template <typename T>
    static void Quat_GetNormalized(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += RQuat.GetNormalized());
    }

    BENCHMARK_TEMPLATE(Quat_GetNormalized, float);
    BENCHMARK_TEMPLATE(Quat_GetNormalized, double);


    template <typename T>
    static void Quat_Rotate(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
        {
            benchmark::DoNotOptimize(qres += RQuat.Rotate(RQuat));
        }
    }

    BENCHMARK_TEMPLATE(Quat_Rotate, float);
    BENCHMARK_TEMPLATE(Quat_Rotate, double);


    template <typename T>
    static void Quat_Dot(benchmark::State& _state)
    {
        T dot = T();

        for (auto _ : _state)
            benchmark::DoNotOptimize(dot += Quat<T>::Dot(RQuat, RQuat));
    }

    BENCHMARK_TEMPLATE(Quat_Dot, float);
    BENCHMARK_TEMPLATE(Quat_Dot, double);


    template <typename T>
    static void Quat_ToEuler(benchmark::State& _state)
    {
        Vec3<Deg<T>> euler;

        for (auto _ : _state)
            benchmark::DoNotOptimize(euler += RQuat.ToEuler());
    }

    BENCHMARK_TEMPLATE(Quat_ToEuler, float);
    BENCHMARK_TEMPLATE(Quat_ToEuler, double);


    template <typename T>
    static void Quat_FromEuler(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += Quat<T>::FromEuler(RVec3));
    }

    BENCHMARK_TEMPLATE(Quat_FromEuler, float);
    BENCHMARK_TEMPLATE(Quat_FromEuler, double);


    template <typename T>
    static void Quat_OperatorPlus(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += RQuat + RQuat);
    }

    BENCHMARK_TEMPLATE(Quat_OperatorPlus, float);
    BENCHMARK_TEMPLATE(Quat_OperatorPlus, double);


    template <typename T>
    static void Quat_OperatorMult(benchmark::State& _state)
    {
        Quat<T> qres;

        for (auto _ : _state)
            benchmark::DoNotOptimize(qres += RQuat * RQuat);
    }

    BENCHMARK_TEMPLATE(Quat_OperatorMult, float);
    BENCHMARK_TEMPLATE(Quat_OperatorMult, double);
}

#endif
