export module complex.pcomplex:abs;

export import :basic;
export import :pcomplex_t;

export namespace kuma
{
	constexpr float64_t abs(const pcomplex64_t& c)noexcept
	{
		return c.radius();
	}

	constexpr float32_t abs(const pcomplex32_t& c)noexcept
	{
		return c.radius();
	}
}