/*
我们有一个非负整数数组 A。

对于每个（连续的）子数组 B = [A[i], A[i+1], ..., A[j]] （ i <= j），我们对 B 中的每个元素进行按位或操作，获得结果 A[i] | A[i+1] | ... | A[j]。

返回可能结果的数量。 （多次出现的结果在最终答案中仅计算一次。）

 

示例 1：

输入：[0]
输出：1
解释：
只有一个可能的结果 0 。
示例 2：

输入：[1,1,2]
输出：3
解释：
可能的子数组为 [1]，[1]，[2]，[1, 1]，[1, 2]，[1, 1, 2]。
产生的结果为 1，1，2，1，3，3 。
有三个唯一值，所以答案是 3 。
示例 3：

输入：[1,2,4]
输出：6
解释：
可能的结果是 1，2，3，4，6，以及 7 。
 

提示：

1 <= A.length <= 50000
0 <= A[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-ors-of-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<unordered_set>
int subarrayBitwiseORs(vector<int>& arr) {
    int len = arr.size();
    if (len < 2)
        return len;
    unordered_set<int> dp;
    for (int i = 0; i < len; ++i)
    {
        dp.insert(arr[i]);
        for (int j = i - 1; j >= 0; --j)
        {
            if ((arr[j] & arr[i]) == arr[i])
            {
                break;
            }
            arr[j] |= arr[i];
            dp.insert(arr[j]);
        }
    }
    return dp.size();

}
int main()
{
    vector<int> nums = {1,1,2};
    cout << subarrayBitwiseORs(nums) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}