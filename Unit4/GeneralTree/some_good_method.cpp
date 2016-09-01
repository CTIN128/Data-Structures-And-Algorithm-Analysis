tree * insert(element_data, root)
{
	if (root == nullptr)
	{
		root = new node;
		root->data = element_data;
		root->left_next = root->right_next = nullptr;
	}
	else if (element_data < root->data)
	{
		root->left_next = insert(element_data, root->left_next);//ÿ��root->left_next���ᱻ����ֱ��
	}                                                           //���һ���ڵ㣬��֮���left_nextΪ������
	                                                            //ִ�д����µĽڵ㣬��������ڵ�ָ�뷵�ظ����ڵ��left_next
	else if (element_data > root->data)
	{
		root->right_next = insert(element_data, root->right);
	}
	return root;
}


tree * delete(element_data,root)
 {
	tree * tempcell;
	if (root == nullptr)
		cerr << "element not find" << endl;
	else if (root->data > element_data)
	{
		root->left = delete(element_data, root->left);
	}
	else if (root->data < element_data)
	{
		root->right = delete(element_data, root->right);
	}

	/*find element_data*/
	else if(root->left && root->right) //two children
	{
		tempcell = findmin(root->right);                //look for the min data of right tree                                       
		root->data = tempcell->data;                    // why do we look for the data in right tree? we shoulde find
		root->right = delete(element_data, root->right);//a number so that left tree always < this number and right tree always > this number
	}
	else//one or zero children 
	{
		tempcell = root;
		if (root->left)
		{
			root = root->left;
		}
		else if(root->right)
		{
			root = root->right;
		}
		delete tempcell;
	}
	return root;


 }






