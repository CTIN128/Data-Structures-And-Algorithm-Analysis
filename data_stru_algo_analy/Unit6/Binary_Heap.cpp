#include <iostream>

template <class T>
class Binary_Heap
{
private:
	T * _data;
	int Heap_Size;
	int Capacity;
public:
	Binary_Heap(const int & Size);
	void Insert(const T & element);
	T DeleteMin();
	void Traversal()
	{
		for (int i = 1; i <= Heap_Size; ++i)
		{
			std::cout << _data[i] << std::endl;
		}
	}
};

template <class T>
Binary_Heap<T>::Binary_Heap(const int & Size)
{
	_data = new T[Size];
	memset(_data, 0, Size);
	Heap_Size = 0;
	Capacity = Size;
}

template <class T>
void Binary_Heap<T>::Insert(const T & element)
{
	int i;
	for (i = ++Heap_Size; _data[i/2] >= element; i /= 2)//иобк
	{
		_data[i] = _data[i / 2];
	}
	_data[i] = element;
}
template <class T>
T Binary_Heap<T>::DeleteMin()
{
	int child,i,mindata = _data[1],lastdata = _data[Heap_Size--];
	for (i = 1; i * 2 <= Heap_Size; i = child)
	{
		child = i * 2;
		if (_data[child] > _data[child + 1])
		{
			child++;
		}
		if (lastdata > _data[child])
		{
			_data[i] = _data[child];
		}
		else
			break;
	}
	_data[i] = lastdata;
	return mindata;
}


int main()
{
	Binary_Heap<int> BH(10);
	BH.Insert(4);
	BH.Insert(6);
	BH.Insert(10);
	BH.Insert(20);
	BH.Insert(5);
	BH.Insert(7);
	BH.Insert(1);
	for (int i = 0; i <= 4; ++i) {
		std::cout << BH.DeleteMin() << std::endl;
	}
	//BH.Traversal() ;
}

