/*
 *Dijkstra堆DeleteMin的方式获取最小距离
 *面对的是图稀疏的情况
 *
 *参考了weiss的《数据结构和算法分析》
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
typedef int index;
//返回堆中index

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
	//constructor
	VertexPro() {}
	//destructor
	~VertexPro() {}
	friend class Heap;

	/*function for initializing every vertex*/
	friend VertexPro* Initiliaze_Vertex(int Vernum, const int& start);

	int& GetKnown()//返回对Known的引用
	{
		return Known;
	}
	Weight& GetDist()//返回对Dist的引用
	{
		return Dist;
	}
	PreVertex& GetPath()//返回对Path的引用
	{
		return Path;
	}
	void OutputProperty()//输出信息
	{
		std::cout << "Known: " << Known << " Dist: " << Dist << " Path: " << Path 
	    << std::endl;
	}
};

VertexPro* Initiliaze_Vertex(int Vernum,const int& start)//同理
{
	VertexPro* Vertices = new VertexPro[Vernum+1];
	for (int i = 0; i < Vernum; ++i)
	{
		Vertices[i+1].Dist = MAX;
		Vertices[i+1].Known = 0;
		Vertices[i+1].Path = -1;
	}
	Vertices[start].Dist = 0;
	Vertices[start].Path = 0;
	return Vertices;
}

class Heap_Node//堆结点
{
private:
	int Weight;//某段路径的权值
	int Start_Ver;//某段路径的起点
	int End_Ver;//某段路径的终点
public:
	//constructor
	Heap_Node(const int& weight,const int& start_ver,const int& end_ver)
	{
		Weight = weight;
		Start_Ver = start_ver;
		End_Ver = end_ver;
	}
	Heap_Node(){}
	//destructor
	~Heap_Node() {}
	friend class Heap;

	int GetStart() //返回路径起点
	{
		return Start_Ver;
	}
	int GetEnd()//返回路径终点
	{
		return End_Ver;
	}
	int GetWeight()//返回路径权重
	{
		return Weight;
	}
	void OutPut()//输出信息
	{
		std::cout << Start_Ver << " " << Weight << " " << End_Ver << std::endl;
	}
};




class Heap//堆
{
private:
	Heap_Node* header;//堆数组
	int Capacity;//堆容量
	int Curr_Size;//堆大小
public:
	//constructor
	Heap(const int&Size);
	~Heap() {}
	//插入节点
	index Insert(Heap_Node temp);
	//删除
	Heap_Node DeleteMin();
   //建堆
	friend void CreateHeap(Heap& H, int data[][Versum+2]);
	//如果发现某段路径的起点对应的点的Dist还是MAX，调用function
	Weight FindEndVertex(const Vertex& data, VertexPro* Vertices);

	void Traversal()//遍历堆
	{
		for (int i = 1; i <= Curr_Size; ++i) {
			std::cout << header[i].Start_Ver << " " << header[i].End_Ver << " " << header[i].Weight << std::endl;
		}
	}

	int GetCurr_size()//返回此时堆的大小
	{
		return Curr_Size;
	}
};

Weight Heap::FindEndVertex(const Vertex& data,VertexPro* Vertices)
{
	int MinWeight = MAX,MinIndex = 1;
	for (int i = 1; i <= Curr_Size; ++i)
	{
		/*
		*在堆中寻找对应的点如 start_ver4  end_ver5 发现Vertices[4]的Dist为MAX，这样就无法改变Vertices[5]的Dist 
		*通过这个先改变Vertices[4]的Dist
		*/
		/*
		*堆中有很多start_ver1  end_ver4 start_ver3  end_ver4
		*所以要找出到start到V4路径的最小值
		*
		*/
		if (header[i].GetEnd() == data &&  (header[i].GetWeight() + Vertices[header[i].GetStart()].GetDist()) < MinWeight)
		{
			//std::cout << header[i].GetStart() <<" " << (header[i].GetWeight() + Vertices[header[i].GetStart()].GetDist()) << std::endl;
			MinWeight = Vertices[header[i].GetStart()].GetDist() + header[i].GetWeight();//右值是start到V4路径的最小值
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
	header = new Heap_Node[Size+1];
	for (int i = 1; i < Size+1; ++i)
	{
		header[i].Weight = 0;
	}
}

index Heap::Insert(Heap_Node temp)
{
	int i = ++Curr_Size;
	for (i; i >= 1; i /= 2)//上滤过程
	{
		if (i/2 && header[i / 2].Weight > temp.Weight)
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
	int child,i;
	for (i = 1; i * 2 <= Curr_Size; i = child)//下滤过程
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
void CreateHeap(Heap& H, int data[][Versum+2])
{
	for (int i = 0; i < Versum; ++i)
	{
		for (int j = 0; data[i][j] != 0; j+=2)
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

		if (Vertices[temp.GetEnd()].GetDist() == MAX)//更新的都是Vertices[temp.GetEnd()]   path等的是temp.GetStart() 
			                                          //   Dist等的是weight加上Vertices[temp.GetStart()].GetDist()
		{
			Vertices[temp.GetEnd()].GetPath() = temp.GetStart();
			if (Vertices[temp.GetStart()].GetDist() == MAX)
			{
				//std::cout << "data: " << temp.GetStart() << std::endl;
				Vertices[temp.GetEnd()].GetDist() = temp.GetWeight() + H.FindEndVertex(temp.GetStart(), Vertices);
			}
			else
			Vertices[temp.GetEnd()].GetDist() = temp.GetWeight() + Vertices[temp.GetStart()].GetDist();

		}
		else if (Vertices[temp.GetEnd()].GetDist() != MAX && temp.GetEnd() != start && Vertices[temp.GetEnd()].GetPath() != start)
		{

			if ((temp.GetWeight() + Vertices[temp.GetStart()].GetDist()) < Vertices[temp.GetEnd()].GetDist())
			{
				Vertices[temp.GetEnd()].GetPath() = temp.GetStart();
				Vertices[temp.GetEnd()].GetDist() = temp.GetWeight() + Vertices[temp.GetStart()].GetDist();
			}
		}
		else
			continue;
	}
	for (int i = 1; i < Versum+1; ++i)
	{
		std::cout << i << " ";
		Vertices[i].OutputProperty();
	}

}