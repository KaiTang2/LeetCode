#include "Question303.h"

class NumArray {
public:
    NumArray(vector<int>& nums) {
        auto length = nums.size();
        sum.resize(length + 1);
        sum[0] = 0;
        for (auto i = 0; i < length; i++)
        {
            sum[i+1] = nums[i] + sum[i];
        }
    }

    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
public:
    vector<int> sum;
};

int main()
{
    /*
    给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。

实现 NumArray 类：

NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是 sum(nums[i], nums[i + 1], ... , nums[j])）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
0 -2 -2 1 -4 -2 -3
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1))
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    
    */
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray* numArray = new NumArray(nums);
    cout << numArray->sumRange(0, 2) << endl;
    cout << numArray->sumRange(2, 5) << endl;
    cout << numArray->sumRange(0, 5) << endl;

	int pass = getchar();
	return 0;
}