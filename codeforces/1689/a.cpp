#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<char> v1;
        vector<char> v2;
        string str1, str2;
        cin >> str1;
        cin >> str2;
        fo(i, n)
        {
            v1.pb(str1[i]);
        }
        fo(i, m)
        {
            v2.pb(str2[i]);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        string ans = "";
        int i = 0, j = 0;
        int consec = 0;
        int prev = -1;
        while (i != n && j != m)
        {
            if (v1[i] < v2[j])
            {
                if (prev == 0 || prev == -1)
                {
                    consec++;
                    if (consec <= k)
                    {
                        ans += v1[i];
                        i++;
                        prev = 0;
                    }
                    else
                    {
                        ans += v2[j];
                        consec = 1;
                        j++;
                        prev = 1;
                    }
                }
                else
                {
                    ans += v1[i];
                    i++;
                    consec = 1;
                    prev = 0;
                }
            }
            else
            {
                if (prev == 1 || prev == -1)
                {
                    consec++;
                    if (consec <= k)
                    {
                        ans += v2[j];
                        j++;
                        prev = 1;
                    }
                    else
                    {
                        ans += v1[i];
                        i++;
                        consec = 1;
                        prev = 0;
                    }
                }
                else
                {
                    ans += v2[j];
                    j++;
                    consec = 1;
                    prev = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}