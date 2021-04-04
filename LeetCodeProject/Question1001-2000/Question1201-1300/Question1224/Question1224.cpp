#include"Question1224.h"
int maxEqualFreq(vector<int>& nums) {
    unordered_map<int, int> num_map;
    unordered_map<int, int> freq_freq;
    int res = 0;
    int species = 0;
    int max_freq = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (num_map[nums[i]] == 0)
        {
            species++;
        }
        num_map[nums[i]]++;
        max_freq = max(max_freq, num_map[nums[i]]);
        freq_freq[num_map[nums[i]]]++;
        freq_freq[num_map[nums[i]] - 1]--;

        if (species == 1 || species == i + 1)
        {
            res = i + 1;
        }
        else if (freq_freq[1] == 1 && freq_freq[max_freq] == species - 1)
        {
            res = i + 1;
        }
        else if (freq_freq[max_freq - 1] == species - 1 && freq_freq[max_freq] == 1)
        {
            res = i + 1;
        }
    }
    return res;
}
int main()
{
    /*
    给出一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回其长度：
从前缀中 删除一个 元素后，使得所剩下的每个数字的出现次数相同。
如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。
示例 1：
输入：nums = [2,2,1,1,5,3,3,5]
输出：7
解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4]=5，就可以得到 [2,2,1,1,3,3]，里面每个数字都出现了两次。
示例 2：
输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
输出：13
示例 3：
输入：nums = [1,1,1,2,2,2]
输出：5
示例 4：
输入：nums = [10,2,8,9,3,8,1,5,2,3,7,6]
输出：8
提示：
2 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

    */
    vector<int> vec = { 10,2,8,9,3,8,1,5,2,3,7,6 };
    cout << maxEqualFreq(vec) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}