#include <iostream>

/*template <class T>*/
class Leftist;

//template <class T>
class Heap_Node
{
private:
	int Npl;//Null path length
	Heap_Node * Left_Next;
	Heap_Node * Right_Next;
	int _data;
public:
	friend class Leftist;
	Heap_Node(const int & data) :_data(data), Left_Next(nullptr), Right_Next(nullptr), Npl(0) {}
	friend void Pre_Traversal(Heap_Node * header,char c);
	friend Heap_Node* Merge1(Heap_Node* H1, Heap_Node* H2);
	friend Heap_Node* Merge2(Heap_Node* H1, Heap_Node* H2);
	//int Find(const T & data);
	friend void SwapChildren(Heap_Node * H1);
};


class Leftist
{
private:
	Heap_Node * header;

public:
	Leftist():header(nullptr){}
	void Insert_Node(const int & data);
	Heap_Node * Get_header();
};

//template <class T>
void SwapChildren(Heap_Node* H1)
{
	Heap_Node * R_tmpcell = H1->Right_Next;
	Heap_Node * L_tmpcell = H1->Left_Next;
	H1->Left_Next = R_tmpcell;
	H1->Right_Next = L_tmpcell;
}
//template <class T>
Heap_Node * Merge1(Heap_Node * H1, Heap_Node * H2)
{
	if (H1->Left_Next == nullptr)//single node
	{
		H1->Left_Next = H2;
	}
	else
	{
		H1->Right_Next = Merge2(H1->Right_Next, H2);//再次调用merge驱动合并H1->Right_Next和H2
		if (H1->Left_Next->Npl < H1->Right_Next->Npl)
		{
			SwapChildren(H1);
		}
		H1->Npl = H1->Right_Next->Npl + 1;
	}
	return H1;//返回给前面的节点8节点合并后返回给7节点的Right_Next
}

Heap_Node * Merge2(Heap_Node * H1, Heap_Node * H2)
{									// 合并的驱动
	if (H1 == nullptr)
	{
		return H2;
	}
	else if (H2 == nullptr)
	{
		return H1;
	}
	else if (H1->_data < H2->_data)
	{
		return Merge1(H1, H2);//H1作为头// 根节点最小的作为之后总的左式堆的头
	}
	else
		return Merge1(H2, H1);
}

//template <class T>
void Leftist::Insert_Node(const int & data)
{
	Heap_Node * tmpcell = new Heap_Node(data);
	header = Merge2(header, tmpcell);
}

//template <class T>
void Pre_Traversal(Heap_Node* _header,char c)
{
	//_header = header;
	if (_header == nullptr)
	{
		return;
	}
	else
	{
		std::cout << c <<": "<<_header->_data << std::endl;
		Pre_Traversal(_header->Left_Next,'l');
		Pre_Traversal(_header->Right_Next,'R');
	}
}
//template <class T>
Heap_Node * Leftist::Get_header()
{
	return header;
}
int main()
{
	Leftist L1;
	Leftist L2;
	int data1[8] = { 3,10,8,21,14,17,23,26 };
	int data2[8] = { 6,12,7,18,24,37,18,33 };
	for (int i = 0; i < 8; ++i)
	{
		L1.Insert_Node(data1[i]);
	}
	for (int i = 0; i < 8; ++i)
	{
		L2.Insert_Node(data2[i]);
	}
	Pre_Traversal(L1.Get_header(),'r');
	std::cout << std::endl;
	Pre_Traversal(L2.Get_header(),'r');
	std::cout << std::endl;
	Heap_Node * tempcell = Merge2(L1.Get_header(), L2.Get_header());
	Pre_Traversal(tempcell,'r');
	return 0;
}


