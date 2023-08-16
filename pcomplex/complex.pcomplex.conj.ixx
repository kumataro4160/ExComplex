export module complex.pcomplex:conj;

export import :pcomplex_t;

export namespace kuma
{
	constexpr pcomplex64_t conj(const pcomplex64_t& c)noexcept
	{
		return pcomplex64_t(c.radius(), -c.argBrad());
	}

	constexpr pcomplex32_t conj(const pcomplex32_t& c)noexcept
	{
		return pcomplex32_t(c.radius(), -c.argBrad());
	}
}