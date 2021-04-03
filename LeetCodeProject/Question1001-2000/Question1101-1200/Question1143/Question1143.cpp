#include"Question1143.h"
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> res(2, vector<int>(n + 1));
    int first = 0,second = 0;
    for (int i = 1; i <= m; i++)
    {
        second = i % 2;
        first = second ^ 1;
        for (int j = 1; j <= n; j++)
        {
            if (text1[i-1] == text2[j-1])
            {
                res[second][j] = res[first][j - 1] + 1;
            }
            else
            {
                res[second][j] = max(res[second][j - 1], res[first][j]);
            }
        }
    }
    return res[second][n];
}
int main()
{
    /*
    给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

 

示例 1：

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。
示例 2：

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
示例 3：

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。


    */
    string str1 = "abcba";
    string str2 = "abcbcba";
    cout << longestCommonSubsequence(str1, str2) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}