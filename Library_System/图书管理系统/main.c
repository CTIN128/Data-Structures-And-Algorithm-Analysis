#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct book
{
int judge;//��insert�����й���judge ==1������Ѿ������==�������������û���
long num;
char name[10];
char wri_name[10];
char sort_name[10];
char edi_name[15];
long edi_date;
double price;
struct book*next;
}book;
void menu()
{
        printf("����������Ҫ�Ĺ��ܱ��:\n");
        printf("(1)¼��ͼ��\n");
        printf("(2)�������ͼ����Ϣ\n");
        printf("(3)��ѯͼ��\n");
        printf("(4)ͼ����Ϣ���޸�\n");
        printf("(5)ͼ����Ϣ��ɾ��\n");
        printf("����������Ĺ��ܱ�ţ�\n");
}
struct book*create(int m)
{
    struct book*head=NULL,*p,*pp;//ǧ�������head�ĳ�ʼ��
    int i=1;
    for(;i<=m;i++)
    {
        p=(struct book*)malloc(sizeof(struct book));
        if(head==NULL)
        {
            pp=head=p;
        }
        else{
          pp->next=p;
          pp=p;
        }
    }
    pp->next=NULL;
    return head;
}
int find_c(struct book*head,char name[])
{
    struct book*find=head;
    while(find->num!=-1&&find->next!=NULL)
    {
        if(strcmp(find->name,name)==0)
        {
           return 1;
        }
       find=find->next;
    }
     return 0;
}
struct book*change(struct book*head,char name[])
{
    struct book*q=(struct book*)malloc(sizeof(struct book));
    puts("�������¼�ţ�������������������ţ����浥λ������ʱ�䣬�۸��Իس�������");
    scanf("%ld%s%s%s%s%ld%lf",&q->num,q->name,q->wri_name,q->sort_name,q->edi_name,&q->edi_date,&q->price);
    struct book*find=head;
    while(find->num!=-1&&find->next!=NULL)
    {
        if(strcmp(find->name,name)==0)
        {
        find->num=q->num;
        strcpy(find->name,q->name);//ע�⣡������������
        strcpy(find->wri_name,q->wri_name);
        strcpy(find->edi_name,q->edi_name);
        strcpy(find->sort_name,q->sort_name);
        find->edi_date=q->edi_date;
        find->price=q->price;
        printf("�޸ĳɹ�������\n");
        menu();
        return head;
        }
       find=find->next;
    }
        printf("��ͼ�鲻���ڣ��������������\n");
        menu();
     return head;
}
struct book*insert(struct book*head,int n)//��ȡ��ͼ����Ϣ�䵽һ��txt�ļ���
{
    struct book*p=head;
    struct book*q=(struct book*)malloc(sizeof(struct book));
    printf("�������¼�ţ�������������������ţ����浥λ������ʱ�䣬�۸��Իس�������\n");
    while(n!=0&&p->next!=NULL)
    {
    scanf("%ld%s%s%s%s%ld%lf",&q->num,q->name,q->wri_name,q->sort_name,q->edi_name,&q->edi_date,&q->price);
    FILE*g = fopen("C:\\Users\\Administrator.2013-20160214QT\\Desktop\\data.txt","w");
    fprintf(g,"%ld%s%s%s%s%ld%lf",q->num,q->name,q->wri_name,q->sort_name,q->edi_name,q->edi_date,q->price);


   // printf("%d\n",head->judge);//���ε���1û����
    if(head->judge==1)
    {
    //puts("ok");//û����
    if(find_c(head,q->name))
    {//������Ƿ��ظ�¼��
      printf("�����Ѿ������������,�Ƿ���Ѵ����鼮�����޸ģ�\n");
      int a;
      puts("1����Ҫ�����޸�");
      puts("0���������޸�");
      scanf("%d",&a);
      if(a==1)
      {
          head=change(head,q->name);//�Ѿ�������ͼ���޸ĵĺ���,Ҫ����HEAD������
          return head;
      }
      if(a==0)
      {
           n=n-1;
           if(n==0){
           menu();
          return head;
          }
          else{
          head=insert(head,n);
          return head;
          }
      }
    }
    else{
    while(p->num!=-1)
    {
        p=p->next;
    }
    }
    }
    //puts("ok1");
        n--;
        p->num=q->num;
        strcpy(p->name,q->name);//ע�⣡������������
        strcpy(p->wri_name,q->wri_name);
        strcpy(p->edi_name,q->edi_name);
        strcpy(p->sort_name,q->sort_name);
        p->edi_date=q->edi_date;
        p->price=q->price;
        p=p->next;
    }
    p->num=-1;
    head->judge=1;
    printf("¼��ͼ��ɹ�������\n");
    menu();
    return head;
}
void print(struct book*head)
{
    struct book*p=NULL;
    p=head;
    puts("��¼��\t ����\t������\t �����\t   ���浥λ     ����ʱ��   �۸�");
    while(p!=NULL&&p->num!=-1)
    {
        printf("%ld  %s  %s   %s  %s   %ld   %.2lf\n\n",p->num,p->name,p->edi_name,p->sort_name,p->edi_name,p->edi_date,p->price);
        p=p->next;
    }
    printf("�������ͼ�����!\n");
    menu();
}
void find_bn(struct book*head)
{
    struct book *p=head;
    printf("������ͼ�����Խ�������\n");
    char bookname[10];
    scanf("%s",bookname);
    while(p->next!=NULL&&p->num!=-1)
    {
        if(strcmp(p->name,bookname)==0)
        {
            printf("��ͼ����ڣ���Ϣ���£�\n");
            puts("��¼��\t ����\t������\t �����\t   ���浥λ     ����ʱ��   �۸�");
            printf("%ld  %s  %s   %s  %s   %ld   %.2lf\n\n",p->num,p->name,p->edi_name,p->sort_name,p->edi_name,p->edi_date,p->price);
            menu();
            return;
        }
        p=p->next;
    }
    puts("��ͼ�鲻����!\n");
    menu();
    return ;
}
void find_wn(struct book*head)
{
    struct book *p=head;
    printf("�������������Խ�������\n");
    char writer_name[10];
    struct book *wr[100];
    scanf("%s",writer_name);
    int i=0;
    while(p->next!=NULL&&p->num!=-1)
    {
        if(strcmp(p->wri_name,writer_name)==0)
        {
               wr[i++]=p;
        }
        p=p->next;
    }
    if(i==0){puts("�����߲�����!\n");
    menu();
    return;}
    else{puts("���ߵ��鼮���£�\n");
    puts("��¼��   ����   ������   �����   ���浥λ   ����ʱ��          �۸�");
    int j=0;
    for(;j<=i-1;j++){
          printf("%ld  %s  %s  %s  %s  %ld  %lf\n",wr[j]->num,wr[j]->name,wr[j]->wri_name,wr[j]->sort_name,wr[j]->edi_name,wr[j]->edi_date,wr[j]->price);
    }
    menu();
    return ;
}
}
struct book*cut(struct book*head,char name[])
{
 struct book*find=head,*c=NULL,*cc=NULL;
 if(strcmp(head->name,name)==0){
 head=head->next;
 puts("ɾ��ͼ����Ϣ�ɹ�������");
 menu();
 return head;}
 else{
 while(find->next!=NULL&&find->num!=-1)
 {

     if(strcmp(find->name,name)==0)
     {
         c=find;
         break;
     }
     cc=find;
     find=find->next;
 }
 cc->next=c->next;
 free(c);
 puts("ɾ��ͼ����Ϣ�ɹ�������");
 menu();
 return head;
 }
}


int main()
{
   printf("��ӭ����XXX��ͼ����Ϣ����ϵͳ\n");
   printf("���ܱ�����£�\n");
   menu();

   int m;
   struct book*head;

   head=create(99999);//����99999Ԫ�صĿյ�����

   while(scanf("%d",&m)!=EOF)
   {

       if(m==1)
       {
          printf("���ѽ���¼��ͼ�鹦��,������Ҫ¼��ͼ������,���Իس�������\n");
          int nn;
          scanf("%d",&nn);
          head=insert(head,nn);//���������������Ϣ

       }
       else if (m==2)
       {
          printf("���ѽ������ͼ����Ϣ����,ͼ����Ϣ���£�\n");
          print(head);
       }
       else if(m==3)
       {
         printf("���ѽ���ͼ���ѯ����,��ѡ��ͼ������ѯ������������ѯ\n");
         printf("(1)ͼ������ѯ\n");
         printf("(2)��������ѯ\n");
         int n;
         scanf("%d",&n);
         if(n==1)
         {
              printf("���ѽ���ͼ������ѯ����,������ͼ����,���Իس�������\n");
              find_bn(head);
         }
       else if(n==2)
         {
               printf("���ѽ�����������ѯ����,������������,���Իس�������\n");
               find_wn(head);
         }
       }
       else if(m==4)
       {
           printf("���ѽ���ͼ�����Ϣ�޸Ĺ���,������Ҫ�޸ĵ�ͼ����,���Իس�������\n");
           char bookname[10];
           scanf("%s",bookname);
           head=change(head,bookname);

       }
       else if (m==5)
       {
           printf("���ѽ���ͼ�����Ϣɾ������,������Ҫɾ����ͼ����,���Իس�������\n");
           char book_name[10];
           scanf("%s",book_name);
           head=cut(head,book_name);

       }
   }

    return 0;
}
