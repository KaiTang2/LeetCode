/*
给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。

 

示例 1：

输入：nums = [1,2,3,1], k = 3, t = 0
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1, t = 2
输出：true
示例 3：

输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false
 

提示：

0 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 104
0 <= t <= 231 - 1


*/
#include"Question.h"
#include<set>
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int len = nums.size();
    if (len <= 1)
    {
        return false;
    }
    set<int> mp;
    for (int i = 0; i < len; i++)
    {
        auto it = mp.lower_bound(max(nums[i], INT_MIN + t) - t);
        if (it != mp.end() && *it <= min(nums[i], INT_MAX - t) + t)
        {
            return true;
        }
        mp.insert(nums[i]);
        if (i >= k)
        {
            mp.erase(nums[i - k]);
        }
    }
    return false;
}
int main()
{

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}