#include"Question.h"
bool CheckPermutation(string s1, string s2) {
    vector<int> hash(26, 0);
    for (auto s : s1)
    {
        hash[s - 'a']++;
    }
    for (auto s : s2)
    {
        hash[s - 'a']++;
    }
    for (auto i : hash)
    {
        if (i != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    /*
    

    */
    cout << CheckPermutation("abc", "bca");
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}