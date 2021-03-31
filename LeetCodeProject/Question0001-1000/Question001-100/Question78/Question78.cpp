#include"Question78.h"
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> t;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                t.push_back(nums[i]);
            }
        }
        result.push_back(t);
    }
    return result;
}
int main()
{
    /*
    给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：
输入：nums = [0]
输出：[[],[0]]
提示：
1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同


    */
    vector<int> vec = { 1,2,3 };
    vector<vector<int>> res = subsets(vec);
    for each (auto var1 in res)
    {
        for each (auto var2 in var1)
        {
            cout << var2 << " ";
        }
        cout << endl;
    }
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}