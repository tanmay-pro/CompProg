#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;

    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;

    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

// Function to print decimal palindromic number
void generatePalindromes(int n, vector<int> &palin)
{
    int number;

    // Run two times for odd and even length palindromes
    for (int j = 0; j < 2; j++)
    {
        // Creates palindrome numbers with first half as i.
        // Value of j decided whether we need an odd length
        // of even length palindrome.
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            palin.push_back(number);
            i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    vector<int> palin;
    int N = 40004;
    palin.push_back(0);
    generatePalindromes(N, palin);
    cout << palin.size() << endl;
    int M = 502;
    long long dp[N][M] = {0};
    // for (int j = 1; j < palin.size(); j++)
    //     dp[0][j] = 1;
    // for (int i = 1; i < N; i++)
    // {
    //     dp[i][0] = 0;
    //     for (int j = 1; j < M; j++)
    //     {
    //         if (palin[j] <= i)
    //             dp[i][j] = (dp[i][j - 1] + dp[i - palin[j]][j]) % MOD;
    //         else
    //             dp[i][j] = dp[i][j - 1];
    //     }
    // }

    // while (tc--)
    // {
    //     int n;
    //     cin >> n;

    //     cout << dp[n][M - 1] << '\n';
    // }
}