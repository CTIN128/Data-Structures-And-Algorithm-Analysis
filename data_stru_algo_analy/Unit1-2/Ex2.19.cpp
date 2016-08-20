//#include <iostream>
//
//
//const int data_size = 10;
//
//
//void Qsort(int data_array[], int sta_index, int end_index)
//{
//	if (sta_index >= end_index)
//	{
//		return;
//	}
//	int first = sta_index, last = end_index, key = data_array[first];
//	while (first < last)
//	{
//		while (first < last && data_array[last] >= key)//
//		{
//			last--;
//		}
//		data_array[first] = data_array[last];
//		while (first < last && data_array[first] <= key)
//		{
//			first++;
//		}
//		data_array[last] = data_array[first];
//	}
//	data_array[first] = key;
//	Qsort(data_array, sta_index, first - 1);
//	Qsort(data_array, first + 1, end_index);
//}
//int main()
//{
//	using namespace std;
//	int data_array[data_size] = {2,4,3,8,3,3,3,3,2,5};
//	Qsort(data_array, 0, data_size - 1);
//
//	int judge_num = data_array[0],num_count = 0;
//	for (int i = 0; i < data_size-1; ++i)
//	{
//		if (data_array[i] == judge_num)
//		{
//			num_count++;
//		}
//		else {
//			num_count = 0;
//			judge_num = data_array[i];
//			num_count++;
//		}
//
//		if (num_count >= data_size / 2)
//		{
//			cout << data_array[i] << endl;
//			break;
//		}
//	}
//}