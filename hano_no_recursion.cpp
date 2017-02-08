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
  if(n%2 == 0)//顺偶ABC
  {
    t[1].name = 'b';
    t[2].name = 'c';
  }
  else//逆奇ABC
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
  int i = 0;//用来判断其他两根柱子情况 i+1和i-1
  int k = 0;//次数
  while(k < max)
  {
    int temp = t[i%3].top();//取余用来循环
    t[i%3].pop();
    t[(i+1)%3].push(temp);
    std::cout << t[i%3].name << " -> " << t[(i+1)%3].name << std::endl;
    ++i;
    ++k;//将最小的即为编号为1的盘顺时针移动到下一个柱子
    if(k < max)
    {
      if(t[(i+1)%3].top() == 0||t[(i-1)%3].top() != 0&&t[(i-1)%3].top() < 
                                                        t[(i+1)%3].top())//如果i+1柱子为空或者i+1和i-1都不为空但是i-1最上
                                                                         //面的盘的编号比i+1最上面的编号小将i-1盘移动到i+1
      {
        int temp = t[(i-1)%3].top();
        t[(i-1)%3].pop();
        t[(i+1)%3].push(temp);
        std::cout << t[(i-1)%3].name << " -> " << t[(i+1)%3].name << std::endl;
        ++k;
      }
      else//i-1为空
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
}//reference：http://blog.minidx.com/2008/01/30/457.html
