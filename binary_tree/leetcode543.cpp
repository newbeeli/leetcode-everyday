/*leetcode 543   二叉树的直径
解题思路：求二叉树的直径长度，指二叉树中任意两个节点之间的长度最大值，既两个节点之间节点个数（包括自身） - 1；
        由于没有指明必须穿越根节点，所以二叉树的直径应该是，以任意一个节点为根节点，其左右子树深度(L于R)相加再加1(L+R+1)的最大值
        所以题目就转换为了，遍历二叉树中所有节点，并求每个节点的直径长度，每个节点的直径长度又是每个节点的(L+R+1)，每个节点深度max(L,R) + 1


方法：1、利用DFS，再求二叉树每一层深度的同时，更新对应的每个节点的直径长度，利用局部变量来记录直径长度

*/

/*1、方法一：遍历二叉树节点，求每个节点的深度*/

#include <iostream>
#include <algorithm>

using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diam = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        depth(root);
        return diam - 1;//这里减1是因为，diam指的最长路径上面的节点个数，换算为直径长度就是减一
    }
    int depth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int L = depth(root->left);//求的root节点左子树的深度L
        int R = depth(root->right);//求的root节点右子树的深度R
        diam = max(diam, L + R + 1);//更新最长路径经过的所有节点的数目
        return max(L, R) + 1;//返回深度，以一个节点为根节点的深度为其左子树的深度+右子树的深度+1（深度就是经过的最多节点个数，从上到下，+1为根节点）
    }
};