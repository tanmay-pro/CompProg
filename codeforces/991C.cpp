#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL taken_candies(LL total_candies, LL k)
{
    LL self_candies = 0;

    while (total_candies > 0)
    {
        self_candies += min(k, total_candies);

        total_candies = total_candies - k;

        LL lost_candies = total_candies / 10;

        total_candies -= lost_candies;
    }

    return self_candies;
}
int main()
{
    LL n;
    cin >> n;
    LL target = n / 2 + n % 2;
    LL left = 1, right = n, answer = 1;
    while (left <= right)
    {
        LL mid = left + (right - left) / 2;

        if (taken_candies(n, mid) >= target)
        {
            if (mid == 1 || taken_candies(n, mid - 1) < target)
            {
                answer = mid;
                break;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << answer;
    return 0;
}