#include <iostream>
const int data_size = 5;


bool iseven(int n)//odd
{
	return n % 2 == 0;
}
int main()
{
	using namespace std;
	int sell_phe[data_size]{ 3, 0, -5, -1, -2 };//正positive 负negative   mul乘积
	int min_pos_sum, minsum, sum = 0, mul = 1,maxmul;
	/*(b)
	for (int i = 0; i < data_size; ++i)
	{
		if (sell_phe[i] > 0)
		{
			min_pos_sum = sell_phe[i];
			break;
		}
	}
	for (int j = 0; j < data_size; ++j)
	{
		sum += sell_phe[j];
		if (sum > 0 && sum < min_pos_sum)
		{
			min_pos_sum = sum;
		}
		if(sum < 0)
			sum = 0;
		
	}*/
	//(a)
	/*
	minsum = sell_phe[0];
	for (int i = 1; i < data_size; ++i)
	{
		if (sell_phe[i] < minsum)
		{
			minsum = sell_phe[i];
		}
	}

	for (int j = 0; j < data_size; ++j)
	{
		sum += sell_phe[j];
		if (sum < minsum)
		{
			minsum = sum;
		}
		if (sum > 0)
			sum = 0;

	}
	*///每次检测并不是最小值为0，每次不能让minsum都为零，要去判定
	maxmul = sell_phe[0];

	for (int i = 0; i < data_size; ++i)
	{
		if (sell_phe[i] > maxmul)
		{
			maxmul = sell_phe[i];
		}
	}
	for (int i = 0; i < data_size; ++i)
	{
		mul *= sell_phe[i];
		if (mul == 0)
		{
			mul = 1;
		} 
		if (mul > maxmul)
		{
			maxmul = mul;
		}
	}
	
	cout << maxmul << endl;
}