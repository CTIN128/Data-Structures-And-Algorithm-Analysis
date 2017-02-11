#include <iostream>  
#include <vector>  
#include <string>
#include <queue>
#include <map>
struct TreeNode
{
  char data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(char d):data(d),left(nullptr),right(nullptr){}
};
TreeNode* BuildTree(std::string s1,std::string s2)//s1,s2Ϊǰ����
{
   char c = s1[0];
   if(s1.size() == 2 && s2.size() == 2)//�����������ĸ
   {
     TreeNode *root = new TreeNode(c);
     int position = c == s2[0]?0:1;
     if(!position)
       root->right = new TreeNode(s2[1]);
     else
       root->left = new TreeNode(s2[0]);
     return root;
   }
   std::string str1,str2;
   std::string temp;
   std::map<char,int> m;//ȷ��������Ȼ���ж�ǰ��
   int num = 1;
   for(int i = 0;i < s2.size();++i)
   {
    m.insert({s2[i],num});
    if(s2[i] != c)
      temp += s2[i];
    else
    {
        num++;
        str1 = temp;
        temp.clear();
    }
   }
   str2 = temp;
   int i;
   if(m[s1[1]] == 1)
   {
     i = 1;
   }
   else
   {
    i = str2.size()+1;
   }
   std::string strr1(s1.begin()+i,s1.begin()+i+str1.size());
   std::string strr2;
   if(i + str1.size() == s1.size()&&str2.size()!=0)
     strr2 = std::string(s1.begin()+1,s1.begin()+1+str2.size());
   else if(str2.size()!=0)
     strr2 = std::string(s1.begin()+i+str1.size(),s1.end());
   TreeNode *root = new TreeNode(c);
   if(str1.size()!=0)
    root->left = BuildTree(strr1,str1);
   if(str2.size()!=0)
    root->right = BuildTree(strr2,str2);
   return root; 
}
int PrintNodeByLevel(TreeNode* root) {
     std::vector<TreeNode*> vec; // ��������ʹ��STL �е�vector���������飬�����õ��䶯̬��չ������
     vec.push_back(root);
     int cur = 0;
     int last = 1;
     int level = 0;
     while(cur < vec.size()) 
     {
          last = vec.size(); // �µ�һ�з��ʿ�ʼ�����¶�λlast�ڵ�ǰ�����һ���ڵ����һ��λ��
          while(cur < last) 
          {
               if(vec[cur] -> left) // ��ǰ���ʽڵ����ڵ㲻Ϊ����ѹ��
                   vec.push_back(vec[cur] -> left);
               if(vec[cur] -> right) // ��ǰ���ʽڵ���ҽڵ㲻Ϊ����ѹ�룬ע�����ҽڵ�ķ���˳���ܵߵ�
                   vec.push_back(vec[cur] -> right);
               cur++;
          }
          level++;// ��cur == lastʱ,˵���ò���ʽ�����������з�
     }
     return level;
}
int main()
{
  int NodeSize;
  std::cin >> NodeSize;
  if(NodeSize <= 1)
  {
    std::cout << NodeSize;
    return 0;
  }
  std::string s1,s2;
  std::cin >> s1 >> s2;
  TreeNode *root = BuildTree(s1,s2);
  std::cout << PrintNodeByLevel(root);
  return 0;  
}  