/*
 *Dijkstra��DeleteMin�ķ�ʽ��ȡ��С����
 *��Ե���ͼϡ������
 *
 *�ο���weiss�ġ����ݽṹ���㷨������
 */


#include <iostream>
#include <string>

#define MAX 646566


const int Versum = 7;//ͼ�е����Ŀ



typedef int Weight;
//WeightΪȨ��ֵ
typedef int PreVertex;
//���ӵ�ǰһ������
typedef int Vertex;
//����
typedef int index;
//���ض���index

class Heap;
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
	//constructor
	VertexPro() {}
	//destructor
	~VertexPro() {}
	friend class Heap;

	/*function for initializing every vertex*/
	friend VertexPro* Initiliaze_Vertex(int Vernum, const int& start);

	int& GetKnown()//���ض�Known������
	{
		return Known;
	}
	Weight& GetDist()//���ض�Dist������
	{
		return Dist;
	}
	PreVertex& GetPath()//���ض�Path������
	{
		return Path;
	}
	void OutputProperty()//�����Ϣ
	{
		std::cout << "Known: " << Known << " Dist: " << Dist << " Path: " << Path 
	    << std::endl;
	}
};

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

class Heap_Node//�ѽ��
{
private:
	int Weight;//ĳ��·����Ȩֵ
	int Start_Ver;//ĳ��·�������
	int End_Ver;//ĳ��·�����յ�
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

	int GetStart() //����·�����
	{
		return Start_Ver;
	}
	int GetEnd()//����·���յ�
	{
		return End_Ver;
	}
	int GetWeight()//����·��Ȩ��
	{
		return Weight;
	}
	void OutPut()//�����Ϣ
	{
		std::cout << Start_Ver << " " << Weight << " " << End_Ver << std::endl;
	}
};




class Heap//��
{
private:
	Heap_Node* header;//������
	int Capacity;//������
	int Curr_Size;//�Ѵ�С
public:
	//constructor
	Heap(const int&Size);
	~Heap() {}
	//����ڵ�
	index Insert(Heap_Node temp);
	//ɾ��
	Heap_Node DeleteMin();
   //����
	friend void CreateHeap(Heap& H, int data[][Versum+2]);
	//�������ĳ��·��������Ӧ�ĵ��Dist����MAX������function
	Weight FindEndVertex(const Vertex& data, VertexPro* Vertices);

	void Traversal()//������
	{
		for (int i = 1; i <= Curr_Size; ++i) {
			std::cout << header[i].Start_Ver << " " << header[i].End_Ver << " " << header[i].Weight << std::endl;
		}
	}

	int GetCurr_size()//���ش�ʱ�ѵĴ�С
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
		*�ڶ���Ѱ�Ҷ�Ӧ�ĵ��� start_ver4  end_ver5 ����Vertices[4]��DistΪMAX���������޷��ı�Vertices[5]��Dist 
		*ͨ������ȸı�Vertices[4]��Dist
		*/
		/*
		*�����кܶ�start_ver1  end_ver4 start_ver3  end_ver4
		*����Ҫ�ҳ���start��V4·������Сֵ
		*
		*/
		if (header[i].GetEnd() == data &&  (header[i].GetWeight() + Vertices[header[i].GetStart()].GetDist()) < MinWeight)
		{
			//std::cout << header[i].GetStart() <<" " << (header[i].GetWeight() + Vertices[header[i].GetStart()].GetDist()) << std::endl;
			MinWeight = Vertices[header[i].GetStart()].GetDist() + header[i].GetWeight();//��ֵ��start��V4·������Сֵ
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
	for (i; i >= 1; i /= 2)//���˹���
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
	for (i = 1; i * 2 <= Curr_Size; i = child)//���˹���
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

								 2,2,4,1,0,0,0,0,0,//Graph[0][0]ָ����V1�㵽V2��Graph[0][1]ָ���Ǵ�·����Ȩֵ 0ֵ�������
								 4,3,5,10,0,0,0,0,0,
								 1,4,6,5,0,0,0,0,0,
								 3,2,6,8,7,4,5,2,0,
								 7,6,0,0,0,0,0,0,0,
								 0,0,0,0,0,0,0,0,0,
								 6,1,0,0,0,0,0,0,0
	};

	int start = 1;//����һ������Ҫ����������̾���Ķ���
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

		if (Vertices[temp.GetEnd()].GetDist() == MAX)//���µĶ���Vertices[temp.GetEnd()]   path�ȵ���temp.GetStart() 
			                                          //   Dist�ȵ���weight����Vertices[temp.GetStart()].GetDist()
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