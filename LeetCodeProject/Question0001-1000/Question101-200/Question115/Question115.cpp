﻿#include"Question115.h"
int numDistinct(string s, string t) {
    int m = s.length(), n = t.length();
    if (m<n)
    {
        return 0;
    }
    vector<vector<long>> result(m+1,vector<long>(n+1));
    for (int i = 0; i <= m; i++)
    {
        result[i][n] = 1;
    }
    for (int i = m-1; i >= 0; i--)
    {
        char sChar = s.at(i);
        for (int j = n-1; j >= 0; j--)
        {
            char tChar = t.at(j);
            if (sChar == tChar)
            {
                result[i][j] = result[i + 1][j] + result[i + 1][j + 1];
            }
            else
            {
                result[i][j] = result[i + 1][j];
            }
        }
    }
    return result[0][0];
}
int main()
{
    /*
    给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
题目数据保证答案符合 32 位带符号整数范围。
示例 1：
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例 2：
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
(上箭头符号 ^ 表示选取的字母)
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
 

提示：

0 <= s.length, t.length <= 1000
s 和 t 由英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    */
    string s = "babgbag";
    string t = "bag";
    cout << numDistinct(s, t) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}