//#include <iostream>/*���һ���ݹ�ԭ�������ͬ�Ķ���������*/
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
//	while (first_index <last_index)//Ϊ���������ݶ����жϵ�
//	{
//		while (a[last_index] >= key)//���ĩλ�õ�����С�ڼ�ֵ
//		{
//			last_index--;
//		}
//		a[first_index] = a[last_index];
//		while (first_index < last_index && a[first_index] <= key)//����first_last��last_index�����,
//		{                                                        //ע��a[first_index] <= key�ĵȺţ�û����ô�ȵ�ʱ��Ͳ�����ͻ����������С����һ��
//			first_index++;
//		}
//		a[last_index] = a[first_index];//����������ֵ����һ����
//	}
//	a[first_index] = key;//��ʱfirst_index��ָ���λ�þ��Ǽ�ֵҪ�����λ��
//	Qsort(a, first_index + 1, high);//��ֵ��λ�þͲ���Ҫ�����������ˣ���Ϊ����߾��Ǳ���С��Ԫ�أ��ұ߾��Ǳ������Ԫ��
//	Qsort(a, low, first_index - 1);//����ֻҪ���ұ߽������оͿ�����
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