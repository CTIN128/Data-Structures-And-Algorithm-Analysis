#include <iostream>

const int data_size = 10;

const int which_turn = 2;

int main()//find which_turn max
{
	int data[data_size][2];
	int i;
	for (i = 0; i < data_size; ++i)
	{
		std::cin >> data[i][0];
	}
	for (i = 0; i < data_size; ++i)
	{
		data[i][1] = 1;
	}
	int data_judge[which_turn];
	int min_of_judge = -1;
	for (int t = 0; t < data_size; ++t)
	{
		int q = 0;
		for (int i = 0; i < which_turn; ++q)
		{
			if (data[q][0] == min_of_judge)
			{
				data[q][1] = 0;
				continue;
			}
			else if(data[q][1] != 0){
				data_judge[i] = data[q][0];
				++i;
			}
		}
		min_of_judge = data_judge[0];
		for (int j = 0; j < which_turn; ++j)
		{
			if (data_judge[j] < min_of_judge)
			{
				min_of_judge = data_judge[j];
			}
		}
		int judge = 0;
		for (int i = q; i < data_size; ++i)
		{
			if (q == data_size)
				break;
			if (data[i][0] > min_of_judge) { judge = 1; }
		}
		if (judge == 0)
		{
			break;
		}
	}
	std::cout << "The answer is : " << min_of_judge << std::endl;
	

}