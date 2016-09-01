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
	T getdata() const//定义两个接口
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
	Stack();//初始化栈
	void push(const T & item);//将元素压入栈
	T pop();//将栈顶元素弹出栈
	void clear();//清空栈
	const T& peek() const;//访问栈顶元素
	bool isempty() const;//判断是否为空
	node<T> *gethead();//定义一个接口
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
//初始化栈
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
//将元素压入栈
template<class T>
T Stack<T>::pop()
{
	node<T> *temp = head;
	T item = temp->getdata();
	head = temp->getnext();
	delete temp;
	return item;
}
//将栈顶元素弹出栈
template <class T>
void Stack<T>::clear()
{
	head = NULL;
}
//清空栈
template <class T>
const T & Stack<T>::peek() const
{
	return head->getdata();
}
//访问栈顶元素
template <class T>
bool Stack<T>::isempty() const
{
	return (head == NULL);
}//判断是否为空

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
 void Tree<T>::Create_Tree(const string & str)//先往栈压入两个数再进行计算
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