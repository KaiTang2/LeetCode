#include"Question90.h"
#include<algorithm>
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        bool input = true;
        vector<int> t;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
                    input = false;
                    break;
                }
                t.push_back(nums[i]);
            }
        }
        if (input)
        {
            result.push_back(t);
        }
    }
    return result;
}
int main()
{
    /*
    给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
示例 1：
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：
输入：nums = [0]
输出：[[],[0]]

提示：
1 <= nums.length <= 10
-10 <= nums[i] <= 10
    */
    vector<int> vec = { 1,2,2 };
    vector<vector<int>> res = subsetsWithDup(vec);
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