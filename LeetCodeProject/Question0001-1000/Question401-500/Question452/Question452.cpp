﻿#include"Question452.h"
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    stack<int> right;
    right.push(nums[n - 1]);
    int max = INT_MIN;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < max)
        {
            return true;
        }
        while (!right.empty() && nums[i] > right.top())
        {
            max = right.top();
            right.pop();
        }
        if (nums[i] > max)
        {
            right.push(nums[i]);
        }
    }
    return false;
}
int main()
{
    /*
    给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。

如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。

 

进阶：很容易想到时间复杂度为 O(n^2) 的解决方案，你可以设计一个时间复杂度为 O(n logn) 或 O(n) 的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/132-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

示例 1：

输入：nums = [1,2,3,4]
输出：false
解释：序列中不存在 132 模式的子序列。
示例 2：

输入：nums = [3,1,4,2]
输出：true
解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
示例 3：

输入：nums = [-1,3,2,0]
输出：true
解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
 

提示：

n == nums.length
1 <= n <= 104
-109 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/132-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    */
    vector<int> value = { 9,8,7,6,5,4,3,2,1};
    cout << find132pattern(value)<<endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}