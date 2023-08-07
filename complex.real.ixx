module;

#include <complex>

export module complex.real;

export import complex.basic;
export import complex.pcomplex;
import realmath.cos;

export namespace complex
{
	template <class FloatType>
	constexpr FloatType real(const std::complex<FloatType>& c)noexcept
	{
		return c.real();
	}

	constexpr float64_t real(const pcomplex64_t& c)noexcept
	{
		return c.radius() * realmath::cos(c.argRad());
	}

	constexpr float32_t real(const pcomplex32_t& c)noexcept
	{
		return c.radius() * realmath::cos(c.argRad());
	}
}