export module complex.rectangular;

export namespace complex
{
	template <class FloatType>
	class complex_polar;

	template <class FloatType>
	constexpr FloatType real(const complex_polar<FloatType>& c)noexcept;

	template <class FloatType>
	constexpr FloatType imag(const complex_polar<FloatType>& c)noexcept;

	template <class FloatType>
	class complex_rectangular
	{
		FloatType r;
		FloatType i;

	public:
		constexpr complex_rectangular()noexcept :
			r(FloatType(0.0)), i(FloatType(0.0))
		{

		}
		constexpr complex_rectangular(FloatType real)noexcept :
			r(real), i(FloatType(0.0))
		{

		}
		constexpr explicit complex_rectangular(FloatType real, FloatType imag)noexcept :
			r(real), i(imag)
		{

		}
		constexpr explicit complex_rectangular(const complex_polar<FloatType>& polar)noexcept :
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
		constexpr const complex_rectangular& operator+=(const complex_rectangular& c)noexcept
		{
			r += c.r;
			i += c.i;
			return *this;
		}
		constexpr const complex_rectangular& operator+=(FloatType real)noexcept
		{
			r += real;
			return *this;
		}
		constexpr const complex_rectangular& operator-=(const complex_rectangular& c)noexcept
		{
			r -= c.r;
			i -= c.i;
			return *this;
		}
		constexpr const complex_rectangular& operator-=(FloatType real)noexcept
		{
			r -= real;
			return *this;
		}
		constexpr const complex_rectangular& operator*=(const complex_rectangular& c)noexcept
		{
			*this = *this * c;
			return *this;
		}
		constexpr const complex_rectangular& operator*=(FloatType real)noexcept
		{
			r *= real;
			i *= real;
			return *this;
		}
		constexpr const complex_rectangular& operator/=(const complex_rectangular& c)noexcept
		{
			*this = *this / c;
			return *this;
		}
		constexpr const complex_rectangular& operator/=(FloatType real)noexcept
		{
			r /= real;
			i /= real;
			return *this;
		}
	};

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator+(const complex_rectangular<FloatType>& cl, const complex_rectangular<FloatType>& cr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() + cr.real(), cl.imag() + cr.imag());
	}

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator+(const complex_rectangular<FloatType>& cl, FloatType rr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() + rr, cl.imag());
	}
	/*
	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator+(FloatType left, const complex_rectangular<FloatType>& right)noexcept
	{
		return complex_rectangular<FloatType>(left + right.real(), right.imag());
	}
	*/
	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator-(const complex_rectangular<FloatType>& cl, const complex_rectangular<FloatType>& cr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() - cr.real(), cl.imag() - cr.imag());
	}

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator-(const complex_rectangular<FloatType>& cl, FloatType rr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() - rr, cl.imag());
	}

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator-(FloatType rl, const complex_rectangular<FloatType>& cr)noexcept
	{
		return complex_rectangular<FloatType>(rl - cr.real(), -cr.imag());
	}

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator*(const complex_rectangular<FloatType>& cl, const complex_rectangular<FloatType>& cr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() * cr.real() - cl.imag() * cr.imag(), cl.real() * cr.imag() + cr.real() * cl.imag());
	}

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator*(const complex_rectangular<FloatType>& cl, FloatType rr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() * rr, cl.imag() * rr);
	}
	/*
	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator*(FloatType left, const complex_rectangular<FloatType>& right)noexcept
	{
		return complex_rectangular<FloatType>(left * right.real(), left * right.imag());
	}
	*/
	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator/(const complex_rectangular<FloatType>& cl, const complex_rectangular<FloatType>& cr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() * cr.real() + cl.imag() * cr.imag(), cr.real() * cl.imag() - cl.real() * cr.imag()) /= (cr.real() * cr.real() + cr.imag() * cr.imag());
	}

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator/(const complex_rectangular<FloatType>& cl, FloatType rr)noexcept
	{
		return complex_rectangular<FloatType>(cl.real() / rr, cl.imag() / rr);
	}

	template <class FloatType>
	constexpr complex_rectangular<FloatType> operator/(FloatType rl, const complex_rectangular<FloatType>& cr)noexcept
	{
		return complex_rectangular<FloatType>(rl * cr.real(), -rl * cr.imag()) /= (cr.real() * cr.real() + cr.imag() * cr.imag());
	}
}