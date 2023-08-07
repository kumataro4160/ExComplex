module;

#include <complex>

export module complex.sqrt;

export import complex.pcomplex;
import realmath.sqrt;

export namespace complex
{
	template <class FloatType>
	constexpr std::complex<FloatType> sqrt(FloatType x)noexcept
	{
		if(x >= 0.0)
		{
			return std::complex<FloatType>(realmath::sqrt(x));
		}
		else
		{
			return std::complex<FloatType>(0.0, realmath::sqrt(-x));
		}
	}

	constexpr pcomplex64_t sqrt(const pcomplex64_t& p, bool upperHalfPlane = true)noexcept
	{
		return pcomplex64_t(realmath::sqrt(p.radius()), (p.argBrad() >> 1) + upperHalfPlane ? 0 : halfArg64);
	}

	constexpr pcomplex32_t sqrt(const pcomplex32_t& p, bool upperHalfPlane = true)noexcept
	{
		return pcomplex32_t(realmath::sqrt(p.radius()), (p.argBrad() >> 1) + upperHalfPlane ? 0 : halfArg32);
	}
}