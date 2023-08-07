module;

#include <complex>

export module complex.polar;

export import complex.basic;
export import complex.pcomplex;
import complex.real;
import complex.imag;

export namespace complex
{
	constexpr std::complex<float64_t> polar(const pcomplex64_t& p)noexcept
	{
		return std::complex<float64_t>(real(p), imag(p));
	}

	constexpr std::complex<float32_t> polar(const pcomplex32_t& p)noexcept
	{
		return std::complex<float32_t>(real(p), imag(p));
	}

	constexpr std::complex<float64_t> polar(float64_t rho, float64_t theta = 0.0)noexcept
	{
		return polar(pcomplex64_t(rho, theta));
	}

	constexpr std::complex<float32_t> polar(float32_t rho, float32_t theta = 0.0f)noexcept
	{
		return polar(pcomplex32_t(rho, theta));
	}
}