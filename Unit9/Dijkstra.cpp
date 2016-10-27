//#include <queue>
//#include <iostream>
//#include <vector>
//#include <limits>
//
//struct Vertex
//{
//	Vertex(){}
//	Vertex(int _Number, int _Dist):Number(_Number), Dist(_Dist) {}
//	int Number;
//	int Dist = INT_MAX;
//	int Path;
//};
//bool operator<(Vertex p1, Vertex p2)
//{
//	return p1.Dist > p2.Dist;
//}
//void PrintPath(int SourceVertex,int vertex, std::vector<Vertex> v)
//{
//	if (vertex == SourceVertex)
//	{
//		std::cout << vertex << std::endl;
//		return;
//	}
//	std::cout << vertex << std::endl;
//	PrintPath(SourceVertex, v[vertex].Path, v);
//}
//int main()
//{
//	int SourceVetex = 0;
//	std::vector<Vertex> vec(7);
//	vec[SourceVetex].Dist = 0;
//	vec[SourceVetex].Path = 0;
//	std::priority_queue<Vertex> pq;
//	int Graph[][7] =
//	{
//	   0,2,0,1,0,0,0,
//	   0,0,0,3,10,0,0,
//	   4,0,0,0,0,5,0,
//	   0,0,2,0,2,8,4,
//	   0,0,0,0,0,0,6,
//	   0,0,0,0,0,0,0,
//	   0,0,0,0,0,1,0
//	};
//	pq.push(Vertex(SourceVetex,0));
//	while (!pq.empty())
//	{
//		Vertex tmpcell = pq.top();
//		pq.pop();
//		for (int i = 0; i < 7; ++i)
//		{
//			if (Graph[tmpcell.Number][i] != 0)
//			{
//				if (vec[tmpcell.Number].Dist + Graph[tmpcell.Number][i] < vec[i].Dist)
//				{
//					vec[i].Dist = vec[tmpcell.Number].Dist + Graph[tmpcell.Number][i];
//					vec[i].Path = tmpcell.Number;
//					pq.push(Vertex(i, vec[i].Dist));
//				}
//			}
//		}
//	}
//	for (int i = 0; i < 7; ++i)
//	{
//		std::cout <<"Vertex: "<< i << std::endl;
//		std::cout << "Dis: " << vec[i].Dist << std::endl;
//		std::cout << "Path: " << std::endl;
//		PrintPath(SourceVetex, i, vec);
//	}
//	return 0;
//}