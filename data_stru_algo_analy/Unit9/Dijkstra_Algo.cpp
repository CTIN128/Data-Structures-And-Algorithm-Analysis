#include <iostream>
#include <string>

#define MAX (~(0x1<<31))

bool reset = true;//看judge数组是否先要被初始化

const int Versum = 7;//图中点的数目

static int judge[Versum + 1][2];//判断某个顶点是否已经被压入栈检测过

/*
 * 邻连接法表示图
 */

typedef int Weight;
//Weight为权重值
typedef int PreVertex;
//连接的前一个顶点
typedef int Vertex;
//顶点


class VertexPro;
class Linkedlist_Node;

/*邻连接法中各个链表的表头*/
class AdjlistHead
{
private:
	Vertex _vertex;
	Linkedlist_Node* First_Node;
public:
	//constructor
	AdjlistHead():First_Node(nullptr) {}
	//constructor
	AdjlistHead(const Vertex& vertex, Linkedlist_Node* first_node) :_vertex(vertex), First_Node(first_node) {}
	//建立邻连接表
	friend AdjlistHead* Create_adjlist(int Vernum, int array[][Versum+2]);
	//Dijkstra算法的implementation
	friend VertexPro* Dijkstra(AdjlistHead* header, VertexPro* Vertices, int Vernum,const int& start);
	//输出邻连接表的单个元素的信息
	void outputinfor();
};

//array Queue
class Queue
{
private:
	AdjlistHead* ver;
	int First, Rear;//头尾指标
	int Queue_Size;//队列大小
	int Capacity;//队列容量
public:
	//constructor
	Queue(const int& Vernum):Queue_Size(0),Capacity(Vernum)
	{
		First = Rear = 0;
		ver = new AdjlistHead[Vernum];
	}
    //压入队列
	void EnQueue(AdjlistHead& data);
	//弹出队列
	AdjlistHead DeQueue();
	//判断队列是否为空
	bool isempty()
	{
		return Queue_Size == 0;
	}
	//获取此时队列大小
	int GetSize()
	{
		return Queue_Size;
	}
};

void Queue::EnQueue(AdjlistHead& data)
{
	ver[Rear++] = data;
	Queue_Size++;
	Rear = Rear % Capacity;
}

AdjlistHead Queue::DeQueue()
{
	AdjlistHead tempdata = ver[First++];
	Queue_Size--;
	First %= Capacity;
	return tempdata;
}

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
	
	//VertexPro(const int& known, const Weight& dist, const PreVertex& path) :Known(known), Dist(dist), Path(path) {}
	VertexPro() {}
	/*constructor for initializing every vertex*/
	friend VertexPro* Initiliaze_Vertex(int Vernum,const int& start);

	friend VertexPro* Dijkstra(AdjlistHead* header, VertexPro* Vertices, int Vernum, const int& start);
	//输出每个顶点的信息
	void OutputProperty()
	{
		std::cout << "Known: " << Known << " Dist: " << Dist << " Path: " << Path 
	   <<" Howtogo: " << Howtogo << std::endl;
	}
};


/*邻连接表中链表的顶点信息*/
class Linkedlist_Node
{
private:
	Vertex _vertex;//顶点
	Linkedlist_Node* Next;//下一个指针
	Weight weight;//记录该顶点的链表头道该顶点的权重
public:
	//constructor
	Linkedlist_Node(const Vertex& vertex):_vertex(vertex),Next(nullptr){}
	Linkedlist_Node():Next(nullptr){}
	//建立邻连接表
	friend AdjlistHead* Create_adjlist(int Vernum, int array[][Versum + 2]);
	friend VertexPro* Dijkstra(AdjlistHead* header, VertexPro* Vertices, int Vernum, const int& start);
	friend void AdjlistHead::outputinfor();
};

void AdjlistHead::outputinfor()
{
	std::cout << _vertex << " ";
	Linkedlist_Node* tmpcell = First_Node;
	while (tmpcell != nullptr)
	{
		std::cout << tmpcell->_vertex <<" (" << tmpcell->weight << ")";
		tmpcell = tmpcell->Next;
	}
	std::cout << std::endl;
}

/*create adjacency list*/
AdjlistHead* Create_adjlist(int Vernum,int array[][Versum + 2])
{
	AdjlistHead* header = new AdjlistHead[Vernum+1];//为头节点分配内存
	for (int i = 0; i < Vernum; i++)
	{
		header[i+1]._vertex = i+1;//保证点数是从1开始
		Linkedlist_Node* head = new Linkedlist_Node();
		Linkedlist_Node* tmpcell = head;
		for (int j = 0; array[i][j] != 0; j+=2)
		{
			tmpcell->Next = new Linkedlist_Node(array[i][j]);
			tmpcell = tmpcell->Next;
			tmpcell->weight = array[i][j + 1];
		}//这样implementation，header[i]跟链表的第一个顶点有着一个空的顶点
		header[i+1].First_Node = head->Next;//所以指向Next
		delete head;//删除head
	}
	return header;
}
/*Initialize Every Vertex*/
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


bool Judge(const Vertex &data)
{
	//std::cout << "reset: " << reset << std::endl;
	if (reset == true)
	{
		for (int i = 1; i < Versum + 1; ++i)
		{
			judge[i][0] = i;
			judge[i][1] = 0;
		}
		reset = false;
	}
	return judge[data][1] == 0;
}

/*Dijkstra algorithm*/
VertexPro* Dijkstra(AdjlistHead* header, VertexPro* Vertices,int Vernum, const int& start)
{
	    Queue Q(Vernum);

		Q.EnQueue(header[start]);
		Judge(start);/*一定要先前就将judge数组初始化，之后初始化会出现错误*/
		judge[start][1] = 1;

		Vertices[start].Known = 1;

		while (!Q.isempty())//FIFO原理来实现一层一层
		{
			AdjlistHead tmpcell = Q.DeQueue();
			
			Linkedlist_Node* tmpptr = tmpcell.First_Node;
			while (tmpptr != nullptr)
			{
				//if (tmpptr->_vertex == 1){}
			    if (Vertices[tmpptr->_vertex].Dist == MAX)//如果该点还没被修改
				{
				
					Vertices[tmpptr->_vertex].Path = tmpcell._vertex;
					Vertices[tmpptr->_vertex].Known = 1;
					int Curr = tmpptr->_vertex;
				                                                
					Vertices[tmpptr->_vertex].Dist = tmpptr->weight+ Vertices[Vertices[Curr].Path].Dist;  //每次只需要加上上一个path顶点的Dist即可
																										  //因为每次的实现都已经将Dist指定为该点到V1点的距离
					Vertices[tmpptr->_vertex].Howtogo.insert(0, 1, char(tmpptr->_vertex + '0'));//先记录此时的顶点值
					Vertices[tmpptr->_vertex].Howtogo.insert(1, 1, ' ');										
					for (int j = Vernum + 1; j >= 1; j--)
					{
						if (Vertices[Curr].Path == j)
						{
							Vertices[tmpptr->_vertex].Howtogo.insert(0,1,char(j + '0'));
							Vertices[tmpptr->_vertex].Howtogo.insert(1,1,' ');
							Curr = Vertices[Curr].Path; 
							if (Vertices[Curr].Path == start)//一旦到了V1输入V1结束循环
							{
								Vertices[tmpptr->_vertex].Howtogo.insert(0, 1, char(start + '0'));
								Vertices[tmpptr->_vertex].Howtogo.insert(1, 1, ' ');
								break;
							}
							j = Vernum + 1;
					     }
					}//记录该点的path到V1值*/
			
				}
				//如果该点已经被修改并且他的path不为V1
				else if(Vertices[tmpptr->_vertex].Dist != MAX && Vertices[tmpptr->_vertex].Path != 1)
				{   
					int temppath = Vertices[tmpptr->_vertex].Path;
					Vertices[tmpptr->_vertex].Path = tmpcell._vertex;
					int result = tmpptr->weight;
					result += Vertices[tmpcell._vertex].Dist;
					int Curr = tmpptr->_vertex;
					std::string temp;
					temp.insert(0, 1, char(tmpptr->_vertex + '0'));
					temp.insert(1, 1, ' ');
					
					for (int j = Vernum + 1; j >= 1; j--)
					{
						if (Vertices[Curr].Path == j )
						{
							temp.insert(0, 1, char(j + '0'));
							temp.insert(1, 1, ' ');
							Curr = Vertices[Curr].Path;
							if (Vertices[Curr].Path == start)//一旦到了V1输入V1结束循环
							{
								temp.insert(0, 1, char(start + '0'));
								temp.insert(1, 1, ' ');
								break;
							}
							j =  Vernum + 1;
						}
					}
					//用来判断howtogo
					if (result < Vertices[tmpptr->_vertex].Dist)
					{
						Vertices[tmpptr->_vertex].Howtogo = temp;
						Vertices[tmpptr->_vertex].Dist = result;
					}
					else
						Vertices[tmpptr->_vertex].Path = temppath;
				}
				//顶点的path为V1那么不用修改
				else 
				{ 
				   if (Judge(tmpptr->_vertex))
				   {
					Q.EnQueue(header[tmpptr->_vertex]);
					judge[tmpptr->_vertex][1] = 1;
				   }
				   tmpptr = tmpptr->Next;
				   continue; 
				}
				if (Judge(tmpptr->_vertex))//判断该顶点是否已经被压入队列过了
				{
					Q.EnQueue(header[tmpptr->_vertex]);
					judge[tmpptr->_vertex][1] = 1;
				}
				tmpptr = tmpptr->Next;
			}
		}
	return Vertices;
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

	int start = 4;//定义一个你所要到其他点最短距离的顶点
	VertexPro* Vertices = Initiliaze_Vertex(Versum,start);
	/*for (int i = 1; i < Versum + 1; ++i)
	{
		std::cout << i << " ";
	   Vertices[i].OutputProperty();
	}*/
	AdjlistHead* header = Create_adjlist(Versum,Graph);
	/*for (int i = 1; i < Versum+1; ++i)
	{
		header[i].outputinfor();
	}*/
	Dijkstra(header, Vertices, Versum,start);
	int sum = 0;
	for (int i = start; i < Versum+1; ++i)
	{
		std::cout <<'V'<<i << ": ";
		Vertices[i].OutputProperty();
		sum++;
	}
	if (Versum != sum)
	{
		for (int i = 1; i < Versum + 1-sum; ++i)
		{
			std::cout << 'V' << i << ": ";
			Vertices[i].OutputProperty();
		}
	}
}