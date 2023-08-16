export module complex.pcomplex:arg;

export import :basic;
export import :pcomplex_t;

export namespace kuma
{
	constexpr float64_t arg(const pcomplex64_t& c)noexcept
	{
		return c.argRad();
	}

	constexpr float32_t arg(const pcomplex32_t& c)noexcept
	{
		return c.argRad();
	}
}