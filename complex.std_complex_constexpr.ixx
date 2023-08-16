module;

#include <complex>

export module complex.std_complex_constexpr;

import realmath.sqrt;
import realmath.arctan;
import realmath.sin;
import realmath.cos;

export namespace kuma
{
	template <class FloatType>
	constexpr FloatType abs(const std::complex<FloatType>& c)noexcept
	{
		return realmath::sqrt(std::norm(c));
	}

	template <class FloatType>
	constexpr FloatType arg(const std::complex<FloatType>& c)noexcept
	{
		return realmath::arctan(c.real(), c.imag());
	}

	template <class FloatType>
	constexpr std::complex<FloatType> sqrt(FloatType x)noexcept
	{
		if(x >= 0.0)
		{
			return std::complex<FloatType>(realmath::sqrt(x));
		}
		else
		{
			return std::complex<FloatType>(0.0, realmath::sqrt(-x));
		}
	}

	template <class FloatType>
	constexpr std::complex<FloatType> polar(FloatType rho, FloatType theta = FloatType())noexcept
	{
		return rho * std::complex<FloatType>(realmath::cos(theta), realmath::sin(theta));
	}
}