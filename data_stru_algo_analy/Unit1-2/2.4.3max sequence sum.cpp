//#include <iostream>
//
//using namespace std;
//
//int max_judge(const int a,const int b,const int c)
//{
//	int max = a > b ? a : b;
//	max = max > c ? max : c;
//	return max;
//    /*
//      if(a >= b && a >=c)
//      {
//         return a;
//       }
//       return max_judge(b, c, a);
//    */
//}
//
//int judge(const int sell_phe[],const int left,const int right)
//{
//
//	if (left == right)
//	{
//		if (sell_phe[left] >= 0)
//			return sell_phe[left];
//		else
//			return 0;
//	}
//	int MaxLeft, MaxRight;
//	int MaxRightBoardSum, RightBoardSum;
//	int MaxLeftBoardSum, LeftBoardSum;
//	int center;
//	center = (left + right) / 2;
//	MaxLeft = judge(sell_phe, left, center);
//	MaxRight = judge(sell_phe, center+1, right);
//
//	MaxLeftBoardSum = 0, LeftBoardSum = 0;
//	for (int i = center; i >= left; --i)//���ļ�˳��ǳ���Ҫ
//	{
//		LeftBoardSum += sell_phe[i];
//		if (LeftBoardSum > MaxLeftBoardSum)
//		{
//			MaxLeftBoardSum = LeftBoardSum;
//		}
//	}
//
//	MaxRightBoardSum = 0, RightBoardSum = 0;
//	for (int i = center+1; i <= right; ++i)//���ļ�˳��ǳ���Ҫ
//	{
//		RightBoardSum += sell_phe[i];
//		if (RightBoardSum > MaxRightBoardSum)
//		{
//			MaxRightBoardSum = RightBoardSum;
//		}
//	}
//	return (MaxLeft, MaxRight, MaxLeftBoardSum + MaxRightBoardSum);
//
//}
//
//
//
//int main()
//{
//	int sell_phe[4] = {-2,4,-3,5};
//	int maxsum,shou_buy = 0,shou_sell = 0;//maxsumҲ����Ϊ�㣬Ҫ�Ǽ������ݶ�Ϊ�����ͳ���
//   /*maxsum = sell_phe[0];
//	for (int i = 1; i < 4; ++i)
//	{
//		if (sell_phe[i] > maxsum)
//		{
//			maxsum = sell_phe[i];
//		}
//	}
//   */
//	/*for (int i = 0; i < 10; ++i)//�ڼ��������
//	{
//		for (int j = i; j < 10; ++j)//�ڼ�������
//		{
//			int thissum = 0;
//			for (int k = i; k <= j; ++k)
//			{
//				thissum += sell_phe[k];
//			}
//			else if (thissum > maxsum)
//			{
//				maxsum = thissum;
//				shou_buy = i;
//				shou_sell = j;
//			}
//		}
//	}
//	*/
//	/*algo1: ʱ�临�Ӷ�Ϊ����Ƕ��ѭ����ʱ��O(n*n*n)����ȡ*/
//	
//	/*
//	for (int i = 0; i < 10; ++i)
//	{
//		int thissum = 0;
//		for (int j = i; j < 10; ++j)
//		{
//			thissum += sell_phe[j];
//			if (thissum > maxsum)
//			{
//				maxsum = thissum;
//				shou_buy = i;
//				shou_sell = j;
//			}
//		}
//		
//	}
//	*/
//	/*
//	*algo2: ʱ�临�Ӷ�Ϊ����Ƕ��ѭ����ʱ��O(n*n)����ȡ�����һ�ֲ�һ�����ǵ�һ��
//	*����kΪָ��������i �� j֮���õ���ӣ����ڶ�������ֱ���ж�i ֮���ʲôʱ�����
//	*��ֵ��֮ǰ��maxsum�Ƚϣ����߸о�������
//	*/
//	cout << judge(sell_phe, 0, 4);
//		/*
//		*algo3: ʱ�临�Ӷ�ΪO(nlgn)��1��2�ⷨ��
//		*�����ƺ�����˵��ʲôʱ����,ʲôʱ����
//		*/
//
//	//int thissum = 0;
//	//for (int i = 0; i < 4; ++i)
//	//{
//	//	thissum += sell_phe[i];
//	//	if (thissum > maxsum)
//	//	{
//	//		maxsum = thissum;
//	//		shou_sell = i;
//	//	}
//	//	if (thissum < 0)
//	//	{
//	//		shou_buy = i+1;
//	//		thissum = 0;
//	//	}
//	//}
//	/*
//	*algo4: ʱ�临�Ӷ�Ϊһ��Ƕ��ѭ����ʱ��O(n)���Ž�
//	*����˵��ʲôʱ����ʲôʱ����
//	*/
///*	cout << "you should buy in " << shou_buy+1 << "th and sell in " << shou_sell+1
//		<< "th" << endl <<"then you will get " << maxsum << endl;*/
//}