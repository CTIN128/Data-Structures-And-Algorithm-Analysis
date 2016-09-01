/*
*Dijkstra堆DeleteMin的方式获取最小距离
*面对的是图稀疏的情况
*/


#include <iostream>
#include <string>

#define MAX 646566


const int Versum = 7;//图中点的数目



typedef int Weight;
//Weight为权重值
typedef int PreVertex;
//连接的前一个顶点
typedef int Vertex;
//顶点

class Heap;
/*每个顶点的属性*/
class VertexPro
{
private:
	int Known;/*
			  像层序遍历，第一层第一个知道，
			  如果该顶点被检测那么Known将变成1
			  */
	Weight Dist;/*记录该顶点到V1顶点的最短距离*/
	PreVertex Path;/*记录他之前的顶点*/
	std::string Howtogo;
public:
	VertexPro() {}
	friend class Heap;
	friend VertexPro* Initiliaze_Vertex(int Vernum, const int& start);
	int& GetKnown()
	{
		return Known;
	}
	Weight& GetDist()
	{
		return Dist;
	}
	PreVertex& GetPath()
	{
		return Path;
	}
	/*constructor for initializing every vertex*/
	void OutputProperty()
	{
		std::cout << "Known: " << Known << " Dist: " << Dist << " Path: " << Path
			<< std::endl;
	}
};
VertexPro* Initiliaze_Vertex(int Vernum, const int& start)//同理
{
	VertexPro* Vertices = new VertexPro[Vernum + 1];
	for (int i = 0; i < Vernum; ++i)
	{
		Vertices[i + 1].Dist = MAX;
		Vertices[i + 1].Known = 0;
		Vertices[i + 1].Path = -1;
	}
	Vertices[start].Dist = 0;
	Vertices[start].Path = 0;
	return Vertices;
}
class Heap_Node
{
private:
	int Weight;
	int Start_Ver;
	int End_Ver;
public:
	Heap_Node(const int& weight, const int& start_ver, const int& end_ver)
	{
		Weight = weight;
		Start_Ver = start_ver;
		End_Ver = end_ver;
	}
	Heap_Node() {}

	friend class Heap;
	int GetStart()
	{
		return Start_Ver;
	}
	int GetEnd()
	{
		return End_Ver;
	}
	int GetWeight()
	{
		return Weight;
	}
	void OutPut()
	{
		std::cout << Start_Ver << " " << Weight << " " << End_Ver << std::endl;
	}
};


typedef int index;
class Heap
{
private:
	Heap_Node* header;
	int Capacity;
	int Curr_Size;
public:
	Heap(const int&Size);
	index Insert(Heap_Node temp);
	Heap_Node DeleteMin();
	friend void CreateHeap(Heap& H, int data[][Versum + 2]);
	Weight FindEndVertex(const Vertex& data, VertexPro* Vertices);
	Weight Compare(const Vertex& data);
	void Traversal()
	{
		for (int i = 1; i <= Curr_Size; ++i) {
			std::cout << header[i].Start_Ver << " " << header[i].End_Ver << " " << header[i].Weight << std::endl;
		}
	}
	int GetCurr_size()
	{
		return Curr_Size;
	}
};

Weight Heap::FindEndVertex(const Vertex& data, VertexPro* Vertices)
{
	int MinWeight = MAX, MinIndex = 1;
	for (int i = 1; i <= Curr_Size; ++i)
	{
		if (header[i].GetEnd() == data && (header[i].GetWeight() + Vertices[header[i].GetStart()].GetDist()) < MinWeight)
		{
			//std::cout << header[i].GetStart() <<" " << (header[i].GetWeight() + Vertices[header[i].GetStart()].GetDist()) << std::endl;
			MinWeight = Vertices[header[i].GetStart()].GetDist() + header[i].GetWeight();
			MinIndex = i;
		}
	}
	Vertices[data].GetDist() = MinWeight;
	Vertices[data].GetPath() = header[MinIndex].GetStart();
	Vertices[data].GetKnown() = 1;
	//Vertices[data].OutputProperty();
	return MinWeight;
}
Heap::Heap(const int&Size)
{
	Capacity = Size;
	Curr_Size = 0;
	header = new Heap_Node[Size + 1];
	for (int i = 1; i < Size + 1; ++i)
	{
		header[i].Weight = 0;
	}
}

index Heap::Insert(Heap_Node temp)
{
	int i = ++Curr_Size;
	for (i; i >= 1; i /= 2)
	{
		if (i / 2 && header[i / 2].Weight > temp.Weight)
		{
			header[i] = header[i / 2];
		}
		else break;
	}
	header[i] = temp;

	return i;
}

Heap_Node Heap::DeleteMin()
{
	Heap_Node temp = header[1];
	Heap_Node last = header[Curr_Size--];
	int child, i;
	for (i = 1; i * 2 <= Curr_Size; i = child)
	{
		child = i * 2;
		if (header[child].Weight > header[child + 1].Weight)
		{
			child++;
		}
		if (last.Weight > header[child].Weight)
		{
			header[i] = header[child];
		}
		else
			break;
	}
	header[i] = last;
	return temp;
}
void CreateHeap(Heap& H, int data[][Versum + 2])
{
	for (int i = 0; i < Versum; ++i)
	{
		for (int j = 0; data[i][j] != 0; j += 2)
		{
			H.Insert(Heap_Node(data[i][j + 1], i + 1, data[i][j]));
		}

	}
}


int main()
{
	int Graph[Versum][Versum + 2] = {

		2,2,4,1,0,0,0,0,0,//Graph[0][0]指的是V1点到V2点Graph[0][1]指的是此路径的权值 0值代表结束
		4,3,5,10,0,0,0,0,0,
		1,4,6,5,0,0,0,0,0,
		3,2,6,8,7,4,5,2,0,
		7,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		6,1,0,0,0,0,0,0,0
	};

	int start = 1;//定义一个你所要到其他点最短距离的顶点
	VertexPro* Vertices = Initiliaze_Vertex(Versum, start);
	Heap H(100);
	CreateHeap(H, Graph);
	for (;;)
	{
		if (H.GetCurr_size() == 0)
			break;
		Heap_Node& temp = H.DeleteMin();
		//temp.OutPut();
		Vertices[temp.GetEnd()].GetKnown() = 1;

		if (Vertices[temp.GetEnd()].GetDist() == MAX)
		{
			Vertices[temp.GetEnd()].GetPath() = temp.GetStart();
			Vertices[temp.GetEnd()].GetDist() = temp.GetWeight();
			/*if (Vertices[temp.GetStart()].GetDist() == MAX)
			{
				//std::cout << "data: " << temp.GetStart() << std::endl;
				Vertices[temp.GetEnd()].GetDist() = temp.GetWeight() + H.FindEndVertex(temp.GetStart(), Vertices);
			}
			else
				Vertices[temp.GetEnd()].GetDist() = temp.GetWeight() + Vertices[temp.GetStart()].GetDist();*/

		}
		else if (Vertices[temp.GetEnd()].GetDist() != MAX /*&& temp.GetEnd() != start && Vertices[temp.GetEnd()].GetPath() != start*/)
		{
			/*if ((temp.GetWeight() + Vertices[temp.GetStart()].GetDist()) < Vertices[temp.GetEnd()].GetDist())
			{
				Vertices[temp.GetEnd()].GetPath() = temp.GetStart();
				Vertices[temp.GetEnd()].GetDist() = temp.GetWeight() + Vertices[temp.GetStart()].GetDist();
			}*/
			if (temp.GetWeight() < Vertices[temp.GetEnd()].GetDist())
			{
				Vertices[temp.GetEnd()].GetPath() = temp.GetStart();
				Vertices[temp.GetEnd()].GetDist() = temp.GetWeight() ;
			}
		}
		else
			continue;
	}
	for (int i = 1; i < Versum + 1; ++i)
	{
		std::cout << i << " ";
		Vertices[i].OutputProperty();
	}

}