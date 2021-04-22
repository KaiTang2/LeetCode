/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<algorithm>
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 10000;
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == target)
            {
                return target;
            }
            if (abs(sum - target) < abs(res - target))
            {
                res = sum;
            }
            if (sum > target)
            {
                int r0 = r - 1;
                while (l < r0 && nums[r0] == nums[r])
                {
                    --r0;
                }
                r = r0;
            }
            else
            {
                int l0 = l + 1;
                while (l0 < r && nums[l] == nums[l0])
                {
                    ++l0;
                }
                l = l0;
            }
        }
    }
    return res;

}
int main()
{
    vector<int> nums = { -1,2,1,-4 };
    int target = -1;
    cout << threeSumClosest(nums, target) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}