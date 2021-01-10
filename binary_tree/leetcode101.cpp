#include <iostream>

/*
leetcode 101 对称二叉树
题目：给定一个二叉树，检查它是否是镜像对称的。
解题思路：对于二叉树的题目，一般就两类大的解法，递归算法和迭代算法。递归算法要点是找到递归点，分解每个节点需要做的事情，如果一个节点分解不鸟，就两个节点。基本的递归方法
        就是三种，前序遍历，中顺遍历，后序遍历。至于迭代算法，就是需要使用循环，找到循环点，其实也是分解要做的事情

方法：1、对称二叉树的判断，就是查看每一层节点的相匹配关系，第一层是，左节点数值是否等于右节点，从第二层开始是左子树左节点是否等于右子树右节点，左子树右节点是否等于右子树
        左节点。第二层的这个递归process可以沿用给下层所有的节点使用，这就找到了递归点。核心是比较两个节点val值，将一个节点问题，转化为两个节点问题。
     2、利用迭代的方法进行处理，可以看出，对称二叉树的每一层其实都是一个回文数组。利用队列的特性进行迭代处理。-----待续
     3、利用BFS算法进行处理
*/

/*方法一：利用递归的方法进行处理，找到递归点。*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return check(root->left, root->right);
    }

    bool check(TreeNode *left, TreeNode *right){
        if (left == NULL && right == NULL)
            return true;
        if (left != NULL && right == NULL)
            return false;
        if (left == NULL && right != NULL)
            return false;
        return (left->val == right->val) & check(left->left, right->right) & check(left->right, right->left);
    }
};

/*方法二：利用迭代法，不用递归的方法，进行处理每一层的内容，相当于层序遍历*/