module;

#include <complex>

export module complex.polar;

export import complex.pcomplex;

export namespace kuma
{
	constexpr std::complex<float64_t> polar(const pcomplex64_t& p)noexcept
	{
		return std::complex<float64_t>(real(p), imag(p));
	}

	constexpr std::complex<float32_t> polar(const pcomplex32_t& p)noexcept
	{
		return std::complex<float32_t>(real(p), imag(p));
	}
}