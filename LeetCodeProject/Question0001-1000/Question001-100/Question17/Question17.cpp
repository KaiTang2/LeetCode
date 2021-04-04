#include"Question17.h"
string tmp;
vector<string> res;
vector<string> board = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
void DFS(int pos, string str)
{
    if (pos == str.size())
    {
        res.push_back(tmp);
        return;
    }
    int num = str[pos] - '0';
    for (int i = 0; i < board[num].size(); i++)
    {
        tmp.push_back(board[num][i]);
        DFS(pos+1, str);
        tmp.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)
    {
        return res;
    }
    DFS(0, digits);
    return res;
}
int main()
{
    /*
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
 

提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。


    */
    vector<string> res = letterCombinations("23");
    for (auto i : res)
    {
        cout << i << endl;
    }
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}