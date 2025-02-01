#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_CONJ_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_CONJ_H

#include "excomplex.pcomplex.pcomplex_t.h"


namespace kuma
{
	constexpr pcomplex64_t conj(const pcomplex64_t& c)noexcept
	{
		return pcomplex64_t(c.radius(), -c.argBrad());
	}

	constexpr pcomplex32_t conj(const pcomplex32_t& c)noexcept
	{
		return pcomplex32_t(c.radius(), -c.argBrad());
	}
}


#endif