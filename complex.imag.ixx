module;

#include <complex>

export module complex.imag;

export import complex.basic;
export import complex.pcomplex;
import realmath.sin;

export namespace complex
{
	template <class FloatType>
	constexpr FloatType real(const std::complex<FloatType>& c)noexcept
	{
		return c.imag();
	}

	constexpr float64_t imag(const pcomplex64_t& c)noexcept
	{
		return c.radius() * realmath::sin(c.argRad());
	}

	constexpr float32_t imag(const pcomplex32_t& c)noexcept
	{
		return c.radius() * realmath::sin(c.argRad());
	}
}