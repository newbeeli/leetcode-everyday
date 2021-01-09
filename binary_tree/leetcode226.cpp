#include <iostream>

/*leetcode 226  翻转二叉树
解题思路：翻转二叉树，相当于交换所有节点的左右子树即可。

方法：1、通过前序遍历，遍历二叉树，并交换所有节点的左右子树
     2、通过后续遍历，遍历二叉树，并交换所有节点的左右子树

PS:为什么不能通过中序遍历，因为中序遍历方法，先遍历的左节点，后遍历根节点，再遍历右节点，如果遍历根节点时交换，相当于左节点交换了两次，但是右节点没有进行交换。
*/

/*1、方法一：前序遍历*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *invertTree(TreeNode *root){
        if (root == NULL){
            return NULL;
        }

        TreeNode *tmp_node = root->left;
        root->left = root->right;
        root->right = tmp_node;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

/*2、方法二：后序遍历*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *invertTree(TreeNode *root){
        if (root == NULL)
            return NULL;

        invertTree(root->left);
        invertTree(root->right);

        TreeNode *tmp_node = root->left;
        root->left = root->right;
        root->right = tmp_node;

        return root;
    }
};