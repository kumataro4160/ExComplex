export module complex.pcomplex:real;

export import :basic;
export import :pcomplex_t;
import realmath.cos;

export namespace kuma
{
	constexpr float64_t real(const pcomplex64_t& c)noexcept
	{
		return c.radius() * cos(c.argRad());
	}

	constexpr float32_t real(const pcomplex32_t& c)noexcept
	{
		return c.radius() * cos(c.argRad());
	}
}