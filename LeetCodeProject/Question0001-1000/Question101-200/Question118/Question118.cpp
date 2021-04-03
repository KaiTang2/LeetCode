#include"Question118.h"
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows == 0)
    {
        return res;
    }
    vector<int> first;
    first.push_back(1);
    res.push_back(first);
    if (numRows == 1)
    {
        return res;
    }
    vector<int> second;
    second.push_back(1);
    second.push_back(1);
    res.push_back(second);
    if (numRows == 2)
    {
        return res;
    }
    for (int i = 2; i < numRows; i++)
    {
        vector<int> val;
        val.push_back(1);
        for (int j = 1; j < i; j++)
        {
            val.push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
        val.push_back(1);
        res.push_back(val);
    }
    return res;
}
int main()
{
    /*
    给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
示例:
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]


    */
    vector<vector<int>> res = generate(5);
    for (auto var1 : res)
    {
        for (auto var2:var1 )
        {
            cout << var2 << " ";
        }
        cout << endl;
    }
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}