/*                                                   */
/*ԭ�����ǰ����������ÿ�ν����Ľ������Ժ���ȥ��ÿ�ε�����涼���*/

#include <iostream>

int main()
{
	using namespace std;
	int ar[10] = {1,8,9,7,6,1,7,2,5,4};
    for(int i = 0; i < 10; i++)
    {
	  for (int j = 0; j < 9 - i; ++j)
	  {
		if (ar[j] > ar[j + 1])
		{
			int temp = ar[j];
			ar[j] = ar[j + 1];
			ar[j + 1] = temp;
		}
	  }
    }
	for (int i = 0; i < 10; ++i)
	{
		cout << ar[i] << endl;
	}
	return 0;
}