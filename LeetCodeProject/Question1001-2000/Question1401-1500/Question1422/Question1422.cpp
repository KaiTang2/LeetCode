﻿#include"Question1422.h"
#include<math.h>
int maxScore(string s) {
    int l = 0, r = 0;
    int Max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            r++;
    }
    if (s[0] == '0')
    {
        l++;
    }
    else
    {
        r--;
    }
    Max = l + r;
    for (int i = 1; i < s.size()-1; i++)
    {
        if (s[i] == '0')
        {
            l++;
        }
        else
        {
            r--;
        }
        Max = max(Max,l+r);
    }
    return Max;
}
int main()
{
    /*
    给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。
「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：s = "011101"
输出：5
解释：
将字符串 s 划分为两个非空子字符串的可行方案有：
左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5
左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4
左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3
左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2
左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：s = "00111"
输出：5
解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5

输入：s = "1111"
输出：3

输入：s = "00"
输出：1
解释：当 左子字符串 = "0" 且 右子字符串 = "0" 时，我们得到最大得分 = 1 + 0 = 1

    */
    string s = "00111";
    //string s = "00";
    cout << maxScore(s) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}