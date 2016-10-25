#include <queue>
#include <iostream>
#include <vector>
#include <limits>
struct Info
{
	int Dis = INT_MAX;
	int Path;
};
struct Vertex
{
	Vertex(int _Number, int _Dist):Number(_Number), Dist(_Dist) {}
	int Number;
	int Dist;
};
bool operator<(Vertex p1, Vertex p2)
{
	return p1.Dist < p2.Dist;
}
void PrintPath(int SourceVertex,int vertex, std::vector<Info> v)
{
	if (vertex == SourceVertex)
	{
		std::cout << vertex << std::endl;
		return;
	}
	std::cout << vertex << std::endl;
	PrintPath(SourceVertex, v[vertex].Path, v);
}
int main()
{
	int SourceVetex = 0;
	std::vector<Info> vec(7);
	vec[SourceVetex].Dis = 0;
	vec[SourceVetex].Path = 0;
	std::priority_queue<Vertex> pq;
	int Graph[][7] =
	{
	   0,2,0,1,0,0,0,
	   0,0,0,3,10,0,0,
	   4,0,0,0,0,5,0,
	   0,0,2,0,2,8,4,
	   0,0,0,0,0,0,6,
	   0,0,0,0,0,0,0,
	   0,0,0,0,0,1,0
	};
	pq.push(Vertex(SourceVetex,0));
	while (!pq.empty())
	{
		Vertex tmpcell = pq.top();
		pq.pop();
		for (int i = 0; i < 7; ++i)
		{
			if (Graph[tmpcell.Number][i] != 0)
			{
				if (vec[tmpcell.Number].Dis + Graph[tmpcell.Number][i] < vec[i].Dis)
				{
					vec[i].Dis = vec[tmpcell.Number].Dis + Graph[tmpcell.Number][i];
					vec[i].Path = tmpcell.Number;
					pq.push(Vertex(i, vec[i].Dis));
				}
			}
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		std::cout <<"Vertex: "<< i << std::endl;
		std::cout << "Dis: " << vec[i].Dis << std::endl;
		std::cout << "Path: " << std::endl;
		PrintPath(SourceVetex, i, vec);
	}
	return 0;
}