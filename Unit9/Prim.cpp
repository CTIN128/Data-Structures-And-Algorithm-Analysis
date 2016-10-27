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
void PrintPath(int SourceVertex, int vertex, std::vector<Vertex> v)
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
	std::vector<Vertex> vec(7);
	vec[SourceVetex].Close_Dist = 0;
	vec[SourceVetex].Path = 0;
	std::priority_queue<Vertex> pq;
	std::vector<int> lowcost(7, INT_MAX);
	int Graph[][7] =
	{
		0,2,4,1,INT_MAX,INT_MAX,INT_MAX,
		2,0,INT_MAX,3,10,INT_MAX,INT_MAX,
		4,INT_MAX,0,2,INT_MAX,5,INT_MAX,
		1,3,2,0,7,8,4,
		INT_MAX,10,INT_MAX,7,0,INT_MAX,6,
		INT_MAX,INT_MAX,5,8,INT_MAX,0,1,
		INT_MAX,INT_MAX,INT_MAX,4,6,1,0
	};
	pq.push(Vertex(SourceVetex, 0));
	while (!pq.empty())
	{
		Vertex tmpcell = pq.top();
		pq.pop();
		vec[tmpcell.Number].Known = true;
		for (int i = 0; i < 7; ++i)
		{
			if (i != tmpcell.Number&&!vec[i].Known&&Graph[tmpcell.Number][i] < lowcost[i])
			{
				lowcost[i] = Graph[tmpcell.Number][i];
				vec[i].Path = tmpcell.Number;
				vec[i].Close_Dist = Graph[tmpcell.Number][i];
				pq.push(Vertex(i, vec[i].Close_Dist));
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