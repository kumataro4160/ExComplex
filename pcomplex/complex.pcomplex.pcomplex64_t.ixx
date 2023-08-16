module;

#include <complex>
#include <numbers>

export module complex.pcomplex:pcomplex64_t;

export import :basic;

namespace kuma
{
	template <class FloatType>
	constexpr FloatType abs(const std::complex<FloatType>& c)noexcept;

	template <class FloatType>
	constexpr FloatType arg(const std::complex<FloatType>& c)noexcept;
}

export namespace kuma
{
	constexpr brad64_t halfArg64 = 0x8000000000000000LL;

	constexpr brad64_t argBrad64(float64_t theta)noexcept
	{
		constexpr float64_t c = 0x4000000000000000LL / 0.25;
		const signed long long loop = static_cast<brad64_t>(theta / (2.0 * std::numbers::pi));
		const float64_t rest = theta - (loop * (2.0 * std::numbers::pi));
		return static_cast<brad64_t>(static_cast<unsigned long long>(rest * c));
	}

	constexpr float64_t argRad64(brad64_t beta)noexcept
	{
		constexpr float64_t c = 0.25 / 0x4000000000000000LL;
		return static_cast<float64_t>(beta * c);
	}

	class pcomplex64_t
	{
		float64_t rho;
		brad64_t beta;

	public:
		constexpr pcomplex64_t(float64_t radius = 0.0, brad64_t argBrad = 0LL)noexcept :
			rho(radius), beta(argBrad)
		{

		}
		constexpr pcomplex64_t(float64_t radius, float64_t argRad)noexcept :
			rho(radius), beta(argBrad64(argRad))
		{

		}
		constexpr explicit pcomplex64_t(const std::complex<float64_t>& rectangular)noexcept :
			rho(kuma::abs(rectangular)), beta(argBrad64(kuma::arg(rectangular)))
		{

		}
		constexpr float64_t& radius()noexcept
		{
			return rho;
		}
		constexpr float64_t radius()const noexcept
		{
			return rho;
		}
		constexpr brad64_t& argBrad()noexcept
		{
			return beta;
		}
		constexpr brad64_t argBrad()const noexcept
		{
			return beta;
		}
		constexpr void argRad(float64_t theta)noexcept
		{
			beta = argBrad64(theta);
		}
		constexpr float64_t argRad()const noexcept
		{
			return argRad64(beta);
		}
		constexpr pcomplex64_t& operator*=(const pcomplex64_t& pr)noexcept
		{
			rho *= pr.rho;
			beta += pr.beta;
			return *this;
		}
		constexpr pcomplex64_t& operator*=(float64_t rr)noexcept
		{
			if(rr >= 0.0)
			{
				rho *= rr;
			}
			else
			{
				rho *= -rr;
				beta += halfArg64;
			}
			return *this;
		}
		constexpr pcomplex64_t& operator/=(const pcomplex64_t& pr)noexcept
		{
			rho /= pr.rho;
			beta -= pr.beta;
			return *this;
		}
		constexpr pcomplex64_t& operator/=(float64_t rr)noexcept
		{
			if(rr >= 0.0)
			{
				rho /= rr;
			}
			else
			{
				rho /= -rr;
				beta += halfArg64;
			}
			return *this;
		}
	};

	constexpr pcomplex64_t operator+(const pcomplex64_t& p)noexcept
	{
		return p;
	}

	constexpr pcomplex64_t operator-(const pcomplex64_t& p)noexcept
	{
		return pcomplex64_t(p.radius(), p.argBrad() + halfArg64);
	}

	constexpr pcomplex64_t operator*(const pcomplex64_t& pl, const pcomplex64_t& pr)noexcept
	{
		return pcomplex64_t(pl) *= pr;
	}

	constexpr pcomplex64_t operator*(const pcomplex64_t& pl, float64_t rr)noexcept
	{
		return pcomplex64_t(pl) *= rr;
	}

	constexpr pcomplex64_t operator/(const pcomplex64_t& pl, const pcomplex64_t& pr)noexcept
	{
		return pcomplex64_t(pl) /= pr;
	}

	constexpr pcomplex64_t operator/(const pcomplex64_t& pl, float64_t rr)noexcept
	{
		return pcomplex64_t(pl) /= rr;
	}

	constexpr pcomplex64_t operator/(float64_t rl, const pcomplex64_t& pr)noexcept
	{
		return pcomplex64_t(rl) /= pr;
	}

	constexpr bool operator==(const pcomplex64_t& pl, const pcomplex64_t& pr)noexcept
	{
		return pl.radius() == pr.radius() && pl.argBrad() == pr.argBrad();
	}

	constexpr bool operator!=(const pcomplex64_t& pl, const pcomplex64_t& pr)noexcept
	{
		return !(pl == pr);
	}
}