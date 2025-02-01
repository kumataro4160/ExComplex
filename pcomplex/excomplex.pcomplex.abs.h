#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_ABS_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_ABS_H

#include "excomplex.pcomplex.base.h"
#include "excomplex.pcomplex.pcomplex_t.h"


namespace kuma
{
	constexpr float64_t abs(const pcomplex64_t& c)noexcept
	{
		return c.radius();
	}

	constexpr float32_t abs(const pcomplex32_t& c)noexcept
	{
		return c.radius();
	}
}


#endif