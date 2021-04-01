#include"Question797.h"
vector<int> res;
vector<vector<int>> result;
void select(vector<vector<int>>& graph, int n)
{
    if (n == graph.size() -1)
    {
        result.push_back(res);
        return;
    }
    int size = graph[n].size();
    for (int i = 0; i < size; i++)
    {
        res.push_back(graph[n][i]);
        select(graph, graph[n][i]);
        res.pop_back();
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    res.push_back(0);
    select(graph, 0);
    return result;
}

int main()
{
    /*
    给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ）空就是没有下一个结点了。
输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
示例 3：

输入：graph = [[1],[]]
输出：[[0,1]]
示例 4：

输入：graph = [[1,2,3],[2],[3],[]]
输出：[[0,1,2,3],[0,2,3],[0,3]]
示例 5：

输入：graph = [[1,3],[2],[3],[]]
输出：[[0,1,2,3],[0,3]]

    */
    vector<vector<int>> vec = { {4,3,1},{3,2,4},{},{4},{} };
    //预期输出[[0,4],[0,3,4],[0,1,3,4],[0,1,4]]
    vec = allPathsSourceTarget(vec);
    for each (auto var in vec)
    {
        for each (auto var1 in var)
        {
            cout << var1 << " ";
        }
        cout<<endl;
    }
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}