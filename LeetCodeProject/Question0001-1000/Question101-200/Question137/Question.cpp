/*
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

 

示例 1：

输入：nums = [2,2,3,2]
输出：3
示例 2：

输入：nums = [0,1,0,1,0,1,99]
输出：99
 

提示：

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<map>
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; ++i)
    {
        int res = 0;
        for (auto num : nums)
        {
            res += ((num >> i) & 1);
        }
        if (res % 3 == 1)
        {
            ans |= (1 << i);
        }
    }
    return ans;
}
int main()
{

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}