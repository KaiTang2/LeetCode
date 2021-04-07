#include"Question.h"
#include<string>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
void DFS(TreeNode* root, string path, vector<string>& paths)
{
    if (root == nullptr)
    {
        return;
    }
    path += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        paths.push_back(path);
    }
    else
    {
        path += "->";
        DFS(root->left, path, paths);
        DFS(root->right, path, paths);
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    DFS(root, "", res);
    return res;
}
int main()
{
    /*
    给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

    */

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}