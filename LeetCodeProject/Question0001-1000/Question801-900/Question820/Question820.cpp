﻿#include"Question820.h"
#include<unordered_set>
class Tree
{
    Tree* children[26];
public:
    int count;
    Tree()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
            count = 0;
        }
    }
    Tree* get(char c)
    {
        if (children[c - 'a'] == NULL)
        {
            children[c - 'a'] = new Tree();
            count++;
        }
        return children[c - 'a'];
    }
};
int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string> good(words.begin(), words.end());
    for (string& word : words)
    {
        for (int k = 1; k < word.size(); k++)
        {
            good.erase(word.substr(k));
        }
    }
    int res = 0;
    for (string word : good)
    {
        res += word.size() + 1;
    }
    return res;
}
int minimumLengthEncoding1(vector<string>& words) {
    int size = words.size();
    Tree* root = new Tree();
    unordered_map<Tree*, int> nodes;
    for (int i = 0; i < size; i++)
    {
        string word = words[i];
        Tree* node = root;
        for (int j = word.size() - 1; j >= 0; j--)
        {
            node = node->get(word[j]);
        }
        nodes[node] = i;
    }
    int res = 0;
    for (auto& node : nodes)
    {
        if (node.first->count == 0)
        {
            res += words[node.second].length() + 1;
        }
    }
    return res;
}
int main()
{
    /*
    单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：
words.length == indices.length
助记字符串 s 以 '#' 字符结尾
对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等
给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。
示例 1：
输入：words = ["time", "me", "bell"]
输出：10
解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
示例 2：
输入：words = ["t"]
输出：2
解释：一组有效编码为 s = "t#" 和 indices = [0] 。
提示：
1 <= words.length <= 2000
1 <= words[i].length <= 7
words[i] 仅由小写字母组成


    */
    vector<string> vec = { "time", "me", "bell" };
    cout << minimumLengthEncoding(vec) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}