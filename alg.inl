#include "alg.h"
#include<vector>
#include<iomanip>

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

// о рюкзаках
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

// о ферзях
class alg::Queens
{
private:
    const int SIZE = 8; // Размер.

    int board[8][8];
    int results_count = 0; // Количество решений.

private:
    // Функция tryQueen() - проверяет нет ли уже установленных ферзей,
    // по вертикали, диагоналям.
    bool tryQueen(int a, int b)
    {
        for (int i = 0; i < a; ++i)
        {
            if (board[i][b])
            {
                return false;
            }
        }

        for (int i = 1; i <= a && b - i >= 0; ++i)
        {
            if (board[a - i][b - i])
            {
                return false;
            }
        }

        for (int i = 1; i <= a && b + i < SIZE; i++)
        {
            if (board[a - i][b + i])
            {
                return false;
            }
        }

        return true;
    }

public:
    // Функция setQueen() - пробует найти результаты решений.
    void setQueen(int a) // a - номер очередной строки в которую нужно поставить очередного ферзя.
    {
        if (a == SIZE)
        {
            showBoard();
            std::cout << "Result #" << ++results_count << "\n\n";
            return; // Опционально.
        }

        for (int i = 0; i < SIZE; ++i)
        {
            // Здесь проверяем, что если поставим в board[a][i] ферзя (единицу),
            // то он будет единственным в этой строке, столбце и диагоналях.
            if (tryQueen(a, i))
            {
                board[a][i] = 1;
                setQueen(a + 1);
                board[a][i] = 0;
            }
        }

        return; // Опционально.
    }

    // Функция showBoard() - отображает доску.
    void showBoard()
    {
        for (int a = 0; a < SIZE; ++a)
        {
            for (int b = 0; b < SIZE; ++b)
            {
                std::cout << ((board[a][b]) ? "Q " : ". ");
            }
            std::cout << '\n';
        }
    }

};

// метод хука-дживса
class alg::JeevesHook
{
private:
    double f(double x0, double x1)

    {

        return (x0 * x0 + 4 * x1 * x1 + 1);

    }

    void issl_search(double start1, double start2, double& new_x1, double& new_x2, double delta1, double delta2)
    {
        double y1, y2;

        double fnx, fy;

        new_x1 = start1;

        new_x2 = start2;

        fnx = f(new_x1, new_x2);

        for (int j = 1; j <= 2;)
        {

            if (j == 1)
            {

                y1 = new_x1 - delta1;

                y2 = new_x2;

            }
            else {

                y1 = new_x1;

                y2 = new_x2 - delta2;

            }

            fy = f(y1, y2);

            if (fnx <= fy)
            {

                if (j == 1)

                {

                    y1 = new_x1 + delta1;

                    y2 = new_x2;

                }
                else {

                    y1 = new_x1;

                    y2 = new_x2 + delta2;

                }

                fy = f(y1, y2);

                if (fnx <= fy)

                {

                    j++;

                    continue;

                }
                else {

                    new_x1 = y1;

                    new_x2 = y2;

                    return;

                }

            }
            else {

                new_x1 = y1;

                new_x2 = y2;

                return;

            }
        }
    }

public:
    void start()
    {
        using namespace std;

        double delta[2] = { 1,1 }; // вектор перемещений

        int gamma = 5; //корректирующий коэффициент для вектора перемещений

        double eps = 0.001; //точность вычислений

        double x0[2]; //начальные значения аргументов(текущие)

        double x1[2]; //смещённая точка

        double nx0[2]; //новые координаты вместо текущих(для первой точки)

        double nx1[2]; //новые координаты второй точки

        double x_min[2], f_min; //точка минимума и сам минимум

        int i = 0; //номер итерации

        std::cout << "f(x1,x2) = x1^2 + 4x2^2 + 1; e = 0.001" << std::endl << std::endl;

        std::cout << "METOD HUKA-DJIVSA" << std::endl << std::endl;

        std::cout << "Enter the start point: ";

        std::cin >> x0[0] >> x0[1];

        std::cout << "N" << std::setw(15) << "x1" << std::setw(15) << "x2" << std::setw(15) << "f(x1,x2)" << std::setw(15) << "e" << std::endl;

        std::cout << i++ << setw(15) << x0[0] << setw(15) << x0[1] << setw(15) << f(x0[0], x0[1]) << setw(15) <<

            sqrt(delta[0] * delta[0] + delta[1] * delta[1]) << endl;

        do {

            if (sqrt(delta[0] * delta[0] + delta[1] * delta[1]) < eps)

            {

                x_min[0] = x0[0];

                x_min[1] = x0[1];

                f_min = f(x_min[0], x_min[1]);

                std::cout << std::endl << "x_min: ( " << x_min[0] << ", " << x_min[1] << ")" << std::endl;

                std::cout << "F_min: " << f_min << std::endl;

                break;

            }

            issl_search(x0[0], x0[1], nx0[0], nx0[1], delta[0], delta[1]);

            if (nx0[0] == x0[0] && nx0[1] == x0[1])

            {

                delta[0] = delta[0] / gamma;

                delta[1] = delta[1] / gamma;

                std::cout << i++ << setw(15) << x0[0] << setw(15) << x0[1] << setw(15) << f(x0[0], x0[1]) << setw(15) <<

                    sqrt(delta[0] * delta[0] + delta[1] * delta[1]) << std::endl;

                continue;

            }

        Sdvig:

            x1[0] = 2 * nx0[0] - x0[0];

            x1[1] = 2 * nx0[1] - x0[1];

            std::cout << i++ << setw(15) << x1[0] << setw(15) << x1[1] << setw(15) << f(x1[0], x1[1]) << setw(15) <<

                sqrt(delta[0] * delta[0] + delta[1] * delta[1]) << endl;

        Issl2:

            if (sqrt(delta[0] * delta[0] + delta[1] * delta[1]) < eps)

            {

                x_min[0] = x1[0];

                x_min[1] = x1[1];

                f_min = f(x_min[0], x_min[1]);

                std::cout << endl << "x_min: ( " << x_min[0] << ", " << x_min[1] << ")" << endl;

                std::cout << "F_min: " << f_min << endl;

                break;

            }

            issl_search(x1[0], x1[1], nx1[0], nx1[1], delta[0], delta[1]);

            if (nx1[0] == x1[0] && nx1[1] == x1[1])

            {

                delta[0] = delta[0] / gamma;

                delta[1] = delta[1] / gamma;

                std::cout << i++ << setw(15) << x1[0] << setw(15) << x1[1] << setw(15) << f(x1[0], x1[1]) << setw(15) <<

                    sqrt(delta[0] * delta[0] + delta[1] * delta[1]) << std::endl;

                goto Issl2;

            }

            double fnx0, fnx1;

            fnx0 = f(nx0[0], nx0[1]);

            fnx1 = f(nx1[0], nx1[1]);

            if (fnx1 < fnx0)

            {

                x0[0] = nx0[0];

                x0[1] = nx0[1];

                nx0[0] = nx1[0];

                nx0[1] = nx1[1];

                std::cout << i++ << setw(15) << x0[0] << setw(15) << x0[1] << setw(15) << f(x0[0], x0[1]) << setw(15) <<

                    sqrt(delta[0] * delta[0] + delta[1] * delta[1]) << std::endl;

                goto Sdvig;

            }
            else {

                x0[0] = nx1[0];

                x0[1] = nx1[1];

                cout << i++ << setw(15) << x0[0] << setw(15) << x0[1] << setw(15) << f(x0[0], x0[1]) << setw(15) <<

                    sqrt(delta[0] * delta[0] + delta[1] * delta[1]) << endl;

                continue;

            }

        } while (true);

    }
};

// о башни
class alg::TowerOfHanoi
{
private:
    int max(int a)            /*возвращает максимальный показатель степени числа 2*/
    {                         /*который показывает уровень надстройки*/
        int p = 1, temp, p1;
        while (pow(2, p) <= a)
        {
            temp = pow(2, p);
            if (a % temp == 0 && temp <= a)
                p1 = p;
            p++;
        }
        return p1;
    }

    int step(int a)  /*возвращает номер позиции для четных номеров*/
    {
        return a / pow(2, max(a));
    }

    int count_step_define(int a, bool rev_along)/*возвращает номер колышка с которого будет очередной шаг*/
    {
        if (rev_along)
        {
            int temp = ((step(a) - 1) / 2) % 3;
            if (max(a) % 2 == 0)
                return 1 + temp;
            else
            {
                if (1 - temp == 0)
                    return 3;
                else
                    return 1 - temp > 0 ? 1 - temp : 2;
            }
        }
        else
            return 1 + ((a - 1) / 2) % 3;
    }

public:
    void start()
    {
        unsigned long long n, loop, a = 1;
        std::cin >> n;   /*количество дисков*/
        loop = pow(2, n) - 1;   /*количество требуемых перемещений*/
        while (a <= loop)
        {
            int temp, over;
            if (a % 2 == 1)
            {
                temp = count_step_define(a, 0);
                (temp + 1 > 3) ? over = 1 : over = temp + 1;
            }
            else
            {
                temp = count_step_define(a, 1);
                if (max(a) % 2 == 0)
                    (temp + 1 > 3) ? over = 1 : over = temp + 1;
                else
                    (temp - 1 < 1) ? over = 3 : over = temp - 1;
            }
            std::cout << temp << " - >" << over << std::endl;/*с какого и на какой колышек переместить*/
            a++;
        }
        system("pause");
    }
};