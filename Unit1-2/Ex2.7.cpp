/*随机生成data_size个数字，保留在数组中*/


#include <iostream>
#include <time.h>

using namespace std;

const int data_size = 5;

int random()
{
	srand(time(0));
	return (1 + rand() % data_size);
}

bool judge(int temp[], int j,int data)
{
	while (j)
	{
		if (data == temp[j-1])
			return false;
		else
		{
			j--;
		}
	}
	return true;
}
void swap(int & temp1, int & temp2)
{
	int temp = temp1;
	temp1 = temp2;
	temp2 = temp;
}
int main()
{
	
	int data_array[data_size];
	int judge_array[data_size]{};
	
	/*
	algorithm1: 7.93s
	*/
	
	for (int i = 0; i < data_size; i++)
	{
		int current_data = random();
		//cout << current_data << endl;
		int index = i;
		while(!judge(data_array,index,current_data))  //O(n^2)
		{
		   current_data = random();
		}//如果存在重复的数，再随机一个数
		data_array[i] = current_data;
	}

	/*
	algorithm2: 9.568s
	*/

	/*for (int i = 0; i < data_size; ++i)
	{
		int current_data = random();
		while (judge_array[current_data - 1] == 1)//O(n)
		{
			current_data = random();
		}
		data_array[i] = current_data;
		judge_array[current_data - 1] = 1;
	}*/

	/*
	algorithm3: 0s
	*/

	/*for (int i = 0; i < data_size; i++)O(n)
	{
		data_array[i] = i + 1;
	}
	for (int i = 0; i < data_size; i++)
	{
		swap(data_array[i], data_array[random()-1]);
	}*/
	

	for (int i = 0; i < data_size; ++i)
	{
		cout << data_array[i] << endl;
	}

}
