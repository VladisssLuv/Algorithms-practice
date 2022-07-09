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

class alg::Backpack
{
public:
	template<typename Container>
	int best_price(const Container& wts, const Container& cost, int W)
	{
		size_t n = wts.size();
		std::vector<std::vector<int> > dp(W + 1, std::vector<int>(n + 1, 0));
		for (size_t j = 1; j <= n; j++)
		{
			for (int w = 1; w <= W; w++)
			{
				if (wts[j - 1] <= w)
				{
					dp[w][j] = std::max(dp[w][j - 1], dp[w - wts[j - 1]][j - 1] + cost[j - 1]);
				}
				else
				{
					dp[w][j] = dp[w][j - 1];
				}
			}
		}
		return dp[W][n];
	}
};