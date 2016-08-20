/* LL_Rotation:  k2节点的左子树的左子树还有一个节点，导致k2左子树的
 *               高度比右子树的高度大于2
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

/* RR_Rotation:  k2节点的右子树的右子树还有一个节点，导致k2右子树的
*                高度比左子树的高度大于2
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
 @对于LL和RR情况插入一个数会对这个数的上上层产生影响
 @两个函数的参数都是不平衡的节点指针
 @
*/


/*
 *LR情况下先进行RR旋转再进行LL旋转
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
 *RL情况下先进行RR旋转再进行LL旋转
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


