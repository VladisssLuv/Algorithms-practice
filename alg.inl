#include "alg.h"

// бинарный поиск
class alg::BF
{

public:
	template<typename Container, typename T>
	int find(const Container& container, T value)
	{
		return _find(value, container.size(), container);
	}

	template<typename T>
	int find(T* array, int size, T value)
	{
		return _find(value, size, array);
	}

private:
	template<typename T, typename mass>
	int _find(T value, int size, const mass& m)
	{
		int low = 0;
		int high = size - 1;

		while(low <= high)
		{
			int mid = (low + high) / 2;

			if (value == m[mid])
				return mid;
			else if (value > m[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
	
		return -1;
	}
};