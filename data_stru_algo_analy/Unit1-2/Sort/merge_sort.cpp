#include <stdlib.h>
#include <stdio.h>

void meger(int a[],int b[],int sta_index,int mid_index,int end_index)//001 223 013
{
  //要么就两个数传入交换，要么就多个数比如像传入4个 sta:0 mid：1 end:3
  //传入两个数让mid+1指向后一个数，多个数的时候让mid+1指向一半的那个数
  //k如传入223这种那么a[k]就是这两个数中第一个数，不同传入的值不同，所以要让k随着sta_index变化//不跟随可设成静态变量也可
  int i = sta_index,j = mid_index+1,k = sta_index;
  while(i <= mid_index&&j <= end_index)//判断此时i或者j读取的是在适当的范围内
  {
     if(a[i] <= a[j])
     {
       b[k++] = a[i++];
     }
     else
     {
       b[k++] = a[j++];
     }
  }
  while(i <= mid_index)//判断某一方超出范围，把剩余一方数据全部输入到数组中
  {
      b[k++] = a[i++];
  }
  while(j <= end_index+1)
  {
      b[k++] = a[j++];
  }
  for(int i = sta_index;i <= end_index;++i)
  {
      a[i] = b[i];
  }
}
void meger_divide(int a[],int b[],int sta_index,int end_index)
{
   if(sta_index < end_index)//相等就表明分到只剩一个数
   {
      int mid_index = (sta_index + end_index)/2;
      meger_divide(a,b,sta_index,mid_index);
      meger_divide(a,b,mid_index+1,end_index);
      meger(a,b,sta_index,mid_index,end_index);//此时的start_index要跟随着变化
                                              //相当于后序遍历，不会时看看二叉树的后续遍历的原理
   }
}
int main(int argc, char * argv[])
{
   int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
   int i, b[8];
   meger_divide(a, b, 0, 7);
   for(i=0; i<8; i++)
     printf("%d ", a[i]);
   printf("\n");
   return 0;
}