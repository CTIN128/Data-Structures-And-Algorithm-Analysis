#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct book
{
int judge;//与insert函数有关若judge ==1则表明已经输过了==其他数则表明还没输过
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
        printf("请输入所需要的功能编号:\n");
        printf("(1)录入图书\n");
        printf("(2)输出所有图书信息\n");
        printf("(3)查询图书\n");
        printf("(4)图书信息的修改\n");
        printf("(5)图书信息的删除\n");
        printf("请输入所需的功能编号：\n");
}
struct book*create(int m)
{
    struct book*head=NULL,*p,*pp;//千万别忘了head的初始化
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
    puts("请输入登录号，书名，作者名，分类号，出版单位，出版时间，价格，以回车键结束");
    scanf("%ld%s%s%s%s%ld%lf",&q->num,q->name,q->wri_name,q->sort_name,q->edi_name,&q->edi_date,&q->price);
    struct book*find=head;
    while(find->num!=-1&&find->next!=NULL)
    {
        if(strcmp(find->name,name)==0)
        {
        find->num=q->num;
        strcpy(find->name,q->name);//注意！！！！！！！
        strcpy(find->wri_name,q->wri_name);
        strcpy(find->edi_name,q->edi_name);
        strcpy(find->sort_name,q->sort_name);
        find->edi_date=q->edi_date;
        find->price=q->price;
        printf("修改成功！！！\n");
        menu();
        return head;
        }
       find=find->next;
    }
        printf("该图书不存在，请检查输入后再试\n");
        menu();
     return head;
}
struct book*insert(struct book*head,int n)//争取把图书信息输到一个txt文件上
{
    struct book*p=head;
    struct book*q=(struct book*)malloc(sizeof(struct book));
    printf("请输入登录号，书名，作者名，分类号，出版单位，出版时间，价格，以回车键结束\n");
    while(n!=0&&p->next!=NULL)
    {
    scanf("%ld%s%s%s%s%ld%lf",&q->num,q->name,q->wri_name,q->sort_name,q->edi_name,&q->edi_date,&q->price);
    FILE*g = fopen("C:\\Users\\Administrator.2013-20160214QT\\Desktop\\data.txt","w");
    fprintf(g,"%ld%s%s%s%s%ld%lf",q->num,q->name,q->wri_name,q->sort_name,q->edi_name,q->edi_date,q->price);


   // printf("%d\n",head->judge);//二次等于1没问题
    if(head->judge==1)
    {
    //puts("ok");//没问题
    if(find_c(head,q->name))
    {//检查书是否重复录入
      printf("此书已经保留在书库中,是否对已存在书籍进行修改？\n");
      int a;
      puts("1代表要进行修改");
      puts("0代表不进行修改");
      scanf("%d",&a);
      if(a==1)
      {
          head=change(head,q->name);//已经定义了图书修改的函数,要返还HEAD！！！
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
        strcpy(p->name,q->name);//注意！！！！！！！
        strcpy(p->wri_name,q->wri_name);
        strcpy(p->edi_name,q->edi_name);
        strcpy(p->sort_name,q->sort_name);
        p->edi_date=q->edi_date;
        p->price=q->price;
        p=p->next;
    }
    p->num=-1;
    head->judge=1;
    printf("录入图书成功！！！\n");
    menu();
    return head;
}
void print(struct book*head)
{
    struct book*p=NULL;
    p=head;
    puts("登录号\t 书名\t作者名\t 分类号\t   出版单位     出版时间   价格");
    while(p!=NULL&&p->num!=-1)
    {
        printf("%ld  %s  %s   %s  %s   %ld   %.2lf\n\n",p->num,p->name,p->edi_name,p->sort_name,p->edi_name,p->edi_date,p->price);
        p=p->next;
    }
    printf("输出所有图书完毕!\n");
    menu();
}
void find_bn(struct book*head)
{
    struct book *p=head;
    printf("请输入图书名以进行搜索\n");
    char bookname[10];
    scanf("%s",bookname);
    while(p->next!=NULL&&p->num!=-1)
    {
        if(strcmp(p->name,bookname)==0)
        {
            printf("该图书存在，信息如下：\n");
            puts("登录号\t 书名\t作者名\t 分类号\t   出版单位     出版时间   价格");
            printf("%ld  %s  %s   %s  %s   %ld   %.2lf\n\n",p->num,p->name,p->edi_name,p->sort_name,p->edi_name,p->edi_date,p->price);
            menu();
            return;
        }
        p=p->next;
    }
    puts("该图书不存在!\n");
    menu();
    return ;
}
void find_wn(struct book*head)
{
    struct book *p=head;
    printf("请输入作者名以进行搜索\n");
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
    if(i==0){puts("该作者不存在!\n");
    menu();
    return;}
    else{puts("作者的书籍如下：\n");
    puts("登录号   书名   作者名   分类号   出版单位   出版时间          价格");
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
 puts("删除图书信息成功！！！");
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
 puts("删除图书信息成功！！！");
 menu();
 return head;
 }
}


int main()
{
   printf("欢迎进入XXX牌图书信息管理系统\n");
   printf("功能编号如下：\n");
   menu();

   int m;
   struct book*head;

   head=create(99999);//做个99999元素的空的链表

   while(scanf("%d",&m)!=EOF)
   {

       if(m==1)
       {
          printf("你已进入录入图书功能,请输入要录入图书数量,并以回车键结束\n");
          int nn;
          scanf("%d",&nn);
          head=insert(head,nn);//往链表里面插入信息

       }
       else if (m==2)
       {
          printf("你已进入输出图书信息功能,图书信息如下：\n");
          print(head);
       }
       else if(m==3)
       {
         printf("你已进入图书查询功能,请选择按图书名查询还是作者名查询\n");
         printf("(1)图书名查询\n");
         printf("(2)作者名查询\n");
         int n;
         scanf("%d",&n);
         if(n==1)
         {
              printf("你已进入图书名查询功能,请输入图书名,并以回车键结束\n");
              find_bn(head);
         }
       else if(n==2)
         {
               printf("你已进入作者名查询功能,请输入作者名,并以回车键结束\n");
               find_wn(head);
         }
       }
       else if(m==4)
       {
           printf("你已进入图书的信息修改功能,请输入要修改的图书名,并以回车键结束\n");
           char bookname[10];
           scanf("%s",bookname);
           head=change(head,bookname);

       }
       else if (m==5)
       {
           printf("你已进入图书的信息删除功能,请输入要删除的图书名,并以回车键结束\n");
           char book_name[10];
           scanf("%s",book_name);
           head=cut(head,book_name);

       }
   }

    return 0;
}
