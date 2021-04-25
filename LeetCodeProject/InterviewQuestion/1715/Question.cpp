/*
给定一组单词words，编写一个程序，找出其中的最长单词，且该单词由这组单词中的其他单词组合而成。若有多个长度相同的结果，返回其中字典序最小的一项，若没有符合要求的单词则返回空字符串。

示例：

输入： ["cat","banana","dog","nana","walk","walker","dogwalker"]
输出： "dogwalker"
解释： "dogwalker"可由"dog"和"walker"组成。
提示：

0 <= len(words) <= 200
1 <= len(words[i]) <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<unordered_set>
#include<algorithm>
bool d[20000 + 10];
bool done(string w, unordered_set<string>& S)
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i < w.size(); ++i)
    {
        if (i < w.size() - 1)
        {
            string s = w.substr(0, i + 1);
            if (S.count(s))
            {
                d[i] = true;
            }
        }
        for (int j = 0; j < i; ++j)
        {
            if (!d[j])
            {
                continue;
            }
            string s = w.substr(j + 1, i - j);
            if (S.count(s))
            {
                d[i] = true;
                break;
            }
        }
    }
    return d[w.size() - 1];
}

string longestWord(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() > b.size() || (a.size() == b.size() && a < b); });
    unordered_set<string> S(words.begin(), words.end());
    for (auto s : words)
    {
        if (s == "")
        {
            continue;
        }
        if (done(s, S))
        {
            return s;
        }
    }
    return "";
}
int main()
{
    vector<string> words = { "cat","banana","dog","nana","walk","walker","dogwalker" };
    cout << longestWord(words) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}