#include <iostream>

/*leetcode 116  填充每一个节点的下一个右侧节点指针
解题思路：将每一层相邻节点从左到右串联起来，二叉树问题的精髓就是：如何把题目的要求细化成每个节点需要左的事情
解题细节：当感觉问题无法利用二叉树的三种遍历方法，无法细化成单个节点做的事情时，就可以考虑将问题变成多个节点一起做的事情。
        1、可以通过子函数的形式，将一个节点的事情，细分为多个节点的事情
        2、在单个节点的函数中，递归除外的process中增加多个节点需要做的事情。

方法1:1、利用子函数的形式，将单个节点的遍历处理，细分为两个节点之间做的事情，总共只做三件事情，将node1的左右子树串联，node2左右子树串联，node1右子树串联node2左子树
     2、不利用子函数的形式，在单个节点中进行递归遍历处理，将方法1中的三个步骤在递归的process中处理，利用前序遍历（只能用前序遍历）
     3、非递归的方法，就是先处理第一二层，然后，每两层一个组合，进行纵向和横向的递归处理。
     4、利用BFS层序遍历的方法，进行处理，但是无法使用常量级的空间------------------待续
*/

/*1、方法一：子函数处理，单节点遍历问题细分为两个节点问题*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode* connect(TreeNode* root) {
        if (root == NULL)
            return NULL;
        connectTwoNode(root->left, root->right);

        return root;
    }
    void connectTwoNode(TreeNode *node1, TreeNode *node2){
            if(node1 == NULL || node2 == NULL)
                return;
            node1->next = node2;
            connectTwoNode(node1->left, node1->right);
            connectTwoNode(node2->left, node2->right);
            connectTwoNode(node1->right, node2->left);
        return;
    }
};

/*方法二：仍然是单节点递归，但是将左的事情放在process中，利用前序遍历*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode* connect(TreeNode* root) {
        if (root == NULL || root->left == NULL) //需要判断root->left为空的情况，没有左节点，循环直接结束
            return root;    // 这里需要注意，需要返回root
        root->left->next = root->right;
        if (root->next){
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);
        return root;
    }
};

/*方法三：利用非递归的方法，将问题变为两层树之间的问题，进行for循环，横向遍历完成，再进行纵向遍历 牛逼的写法！！*/
/*二叉树的时间复炸度未知，还不会算*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode* connect(TreeNode* root) {
        if (root == NULL || root->left == NULL) //需要判断root->left为空的情况，没有左节点，循环直接结束
            return root;    // 这里需要注意，需要返回root
        root->left->next = root->right;
        TreeNode *pre = root->left;
        TreeNode *cur = root->left->left;
        while (cur){
            while(pre){
                pre->left->next = pre->right;
                if (pre->next)
                    pre->right->next = pre->next->left;
                pre = pre->next;
            }
            pre = cur;
            cur = cur->left;
        }

        return root;
    }
};