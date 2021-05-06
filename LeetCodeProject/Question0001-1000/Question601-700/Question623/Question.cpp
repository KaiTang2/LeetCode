/*
给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。

添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。

将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。

如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。

示例 1:

输入:
二叉树如下所示:
       4
     /   \
    2     6
   / \   /
  3   1 5

v = 1

d = 2

输出:
       4
      / \
     1   1
    /     \
   2       6
  / \     /
 3   1   5

示例 2:

输入:
二叉树如下所示:
      4
     /
    2
   / \
  3   1

v = 1

d = 3

输出:
      4
     /
    2
   / \
  1   1
 /     \
3       1
注意:

输入的深度值 d 的范围是：[1，二叉树最大深度 + 1]。
输入的二叉树至少有一个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-one-row-to-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<queue>
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1)
    {
        TreeNode* res = new TreeNode(val, root, nullptr);
        return res;
    }
    queue<TreeNode*> dp;
    dp.push(root);
    int de = 2;
    while (!dp.empty())
    {
        if (de == depth)
        {
            int len = dp.size();
            for (int i = 0; i < len; ++i)
            {
                TreeNode* nodeL = new TreeNode(val, dp.front()->left, nullptr);
                dp.front()->left = nodeL;
                TreeNode* nodeR = new TreeNode(val, nullptr, dp.front()->right);
                dp.front()->right = nodeR;
                dp.pop();
            }
            break;
        }
        else
        {
            int len = dp.size();
            for (int i = 0; i < len; ++i)
            {
                if (dp.front()->left != nullptr)
                {
                    dp.push(dp.front()->left);
                }
                if (dp.front()->right != nullptr)
                {
                    dp.push(dp.front()->right);
                }
                dp.pop();
            }
            ++de;
        }
    }
    return root;
}
int main()
{

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}