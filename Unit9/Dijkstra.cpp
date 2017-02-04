#include <queue>
#include <iostream>
#include <vector>
#include <limits>

struct Vertex
{
	Vertex(){}
	Vertex(int _Number, int _Dist):Number(_Number), Dist(_Dist) {}
	int Number;
	int Dist = INT_MAX;
	int Path;
};
bool operator<(Vertex p1, Vertex p2)
{
	return p1.Dist > p2.Dist;
}
void PrintPath(int SourceVertex,int vertex, std::vector<Vertex> v)
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
	int SourceVetex = 0;//设置源点
	std::vector<Vertex> vec(7);//创建容器记录顶点状态
	vec[SourceVetex].Dist = 0;//源点到源点距离当然为0
	vec[SourceVetex].Path = SourceVetex;//源点自己本身
	std::priority_queue<Vertex> pq;//创建优先队列并且是按照节点中的dist从小到大排列
	std::vector<bool> Known(7, false);
	int Graph[][7] =//创建有向图
	{
	   0,2,0,1,0,0,0,
	   0,0,0,3,10,0,0,
	   4,0,0,0,0,5,0,
	   0,0,2,0,2,8,4,
	   0,0,0,0,0,0,6,
	   0,0,0,0,0,0,0,
	   0,0,0,0,0,1,0
	};
	/*
       for(int i = 0;i < 7;++i)
	   {
	      if(i == SourceVertex)
		    pq.push(Vertex(SourceVertex,0));
		  else
		  pq.push(Vertex(SourceVertx,INT_MAX));
        }
	*/
	pq.push(Vertex(SourceVetex, 0));
	int IsKnown = 0;
	while (!pq.empty())
	{
		Vertex tmpcell = pq.top();
		pq.pop();//弹出点
		IsKnown++;
		Known[tmpcell.Number] = true;
		for (int i = 0; i < 7; ++i)
		{
				if (!Known[i]&&Graph[tmpcell.Number][i] != 0&&vec[tmpcell.Number].Dist + Graph[tmpcell.Number][i] < vec[i].Dist)//如果检测的点加上连接它点的到源点路径长比原来他到源点路径小则更新
				{
					vec[i].Dist = vec[tmpcell.Number].Dist + Graph[tmpcell.Number][i];//更新路径长
					vec[i].Path = tmpcell.Number;//更新连接它的节点
					pq.push(Vertex(i, vec[i].Dist));
					//将pq中的i对应的关键值修改，但是STL中没有这类函数
				}		
		}
	}
	/*
	  由算法导论可知，pq中应该先全部压入所有点，然后源点到自己的距离为0，之后pq中弹出u，遍历u的
	  邻接点，某点v现在到源点距离比原先短就更新信息，此时也要将队列中v对应的关键值修改，但如果用STL
	  最后无法做到更新，那么可以这么想，距源点为INT_MAX值的点，pq的top永远不会选到他，那么可以先不将这些点压入到队列中，
	  只将那些有更新的点压入，最终INT_MAX被修改时可将该点压入,增加了是否访问过的判断，
//    因为我们每次都选取到源点最短的距离，所以我们只要pq(保存每个点到源点的最短路径)中弹出的这个点，那就是已经确定好的前驱是谁，到源点最短距离了，
//	  不用再管其他的
	*/
	for (int i = 0; i < 7; ++i)
	{
		std::cout <<"Vertex: "<< i << std::endl;
		std::cout << "Dis: " << vec[i].Dist << std::endl;
		std::cout << "Path: " << std::endl;
		PrintPath(SourceVetex, i, vec);
	}
	return 0;
}