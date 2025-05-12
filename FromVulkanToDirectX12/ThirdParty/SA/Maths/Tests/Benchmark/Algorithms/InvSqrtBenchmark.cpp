// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <cmath>

#include <benchmark/benchmark.h>

#if SA_SUPPORT_IMPL

	#include <SA/Support/Intrinsics.hpp>

#endif


#include "../Tools/Random.hpp"

#define SA_MATHS_BENCHMARK_INV_SQRT (0 || SA_CI)

#if SA_MATHS_BENCHMARK_INV_SQRT

namespace SA::Benchmark
{
#if !SA_MATHS_INTRINSICS_OPT

//{ STD

	template <typename T>
	T InvSqrt_STD(T _in) noexcept
	{
		return T(1) / std::sqrt(_in);
	}

	template <typename T>
	static void BM_InvSqrt_STD(benchmark::State& _state)
	{
		T x = T();

		for (auto _ : _state)
			benchmark::DoNotOptimize(x += InvSqrt_STD(Rand<T>()));
	}

	BENCHMARK_TEMPLATE(BM_InvSqrt_STD, float);
	BENCHMARK_TEMPLATE(BM_InvSqrt_STD, double);

//}

#else

//{ Fast

	/**
	*	Sources: https://en.wikipedia.org/wiki/Fast_inverse_square_root
	*/
	float InvSqrt_Fast(float _in) noexcept
	{
		const float threehalfs = 1.5f;

		float y = _in;
		float x2 = _in * 0.5F;

		int64_t i = *(int64_t*)&y;

		i = 0x5f3759df - (i >> 1);
		y = *(float*)&i;

		// 1st Newton-Raphson iteration
		y *= threehalfs - (x2 * y * y);

		// 2nd Newton-Raphson iteration
		y *= threehalfs - (x2 * y * y);

		return y;
	}

	/**
	*	Sources:
	*	https://stackoverflow.com/questions/11644441/fast-inverse-square-root-on-x64/11644533
	*	https://stackoverflow.com/a/41637260
	*/
	double InvSqrt_Fast(double _in) noexcept
	{
		const double threehalfs = 1.5;

		double y = _in;
		double x2 = _in * 0.5;

		int64_t i = *(int64_t*)&y;

		i = 0x5fe6eb50c7b537a9 - (i >> 1);
		y = *(double*)&i;

		// 1st Newton-Raphson iteration
		y *= threehalfs - (x2 * y * y);
		
		// 2nd Newton-Raphson iteration
		y *= threehalfs - (x2 * y * y);

		return y;
	}

	template <typename T>
	static void BM_InvSqrt_Fast(benchmark::State& _state)
	{
		T x = T();

		for (auto _ : _state)
			benchmark::DoNotOptimize(x += InvSqrt_Fast(Rand<T>()));
	}

	BENCHMARK_TEMPLATE(BM_InvSqrt_Fast, float);
	BENCHMARK_TEMPLATE(BM_InvSqrt_Fast, double);

//}


//{ SIMD

#if SA_INTRISC_SSE

	/**
	*	Unreal Engine 4 implementation.
	*/
	float InvSqrt_SIMD(float _in) noexcept
	{
		const __m128 fOneHalf = _mm_set_ss(0.5f);
		__m128 Y0, X0, X1, X2, FOver2;
		float temp;

		Y0 = _mm_set_ss(_in);
		X0 = _mm_rsqrt_ss(Y0);	// 1/sqrt estimate (12 bits)
		FOver2 = _mm_mul_ss(Y0, fOneHalf);

		// 1st Newton-Raphson iteration
		X1 = _mm_mul_ss(X0, X0);
		X1 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X1));
		X1 = _mm_add_ss(X0, _mm_mul_ss(X0, X1));

		// 2nd Newton-Raphson iteration
		X2 = _mm_mul_ss(X1, X1);
		X2 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X2));
		X2 = _mm_add_ss(X1, _mm_mul_ss(X1, X2));

		_mm_store_ss(&temp, X2);
		return temp;
	}

	template <typename T>
	static void BM_InvSqrt_SIMD(benchmark::State& _state)
	{
		T x = T();

		for (auto _ : _state)
			benchmark::DoNotOptimize(x += InvSqrt_SIMD(Rand<T>()));
	}

	BENCHMARK_TEMPLATE(BM_InvSqrt_SIMD, float);

#endif

//}

#endif

}

#endif
