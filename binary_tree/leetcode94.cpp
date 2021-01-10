/*
leetcode94 二叉树的中序遍历  中等难度
解题思路：1、利用递归思想，中序遍历二叉树，分辨输出每个节点值，并将其存入vector，并输出
        2、不使用递归的方法，使用迭代的方法来输出二叉树，这个是本题目的核心算法。

方法：1、利用递归思想进行遍历输出
     2、利用迭代的方法进行输出

*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*方法1：利用中序遍历，进行递归输出*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        go(root, output);
        return output;
    }
    void go(TreeNode *root, vector<int> &output){
        if(root == NULL)
            return;
        go(root->left,output);
        output.push_back(root->val);
        go(root->right,output);
        return;
    }
};


/*方法2：利用迭代的方法，进行输出*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

    }
};
