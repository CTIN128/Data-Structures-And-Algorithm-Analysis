#pragma once
#include <iostream>
template <class T>
class AVLTree_Node
{
	
public:
	using AVLTree_Ptr = AVLTree_Node<T> *;
	int _height;//旋转对高度做了处理
	AVLTree_Ptr Left_Next;
	AVLTree_Ptr Right_Next;
	T _data;
	AVLTree_Node(T data) :_data(data), Left_Next(nullptr), Right_Next(nullptr),_height(0) {};

};

template <class T>
class AVLTree
{
	using AVLTree_Ptr = AVLTree_Node<T> *;
private:
	AVLTree_Node<T> * header;
public:
	AVLTree() {}
	~AVLTree() {}
	AVLTree_Node<T> * Insert(const T & data, AVLTree_Node<T> * &header);
	AVLTree_Node<T> * Delete(const T & data, AVLTree_Node<T> * &header);
	AVLTree_Node<T> * Findmin(AVLTree_Node<T> * header = nullptr);
	AVLTree_Node<T> * Findmax(AVLTree_Node<T> * header = nullptr);
	AVLTree_Node<T> * Find(const T & data, AVLTree_Node<T> * header = nullptr);
	static int height(AVLTree_Node<T> * header = nullptr);
	static AVLTree_Node<T> * LeftLeftRotation(AVLTree_Node<T> * k2);
	static AVLTree_Node<T> * LeftRightRotation(AVLTree_Node<T> * k2);
	static AVLTree_Node<T> * RightLeftRotation(AVLTree_Node<T> * k2);
	static AVLTree_Node<T> * RightRightRotation(AVLTree_Node<T> * k2);
	static void Pre_Traversal(AVLTree_Node<T> * header);
	AVLTree_Node<T> * Get_Header()
	{
		return header;
	}
	
};

template <class T>
void AVLTree<T>:: Pre_Traversal(AVLTree_Node<T> * header)
{
	if (header == nullptr)
	{
		return;
	}
	std::cout << header->_data <<":" << header->_height<< std::endl;
	Pre_Traversal(header->Left_Next);
	Pre_Traversal(header->Right_Next);
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::LeftLeftRotation(AVLTree_Node<T> * k2)
{
	AVLTree_Node<T> * k1 = k2->Left_Next;
	k2->Left_Next = k1->Right_Next;
	k1->Right_Next = k2;

	k2->_height = max2(height(k2->Left_Next), height(k2->Right_Next)) + 1;//这里对高度做了处理
	k1->_height = max2(height(k1->Left_Next), k2->_height) + 1;
	return k1;
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::RightRightRotation(AVLTree_Node<T> * k2)
{
	AVLTree_Node<T> * k1 = k2->Right_Next;
	k2->Right_Next = k1->Left_Next;
	k1->Left_Next = k2;

	k2->_height = max2(height(k2->Left_Next), height(k2->Right_Next)) + 1;
	k1->_height = max2(height(k1->Left_Next), k2->_height) + 1;
	return k1;
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::RightLeftRotation(AVLTree_Node<T> * k2)
{
	/*algo1:
	*/
	/*AVLTree<T> * k1 = k2->Right_Next;
	AVLTree<T> * k3 = k1->Left_Next;
	k2->Right_Next = k3->Left_Next;
	k1->Left_Next = k3->Right_Next;
	k3->Left_Next = k2;
	k3->Right_Next = k1;

	k2->_height = max2(height(k2->Left_Next), height(k2->Right_Next)) + 1;
	k1->_height = max2(height(k1->Left_Next), height(k1->Right_Next)) + 1;
	k3->_height = max2(k1->_height, k2->_height);
	return k3;*/

	/*algo2:
	*/
	k2->Right_Next = LeftLeftRotation(k2->Right_Next);
	return RightRightRotation(k2);
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::LeftRightRotation(AVLTree_Node<T> * k2)
{
	/*algo1:
	*/
	/*AVLTree<T> * k1 = k2->Left_Next;
	AVLTree<T> * k3 = k1->Right_Next;
	k2->Left_Next = k3->Right_Next;
	k1->Right_Next = k3->Left_Next;
	k3->Left_Next = k1;
	k3->Right_Next = k2;

	k2->_height = max2(height(k2->Left_Next), height(k2->Right_Next)) + 1;
	k1->_height = max2(height(k1->Left_Next), height(k1->Right_Next)) + 1;
	k3->_height = max2(k1->_height, k2->_height);
	return k3;*/

	/*algo2:
	*/
	k2->Left_Next = RightRightRotation(k2->Left_Next);
	return RightRightRotation(k2);
}

static int max2(int a, int b)
{
	return a > b ? a : b;
}

template <class T>
int AVLTree<T>::height(AVLTree_Node<T> * header = nullptr)
{
	if (header == nullptr)
		return -1;//规定空树的高度为-1
	else
	{
		return header->_height;
	}
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::Findmin(AVLTree_Node<T> * header = nullptr)//recursively
{
	if (header == nullptr)
	{
		return nullptr;    
	}
	else if(header->Left_Next == nullptr)//越往左边数越小
	{
		return header;//都返回给上一个挂起的Findmin函数
	}
	else
	{
		return Findmin(header->left);
	}
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::Findmax(AVLTree_Node<T> * header = nullptr)//gernally
{
	if (header == nullptr)
	{
		return nullptr;
	}
	else
	{
		AVLTree_Node<T> * tmpcell = header;
		while (tmpcell->Right_Next != nullptr)//越往右走数越大
		{
			tmpcell = tmpcell->Right_Next;
		}
		return tmpcell;
	}
}

template<class T>
AVLTree_Node<T> * AVLTree<T>::Find(const T & data, AVLTree_Node<T> * header = nullptr)
{
	if (header == nullptr)
	{
		return nullptr;
	}
	else
	{
		if(data < header->_data)
			return Find(header->Left_Next);
		else if(data > header > _data)
		{
			return Find(header->Right_Next);
		}
		else//find it
			return header;//也是返回给上一个挂起的函数
	}
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::Insert(const T & data, AVLTree_Node<T>* & header)
{
	if(header == nullptr)
	{
		header = new AVLTree_Node<T>(data);
		return header;//返回给上一个挂起的Insert函数
	}
	else if(data < header->_data)//表示要插入左边
	{
		header->Left_Next = Insert(data, header->Left_Next);
		if (height(header->Left_Next) - height(header->Right_Next) == 2)//一层一层返回判断左右子树是否平衡
		{
			std::cout << height(header->Left_Next) << height(header->Right_Next) << std::endl;
			if(data < header->Left_Next->_data)
				header = LeftLeftRotation(header);
			else
				header = LeftRightRotation(header);
		}
	}
	else if(data > header->_data)
	{
		header->Right_Next = Insert(data, header->Right_Next);
		if (height(header->Right_Next) - height(header->Left_Next) == 2)
		{
	    	if (data > header->Right_Next->_data)
			{
				header = RightRightRotation(header);//任何旋转都必须将头节点返回让整棵树都是联通的
			}
			else
				header = RightLeftRotation(header);
		}
	}
	else{}

	header->_height = max2(height(header->Right_Next), height(header->Left_Next)) + 1;
	return header;
}

template <class T>
AVLTree_Node<T> * AVLTree<T>::Delete(const T & data, AVLTree_Node<T> * &header)
{
	if (header == nullptr)
	{
		std::cerr << "Not Find data" << std::endl;
	}
	else if (data < header->_data)
	{
		header->Left_Next = Delete(data, header->Left_Next);
		if (height(header->Right_Next) - height(header->Left_Next) == 2)
		{
			AVLTree_Node<T> * rightptr = header->Right_Next;
			if (height(rightptr->Left_Next) > height(rightptr->Right_Next))
			{
				header = RightLeftRotation(header);	
			}
			else
				header = RightRightRotation(header);
		}
	}
	else if (data > header->_data)
	{
		header->Right_Next = Delete(data, header->Right_Next);
		if (height(header->Left_Next) - height(header->Right_Next) == 2)
		{
			AVLTree_Node<T> * leftptr = header->Left_Next;
			if (height(leftptr->Left_Next) < height(leftptr->Right_Next))
			{
				header = LeftRightRotation(header);//旋转后把节点返回
				//看双层出现在有问题节点的哪个方向就调用哪个旋转
			}
			else
				header = LeftLeftRotation(header)
		}
	}

	//find data and two children 
	else if (header->Left_Next && header->Right_Next)
	{
		T temp_data = Findmin(header->Right_Next);
		header->_data = temp_data;
		header->Right_Next = Delete(temp_data, header->Right_Next);
	}
	//one or zero children
	else
	{
		AVLTree_Node<T> * tmpptr = header;
		if (header->Left_Next == nullptr)//only one child
		{
			header = header->Right_Next;
		}
		else if (header->Right_Next == nullptr)//only one child
		{
			header = header->Left_Next;
		}
		delete tmpptr;
	}
	return header;
}
