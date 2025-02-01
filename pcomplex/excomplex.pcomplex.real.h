#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_REAL_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_REAL_H

#include "excomplex.pcomplex.base.h"
#include "excomplex.pcomplex.pcomplex_t.h"
#include "../../RealMath/realmath.cos.h"


namespace kuma
{
	constexpr float64_t real(const pcomplex64_t& c)noexcept
	{
		return c.radius() * cos(c.argRad());
	}

	constexpr float32_t real(const pcomplex32_t& c)noexcept
	{
		return c.radius() * cos(c.argRad());
	}
}


#endif