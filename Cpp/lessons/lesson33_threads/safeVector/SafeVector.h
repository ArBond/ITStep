#include <vector>
#include <mutex>
#include <initializer_list>

template <typename T>
class SafeVector
{
	std::vector<T> vector;
	std::mutex mutex;

public:

	SafeVector() = default;

	SafeVector(std::initializer_list<T> list) :
		vector(list)
	{
	}

	void PushBack(T& const element)
	{
		std::unique_lock<std::mutex> lock(mutex);
		vector.push_back(element);
	}

	T PopBack()
	{
		std::unique_lock<std::mutex> lock(mutex);

		if (vector.empty())
			throw std::exception("out of range");
		
		T result = vector[vector.size() - 1];
		vector.pop_back();
		return result;
	}

	T operator[](size_t idx)
	{
		std::unique_lock<std::mutex> lock(mutex);

		if (idx >= vector.size() )
			throw std::exception("out of range");

		return vector[idx];
	}
};
