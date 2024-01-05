//
//  tree.cpp
//  Algorithm
//
//  Created by marco on 2019/7/24.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "tree.hpp"
#include <cmath>
#include <algorithm>

/*
 树的三种遍历
 线索二叉树
 
 排序二叉树、平衡二叉树
 哈夫曼树
 
 树和森林的转换
 并查集
 
 树的存储
 1.双亲表示法：一个{data,parent}的数组，根节点aparent为-1
 2.孩子表示法：每个结点的孩子节点都用单链表链接起来
 3.孩子兄弟表示法（二叉树表示法，以二叉链表作为树的存储结构）：每个结点包括结点值、指向第一个孩子的指针和指向下一个兄弟的指针
 
 树、森林与二叉树的转换
 树转二叉树：每个节点左指针指向第一个海子节点，右指针指向它的相邻兄弟结点，即左子右兄。
 森林转二叉树：每棵树先转二叉树，再把第一棵树的根作为转换后的二叉树的根，第一棵树的左子树作为二叉树的左子树，右子树作为左子树的右子树，第二棵树作为右子树，第三棵作为转换后二叉树的右子树的右子树。
 二叉转森林：若二叉树非空，则二叉树根及左子树为第一棵树的二叉树，二叉树的右子树看做一个由除第一棵树外的森林转换后的二叉树。。。直至最后产生一棵没有右子树的二叉树为止。
 */

//Balanced Binary Tree (是否是平衡二叉树)
//LeetCode 110
bool SolutionTree::isBalance(TreeNode *tree)
{
    if (tree == NULL) {
        return true;
    }
    int left = maxDepth(tree->left);
    int right = maxDepth(tree->right);
    if (abs(left-right)>1) {
        return false;
    }else{
        return isBalance(tree->left)&&isBalance(tree->right);
    }
}



//LeetCode 104
//Maximum Depth of Binary Tree (二叉树的深度)
int SolutionTree::maxDepth(TreeNode *tree){
    if (!tree) {
        return 0;
    }
    int left = maxDepth(tree->left);
    int right = maxDepth(tree->right);
    return 1+(left>right?left:right);
}

//LeetCode 226
//Invert Binary Tree (反转二叉树)
TreeNode* SolutionTree::invertTree(TreeNode* root) {
    if (!root) {
        return NULL;
    }
    
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

//Symmetric Tree （是否是镜像树）
//LeetCode 101
//当比较的结点不在一个node上时c，参数要分成左右两个子node
bool checkLeftAndRightNodes(TreeNode *leftNode, TreeNode *rightNode);

bool SolutionTree::isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return false;
    }
    return checkLeftAndRightNodes(root->left, root->right);
}

bool checkLeftAndRightNodes(TreeNode *leftNode, TreeNode *rightNode){
    if (rightNode == NULL && rightNode == NULL) {
        return true;
    }
    if (rightNode == NULL || leftNode == NULL) {
        return false;
    }
    if (rightNode->val==leftNode->val) {
        return checkLeftAndRightNodes(leftNode->right,rightNode->left)&&
        checkLeftAndRightNodes(leftNode->left,rightNode->right);
    }else{
        return false;
    }
}

//Is Same Tree (树是否相等)
//LeetCode 100
bool SolutionTree::isSameTree(TreeNode* p,TreeNode* q){
    if (p==NULL && q==NULL) {
        return true;
    }
    if (p==NULL || q==NULL) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }else{
        return isSameTree(p->left, q->left)&&
        isSameTree(p->right, q->right);
    }
}
