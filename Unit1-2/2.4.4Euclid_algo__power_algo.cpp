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
/*��������㷨ԭ��������������ȡ�֮࣬�󱻳�����ɳ������������������֪����������㽫��������һ��
 *�����ı���������
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
		return X;//����X��û��*X
	if (iseven(n))
	{
		return pow1(X * X, n / 2);
	}
	else
	{
		return pow1(X * X, n / 2) * X;
	}
}
         x^n/2 * x^n/2     iseven   ԭ�����ָ����һ��2��չ
   X^N = 
         x^n/2 * x^n/2 * x isodd    ʱ��O��logn��
   */

int pow2(int x, int n)
{
	return pow2(x, n - 1) * x;
}

/*����ʱ�䶼��O��logn��*/
int main()
{
	cout << GCD(50, 15) << endl;
	cout << pow2(2, 3) << endl;
	return 0;
}