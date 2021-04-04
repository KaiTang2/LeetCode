#include"Question1030.h"
#include<math.h>
int dis(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2);
}
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
{
    int maxDis = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
    vector<vector<vector<int>>> map(maxDis+1);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int d = dis(i, j, r0, c0);
            vector<int> tmp = { i,j };
            map[d].push_back(move(tmp));
        }
    }
    vector<vector<int>> res;
    for (int i = 0; i <= maxDis; i++)
    {
        for (auto j : map[i])
        {
            res.push_back(j);
        }
    }
    return res;
}
int main()
{
    /*
    

    */
    vector<vector<int>> res = allCellsDistOrder(2, 2, 0, 1);
    for (int i = 0;i<res.size();i++)
    {
        cout << "[";
        for (auto j : res[i])
        {
            cout << j << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}