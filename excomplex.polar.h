#ifndef KUMATARO_INCLUDE_EXCOMPLEX_POLAR_H
#define KUMATARO_INCLUDE_EXCOMPLEX_POLAR_H

#include <complex>
#include "pcomplex/excomplex.pcomplex.h"


namespace kuma
{
	constexpr std::complex<float64_t> polar(const pcomplex64_t& p)noexcept
	{
		return std::complex<float64_t>(real(p), imag(p));
	}

	constexpr std::complex<float32_t> polar(const pcomplex32_t& p)noexcept
	{
		return std::complex<float32_t>(real(p), imag(p));
	}
}


#endif