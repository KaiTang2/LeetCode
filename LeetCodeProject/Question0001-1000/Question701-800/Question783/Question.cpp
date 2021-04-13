/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

 

示例 1：


输入：root = [4,2,6,1,3]
输出：1
示例 2：


输入：root = [1,0,48,null,null,12,49]
输出：1
 

提示：

树中节点数目在范围 [2, 100] 内
0 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
void CLR(TreeNode* root, int& val, int& res)
{
    if (root == nullptr)
    {
        return;
    }
    CLR(root->left, val, res);
    if (val != -1)
    {
        res = min(res, root->val - val);
    }
    val = root->val;
    CLR(root->right, val, res);
}
int minDiffInBST(TreeNode* root) {
    int res = INT_MAX, val = -1;
    CLR(root, val, res);
    return res;
}
int main()
{

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}