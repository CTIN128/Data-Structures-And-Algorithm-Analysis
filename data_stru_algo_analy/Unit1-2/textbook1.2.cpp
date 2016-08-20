///*编写一个猜字谜游戏*/
///*暴力方法*/
//#include <iostream>
//#include <string>
//using namespace std;
//
//bool judge(const string str[], string & s)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if (s == str[i])
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	char let_puz[4][4];
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			cin >> let_puz[i][j];
//		}
//	}
//	string dict[4] = { "this",
//		               "two",
//		               "fat",
//		               "that" };
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			for (int dire = 0; dire < 8; ++dire)
//			{
//				if (dire == 0)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (x-- && y--)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//				else if (dire == 1)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (x--)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//				else if (dire == 2)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (--x && ++y && y<4)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//				else if (dire == 3)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (++y && y<4)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//				else if (dire == 4)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (++x && ++y && x<4 && y<4)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//				else if (dire == 5)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (++x && x<4)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//				else if (dire == 6)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (++x && y--)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//				else if (dire == 7)
//				{
//					string letter;
//					letter += let_puz[i][j];
//					int x = i, y = j;
//					while (y--)
//					{
//						letter += let_puz[x][y];
//						if (judge(dict, letter))
//						{
//							cout << letter << " is from" << "(" << i << "," << j << ") to "
//								<< "(" << x << "," << y << ")" << endl;
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
