/*


*/
#include"Question.h"
#include<unordered_map>
#include<functional>
#include<algorithm>
int ToMin(string& s)
{
    return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}
vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    unordered_map<string, vector<int>> all;
    vector<string> res;
    for (int i = 0; i < keyName.size(); i++)
    {
        auto it = all.find(keyName[i]);
        if (it == all.end())
        {
            all.insert(unordered_map<string, vector<int>>::value_type(keyName[i], vector<int>{ToMin(keyTime[i])}));
        }
        else
        {
            it->second.push_back(ToMin(keyTime[i]));
        }
    }
    for (auto it : all)
    {
        if (it.second.size() <= 2)
        {
            continue;
        }
        sort(it.second.begin(), it.second.end());
        for (int i = 0; i < it.second.size() - 2; ++i)
        {
            if (it.second[i + 2] - it.second[i] <= 60)
            {
                res.push_back(it.first);
                break;
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    vector<string> name = { "daniel","daniel","daniel","luis","luis","luis","luis" };
    vector<string> time = { "10:00","10:40","11:00","09:00","11:00","13:00","15:00" };
    vector<string> res = alertNames(name, time);
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}