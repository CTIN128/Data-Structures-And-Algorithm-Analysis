#include <stdlib.h>
#include <stdio.h>

void meger(int a[],int b[],int sta_index,int mid_index,int end_index)//001 223 013
{
  //Ҫô�����������뽻����Ҫô�Ͷ������������4�� sta:0 mid��1 end:3
  //������������mid+1ָ���һ�������������ʱ����mid+1ָ��һ����Ǹ���
  //k�紫��223������ôa[k]�������������е�һ��������ͬ�����ֵ��ͬ������Ҫ��k����sta_index�仯//���������ɾ�̬����Ҳ��
  int i = sta_index,j = mid_index+1,k = sta_index;
  while(i <= mid_index&&j <= end_index)//�жϴ�ʱi����j��ȡ�������ʵ��ķ�Χ��
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
  while(i <= mid_index)//�ж�ĳһ��������Χ����ʣ��һ������ȫ�����뵽������
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
   if(sta_index < end_index)//��Ⱦͱ����ֵ�ֻʣһ����
   {
      int mid_index = (sta_index + end_index)/2;
      meger_divide(a,b,sta_index,mid_index);
      meger_divide(a,b,mid_index+1,end_index);
      meger(a,b,sta_index,mid_index,end_index);//��ʱ��start_indexҪ�����ű仯
                                              //�൱�ں������������ʱ�����������ĺ���������ԭ��
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