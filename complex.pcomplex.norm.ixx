export module complex.pcomplex.norm;

export import complex.basic;
export import complex.pcomplex;

export namespace complex
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