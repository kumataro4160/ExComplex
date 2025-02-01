#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_SQRT_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_SQRT_H

#include "excomplex.pcomplex.pcomplex_t.h"
#include "../../RealMath/realmath.sqrt.h"


namespace kuma
{
	constexpr pcomplex64_t sqrt(const pcomplex64_t& p, bool upperHalfPlane = true)noexcept
	{
		return pcomplex64_t(sqrt(p.radius()), (p.argBrad() >> 1) + upperHalfPlane ? 0 : halfArg64);
	}

	constexpr pcomplex32_t sqrt(const pcomplex32_t& p, bool upperHalfPlane = true)noexcept
	{
		return pcomplex32_t(sqrt(p.radius()), (p.argBrad() >> 1) + upperHalfPlane ? 0 : halfArg32);
	}
}


#endif