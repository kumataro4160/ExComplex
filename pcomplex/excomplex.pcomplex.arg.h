#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_ARG_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_ARG_H

#include "excomplex.pcomplex.base.h"
#include "excomplex.pcomplex.pcomplex_t.h"


namespace kuma
{
	constexpr float64_t arg(const pcomplex64_t& c)noexcept
	{
		return c.argRad();
	}

	constexpr float32_t arg(const pcomplex32_t& c)noexcept
	{
		return c.argRad();
	}
}


#endif