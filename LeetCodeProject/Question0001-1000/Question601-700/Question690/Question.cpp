/*


*/
#include"Question.h"
#include<unordered_map>
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
unordered_map<int, Employee*> mp;
int dfs(int& id)
{
    Employee* cur = mp[id];
    int all = cur->importance;
    for (auto val : cur->subordinates)
    {
        all += dfs(val);
    }
    return all;
}
int getImportance(vector<Employee*> employees, int id) {
    for (auto val : employees)
    {
        mp[val->id] = val;
    }
    return dfs(id);
}
int main()
{

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}