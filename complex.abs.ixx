module;

#include <complex>

export module complex.abs;

export import complex.basic;
import complex.pcomplex;
import complex.pcomplex.norm;
import realmath.sqrt;

export namespace complex
{
	template <class FloatType>
	constexpr FloatType abs(const std::complex<FloatType>& c)noexcept
	{
		return realmath::sqrt(std::norm(c));
	}

	constexpr float64_t abs(const pcomplex64_t& c)noexcept
	{
		return c.radius();
	}

	constexpr float32_t abs(const pcomplex32_t& c)noexcept
	{
		return c.radius();
	}
}