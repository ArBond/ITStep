#pragma once

template<class T, int N>
class Array
{
public:
	T m_array[N];
	Array();


	template<int N1>
	Array(const Array<T, N1>& rhs);

	T& operator[](int idx);

	int GetSize() const;

	template<int N1>
	Array<T, N>& operator=(Array<T, N1> const& rhs);
};

template<class T, int N>
template<int N1>

Array<T, N>& Array<T, N>::operator=(Array<T, N1> const& rhs)
{
	if ((void*)&rhs != (void*)this)
	{
		for (int i = 0; i < N; ++i)
		{
			m_array[i] = i < N1 ? rhs.m_array[i] : T();
		}
	}
	return *this;
}

template<class T, int N>
Array<T, N>::Array()
{
	memset(m_array, 0, N);
}

template<class T, int N>
template<int N1>
Array<T, N>::Array(const Array<T, N1>& rhs)
{
	for (int i = 0; i < N; ++i)
	{
		m_array[i] = i < N1 ? rhs.m_array[i] : T();
	}
}

template<class T, int N>
T& Array<T, N>::operator[](int idx)
{
	if (idx < 0 || idx >= N)
	{
		std::cout << "Invalid index\n";
		exit(1);
	}
	return m_array[idx];
}

template<class T, int N>
int Array<T, N>::GetSize() const
{
	return N;
}