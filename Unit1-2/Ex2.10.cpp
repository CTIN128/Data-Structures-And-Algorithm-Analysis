/*
*horner�㷨
*���� A[1]*X^1+A[2]*X^2+......A[N]*X^N
*ʱ�临�Ӷ�ΪO(n)
*/


#include <iostream>
int main()
{
	using namespace std;
	int hor = 0;
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int X = 1;                     
	for (int i = 9; i  >= 0 ; --i)//˳���ܸ㷴����ǰ��Ĵ����߼������������
	{                              //A[N]*X^N+....A[2]*X^2+A[1]*X^1
		hor = hor * X + A[i];
	}
	cout << hor << endl;
}
