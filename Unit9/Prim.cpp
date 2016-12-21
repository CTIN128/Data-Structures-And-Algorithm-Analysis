/*
  Prim思想：
  先确定一个源点，设为已知点，作为集合A，则剩下的未知点即为集合B，从源点出发，
  将与之相邻并且未知的点压入最小堆（以权值大小排序）中，然后从堆中弹出权值最小的点m，此时A中
  加入该点m，B中删除该点m。同理接着就把与该点相邻并且未知的点压入最小堆中，弹出权值最小的点n，
  此时A中加入该点n，B中删除n。一直这样后，直到所有点都被访问
*/
#include <queue>
#include <iostream>
#include <vector>
#include <limits>
struct Vertex
{
	Vertex() {}
	Vertex(int _Number, int _Dist):Number(_Number), Close_Dist(_Dist) {}
	bool Known = false;
	int Number;
	int Close_Dist = INT_MAX;
	int Path;
};
bool operator<(Vertex p1, Vertex p2)
{
	return p1.Close_Dist > p2.Close_Dist;
}
int main()
{
	int SourceVetex = 4;
	std::vector<Vertex> vec(7);
	vec[SourceVetex].Close_Dist = 0;
	vec[SourceVetex].Path = SourceVetex;
	std::priority_queue<Vertex> pq;
	std::vector<bool> Known(7,false);
	//int Graph[][7] =
	//{
	//	0,2,4,1,INT_MAX,INT_MAX,INT_MAX,
	//	2,0,INT_MAX,3,10,INT_MAX,INT_MAX,
	//	4,INT_MAX,0,2,INT_MAX,5,INT_MAX,
	//	1,3,2,0,7,8,4,
	//	INT_MAX,10,INT_MAX,7,0,INT_MAX,6,
	//	INT_MAX,INT_MAX,5,8,INT_MAX,0,1,
	//	INT_MAX,INT_MAX,INT_MAX,4,6,1,0
	//};
	int Graph[][7] =
	{
		0,8,INT_MAX,INT_MAX,6,INT_MAX,INT_MAX,
		8,0,4,7,INT_MAX,INT_MAX,INT_MAX,
		INT_MAX,4,0,INT_MAX,INT_MAX,2,INT_MAX,
		INT_MAX,7,INT_MAX,0,8,1,INT_MAX,
		6,INT_MAX,INT_MAX,8,0,INT_MAX,7,
		INT_MAX,INT_MAX,2,1,INT_MAX,0,5,
		INT_MAX,INT_MAX,INT_MAX,INT_MAX,7,5,0
	};
	pq.push(Vertex(SourceVetex, 0));
	int IsKnown = 0;
	while (!pq.empty()&&IsKnown != 7)
	{
		Vertex tmpcell = pq.top();
		pq.pop();
		Known[tmpcell.Number] = true;
		++IsKnown;//判断是否都已访问过
		for (int i = 0; i < 7; ++i)
		{
			if (Graph[tmpcell.Number][i] != INT_MAX&&Graph[tmpcell.Number][i] != 0 && !Known[i])
			{
				pq.push(Vertex(i, Graph[tmpcell.Number][i]));
				if (Graph[tmpcell.Number][i] < vec[i].Close_Dist)//如果tmpcell.number点到i的值比原来close_dist的小，则更新。
				{                                                //此时close_dist不是该点到源点距离而是该点到离他最近点的距离
					vec[i].Close_Dist = Graph[tmpcell.Number][i];
					vec[i].Path = tmpcell.Number;
				}
			}
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		std::cout << "Vertex: " << i << std::endl;
		std::cout << "Dis: " << vec[i].Close_Dist << std::endl;
		std::cout << "Path: " << vec[i].Path << std::endl << std::endl;
	}
	return 0;
}