/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include"Question.h"
int nr;
int nc;
void find1(vector<vector<char>>& grid, int x, int y)
{
    if (x >= nr || y >= nc || x < 0 || y < 0)
    {
        return;
    }
    if (grid[x][y] == '1')
    {
        grid[x][y] = '0';
        find1(grid, x + 1, y);
        find1(grid, x, y + 1);
        find1(grid, x - 1, y);
        find1(grid, x, y - 1);
    }
}
int numIslands(vector<vector<char>>& grid) {
    nr = grid.size();
    if (!nr) return 0;
    nc = grid[0].size();

    int res = 0;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
                ++res;
                find1(grid, r, c);
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<char>> grid = { {'1','1','1','1','0'} ,
                                  {'1','1','0','1','0'},
                                  {'1','1','0','0','0'},
                                  {'0','0','0','0','0'} };
    cout << numIslands(grid) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}