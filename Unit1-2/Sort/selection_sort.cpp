/*                                                   */
/*原理就是寻找指定数的后面的数中的最小值然后与指定的数交换*/

#include <iostream>

int main()
{
	using namespace std;
	int ar[10] = {1,8,9,7,6,1,7,2,5,4};
	for(int i = 0;i < 9;++i)
    {
      int min_index = i;
      for (int j = i; j < 10; ++j)
      {
	   if (ar[j] < ar[min_index])
	   {
		   min_index = j;
	   }
      }
      int temp = ar[i];
      ar[i] = ar[min_index];
      ar[min_index] = temp;
    }
	for (int i = 0; i < 10; ++i)
	{
		cout << ar[i] << endl;
	}
	return 0;
}