//#include <iostream>/*外带一个递归原理基本相同的二叉搜索法*/
//
//using namespace std;
//
//void Qsort(int a[], int low, int high)
//{
//	if (low > high)
//	{
//		return;
//	}
//	int first_index = low, last_index = high, key = a[first_index];
//	while (first_index <last_index)//为了所有数据都能判断到
//	{
//		while (a[last_index] >= key)//如果末位置的数据小于键值
//		{
//			last_index--;
//		}
//		a[first_index] = a[last_index];
//		while (first_index < last_index && a[first_index] <= key)//最终first_last和last_index会相等,
//		{                                                        //注意a[first_index] <= key的等号，没有那么等的时候就不满足就会把它交换到小的那一边
//			first_index++;
//		}
//		a[last_index] = a[first_index];//最终这两个值就是一样的
//	}
//	a[first_index] = key;//此时first_index所指向的位置就是键值要插入的位置
//	Qsort(a, first_index + 1, high);//键值的位置就不需要重新再排列了，因为他左边就是比他小的元素，右边就是比他大的元素
//	Qsort(a, low, first_index - 1);//所以只要左右边进行排列就可以了
//}
//
//int binary_search(int a[], int b, int sta, int end)
//{
//
//	int mid = (sta + end) / 2;
//	//cout << a[mid] << endl;
//	if (b == a[mid])
//	{
//		return mid;
//	}
//	else if (b < a[mid])
//		binary_search(a, b, sta, mid - 1);
//	else
//		binary_search(a, b, mid + 1, end);
//}
//
//int main()
//{
//	int a[] = { 57, 68, 59, 72, 72, 28, 96, 33, 24 };
//	int b[sizeof(a) / sizeof(a[0])];
//	Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << binary_search(a,59,0, sizeof(a) / sizeof(a[0]) - 1) << endl;
//	return 0;
//}