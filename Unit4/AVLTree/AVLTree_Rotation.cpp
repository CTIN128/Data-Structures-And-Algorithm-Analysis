/* LL_Rotation:  k2�ڵ��������������������һ���ڵ㣬����k2��������
 *               �߶ȱ��������ĸ߶ȴ���2
 *
 */

/*template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
	AVLTreeNode<T> * k1 = k2->left_next;
	k2->left_next = k1->right_next;
	k1->right_next = k2;

	k2->height = max(height(k2->left_next), height(k2->right_next)) + 1;// post height is a function
	k1->height = max(k2->height, height(k1->left_next)) + 1;
	return k1;
}*/

/* RR_Rotation:  k2�ڵ��������������������һ���ڵ㣬����k2��������
*                �߶ȱ��������ĸ߶ȴ���2
*
*/
/*
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightrightRotation(AVLTreeNode<T>* k2)
{
	AVLTreeNode<T> * k1 = k2->right_next;
	k2->right_next = k1->left_next;
	k1->left_next = k2;

	k2->height = max(height(k2->left_next), height(k2->right_next)) + 1;// post height is a function
	k1->height = max(k2->height, height(k1->right_next)) + 1;
	return k1;
}
*/

/*
 @
 @����LL��RR�������һ�����������������ϲ����Ӱ��
 @���������Ĳ������ǲ�ƽ��Ľڵ�ָ��
 @
*/


/*
 *LR������Ƚ���RR��ת�ٽ���LL��ת
 *
*/

/*
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightleftRotation(AVLTreeNode<T>* k3)
{
	k3->left_next = rightrightrotation(k3->left);
	return leftleftrotation(k3);
}
*/
/*
 *RL������Ƚ���RR��ת�ٽ���LL��ת
 *
 */

/*
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftrightRotation(AVLTreeNode<T>* k3)
{
  k3->right_next = leftleftrotation(k3->left);
  return rightrightrotation(k3);
}
*/


