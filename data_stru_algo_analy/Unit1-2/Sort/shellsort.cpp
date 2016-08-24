//#include <iostream>
//
//void ShellSort(int arr[], int length)
//{
//	int i, j, middle = length, temp;
//	for (middle >>= 1; middle > 0; middle >>= 1)
//	{
//		for (i = middle; i < length; ++i)
//		{
//			temp = arr[i];
//			for (j = i; j >= middle; j -= middle)
//			{
//				if (temp < arr[j - middle])
//				{
//					arr[j] = arr[j - middle];
//				}
//				else
//					break;
//			}
//			arr[j] = temp;
//		}
//
//	}
//}
//int main()
//{
//	int data[6] = { 1,8,7,9,1,4 };
//	ShellSort(data, 6);
//	for (auto x : data)
//	{
//		std::cout << x << std::endl;
//	}
//}