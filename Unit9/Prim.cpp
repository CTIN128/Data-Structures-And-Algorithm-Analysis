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
			if (Graph[tmpcell.Number][i] != INT_MAX && !Known[i]&& Graph[tmpcell.Number][i] < vec[i].Close_Dist)
			{
					vec[i].Close_Dist = Graph[tmpcell.Number][i];
					vec[i].Path = tmpcell.Number;
					pq.push(Vertex(i, Graph[tmpcell.Number][i]));
			} 
		}
	}
	/*
	按照算法导论所说，先把所有节点压入pq中，源点的dist设置为0，此时的dist与Dijkstra的dist不一样，
	此时是该点到最近点的距离，而dijkstra是到源点的距离，增加了是否访问过的判断，
  因为我们每次都选取最短的距离，所以我们只要pq中弹出的这个点，那就是已经确定好的前驱点是谁了，
	不用再管其他的
	*/
	for (int i = 0; i < 7; ++i)
	{
		std::cout << "Vertex: " << i << std::endl;
		std::cout << "Dis: " << vec[i].Close_Dist << std::endl;
		std::cout << "Path: " << vec[i].Path << std::endl << std::endl;
	}
	return 0;
}