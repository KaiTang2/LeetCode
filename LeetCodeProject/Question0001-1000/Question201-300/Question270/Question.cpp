﻿/*
270. 最接近的二叉搜索树值
给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。

注意：

给定的目标值 target 是一个浮点数
题目保证在该二叉搜索树中只会存在一个最接近目标值的数
示例：

输入: root = [4,2,5,1,3]，目标值 target = 3.714286

    4
   / \
  2   5
 / \
1   3

输出: 4

*/
#include"Question.h"
int closestValue(TreeNode* root, double target) {
    int val;
    int res = root->val;
    while (root != nullptr)
    {
        val = root->val;
        res = abs(val - target) < abs(res - target) ? val : res;
        root = target < val ? root->left : root->right;
    }
    return res;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    cout << closestValue(root, 3.3) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}