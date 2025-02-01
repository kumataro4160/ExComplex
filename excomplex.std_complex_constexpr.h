#ifndef KUMATARO_INCLUDE_EXCOMPLEX_STD_COMPLEX_CONSTEXPR_H
#define KUMATARO_INCLUDE_EXCOMPLEX_STD_COMPLEX_CONSTEXPR_H

#include <complex>
#include "../RealMath/realmath.sqrt.h"
#include "../RealMath/realmath.arctan.h"
#include "../RealMath/realmath.sin.h"
#include "../RealMath/realmath.cos.h"


namespace kuma
{
	template <class FloatType>
	constexpr FloatType abs(const std::complex<FloatType>& c)noexcept
	{
		return sqrt(std::norm(c));
	}

	template <class FloatType>
	constexpr FloatType arg(const std::complex<FloatType>& c)noexcept
	{
		return arctan(c.real(), c.imag());
	}

	template <class FloatType>
	constexpr std::complex<FloatType> sqrt(FloatType x)noexcept
	{
		if(x >= 0.0)
		{
			return std::complex<FloatType>(sqrt(x));
		}
		else
		{
			return std::complex<FloatType>(0.0, sqrt(-x));
		}
	}

	template <class FloatType>
	constexpr std::complex<FloatType> polar(FloatType rho, FloatType theta = FloatType())noexcept
	{
		return rho * std::complex<FloatType>(cos(theta), sin(theta));
	}
}


#endif