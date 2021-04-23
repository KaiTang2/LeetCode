/*
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。

 

示例 1：

输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案。
示例 2：

输入：nums = [1,2,4,8]
输出：[1,2,4,8]
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
nums 中的所有整数 互不相同


*/
#include"Question.h"
#include<algorithm>
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(len, 1);
    int maxValue = 0;
    int maxSize = 1;
    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] % nums[j] == 0)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > maxSize)
        {
            maxValue = nums[i];
            maxSize = dp[i];
        }
    }
    vector<int> res;
    if (maxSize == 1)
    {
        return { nums[0] };
    }
    for (int i = len - 1; i >= 0 && maxSize > 0; --i)
    {
        if (dp[i] == maxSize && maxValue % nums[i] == 0)
        {
            res.push_back(nums[i]);
            maxValue = nums[i];
            --maxSize;

        }
    }
    return res;
}
int main()
{
    vector<int> nums = { 1,2,4,8 };
    nums = largestDivisibleSubset(nums);
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}