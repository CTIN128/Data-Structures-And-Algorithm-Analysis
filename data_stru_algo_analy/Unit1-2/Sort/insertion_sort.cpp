/*                                                   */	
/*原理就是后面的数保留前面的数，前面的数就作为插入点*/

//#include <iostream>
//
//int main()
//{
//	using namespace std;
//	int ar[10] = {1,8,9,7,6,1,7,2,5,4};
//	for (int j = 1; j < 10; ++j)
//	{
//		int key = ar[j];
//		int i = j - 1;
//		while (i >= 0 && ar[i] > key) {
//			ar[i + 1] = ar[i];
//			--i;
//		}
//		ar[i + 1] = key;
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << ar[i] << endl;
//	}
//	return 0;
//}