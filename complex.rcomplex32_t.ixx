export module complex.rcomplex32_t;

export namespace complex
{
	template <class FloatType>
	class complex_polar;

	template <class FloatType>
	constexpr FloatType real(const complex_polar<FloatType>& c)noexcept;

	template <class FloatType>
	constexpr FloatType imag(const complex_polar<FloatType>& c)noexcept;

	using float32_t = float;

	class rcomplex32_t
	{
		float32_t r;
		float32_t i;

	public:
		constexpr rcomplex32_t()noexcept :
			r(0.0f), i(0.0f)
		{

		}
		constexpr rcomplex32_t(FloatType real)noexcept :
			r(real), i(0.0f)
		{

		}
		constexpr explicit rcomplex32_t(FloatType real, FloatType imag)noexcept :
			r(real), i(imag)
		{

		}
		constexpr explicit rcomplex32_t(const complex_polar<FloatType>& polar)noexcept :
			r(helix::real(polar)), i(helix::imag(polar))
		{

		}
		constexpr FloatType real()const noexcept
		{
			return r;
		}
		constexpr FloatType imag()const noexcept
		{
			return i;
		}
		constexpr const rcomplex32_t& operator+=(const rcomplex32_t& c)noexcept
		{
			r += c.r;
			i += c.i;
			return *this;
		}
		constexpr const rcomplex32_t& operator+=(FloatType real)noexcept
		{
			r += real;
			return *this;
		}
		constexpr const rcomplex32_t& operator-=(const rcomplex32_t& c)noexcept
		{
			r -= c.r;
			i -= c.i;
			return *this;
		}
		constexpr const rcomplex32_t& operator-=(FloatType real)noexcept
		{
			r -= real;
			return *this;
		}
		constexpr const rcomplex32_t& operator*=(const rcomplex32_t& c)noexcept
		{
			*this = *this * c;
			return *this;
		}
		constexpr const rcomplex32_t& operator*=(FloatType real)noexcept
		{
			r *= real;
			i *= real;
			return *this;
		}
		constexpr const rcomplex32_t& operator/=(const rcomplex32_t& c)noexcept
		{
			*this = *this / c;
			return *this;
		}
		constexpr const rcomplex32_t& operator/=(FloatType real)noexcept
		{
			r /= real;
			i /= real;
			return *this;
		}
	};

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator+(const rcomplex32_t<FloatType>& cl, const rcomplex32_t<FloatType>& cr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() + cr.real(), cl.imag() + cr.imag());
	}

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator+(const rcomplex32_t<FloatType>& cl, FloatType rr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() + rr, cl.imag());
	}
	/*
	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator+(FloatType left, const complex_rectangular<FloatType>& right)noexcept
	{
		return complex_rectangular<FloatType>(left + right.real(), right.imag());
	}
	*/
	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator-(const rcomplex32_t<FloatType>& cl, const rcomplex32_t<FloatType>& cr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() - cr.real(), cl.imag() - cr.imag());
	}

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator-(const rcomplex32_t<FloatType>& cl, FloatType rr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() - rr, cl.imag());
	}

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator-(FloatType rl, const rcomplex32_t<FloatType>& cr)noexcept
	{
		return rcomplex32_t<FloatType>(rl - cr.real(), -cr.imag());
	}

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator*(const rcomplex32_t<FloatType>& cl, const rcomplex32_t<FloatType>& cr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() * cr.real() - cl.imag() * cr.imag(), cl.real() * cr.imag() + cr.real() * cl.imag());
	}

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator*(const rcomplex32_t<FloatType>& cl, FloatType rr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() * rr, cl.imag() * rr);
	}
	/*
	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator*(FloatType left, const complex_rectangular<FloatType>& right)noexcept
	{
		return complex_rectangular<FloatType>(left * right.real(), left * right.imag());
	}
	*/
	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator/(const rcomplex32_t<FloatType>& cl, const rcomplex32_t<FloatType>& cr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() * cr.real() + cl.imag() * cr.imag(), cr.real() * cl.imag() - cl.real() * cr.imag()) /= (cr.real() * cr.real() + cr.imag() * cr.imag());
	}

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator/(const rcomplex32_t<FloatType>& cl, FloatType rr)noexcept
	{
		return rcomplex32_t<FloatType>(cl.real() / rr, cl.imag() / rr);
	}

	template <class FloatType>
	constexpr rcomplex32_t<FloatType> operator/(FloatType rl, const rcomplex32_t<FloatType>& cr)noexcept
	{
		return rcomplex32_t<FloatType>(rl * cr.real(), -rl * cr.imag()) /= (cr.real() * cr.real() + cr.imag() * cr.imag());
	}
}