export module complex.pcomplex:imag;

export import :basic;
export import :pcomplex_t;
import realmath.sin;

export namespace kuma
{
	constexpr float64_t imag(const pcomplex64_t& c)noexcept
	{
		return c.radius() * realmath::sin(c.argRad());
	}

	constexpr float32_t imag(const pcomplex32_t& c)noexcept
	{
		return c.radius() * realmath::sin(c.argRad());
	}
}