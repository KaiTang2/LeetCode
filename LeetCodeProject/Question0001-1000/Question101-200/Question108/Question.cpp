#include"Question.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
TreeNode* makeTree(TreeNode* root, vector<int>& nums, int min, int max)
{
    if (min > max)
    {
        return nullptr;
    }
    int mid = (max + min + 1) / 2;
    root = new TreeNode(nums[mid]);
    root->left = makeTree(root->left, nums, min, mid - 1);
    root->right = makeTree(root->right, nums, mid + 1, max);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* res = nullptr;
    res = makeTree(res, nums, 0, nums.size() - 1);
    return res;
}

int main()
{
    /*
    

    */
    vector<int> val = { -10,-3,0,5,9 };
    TreeNode* res = sortedArrayToBST(val);

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}