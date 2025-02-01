#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_IMAG_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_IMAG_H

#include "excomplex.pcomplex.base.h"
#include "excomplex.pcomplex.pcomplex_t.h"
#include "../../RealMath/realmath.sin.h"


namespace kuma
{
	constexpr float64_t imag(const pcomplex64_t& c)noexcept
	{
		return c.radius() * sin(c.argRad());
	}

	constexpr float32_t imag(const pcomplex32_t& c)noexcept
	{
		return c.radius() * sin(c.argRad());
	}
}


#endif