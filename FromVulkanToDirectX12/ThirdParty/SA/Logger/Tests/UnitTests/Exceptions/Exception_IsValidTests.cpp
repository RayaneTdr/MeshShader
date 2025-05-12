// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_IsValid
{
	class MyClass
	{
	public:
		int i = 0;

		MyClass(int _i) noexcept : i{_i}
		{
		}

		bool IsValid() const noexcept { return i > 0;}

		void Foo()
		{
			SA_ASSERT(IsThisValid, SA/UnitTests/Exception, L"Must be valid before executing Foo()");
		}
	};

	TEST(Exception, IsValid_Success)
	{
		MyClass m1(4);

		EXPECT_NO_THROW(SA_ASSERT((IsValid, m1), SA/UnitTests/Exception));
		EXPECT_NO_THROW(m1.Foo());
	}

	TEST(Exception, IsValid_Failure)
	{
		MyClass m2(-1);

		EXPECT_THROW(SA_ASSERT((IsValid, m2), SA/UnitTests/Exception), Exception_IsValid);
		EXPECT_THROW(m2.Foo(), Exception_IsValid);
	}
}

namespace SA
{
	template <>
	std::string ToString(const UT::Exc_IsValid::MyClass& _m)
	{
		return "i: " + std::to_string(_m.i);
	}
}
