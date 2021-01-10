#include <iostream>

/*leetcode 617  合并二叉树  简单难度
解题思路：合并二叉树，将二叉树相对应位置上的节点相加。

方法：1、通过前序遍历，同时遍历两棵二叉树，相加对应位置
     2、通过中序遍历，同时遍历两棵二叉树，相加对应位置
     2、通过后续遍历，同时遍历两棵二叉树，相加对应位置
*/

/*1、方法一：前序遍历*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL)
            return NULL;
        TreeNode *NewNode = new TreeNode((t1?t1->val:0) + (t2?t2->val:0));
        NewNode->left = mergeTrees(t1?t1->left:NULL, t2?t2->left:NULL);
        NewNode->right = mergeTrees(t1?t1->right:NULL, t2?t2->right:NULL);
        return NewNode;
    }
};

/*2、方法二：中序遍历*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL)
            return NULL;
        TreeNode *Newleft = mergeTrees(t1?t1->left:NULL, t2?t2->left:NULL);
        TreeNode *NewNode = new TreeNode((t1?t1->val:0) + (t2?t2->val:0));
        NewNode->left = Newleft;
        NewNode->right = mergeTrees(t1?t1->right:NULL, t2?t2->right:NULL);
        return NewNode;
    }
};

/*3、方法三：后序遍历*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL)
            return NULL;
        TreeNode *Newleft = mergeTrees(t1?t1->left:NULL, t2?t2->left:NULL);
        TreeNode *Newright = mergeTrees(t1?t1->right:NULL, t2?t2->right:NULL);
        TreeNode *NewNode = new TreeNode((t1?t1->val:0) + (t2?t2->val:0));
        NewNode->left = Newleft;
        NewNode->right = Newright;
        return NewNode;
    }
};