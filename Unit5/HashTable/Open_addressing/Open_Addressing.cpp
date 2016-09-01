#include <iostream>
#include <time.h>



enum class KindOfEntry//�ж�ÿ����ַ��״̬
{
	Legitimate,
	Empty,
	Deleted
};

template <class T>
class HashTable;

template <class T>
class Table_Entry
{
private:
	enum class KindOfEntry TheCell;//����һ��ö�ٱ���
	T _data;
public:
	Table_Entry():TheCell(KindOfEntry::Empty){}
	friend class HashTable<T>;
	Table_Entry(const T & data):_data(data){}
};

template <class T>
class HashTable
{
private:
	Table_Entry<T> * Top_Ptr;
	int Table_Size;
public:
	int Hash_Transform(const T & data) const
	{
		return data % Table_Size;
	}
	HashTable(const int & Size);
	void Insert(const T & data);
	int Find(const T & data) const;
	void Traversal();
};



template <class T>
void HashTable<T>::Traversal()
{
	for (int i = 0; i < Table_Size; ++i)
	{
		if (Top_Ptr[i].TheCell != KindOfEntry::Empty)
			std::cout << Top_Ptr[i]._data << std::endl;
		else
			std::cout << std::endl;
	}
}

template <class T>
HashTable<T>::HashTable(const int & Size) :Table_Size(Size) 
{
	Top_Ptr = new Table_Entry<T>[Size];
	for (int i = 0; i < Size; ++i)
	{
		Top_Ptr[i] = Table_Entry<T>();
	}
}

template <class T>
int HashTable<T>::Find(const T & data) const//Ѱ�Һ��ʵ�λ��
{
	int CurrentPos;
	int Collisionnum = 0;
	CurrentPos = Hash_Transform(data);
	while (Top_Ptr[CurrentPos].TheCell != KindOfEntry::Empty && Top_Ptr[CurrentPos]._data != data)
	{
		//CurrentPos = 7 - (data % 7)-1;
		//CurrentPos += 1;//linear hash
		/*++Collisionnum;
		 CurrentPos +=  (Collisionnum * Collisionnum);*///sequare hash
		//CurrentPos += ++Collisionnum * Hash_Transform(data);//double hash
		if (CurrentPos > Table_Size - 1)
		{
			CurrentPos %= Table_Size;
		}
	}
	return CurrentPos;
}

template <class T>
void HashTable<T>::Insert(const T & data)
{
	int Pos = Find(data);
	if (Top_Ptr[Pos].TheCell != KindOfEntry::Legitimate)//����д���Բ�������ɾ���ĵ�
	{
		Top_Ptr[Pos].TheCell = KindOfEntry::Legitimate;
		Top_Ptr[Pos]._data = data;
	}
}

int main()
{
	HashTable<int> H(10);
	int data[5];
	srand(unsigned(time(0)));
	for (int i = 0; i < 5; ++i)
	{
		data[i] = (rand() % 100 + 1);
	}


	for (auto x : data)
	{
		H.Insert(x);
	}

	H.Traversal();
}