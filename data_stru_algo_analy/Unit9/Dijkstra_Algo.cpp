#include <iostream>
#include <string>

#define MAX (~(0x1<<31))

bool reset = true;//��judge�����Ƿ���Ҫ����ʼ��

const int Versum = 7;//ͼ�е����Ŀ

static int judge[Versum + 1][2];//�ж�ĳ�������Ƿ��Ѿ���ѹ��ջ����

/*
 * �����ӷ���ʾͼ
 */

typedef int Weight;
//WeightΪȨ��ֵ
typedef int PreVertex;
//���ӵ�ǰһ������
typedef int Vertex;
//����


class VertexPro;
class Linkedlist_Node;

/*�����ӷ��и�������ı�ͷ*/
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
	//���������ӱ�
	friend AdjlistHead* Create_adjlist(int Vernum, int array[][Versum+2]);
	//Dijkstra�㷨��implementation
	friend VertexPro* Dijkstra(AdjlistHead* header, VertexPro* Vertices, int Vernum,const int& start);
	//��������ӱ�ĵ���Ԫ�ص���Ϣ
	void outputinfor();
};

//array Queue
class Queue
{
private:
	AdjlistHead* ver;
	int First, Rear;//ͷβָ��
	int Queue_Size;//���д�С
	int Capacity;//��������
public:
	//constructor
	Queue(const int& Vernum):Queue_Size(0),Capacity(Vernum)
	{
		First = Rear = 0;
		ver = new AdjlistHead[Vernum];
	}
    //ѹ�����
	void EnQueue(AdjlistHead& data);
	//��������
	AdjlistHead DeQueue();
	//�ж϶����Ƿ�Ϊ��
	bool isempty()
	{
		return Queue_Size == 0;
	}
	//��ȡ��ʱ���д�С
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

/*ÿ�����������*/
class VertexPro
{
private:
	int Known;/*
			  ������������һ���һ��֪����
			  ����ö��㱻�����ôKnown�����1
			  */
	Weight Dist;/*��¼�ö��㵽V1�������̾���*/
	PreVertex Path;/*��¼��֮ǰ�Ķ���*/
	std::string Howtogo;
public:
	
	//VertexPro(const int& known, const Weight& dist, const PreVertex& path) :Known(known), Dist(dist), Path(path) {}
	VertexPro() {}
	/*constructor for initializing every vertex*/
	friend VertexPro* Initiliaze_Vertex(int Vernum,const int& start);

	friend VertexPro* Dijkstra(AdjlistHead* header, VertexPro* Vertices, int Vernum, const int& start);
	//���ÿ���������Ϣ
	void OutputProperty()
	{
		std::cout << "Known: " << Known << " Dist: " << Dist << " Path: " << Path 
	   <<" Howtogo: " << Howtogo << std::endl;
	}
};


/*�����ӱ�������Ķ�����Ϣ*/
class Linkedlist_Node
{
private:
	Vertex _vertex;//����
	Linkedlist_Node* Next;//��һ��ָ��
	Weight weight;//��¼�ö��������ͷ���ö����Ȩ��
public:
	//constructor
	Linkedlist_Node(const Vertex& vertex):_vertex(vertex),Next(nullptr){}
	Linkedlist_Node():Next(nullptr){}
	//���������ӱ�
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
	AdjlistHead* header = new AdjlistHead[Vernum+1];//Ϊͷ�ڵ�����ڴ�
	for (int i = 0; i < Vernum; i++)
	{
		header[i+1]._vertex = i+1;//��֤�����Ǵ�1��ʼ
		Linkedlist_Node* head = new Linkedlist_Node();
		Linkedlist_Node* tmpcell = head;
		for (int j = 0; array[i][j] != 0; j+=2)
		{
			tmpcell->Next = new Linkedlist_Node(array[i][j]);
			tmpcell = tmpcell->Next;
			tmpcell->weight = array[i][j + 1];
		}//����implementation��header[i]������ĵ�һ����������һ���յĶ���
		header[i+1].First_Node = head->Next;//����ָ��Next
		delete head;//ɾ��head
	}
	return header;
}
/*Initialize Every Vertex*/
VertexPro* Initiliaze_Vertex(int Vernum,const int& start)//ͬ��
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
		Judge(start);/*һ��Ҫ��ǰ�ͽ�judge�����ʼ����֮���ʼ������ִ���*/
		judge[start][1] = 1;

		Vertices[start].Known = 1;

		while (!Q.isempty())//FIFOԭ����ʵ��һ��һ��
		{
			AdjlistHead tmpcell = Q.DeQueue();
			
			Linkedlist_Node* tmpptr = tmpcell.First_Node;
			while (tmpptr != nullptr)
			{
				//if (tmpptr->_vertex == 1){}
			    if (Vertices[tmpptr->_vertex].Dist == MAX)//����õ㻹û���޸�
				{
				
					Vertices[tmpptr->_vertex].Path = tmpcell._vertex;
					Vertices[tmpptr->_vertex].Known = 1;
					int Curr = tmpptr->_vertex;
				                                                
					Vertices[tmpptr->_vertex].Dist = tmpptr->weight+ Vertices[Vertices[Curr].Path].Dist;  //ÿ��ֻ��Ҫ������һ��path�����Dist����
																										  //��Ϊÿ�ε�ʵ�ֶ��Ѿ���Distָ��Ϊ�õ㵽V1��ľ���
					Vertices[tmpptr->_vertex].Howtogo.insert(0, 1, char(tmpptr->_vertex + '0'));//�ȼ�¼��ʱ�Ķ���ֵ
					Vertices[tmpptr->_vertex].Howtogo.insert(1, 1, ' ');										
					for (int j = Vernum + 1; j >= 1; j--)
					{
						if (Vertices[Curr].Path == j)
						{
							Vertices[tmpptr->_vertex].Howtogo.insert(0,1,char(j + '0'));
							Vertices[tmpptr->_vertex].Howtogo.insert(1,1,' ');
							Curr = Vertices[Curr].Path; 
							if (Vertices[Curr].Path == start)//һ������V1����V1����ѭ��
							{
								Vertices[tmpptr->_vertex].Howtogo.insert(0, 1, char(start + '0'));
								Vertices[tmpptr->_vertex].Howtogo.insert(1, 1, ' ');
								break;
							}
							j = Vernum + 1;
					     }
					}//��¼�õ��path��V1ֵ*/
			
				}
				//����õ��Ѿ����޸Ĳ�������path��ΪV1
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
							if (Vertices[Curr].Path == start)//һ������V1����V1����ѭ��
							{
								temp.insert(0, 1, char(start + '0'));
								temp.insert(1, 1, ' ');
								break;
							}
							j =  Vernum + 1;
						}
					}
					//�����ж�howtogo
					if (result < Vertices[tmpptr->_vertex].Dist)
					{
						Vertices[tmpptr->_vertex].Howtogo = temp;
						Vertices[tmpptr->_vertex].Dist = result;
					}
					else
						Vertices[tmpptr->_vertex].Path = temppath;
				}
				//�����pathΪV1��ô�����޸�
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
				if (Judge(tmpptr->_vertex))//�жϸö����Ƿ��Ѿ���ѹ����й���
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

								 2,2,4,1,0,0,0,0,0,//Graph[0][0]ָ����V1�㵽V2��Graph[0][1]ָ���Ǵ�·����Ȩֵ 0ֵ�������
								 4,3,5,10,0,0,0,0,0,
								 1,4,6,5,0,0,0,0,0,
								 3,2,6,8,7,4,5,2,0,
								 7,6,0,0,0,0,0,0,0,
								 0,0,0,0,0,0,0,0,0,
								 6,1,0,0,0,0,0,0,0
	};

	int start = 4;//����һ������Ҫ����������̾���Ķ���
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