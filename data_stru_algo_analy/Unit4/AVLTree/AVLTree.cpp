#include "AVLTree.h"

int main()
{
	AVLTree<int> a;
	AVLTree_Node<int> * header = a.Get_Header();
	header = a.Insert(37,header);
	header = a.Insert(49, header);
	header = a.Insert(7, header);
	header = a.Insert(71, header);
	header = a.Insert(5, header);
	header = a.Insert(9, header);
	header = a.Insert(10, header);
	header = a.Insert(8, header);
	header = a.Insert(72, header);
	a.Pre_Traversal(header);
}