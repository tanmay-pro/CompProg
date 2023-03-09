#include <iostream>
using namespace std;
long long answer(int t, long long &res)
{
    if (t == 1)
    {
        res = res + 4;
        return 0;
    }
    else if (t % 2 == 0)
    {
        //res += answer(t - 1, res);
        
    }
    else
    {
        int k = (t + 1) / 2;
        res += 4 * k + answer(t - 1, res);
    }
    return 0;
}
int main()
{
    int t;
    long long res = 0;
    cin >> t;
    answer(t, res);
    cout << res;
    return 0;
}
