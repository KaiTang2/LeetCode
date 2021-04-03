#include"Question136.h"
#include<map>
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto i : nums)
    {
        res ^= i;
    }
    return res;
}
int main()
{
    /*
    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]
输出: 1
示例 2:
输入: [4,1,2,1,2]
输出: 4
    */
    map<int, int> res;
    res[1] = 3;
    res[2] += 4;
    auto it = res.begin();
    int k = it->second;
    vector<int> vec = { 4,1,2,1,2 };
    cout << singleNumber(vec) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}