#include"Question213.h"
int rob(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    int size = nums.size();
    if (size == 1)
    {
        return nums[0];
    }
    if (size == 2)
    {
        return max(nums[0], nums[1]);
    }
    int f1 = nums[0];
    int f2 = max(nums[0], nums[1]);
    int temp = 0;
    for (int i = 2; i < size - 1; i++)
    {
        temp = f2;
        f2 = max(nums[i] + f1, f2);
        f1 = temp;
    }
    int Max = f2;
    f1 = nums[1];
    f2 = max(nums[1], nums[2]);
    for (int i = 3; i < size; i++)
    {
        temp = f2;
        f2 = max(nums[i] + f1, f2);
        f1 = temp;
    }
    return max(f2, Max);
}int main()
{
    /*
    * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
示例 1：
    输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：
输入：nums = [0]
输出：0
提示：
1 <= nums.length <= 100
0 <= nums[i] <= 1000
    */
    vector<int> vec = { 1,2,1,1 };
    cout << rob(vec) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}