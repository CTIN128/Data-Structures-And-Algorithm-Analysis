#pragma once
#include <iostream>
enum class Direction/*规定方向是左方向还是右方向*/
{
	left,
	right
};

template <class T>
struct Node
{
public:
	Node() {};
	Node(T data):_data(data),prev_next(nullptr),next_next(nullptr){}//初始化列表很有用
	~Node() {};
	T _data;
	Node * prev_next;
	Node * next_next;
};

template<class T>
class DdLinkedlist//定义一个链表，当初始化对象时，是对对象中的指针做操作
{
public:
	DdLinkedlist():Left_header(nullptr),Right_header(nullptr){};
	~DdLinkedlist() {};
	bool Insert_after(const T & data,Direction dire,int position);
	void Travser_list(Direction position);
	bool Delete_elem(const T & data);
	void Find_elem(const T & data);
private:
	Node<T> * Left_header;
	Node<T> * Right_header;

};

template <class T>
bool DdLinkedlist<T>::Insert_after(const T & data, Direction dire,int position)//在节点后的插入
{
	Node<T> * temp_node = new Node<T>(data);
	if (Left_header == nullptr && Right_header == nullptr)
	{
		Left_header = Right_header = temp_node;
	}//注意特殊情况
	else
	{
		if (dire == Direction::left)
		{

			Node<T> * curr_ptr = Left_header;
			Node<T> * curr_pre_ptr = Left_header;
			while ((position-1) != 0 && curr_ptr != nullptr)
			{
				curr_pre_ptr = curr_ptr;
				curr_ptr = curr_ptr->next_next;
				position--;
			}
			if (curr_ptr == nullptr)
			{
				curr_pre_ptr->next_next = temp_node;
				temp_node->prev_next = curr_pre_ptr;
				Right_header = temp_node;
			}//特殊情况在表尾插入时要更新left_header或者right_header
			else
			{
				temp_node->next_next = curr_ptr->next_next;
				temp_node->prev_next = curr_ptr;
				curr_ptr->next_next->prev_next = temp_node;//注意和下句的先后顺序，一定要注意
				curr_ptr->next_next = temp_node;//
				
			}
		}
		else
		{
			Node<T> * curr_ptr = Right_header;
			Node<T> * curr_pre_ptr = Right_header;
			while ((position - 1) != 0 && curr_ptr != nullptr)
			{
				curr_pre_ptr = curr_ptr;
				curr_ptr = curr_ptr->prev_next;
				position--;
			}
			if (curr_ptr == nullptr)
			{
				curr_pre_ptr->prev_next = temp_node;
				temp_node->next_next = curr_pre_ptr;
				Left_header = temp_node;
			}//特殊情况在表尾插入时要更新left_header或者right_header
			else
			{
				temp_node->next_next = curr_ptr;
				temp_node->prev_next = curr_ptr->prev_next;
				curr_ptr->prev_next->next_next = temp_node;
				curr_ptr->prev_next = temp_node;
			}
		}
	}
	return true;
}
template <class T>
void DdLinkedlist<T>::Travser_list(Direction position)
{
	if (position == Direction::left)
	{
		Node<T> * curr_ptr = Left_header;
		while (curr_ptr != nullptr)
		{
			std::cout << curr_ptr->_data << std::endl;
			curr_ptr = curr_ptr->next_next;
		}
	}
	else
	{
		Node<T> * curr_ptr = Right_header;
		while (curr_ptr != nullptr)
		{
			std::cout << curr_ptr->_data << std::endl;
			curr_ptr = curr_ptr->prev_next;
		}
	}
}

template <class T>
bool DdLinkedlist<T>::Delete_elem(const T & data)
{
	
	if (Left_header->_data == data)
	{
		Node<T> * temp = Left_header->next_next;
		delete Left_header;
		Left_header = temp;
		temp->prev_next = nullptr;
	}
	if (Right_header->_data == data)
	{
		Node<T> * temp = Right_header->prev_next;
		delete Right_header;
		Right_header = temp;
		temp->next_next = nullptr;
	}
	Node<T> * curr_ptr = Left_header->next_next;
	Node<T> * curr_pre_ptr = Left_header;
	while (curr_ptr != nullptr)
	{
		if (curr_ptr->_data == data)
		{
			Node<T> * temp = curr_ptr->next_next;
			curr_pre_ptr->next_next = temp;
			temp->prev_next = curr_pre_ptr;
			delete curr_ptr;
			curr_ptr = curr_pre_ptr;
		}
		curr_pre_ptr = curr_ptr;
		curr_ptr = curr_ptr->next_next;
	}
	return true;
}
template<class T>
void DdLinkedlist<T>::Find_elem(const T & data)
{
	int left_pos = 0,right_pos = 0,find_judge = 0;
	Node<T> * curr_left_ptr = Left_header;
	Node<T> * curr_right_ptr = Right_header;
	while (curr_left_ptr != nullptr)
	{
		if (curr_left_ptr->_data == data)
		{
			std::cout << "from left to right,this data position is"
				<< left_pos << std::endl;
			find_judge = 1;
		}
		left_pos++;
		curr_left_ptr = curr_left_ptr->next_next;
	}

	while (curr_right_ptr != nullptr)
	{
		if (curr_right_ptr->_data == data)
		{
			std::cout << "from right to left,this data position is"
				<< right_pos << std::endl;
			find_judge = 1;
		}
		right_pos++;
		curr_right_ptr = curr_right_ptr->prev_next;
	}
	if (!find_judge)
	{
		std::cout << "not find this data" << std::endl;
	}
}


