/*
给你一个二维数组 wall ，该数组包含这堵墙的相关信息。其中，wall[i] 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 穿过的砖块数量最少 ，并且返回 穿过的砖块数量 。

 

示例 1：


输入：wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
输出：2
示例 2：

输入：wall = [[1],[1],[1]]
输出：3
 
提示：

n == wall.length
1 <= n <= 104
1 <= wall[i].length <= 104
1 <= sum(wall[i].length) <= 2 * 104
对于每一行 i ，sum(wall[i]) 应当是相同的
1 <= wall[i][j] <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/brick-wall
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
#include<unordered_map>
int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> mp;
    for (auto width : wall)
    {
        int n = width.size();
        int sum = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            sum += width[i];
            ++mp[sum];
        }
    }
    int maxCount = 0;
    for (auto m : mp)
    {
        maxCount = max(maxCount, m.second);
    }
    return wall.size() - maxCount;
}
int main()
{

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}