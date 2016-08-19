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
//	for (int i = center; i >= left; --i)//从哪加顺序非常重要
//	{
//		LeftBoardSum += sell_phe[i];
//		if (LeftBoardSum > MaxLeftBoardSum)
//		{
//			MaxLeftBoardSum = LeftBoardSum;
//		}
//	}
//
//	MaxRightBoardSum = 0, RightBoardSum = 0;
//	for (int i = center+1; i <= right; ++i)//从哪加顺序非常重要
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
//	int maxsum,shou_buy = 0,shou_sell = 0;//maxsum也不能为零，要是检测的数据都为负数就出错
//   /*maxsum = sell_phe[0];
//	for (int i = 1; i < 4; ++i)
//	{
//		if (sell_phe[i] > maxsum)
//		{
//			maxsum = sell_phe[i];
//		}
//	}
//   */
//	/*for (int i = 0; i < 10; ++i)//第几天买入的
//	{
//		for (int j = i; j < 10; ++j)//第几天卖出
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
//	/*algo1: 时间复杂度为三重嵌套循环的时间O(n*n*n)不可取*/
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
//	*algo2: 时间复杂度为两重嵌套循环的时间O(n*n)不可取，与第一种不一样的是第一种
//	*是以k为指标来进行i 与 j之内置的相加，而第二种则是直接判断i 之后和什么时候最大
//	*则将值与之前的maxsum比较，两者感觉半斤八两
//	*/
//	cout << judge(sell_phe, 0, 4);
//		/*
//		*algo3: 时间复杂度为O(nlgn)比1，2解法好
//		*但是似乎不能说明什么时候买,什么时候卖
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
//	*algo4: 时间复杂度为一重嵌套循环的时间O(n)最优解
//	*又能说明什么时候买，什么时候卖
//	*/
///*	cout << "you should buy in " << shou_buy+1 << "th and sell in " << shou_sell+1
//		<< "th" << endl <<"then you will get " << maxsum << endl;*/
//}