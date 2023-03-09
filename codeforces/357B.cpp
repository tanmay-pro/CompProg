#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    // ll t = 1;
    // cin >> t;
    // while (t--)
    // {
    // }
    ll n, m;
    cin >> n >> m;
    ll dance[m][3];
    fo(i, m)
    {
        cin >> dance[i][0];
        cin >> dance[i][1];
        cin >> dance[i][2];
    }
    unordered_map<ll, int> mp;
    fo(i, m)
    {
        ll freq[4] = {0};
        fo(j, 3)
        {
            if (mp[dance[i][j]] == 0)
                freq[0]++;
            if (mp[dance[i][j]] == 1)
                freq[1]++;
            if (mp[dance[i][j]] == 2)
                freq[2]++;
            if (mp[dance[i][j]] == 3)
                freq[3]++;
        }
        if (freq[0] == 3)
        {
            fo(j, 3)
            {
                mp[dance[i][j]] = j + 1;
            }
        }
        else if (freq[0] == 2)
        {
            ll val = 0;
            fo(j, 4)
            {
                if (freq[j] == 1)
                    val = j;
            }
            ll index = 0;
            fo(j, 3)
            {
                if (val == mp[dance[i][j]])
                {
                    index = j;
                    break;
                }
            }
            ll occu = -1;
            fo(j, 3)
            {
                if (index == j)
                {
                    continue;
                }
                else
                {
                    Fo(k, 1, 4)
                    {
                        if (val != k && k != occu)
                        {
                            mp[dance[i][j]] = k;
                            occu = k;
                            break;
                        }
                    }
                }
            }
        }
    }
    Fo(i, 1, n + 1)
    {
        cout << mp[i] << " ";
    }
    br;
    return 0;
}