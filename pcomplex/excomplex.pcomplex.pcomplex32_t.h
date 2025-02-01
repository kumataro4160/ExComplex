#ifndef KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_PCOMPLEX32_T_H
#define KUMATARO_INCLUDE_EXCOMPLEX_PCOMPLEX_PCOMPLEX32_T_H

#include <complex>
#include <numbers>
#include "excomplex.pcomplex.base.h"


namespace kuma
{
	template <class FloatType>
	constexpr FloatType abs(const std::complex<FloatType>& c)noexcept;

	template <class FloatType>
	constexpr FloatType arg(const std::complex<FloatType>& c)noexcept;
}

namespace kuma
{
	constexpr brad32_t halfArg32 = static_cast<brad32_t>(0x80000000LL);

	constexpr brad32_t argBrad32(float32_t theta)noexcept
	{
		constexpr float32_t c = 0x40000000L / 0.25f;
		constexpr float32_t twopi = static_cast <brad32_t>(2.0f * std::numbers::pi);
		const signed long long loop = static_cast<brad32_t>(theta / twopi);
		const float32_t rest = theta - (loop * twopi);
		return static_cast<brad32_t>(static_cast<unsigned long long>(rest * c));
	}

	constexpr float32_t argRad32(brad32_t beta)noexcept
	{
		constexpr float32_t c = 0.25f / 0x40000000L;
		return static_cast<float32_t>(beta * c);
	}

	class pcomplex32_t
	{
		float32_t rho;
		brad32_t beta;

	public:
		constexpr pcomplex32_t(float32_t radius = 0.0f, brad32_t argBrad = 0L)noexcept :
			rho(radius), beta(argBrad)
		{

		}
		constexpr pcomplex32_t(float32_t radius, float32_t argRad)noexcept :
			rho(radius), beta(argBrad32(argRad))
		{

		}
		constexpr explicit pcomplex32_t(const std::complex<float32_t>& rectangular)noexcept :
			rho(kuma::abs(rectangular)), beta(argBrad32(kuma::arg(rectangular)))
		{

		}
		constexpr float32_t& radius()noexcept
		{
			return rho;
		}
		constexpr float32_t radius()const noexcept
		{
			return rho;
		}
		constexpr brad32_t& argBrad()noexcept
		{
			return beta;
		}
		constexpr brad32_t argBrad()const noexcept
		{
			return beta;
		}
		constexpr void argRad(float32_t theta)noexcept
		{
			beta = argBrad32(theta);
		}
		constexpr float32_t argRad()const noexcept
		{
			return argRad32(beta);
		}
		constexpr pcomplex32_t& operator*=(const pcomplex32_t& pr)noexcept
		{
			rho *= pr.rho;
			beta += pr.beta;
			return *this;
		}
		constexpr pcomplex32_t& operator*=(float32_t rr)noexcept
		{
			if(rr >= 0.0f)
			{
				rho *= rr;
			}
			else
			{
				rho *= -rr;
				beta += halfArg32;
			}
			return *this;
		}
		constexpr pcomplex32_t& operator/=(const pcomplex32_t& pr)noexcept
		{
			rho /= pr.rho;
			beta -= pr.beta;
			return *this;
		}
		constexpr pcomplex32_t& operator/=(float32_t rr)noexcept
		{
			if(rr >= 0.0f)
			{
				rho /= rr;
			}
			else
			{
				rho /= -rr;
				beta += halfArg32;
			}
			return *this;
		}
	};

	constexpr pcomplex32_t operator+(const pcomplex32_t& p)noexcept
	{
		return p;
	}

	constexpr pcomplex32_t operator-(const pcomplex32_t& p)noexcept
	{
		return pcomplex32_t(p.radius(), p.argBrad() + halfArg32);
	}

	constexpr pcomplex32_t operator*(const pcomplex32_t& pl, const pcomplex32_t& pr)noexcept
	{
		return pcomplex32_t(pl) *= pr;
	}

	constexpr pcomplex32_t operator*(const pcomplex32_t& pl, float32_t rr)noexcept
	{
		return pcomplex32_t(pl) *= rr;
	}

	constexpr pcomplex32_t operator/(const pcomplex32_t& pl, const pcomplex32_t& pr)noexcept
	{
		return pcomplex32_t(pl) /= pr;
	}

	constexpr pcomplex32_t operator/(const pcomplex32_t& pl, float32_t rr)noexcept
	{
		return pcomplex32_t(pl) /= rr;
	}

	constexpr pcomplex32_t operator/(float32_t rl, const pcomplex32_t& pr)noexcept
	{
		return pcomplex32_t(rl) /= pr;
	}

	constexpr bool operator==(const pcomplex32_t& pl, const pcomplex32_t& pr)noexcept
	{
		return pl.radius() == pr.radius() && pl.argBrad() == pr.argBrad();
	}

	constexpr bool operator!=(const pcomplex32_t& pl, const pcomplex32_t& pr)noexcept
	{
		return !(pl == pr);
	}
}


#endif