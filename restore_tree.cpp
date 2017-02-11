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
TreeNode* BuildTree(std::string s1,std::string s2)//s1,s2为前和中
{
   char c = s1[0];
   if(s1.size() == 2 && s2.size() == 2)//如果就两个字母
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
   std::map<char,int> m;//确定了中序然后判断前序
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
     std::vector<TreeNode*> vec; // 这里我们使用STL 中的vector来代替数组，可利用到其动态扩展的属性
     vec.push_back(root);
     int cur = 0;
     int last = 1;
     int level = 0;
     while(cur < vec.size()) 
     {
          last = vec.size(); // 新的一行访问开始，重新定位last于当前行最后一个节点的下一个位置
          while(cur < last) 
          {
               if(vec[cur] -> left) // 当前访问节点的左节点不为空则压入
                   vec.push_back(vec[cur] -> left);
               if(vec[cur] -> right) // 当前访问节点的右节点不为空则压入，注意左右节点的访问顺序不能颠倒
                   vec.push_back(vec[cur] -> right);
               cur++;
          }
          level++;// 当cur == last时,说明该层访问结束，输出换行符
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