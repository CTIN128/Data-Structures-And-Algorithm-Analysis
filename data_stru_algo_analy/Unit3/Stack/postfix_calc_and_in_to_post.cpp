
/*ԭ��:
 *
 *����һ��ջ��Ȼ������ջ����׺���ʽת����
 *��׺���ʽ��Ȼ�����ϼ����༴������һ���򵥼�����
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
	system("cls");
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

/*calculate with postfix and stack
 *
 *
 *
 */
class Calculate
{
private:
	Stack<double> stack;
	void enter(double num);//��������numѹ��ջ
	bool gettwooper(double& oper1, double& oper2);
	//��������������������ջ
	void compute(char op);//ִ���ɲ�����opָ��������
public:
	void run(const string &);//���м���������
	void clear();//��ղ�����ջ
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
		oper1 = stack.pop();//�õ�������������������
		oper2 = stack.pop();
		return true;
	}
	return false;
}//��������������������ջ
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

void Calculate::run(const string & str)//����ջѹ���������ٽ��м���
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
				if (stack.peek() == '*' || stack.peek() == '/')/*������֮����ǡ�*�����Խ���֮��Ķ���ȫ����������������)��*/
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
			stack.push(str[i]);//�ٰ�+��ѹ��ջ��
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
