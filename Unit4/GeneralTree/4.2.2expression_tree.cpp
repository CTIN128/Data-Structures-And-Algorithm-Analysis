#include <iostream>
#include <string>

using namespace std;
template <class T>
class node
{
private:
	T data;
	node *next;
public:
	node(const T& item, node*next = NULL) :data(item), next(next) {}
	T getdata() const//���������ӿ�
	{
		return data;
	}
	node* getnext() const
	{
		return next;
	}
};

template <class T>
class Stack
{
private:
	node<T> *head;
public:
	Stack();//��ʼ��ջ
	void push(const T & item);//��Ԫ��ѹ��ջ
	T pop();//��ջ��Ԫ�ص���ջ
	void clear();//���ջ
	const T& peek() const;//����ջ��Ԫ��
	bool isempty() const;//�ж��Ƿ�Ϊ��
	node<T> *gethead();//����һ���ӿ�
	void print() const       //traver_stack
	{
		node<T> * ptr = head;
		if (ptr == nullptr)
		{
			cout << "null" << endl;
			return;
		}
		while (ptr != nullptr)
		{
			cout << ptr->getdata() << endl;
			ptr = ptr->getnext();
		}
		return;
	}
};

template<class T>
node<T> *Stack<T>::gethead()
{
	return head;
}
template<class T>
Stack<T>::Stack() :head(NULL) {}
//��ʼ��ջ
template<class T>
void Stack<T>::push(const T & item)
{
	if (head == NULL)
	{
		head = new node<T>(item);
	}
	else
	{
		node<T> *Newnode = new node<T>(item, head);
		head = Newnode;
	}
}
//��Ԫ��ѹ��ջ
template<class T>
T Stack<T>::pop()
{
	node<T> *temp = head;
	T item = temp->getdata();
	head = temp->getnext();
	delete temp;
	return item;
}
//��ջ��Ԫ�ص���ջ
template <class T>
void Stack<T>::clear()
{
	head = NULL;
}
//���ջ
template <class T>
const T & Stack<T>::peek() const
{
	return head->getdata();
}
//����ջ��Ԫ��
template <class T>
bool Stack<T>::isempty() const
{
	return (head == NULL);
}//�ж��Ƿ�Ϊ��

template <class T>
class Tree
{
	using Tree_Ptr = Tree *;
private:
	Tree_Ptr Left_Next;
	Tree_Ptr Right_Next;
	T _data;
	Stack<Tree<char>*> stack;
public:
	Tree(T data) :_data(data), Left_Next(nullptr), Right_Next(nullptr) {};
	Tree() {}
	void Create_Tree(const string & str);
	void Post_Traversal( Tree_Ptr ptr)
	{
		if (ptr == nullptr)
			return;
		Post_Traversal(ptr->Left_Next);
		Post_Traversal(ptr->Right_Next);
		std::cout << ptr->_data;
	}
	 Tree_Ptr getpeek() const
	{
		 //cout << "hellopeek" << endl;
		return stack.peek();
	}
};
template <class T>
 void Tree<T>::Create_Tree(const string & str)//����ջѹ���������ٽ��м���
 {
 		for (int i = 0; i < str.size(); ++i)
 		{
 			//cout << str[i] << endl;
 			switch (str[i])
 			{
 			case'-':
 			case'+':
 			case'*':
 			case'/':
			{
				Tree_Ptr root = new Tree<char>(str[i]);
				root->Right_Next = stack.pop();
				root->Left_Next = stack.pop();
				stack.push(root);
				break;
			}
 			default:
				Tree_Ptr node = new Tree<char>(str[i]);
				stack.push(node);
				break;
 			}
 		}
 }

 int main()
 {
	 string a;
	 cin >> a;
	 Tree<char>T; 
	 T.Create_Tree(a);
	 Tree<char> * ptr = T.getpeek();
	 T.Post_Traversal(ptr);
 }