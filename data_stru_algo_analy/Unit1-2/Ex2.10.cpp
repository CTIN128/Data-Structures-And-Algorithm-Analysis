/*
*horner算法
*计算 A[1]*X^1+A[2]*X^2+......A[N]*X^N
*时间复杂度为O(n)
*/


#include <iostream>
int main()
{
	using namespace std;
	int hor = 0;
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int X = 1;                     
	for (int i = 9; i  >= 0 ; --i)//顺序不能搞反，在前面的次数高计算出来反而是
	{                              //A[N]*X^N+....A[2]*X^2+A[1]*X^1
		hor = hor * X + A[i];
	}
	cout << hor << endl;
}
