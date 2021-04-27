/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<unordered_map>
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> sum;
    for (auto num1 : nums1)
    {
        for (auto num2 : nums2)
        {
            ++sum[num1 + num2];
        }
    }
    int res = 0;
    for (auto num3 : nums3)
    {
        for (auto num4 : nums4)
        {
            if (sum.count(-num3 - num4))
            {
                res += sum[-num3 - num4];
            }
        }
    }
    return res;
}
int main()
{
    vector<int>  nums1 = { 1, 2 };
    vector<int>  nums2 = { -2,-1 };
    vector<int>  nums3 = { -1, 2 };
    vector<int>  nums4 = { 0, 2 };
    cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}