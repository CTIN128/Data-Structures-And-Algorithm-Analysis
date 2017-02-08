#include <iostream>

struct towel
{
  int disk[64];
  int Top = -1;
  char name;
  void push(int data)
  {
    disk[++Top] = data;
  }
  void pop()
  {
    Top--;
  }
  int top()
  {
    return disk[Top];
  }
};
void init(int n,towel t[])
{
  for(int i = 0;i < n;++i)
  {
    t[0].push(n-i);
  }
  t[0].name = 'a';
  t[1].push(0);
  t[2].push(0);
  if(n%2 == 0)//˳żABC
  {
    t[1].name = 'b';
    t[2].name = 'c';
  }
  else//����ABC
  {
    t[1].name = 'c';
    t[2].name = 'b';
  }
  return;
}
int Pow(int x,int n)
{
  if(n == 0)
    return 1;
  if(n == 1)
    return x;
  if(n % 2 == 0)
    return Pow(x*x,n/2);
  else
    return Pow(x*x,n/2)*x;
}
void hano(int max,towel t[])
{
  int i = 0;//�����ж���������������� i+1��i-1
  int k = 0;//����
  while(k < max)
  {
    int temp = t[i%3].top();//ȡ������ѭ��
    t[i%3].pop();
    t[(i+1)%3].push(temp);
    std::cout << t[i%3].name << " -> " << t[(i+1)%3].name << std::endl;
    ++i;
    ++k;//����С�ļ�Ϊ���Ϊ1����˳ʱ���ƶ�����һ������
    if(k < max)
    {
      if(t[(i+1)%3].top() == 0||t[(i-1)%3].top() != 0&&t[(i-1)%3].top() < 
                                                        t[(i+1)%3].top())//���i+1����Ϊ�ջ���i+1��i-1����Ϊ�յ���i-1����
                                                                         //����̵ı�ű�i+1������ı��С��i-1���ƶ���i+1
      {
        int temp = t[(i-1)%3].top();
        t[(i-1)%3].pop();
        t[(i+1)%3].push(temp);
        std::cout << t[(i-1)%3].name << " -> " << t[(i+1)%3].name << std::endl;
        ++k;
      }
      else//i-1Ϊ��
      {
        int temp = t[(i+1)%3].top();
        t[(i+1)%3].pop();
        t[(i-1)%3].push(temp);
        std::cout << t[(i+1)%3].name << " -> " << t[(i-1)%3].name << std::endl;
        ++k; 
      }
    }
  }
}
int main()
{
  int m;
  std::cin >> m;
  towel t[3];
  init(m,t);
  hano(Pow(2,m)-1,t);
  return 0;
}