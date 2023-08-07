module;

#include <complex>

export module complex.arg;

export import complex.basic;
export import complex.pcomplex;
import realmath.arctan;

export namespace complex
{
	template <class FloatType>
	constexpr FloatType arg(const std::complex<FloatType>& c)noexcept
	{
		return realmath::arctan(c.real(), c.imag());
	}

	constexpr float64_t arg(const pcomplex64_t& c)noexcept
	{
		return c.argRad();
	}

	constexpr float32_t arg(const pcomplex32_t& c)noexcept
	{
		return c.argRad();
	}
}