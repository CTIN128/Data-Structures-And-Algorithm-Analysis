/*
 *Splay Tree ��AVLTree�򵥵����죬Ŀ�ľ�����Ӧ�����������Ȳ��ҵ�һ������
 *�´ζ�������ݿ��ܲ��ҵĻ����Σ����Ծͽ��õ�ŵ����ڵ㴦����Ȼ��������ô��Ҫ
 *�õ�AVLTree�е�rotation����ʱ������ά��ƽ����ǽ��ض��Ľڵ�һ��һ��ص���root����
 *���Գ������������һ��zig-zag���Σ�֮�����Σ���ʱ�õ�����˫��ת����һ����zig-zig��һ�֣�
 *��ʱ�õ����ǵ���ת������Ŀ�Rotation_Tree����
 */

#include <iostream>



template <class T>
class TreeNode
{
public:
	TreeNode * Left_Next;
	TreeNode * Right_Next;
	T _data;
	TreeNode(){}
	TreeNode(const T & data):_data(data),Left_Next(nullptr),Right_Next(nullptr){}
	~TreeNode(){}
};
template <class T>
class Splay_Tree
{
private:
public:
	TreeNode<T> * Insert(const T & data, TreeNode<T>*  header);
	TreeNode<T> * Find(const T & data, TreeNode<T>*  header);
	TreeNode<T> * Rotation_Tree(const TreeNode<T> *tmpcell, TreeNode<T>*  header);
	static TreeNode<T> * LeftLeftRotation(TreeNode<T>* );
	static TreeNode<T> * LeftRightRotation(TreeNode<T>* );
	static TreeNode<T> * RightLeftRotation(TreeNode<T>* );
	static TreeNode<T> * RightRightRotation(TreeNode<T>* );
	static void Pre_Traversal(TreeNode<T>* & header);
};
template <class T>
void Splay_Tree<T>::Pre_Traversal(TreeNode<T>* & header)
{
	if (header == nullptr)
	{
		return;
	}
	std::cout << header->_data << std::endl;
	Pre_Traversal(header->Left_Next);
	Pre_Traversal(header->Right_Next);
}

template <class T>
TreeNode<T> * Splay_Tree<T>::Rotation_Tree(const TreeNode<T> * tmpcell, TreeNode<T> *  header)
{
	if (tmpcell->_data < header->_data)
	{
		header->Left_Next = Rotation_Tree(tmpcell, header->Left_Next);
	    if (header->Left_Next == tmpcell)
	    {
		    header = LeftLeftRotation(header);
	    }
		else if (header->Left_Next->Left_Next == tmpcell)
		{
			header = LeftLeftRotation(header->Left_Next);
		}
		else if (header->Left_Next->Right_Next == tmpcell)
		{
			header = LeftRightRotation(header);
		}
	}
	else if (tmpcell->_data > header->_data)
	{
		header->Right_Next = Rotation_Tree(tmpcell, header->Right_Next);
		if (header->Right_Next == tmpcell)
		{
			header = RightRightRotation(header);
		}
		else if (header->Right_Next->Right_Next == tmpcell)
		{
			header = RightRightRotation(header->Right_Next);
		}
		else if (header->Right_Next->Left_Next == tmpcell)
		{
			header = RightLeftRotation(header);
		}
	}
	else {}//����һ����ͬ�����ݽڵ㲻��������������һ�����ж�������ǲ���Ҫ����ĵ�
	return header;
}
template <class T>
TreeNode<T> * Splay_Tree<T>::Find(const T & data, TreeNode<T>* header)
{
	if (header == nullptr)
	{
		std::cerr << "not find this data" << std::endl;
	}
	else if (data < header->_data)
	{
	    return Find(data,header->Left_Next);
	}
	else if (data > header->_data)
	{
		return Find(data,header->Right_Next);
	}
	return header;
}
template<class T>
TreeNode<T> * Splay_Tree<T>::LeftLeftRotation(TreeNode<T>* k2)
{
	TreeNode<T> * k1 = k2->Left_Next;
	k2->Left_Next = k1->Right_Next;
	k1->Right_Next = k2;
	return k1;
}

template<class T>
TreeNode<T> * Splay_Tree<T>::LeftRightRotation(TreeNode<T>* k2)
{
	k2->Left_Next = RightRightRotation(k2->Left_Next);
	return LeftLeftRotation(k2);
}

template<class T>
TreeNode<T> * Splay_Tree<T>::RightLeftRotation(TreeNode<T>* k2)
{
	k2->Right_Next = LeftLeftRotation(k2->Right_Next);
	return RightRightRotation(k2);
}

template<class T>
TreeNode<T> * Splay_Tree<T>::RightRightRotation(TreeNode<T>* k2)
{
	TreeNode<T> * k1 = k2->Right_Next;
	k2->Right_Next = k1->Left_Next;
	k1->Left_Next = k2;
	return k1;
}

template<class T>
TreeNode<T> * Splay_Tree<T>::Insert(const T & data,TreeNode<T>* header)
{
	if (header == nullptr)
	{
		header = new TreeNode<T>(data);
		return header;
	}
	else if (data < header->_data)
	{
		//std::cout << "Left_hello" << std::endl;
		header->Left_Next = Insert(data, header->Left_Next);
	}
	else if (data > header->_data)
	{
		//std::cout << "Right_hello" << std::endl;
		header->Right_Next = Insert(data, header->Right_Next);
	}
	else{}
	return header;
}

int main()
{
	Splay_Tree<int> ST;
	TreeNode<int> * header = nullptr;
	header = ST.Insert(5, header);//���ַ������ǰ����ĸ�����
	header = ST.Insert(8, header);
	header = ST.Insert(9, header);
	header = ST.Insert(6, header);
	header = ST.Insert(7, header);
	header = ST.Insert(3, header);
	ST.Pre_Traversal(header);
	TreeNode<int> * tmpcell;
	tmpcell = ST.Find(7,header);
	header = ST.Rotation_Tree(tmpcell, header);
	std::cout << std::endl;
	ST.Pre_Traversal(header);
}