#pragma once

#include <iostream>

template<class T>
class Complex
{
	T m_Re;
	T m_Im;
public:
	Complex();
	Complex(T Re, T Im);
	template<class T2>
	Complex(Complex<T2> const& rhs);

	template<class T2>
	Complex<T>& operator=(Complex<T2> const& rhs);

	T GetRe() const;
	T GetIm() const;

	Complex<T> operator+(Complex<T> const& rhs);
	Complex<T> operator*(Complex<T> const& rhs);
};

template<class T>
Complex<T>::Complex() :
	m_Re(0), m_Im(0)
{
}

template<class T>
Complex<T>::Complex(T Re, T Im)
{
	m_Re = Re;
	m_Im = Im;
}

template<class T>
template<class T2>
Complex<T>::Complex(Complex<T2> const& rhs)
{
	m_Im = (T)rhs.GetIm();
	m_Re = (T)rhs.GetRe();
}

template<class T>
T Complex<T>::GetRe() const
{
	return m_Re;
}

template<class T>
T Complex<T>::GetIm() const
{
	return m_Im;
}

template<class T>
Complex<T> Complex<T>::operator+(Complex<T> const& rhs)
{
	Complex<T> result(m_Re + rhs.m_Re, m_Im + rhs.m_Im);
	return result;
}

template<class T>
Complex<T> Complex<T>::operator*(Complex<T> const& rhs)
{
	Complex<T> result(m_Re * rhs.m_Re - m_Im * rhs.m_Im,
		m_Im * rhs.m_Re + m_Re * rhs.m_Im);
	return result;
}

template<class T>
std::ostream& operator<<(std::ostream& stream, Complex<T> const& rhs)
{
	stream << rhs.GetRe() << (rhs.GetIm() >= 0 ? "+" : "") << rhs.GetIm() << "i";
	return stream;
}

template<class T>
template<class T2>
Complex<T>& Complex<T>::operator=(Complex<T2> const& rhs)
{
	if ((void*)this != (void*)&rhs)
	{
		m_Im = (T)rhs.m_Im;
		m_Re = (T)rhs.m_Re;
	}
	return *this;
}