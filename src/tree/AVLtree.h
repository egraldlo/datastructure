/*
 * AVLtree.h
 *
 *      Author: casa
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <iostream>
using namespace std;
#include <malloc.h>

/*
 * AVL树是平衡二叉树，这棵树的两个枝叶之间的高度差不可能是大于等于2
 * 难点在旋转（旋转的时候按照形态来旋转会很好理解）：
 * 1，左旋   : 插入一个新节点到根节点的左子树的左子树，根节点的平衡因子从1变为2
 *   此时左旋直接动根节点
 * 2，右旋   : 插入一个新节点到根节点的右子树的右子树，根节点的平衡因子从-1变为-2
 *   此时右旋直接动根节点
 * 3，先左后右：插入一个新节点到根节点的左子树的右子树，根节点的平衡因子从1变为2
 *   此时先将根节点的左孩子左旋，再将根节点右旋
 * 4，先右后左
 *   此时先将根节点的右孩子右旋，再将根节点左旋
 * */
template <class TA>
class AVLtree {
public:
	template <typename TTA>
	struct tree_node{
		TTA value;
		struct tree_node *left;
		struct tree_node *right;
		int height;
	};

	int height(tree_node<TA> *root){
		if(root==0)
			return 1;
		else
			return root->height;
	}

	int Max(int left,int right){
		if(left>right)
			return left;
		else
			return right;
	}
public:
	AVLtree(){}
	virtual ~AVLtree(){};

	void Build(TA &value){
		cout<<"build the avl tree with the value: "<<value<<endl;
		root=(tree_node<TA>*)malloc(sizeof(tree_node<TA>));
		root->value=value;
		root->left=0;
		root->right=0;
		root->height=1;
	};

	void Print(tree_node<TA> *root){
		if(root->left!=0){
			Print(root->left);
		}
		cout<<"node: "<<root->value<<endl<<endl;
		if(root->right!=0){
			Print(root->right);
		}
	};

	void Insert(TA &value,tree_node<TA> * &root){
		if(root==0){
			/*遍历到最后一层的时候开始插入*/
			tree_node<TA> *new_node=(tree_node<TA>*)malloc(sizeof(tree_node<TA>));
			new_node->left=0;
			new_node->right=0;
			new_node->height=1;
			new_node->value=value;
			root=new_node;
		}
		else if(value<root->value){
			/*如果是比根节点的value小，就插入到左子树*/
			Insert(value,root->left);
			/*插入完毕之后比较左子树和右子树的差距，如果变为2，就旋转*/
			if(height(root->left)-height(root->right)==2){
				if(value<root->left->value){
					root=Rrotate(root);
				}
				else{
					root=LRrotate(root);
				}
			}
		}
		else{
			Insert(value,root->right);
			if(height(root->right)-height(root->left)==2){
				if(value>root->right->value){
					root=Lrotate(root);
				}
				else{
					root=RLrotate(root);
				}
			}
		}
		root->height=Max(height(root->left),height(root->right))+1;
	};

	void Delete(TA &value,tree_node<TA> * &root){
		if(root==0)
			return;
		if(value==root->value){
			if(root->left&&root->right){
				/* todo: to be completed!
				 * has two children*/

			}
			else{
				if(root->left){
					root=root->left;
				}
				else if(root->right){
					root=root->right;
				}
				else{
					delete(root);
					root=0;
				}
			}
		}
		else if(value<root->value){
			Delete(value,root->left);
			/*after deleting the left of the root*/
			if(height(root->right)-height(root->left)==2){
				/*you can remember the two cases when deleting*/
				if(root->right->left!=0&&(height(root->right->left)>height(root->right->right))){
					root=LRrotate(root);
				}
				else{
					root=Lrotate(root);
				}
			}
		}
		else{
			Delete(value,root->right);
			if(height(root->left)-height(root->right)==2){
				/*you can remember the two cases when deleting*/
				if(root->left->right!=0&&(height(root->left->right)>height(root->left->left))){
					root=LRrotate(root);
				}
			}
		}
	};

	tree_node<TA> * Lrotate(tree_node<TA> * root){
		tree_node<TA> *tmp=root->right;
		root->right=tmp->left;
		tmp->left=root;
		/*'root' first rotate, and next the 'tmp'*/
		root->height=Max(height(root->left),height(root->right));
		cout<<"rotate: "<<root->height<<"value: "<<root->value<<endl;
		tmp->height=Max(height(tmp->left),height(tmp->right));
		cout<<"rotate: "<<tmp->height<<"value: "<<tmp->value<<endl;
		return tmp;
	};

	tree_node<TA> * Rrotate(tree_node<TA> * root){
		tree_node<TA> *tmp=root->left;
		root->left=tmp->right;
		tmp->right=root;
		cout<<"++++"<<endl;
		/*'root' first rotate, and next the 'tmp'*/
		root->height=Max(height(root->left),height(root->right));
		cout<<"rotate: "<<root->height<<"value: "<<root->value<<endl;
		tmp->height=Max(height(tmp->left),height(tmp->right));
		cout<<"rotate: "<<tmp->height<<"value: "<<tmp->value<<endl;
		return tmp;
	};

	tree_node<TA> * RLrotate(tree_node<TA> * root){
		root->right=Rrotate(root->right);
		return Lrotate(root);
	};

	tree_node<TA> * LRrotate(tree_node<TA> * root){
		root->left=Lrotate(root->left);
		return Rrotate(root);
	};

//private:
	tree_node<TA> *root;
};

#endif /* AVLTREE_H_ */
