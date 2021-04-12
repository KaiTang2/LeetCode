/*
一个字符串的 美丽值 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。

比方说，"abaacc" 的美丽值为 3 - 1 = 2 。
给你一个字符串 s ，请你返回它所有子字符串的 美丽值 之和。

 

示例 1：

输入：s = "aabcb"
输出：5
解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。
示例 2：

输入：s = "aabcbaa"
输出：17
 

提示：

1 <= s.length <= 500
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-beauty-of-all-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<string>
int beautySum(string s) {
    int n = s.size(), sum = 0;
    for (int len = 2; len <= n; ++len) {
        int r = 0, l = 0, minN = INT_MAX, maxN = INT_MIN;
        vector<int> nums(26, 0); // 使用数组存储每个字符的数量
        while (r < n) { // 滑动窗口
            nums[s[r] - 'a']++;
            r++;
            if (r - l == len) {
                minN = INT_MAX;
                maxN = INT_MIN;
                for (int i = 0; i < 26; ++i) {
                    if (nums[i] > 0) {
                        minN = min(minN, nums[i]);
                        maxN = max(maxN, nums[i]);
                    }
                }
                sum += maxN - minN;
                nums[s[l] - 'a']--;
                l++;
            }
        }
    }
    return sum;
}
int main()
{
    cout << beautySum("aabcb") << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}