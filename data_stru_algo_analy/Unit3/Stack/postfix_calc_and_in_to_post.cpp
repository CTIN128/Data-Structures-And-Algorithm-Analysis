
/*原理:
 *
 *建立一个栈，然后利用栈将中缀表达式转换成
 *后缀表达式，然后配上计算类即可做成一个简单计算器
 *
 */



#include <iostream>
#include <cmath>
#include <sstream>

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
	system("cls");
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

/*calculate with postfix and stack
 *
 *
 *
 */
class Calculate
{
private:
	Stack<double> stack;
	void enter(double num);//将操作数num压入栈
	bool gettwooper(double& oper1, double& oper2);
	//连续将两个操作数弹出栈
	void compute(char op);//执行由操作符op指定的运算
public:
	void run(const string &);//运行计算器程序
	void clear();//清空操作数栈
	const double & getanswer() const
	{
		return stack.peek();
	}
};
void Calculate::enter(double num)
{
	stack.push(num);
}
bool Calculate::gettwooper(double & oper1, double & oper2)
{
	if (stack.gethead() != NULL&&stack.gethead()->getnext() != NULL)
	{
		oper1 = stack.pop();//得到的数反而是最后输入的
		oper2 = stack.pop();
		return true;
	}
	return false;
}//连续将两个操作数弹出栈
void Calculate::compute(char op)
{
	//cout << op << endl;
	double oper1, oper2;
	bool result = gettwooper(oper1, oper2);
	//cout << result << endl;
	if (result)
	{
		switch (op)
		{
		case '+':
			stack.push(oper2 + oper1);

			break;
		case '-':
			stack.push(oper2 - oper1);

			break;
		case '*':
			stack.push(oper2*oper1);

			break;
		case '/':
			if (oper1 == 0)
			{
				cout << "Divided by 0!" << endl;
				stack.clear();
			}
			else
			{
				stack.push(oper2 / oper1);

			}
			break;
		case '^':
			stack.push(pow(oper2, oper1));
			break;
		default:
			cout << "none data" << endl;
			break;
		}
	}
	else
	{
		cout << "none data" << endl;
		stack.clear();
	}
}
inline double stringtodouble(const string & str)
{
	istringstream stream(str);
	double result;
	stream >> result;
	return result;
}

void Calculate::run(const string & str)//先往栈压入两个数再进行计算
{
	if (str != "q") 
	{
		for (int i = 0; i < str.sizea(); ++i)
		{
			//cout << str[i] << endl;
			switch (str[i])
			{
			case 'c':
				stack.clear();
				break;
			case '-':
				if (str.size() > 1)
				{
					string str1;
					str1 += str[i];
					enter(stringtodouble(str1));
				}
				else
					compute(str[i]);
				break;
			case'+':
			case'*':
			case'/':
			case'^':
				compute(str[i]);
				break;
			default:
				string str1;
				str1 += str[i];
				//cout << stringtodouble(str1) << endl;
				enter(stringtodouble(str1));
				break;
			}
		}
	}

}
void Calculate::clear()
{
	stack.clear();
}





/*
 *
 *          use stack try to transform infix to postfix
 *
 */

const string transform(string & str)
{
	Stack<char> stack;
	string result;
	for (int i = 0; i < str.size(); ++i)
	{
		
		switch (str[i])
		{
		case '+':
			//cout << "hello" << endl;
			if (stack.gethead() != NULL) 
			{
				if (stack.peek() == '*' || stack.peek() == '/')/*发现他之后的是‘*’所以将他之后的东西全部弹出但不包括‘)’*/
				{
					//cout << "hello if" << endl;
					node<char> * ptr = stack.gethead();
					while (ptr != nullptr && ptr->getdata() != '(')
					{
						result += stack.pop();
						ptr = stack.gethead();
					}
				}
			}
			stack.push(str[i]);//再把+号压入栈中
			//cout << "ok" << str[i]<< endl;
			break;
		case '-':
		{
			if (stack.peek() == '*' || stack.peek() == '/')
			{
				node<char> * ptr = stack.gethead();
				while (ptr != nullptr)
				{
					result += stack.pop();
				}
			}
			stack.push(str[i]);
			//cout << "ok" << str[i] << endl;
			break;
		}
		case '*':
			stack.push(str[i]);
			//cout << "ok" << str[i] << endl;
			break;
		case '/':
			stack.push(str[i]);
			//cout << "ok" << str[i] << endl;
			break;
		case'(':
			stack.push(str[i]);
			//cout << "ok" << str[i] << endl;
			break;
		case ')':
		{
			node<char> * ptr = stack.gethead();
			while (ptr != nullptr)
			{
				char curr_str = stack.pop();
				if (curr_str != '(' && curr_str != ')')
				{
					result += curr_str;
					ptr = stack.gethead();
				}
				if (curr_str == '(')
				{
					break;
				}
			}
			break;
		}
		default:
			result += str[i];
			//cout << "ok" << str[i] << endl;
			break;
		}	
	}
	node<char> * ptr = stack.gethead();
	while (ptr != nullptr)
	{
		result += stack.pop();
		ptr = stack.gethead();
	}
	return result;
}
int main()
{
	Calculate c;
	string expression;
	cin >> expression;
	c.run(transform(expression));
	cout << c.getanswer() << endl;
	return 0;
}
