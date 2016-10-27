#include <queue>
#include <vector>
#include <iostream>
#include <limits>

struct VertexInfo
{
	VertexInfo() {}
	VertexInfo(int _Number, int _Dist):Number(_Number), Close_Dist(_Dist) {}
	bool Known = false;
	int Number;
	int Close_Dist = INT_MAX;
	int Path;
};
struct Vertex
{
	Vertex(int &_Start, int &_End,int &_Dist) :Start(_Start), End(_End),Dist(_Dist){}
    int Start,End,Dist;
};
bool operator< (Vertex p1, Vertex p2)//此处有坑不准加上引用
{
	return p1.Dist > p2.Dist;
}
int main()
{
	std::priority_queue<Vertex> pq;
	std::vector<VertexInfo> vec(7);
	int Graph[][7] =//创建无向图，但是不相邻的节点要用INT_MAX代替
	{
		0,2,4,1,INT_MAX,INT_MAX,INT_MAX,
		2,0,INT_MAX,3,10,INT_MAX,INT_MAX,
		4,INT_MAX,0,2,INT_MAX,5,INT_MAX,
		1,3,2,0,7,8,4,
		INT_MAX,10,INT_MAX,7,0,INT_MAX,6,
		INT_MAX,INT_MAX,5,8,INT_MAX,0,1,
		INT_MAX,INT_MAX,INT_MAX,4,6,1,0
	};
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 6; j >= i; --j)//取哪一半都一样
		{
			if(Graph[i][j]!=INT_MAX && i!=j)
			pq.push(Vertex(i, j, Graph[i][j]));
		}
	}
	int judge[7];
	for (int i = 0; i < 7; ++i)
	{
		judge[i] = i;
	}
	while (!pq.empty())
	{
		Vertex tmpcell = pq.top();
		pq.pop();
		int Sn1 = judge[tmpcell.Start];
		int Sn2 = judge[tmpcell.End];
		if (Sn1 != Sn2)
		{
			std::cout << "("<< tmpcell.Start <<", " << tmpcell.End << ")" << std::endl;
			for (int i = 0; i < 7; ++i)
			{
				if (judge[i] == Sn2)
				{
					judge[i] = Sn1;
				}
			}
		}
	}
}
