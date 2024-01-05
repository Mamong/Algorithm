//
//  tree.hpp
//  Algorithm
//
//  Created by marco on 2019/7/24.
//  Copyright © 2019 flywire. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

//#include <stdio.h>
#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class SolutionTree
{
public:
    bool isBalance(TreeNode *tree);
    int maxDepth(TreeNode *tree);
    TreeNode* invertTree(TreeNode* root);
    bool isSymmetric(TreeNode* root);
    bool isSameTree(TreeNode* p,TreeNode* q);
    
private:
    int treeDepth(TreeNode *tree);

};

#endif /* tree_hpp */
