#include <iostream>

const int Versum = 7;
#define reset(header) memset(header,0,Versum)
class Heap_Node
{
private:
	int Weight;
	int Start_Ver;
	int End_Ver;
public:
	Heap_Node(const int& weight,const int& start_ver,const int& end_ver)
	{
		Weight = weight;
		Start_Ver = start_ver;
		End_Ver = end_ver;
	}
	Heap_Node(){}

	friend class Heap;
	int GetStart() 
	{
		return Start_Ver;
	}
	int GetEnd()
	{
		return End_Ver;
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
	friend void CreateHeap(Heap& H, int data[][Versum]);
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
	for (i; i >= 1; i /= 2)
	{
		if (i/2 && header[i / 2].Weight > temp.Weight)
		{
			header[i] = header[i / 2];
		}
		else break;
	}
	header[i] = temp;
		/*int i;
		for (i = ++Curr_Size; header[i/2].Weight >= temp.Weight; i /= 2)//上滤
		{
			header[i] = header[i / 2];
		}
		header[i] = temp;*/
	return i;
}

Heap_Node Heap::DeleteMin()
{
	Heap_Node temp = header[1];
	Heap_Node last = header[Curr_Size--];
	int child,i;
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
void CreateHeap(Heap& H, int data[][Versum])
{
	for (int i = 0; i < Versum; ++i)
	{

		if (data[i][0] == 0)
			break;
		for (int j = 0; data[i][j] != 0; j+=2)
		{
			H.Insert(Heap_Node(data[i][j + 1], i + 1, data[i][j]));
		}
		
	}
}

int main()
{
	int Graph[Versum][Versum] = {
									2,2,3,4,4,1,0,    V4只能到V5 ，6，7
									4,3,5,10,0,0,0,
									4,2,6,5,0,0,0,
									6,8,7,4,5,7,0,
									7,6,0,0,0,0,0,
									7,1,0,0,0,0,0,//所以V7就没了
	                             };
	int sum = 0;
	for (int i = 0; i < Versum; i++)
	{
		for (int j = 0; j < Versum; ++j)
		{
			if (Graph[i][j] != 0)
				sum++;
		}
	}
	Heap H(sum/2);
	CreateHeap(H, Graph);
	//H.Traversal();
	int judge[Versum+1];

	for (int i = 1; i < Versum+1; ++i)
	{
		judge[i] = i;
	}
	
	for (;;)/*最重要的标记算法*/
	{
		if (H.GetCurr_size() == 0)
		{
			break;
		}
		Heap_Node temp = H.DeleteMin();
		int Sn1 = judge[temp.GetStart()];
		int Sn2 = judge[temp.GetEnd()];
		if (Sn1 != Sn2)
		{
			std::cout << "("<<  temp.GetStart() <<", " << temp.GetEnd() << ")" << std::endl;
			for (int i = 1; i < Versum+1; ++i)
			{
				if (judge[i] == Sn2)
				{
					judge[i] = Sn1;
				}
			}
		}
	}

	
}





