#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_NORM_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_NORM_H

#include "excomplex.pcomplex.base.h"
#include "excomplex.pcomplex.pcomplex_t.h"


namespace kuma
{
	constexpr float64_t norm(const pcomplex64_t& c)noexcept
	{
		return c.radius() * c.radius();
	}

	constexpr float32_t norm(const pcomplex32_t& c)noexcept
	{
		return c.radius() * c.radius();
	}
}


#endif