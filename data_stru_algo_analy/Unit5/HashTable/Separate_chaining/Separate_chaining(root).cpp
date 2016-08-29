#include <iostream>

template <class T>
class LinkedList_Node
{
	using List_Ptr = LinkedList_Node *;
public:
	List_Ptr Next;
	T _data;
	LinkedList_Node(const T & data):_data(data),Next(nullptr){}
	LinkedList_Node() :Next(nullptr) {}
	~LinkedList_Node(){}
};
template <class T>
class Hash_Node
{
public:
	LinkedList_Node<T> ** Next;
};

template <class T>
class HashTable
{
private:
	Hash_Node<T> * Top_Ptr;
	int HashTable_Size;
public:
	HashTable(const int & Size);
	int Hash_Calc(const T & data);
	void Insert(const T &);
	LinkedList_Node<T> * Find(const T &);
	void Traversal();
	~HashTable(){}
};
template <class T>
void HashTable<T>::Traversal()
{
	/*if (header == nullptr)
	{
		return;
	}
	LinkedList_Node<T> * tmpcell = header->Next;
	while (tmpcell != nullptr)
	{
		std::cout << tmpcell->_data << " ";
		tmpcell = tmpcell->Next;
	}
	std::cout << std::endl;
	Traversal(header + 1);*/
	Hash_Node<T> * header = Top_Ptr;
	for (int i = 0; i < HashTable_Size; ++i) {
		LinkedList_Node<T> * tmpcell = header->Next[i];
		while (tmpcell != nullptr)
		{
			std::cout << tmpcell->_data << " ";
			tmpcell = tmpcell->Next;
		}
		std::cout << std::endl;
	}
}

template <class T>
int HashTable<T>::Hash_Calc(const T & data)
{
	return data % HashTable_Size;
}

template <class T>
HashTable<T>::HashTable(const int & Size) :HashTable_Size(Size)
{
	Top_Ptr = new Hash_Node<T>();
	Top_Ptr->Next = new LinkedList_Node<T>* [Size];//allocate  HashTable
	for (int i = 0; i < Size; ++i)
	{
		Top_Ptr->Next[i] = new LinkedList_Node<T>();
		//Top_Ptr[i].Next->_data = 5;
	}
}

template <class T>
void HashTable<T>::Insert(const T & data)
{
	LinkedList_Node<T> * tmpcell = Top_Ptr->Next[Hash_Calc(data)];
	LinkedList_Node<T> * newnode = new LinkedList_Node<T>(data);
	newnode->Next = tmpcell->Next;
	tmpcell->Next = newnode;
}

template <class T>
LinkedList_Node<T> * HashTable<T>::Find(const T & data)
{
	LinkedList_Node<T> * tmpcell = Top_Ptr->Next[Hash_Calc(data)];
	while (tmpcell != nullptr)
	{
		if (tmpcell->_data == data) 
		{
			std::cout << "Find it" << std::endl;
			return tmpcell;
		}
		tmpcell = tmpcell->Next;
	}
	std::cerr << "Not find this data" << std::endl;
}


int main()
{
	HashTable<int> H(10);
	H.Insert(5);
	H.Insert(6);
	H.Insert(8);
	H.Insert(7);
	H.Insert(77);
	H.Insert(69);
	H.Insert(99);
	H.Traversal();
	H.Find(5);
}

