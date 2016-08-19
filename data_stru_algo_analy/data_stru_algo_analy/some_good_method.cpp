//Tree * Insert(element_data, root)
//{
//	if (root == nullptr)
//	{
//		root = new node;
//		root->data = element_data;
//		root->left_next = root->right_next = nullptr;
//	}
//	else if (element_data < root->data)
//	{
//		root->left_next = Insert(element_data, root->left_next);//每次root->left_next都会被更新直到
//	}                                                           //最后一个节点，他之后的left_next为空所以
//	                                                            //执行创建新的节点，并把这个节点指针返回给最后节点的left_next
//	else if (element_data > root->data)
//	{
//		root->right_next = Insert(element_data, root->right);
//	}
//	return root;
//}


//Tree * Delete(element_data,root)
// {
//	Tree * tempcell;
//	if (root == nullptr)
//		cerr << "element not find" << endl;
//	else if (root->data > element_data)
//	{
//		root->left = Delete(element_data, root->left);
//	}
//	else if (root->data < element_data)
//	{
//		root->right = Delete(element_data, root->right);
//	}
//
//	/*find element_data*/
//	else if(root->left && root->right) //two children
//	{
//		tempcell = findmin(root->right);                //look for the min data of right tree                                       
//		root->data = tempcell->data;                    // why do we look for the data in right tree? we shoulde find
//		root->right = Delete(element_data, root->right);//a number so that left tree always < this number and right tree always > this number
//	}
//	else//one or zero children 
//	{
//		tempcell = root;
//		if (root->left)
//		{
//			root = root->left;
//		}
//		else if(root->right)
//		{
//			root = root->right;
//		}
//		delete tempcell;
//	}
//	return root;
//
//
// }






