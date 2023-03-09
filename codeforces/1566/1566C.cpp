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
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        ll ans = 0;
        fo(i, n)
        {
            if (str1[i] != str2[i])
            {
                ans += 2;
            }
            else
            {
                if (i + 1 < n && str1[i + 1] == str2[i + 1])
                {
                    if (str1[i + 1] == '1' && str1[i] == '0')
                    {
                        ans += 2;
                        i++;
                    }
                    else if (str1[i + 1] == '0' && str1[i] == '1')
                    {
                        ans += 2; i++;
                    }
                    else if (str1[i + 1] == '0' && str1[i] == '0')
                    {
                        ans++;
                    }
                }
                else if (i + 1 < n && str1[i + 1] != str2[i + 1])
                {
                    if (str1[i] == '0')
                    {
                        ans++;
                    }
                }
                else if (i + 1 == n)
                {
                    if (str1[i] == '0')
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans;
        br;
    }
    return 0;
}