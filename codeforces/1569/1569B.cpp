#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define endl "\n"
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ff first
#define ss second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int count_2 = 0;
        fo(i, n)
        {
            if (str[i] == '2')
                count_2++;
        }
        char table[n][n];
        fo(i, n)
        {
            fo(j, n)
            {
                table[i][j] = 'X';
            }
        }

        bool set = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i && str[i] == '1' && str[j] == '1')
                {
                    table[i][j] = '=';
                    table[j][i] = '=';
                }
                else if (j != i && str[i] == '1' && str[j] == '2')
                {
                    table[i][j] = '+';
                    table[j][i] = '-';
                }
                else if (j != i && str[i] == '2' && str[j] == '1')
                {
                    table[i][j] = '-';
                    table[j][i] = '+';
                }
            }
        }
        if (count_2 > 2 || count_2 == 0)
        {
            cout << "YES" << endl;
            fo(i, n)
            {
                int nu = 0;
                fo(j, n)
                {
                    if (table[i][j] == '+')
                    {
                        nu++;
                    }
                    if (table[i][j] == 'X' && i != j)
                    {
                        if (nu == 0)
                        {
                            table[i][j] = '+';
                            table[j][i] = '-';
                            nu++;
                        }
                        else
                        {
                            table[i][j] = '-';
                            table[j][i] = '+';
                        }
                    }
                    else if (table[i][j] == '+')
                    {
                        nu++;
                    }
                }
            }
            fo(i, n)
            {
                fo(j, n)
                {
                    cout << table[i][j];
                }
                br;
            }
        }
        else
        {
            cout << "NO";
            br;
        }
    }
    return 0;
}