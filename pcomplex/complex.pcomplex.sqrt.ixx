export module complex.pcomplex:sqrt;

export import :pcomplex_t;
import realmath.sqrt;

export namespace kuma
{
	constexpr pcomplex64_t sqrt(const pcomplex64_t& p, bool upperHalfPlane = true)noexcept
	{
		return pcomplex64_t(realmath::sqrt(p.radius()), (p.argBrad() >> 1) + upperHalfPlane ? 0 : halfArg64);
	}

	constexpr pcomplex32_t sqrt(const pcomplex32_t& p, bool upperHalfPlane = true)noexcept
	{
		return pcomplex32_t(realmath::sqrt(p.radius()), (p.argBrad() >> 1) + upperHalfPlane ? 0 : halfArg32);
	}
}