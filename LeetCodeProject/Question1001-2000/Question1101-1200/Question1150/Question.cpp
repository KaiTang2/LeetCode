﻿/*
给出一个按 非递减 顺序排列的数组 nums，和一个目标数值 target。假如数组 nums 中绝大多数元素的数值都等于 target，则返回 True，否则请返回 False。

所谓占绝大多数，是指在长度为 N 的数组中出现必须 超过 N/2 次。

 

示例 1：

输入：nums = [2,4,5,5,5,5,5,6,6], target = 5
输出：true
解释：
数字 5 出现了 5 次，而数组的长度为 9。
所以，5 在数组中占绝大多数，因为 5 次 > 9/2。
示例 2：

输入：nums = [10,100,101,101], target = 101
输出：false
解释：
数字 101 出现了 2 次，而数组的长度是 4。
所以，101 不是 数组占绝大多数的元素，因为 2 次 = 4/2。
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 10^9
1 <= target <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
bool isMajorityElement(vector<int>& nums, int target) {
    int len = nums.size();
    int left = 0, right = len - 1, mid = 0;
    int count = 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            for (int i = mid - 1; i >= 0; i--)
            {
                if (nums[i] == target)
                {
                    ++count;
                }
                else
                {
                    break;
                }
            }
            for (int i = mid + 1; i < len; i++)
            {
                if (nums[i] == target)
                {
                    ++count;
                }
                else
                {
                    break;
                }
            }
            break;
        }
    }
    return count > len / 2;
}
int main()
{
    vector<int> nums = { 1 };
    cout << isMajorityElement(nums, 2)<<endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}