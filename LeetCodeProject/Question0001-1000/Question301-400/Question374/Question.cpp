/*

2126753390
1702766719
*/
#include"Question.h"
int numberGuess = 1702766719;
int guess(int n)
{
    if(numberGuess > n)
    {
        return 1;
    }
    else if (numberGuess < n)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int guessNumber(int n) {
    int l = 1;
    int r = n;
    while (l <= r)
    {
        auto m = (l - r) / 2 + r;
        switch (guess(m))
        {
        case 1: {l = m + 1; break; }
        case -1: {r = m - 1; break; }
        case 0: {return m; }
        }
    }
    return -1;
}
int main()
{
    cout << guessNumber(2126753390) << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}