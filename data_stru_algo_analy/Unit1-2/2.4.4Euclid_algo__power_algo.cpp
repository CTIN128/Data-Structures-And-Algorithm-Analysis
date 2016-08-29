#include <iostream>

using namespace std;

int GCD(unsigned int M, unsigned int N)
{
	unsigned int Rem;
	while (N != 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}
/*阿基里德算法原理是两个数互相取余，之后被除数变成除数，除数变成余数，知道余数变成零将保留了上一次
 *余数的被除数返回
 */
bool iseven(int n)
{
	return n % 2 == 0;
}

int pow1(int X, unsigned int n)
{
	if (n == 0)
		return 1;
    else if (n == 1)
		return X;//返回X并没有*X
	if (iseven(n))
	{
		return pow1(X * X, n / 2);
	}
	else
	{
		return pow1(X * X, n / 2) * X;
	}
}
         x^n/2 * x^n/2     iseven   原理就是指数除一个2扩展
   X^N = 
         x^n/2 * x^n/2 * x isodd    时间O（logn）
   */

int pow2(int x, int n)
{
	return pow2(x, n - 1) * x;
}

/*两者时间都是O（logn）*/
int main()
{
	cout << GCD(50, 15) << endl;
	cout << pow2(2, 3) << endl;
	return 0;
}