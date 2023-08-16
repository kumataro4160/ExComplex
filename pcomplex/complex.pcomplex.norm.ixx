export module complex.pcomplex:norm;

export import :basic;
export import :pcomplex_t;

export namespace kuma
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