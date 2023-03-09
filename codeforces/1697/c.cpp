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
        ll n;
        cin >> n;
        string s;
        string t;
        cin >> s;
        cin >> t;
        bool poss = true;
        vl indA;
        vl indB;
        fo(i, n)
        {

            if (s[i] == 'a' && t[i] == 'b')
            {
                if (!indB.empty())
                {
                    poss = false;
                    break;
                }
                if (i == n - 1)
                {
                    poss = false;
                    break;
                }
                else
                {
                    if (s[i + 1] == 'a')
                    {
                        indA.pb(i);
                    }
                    else if (s[i + 1] == 'b')
                    {
                        swap(s[i], s[i + 1]);
                    }
                    else
                    {
                        poss = false;
                        break;
                    }
                }
            }
            else if (s[i] == 'a' && t[i] == 'a')
            {
                if (!indB.empty())
                {
                    poss = false;
                    break;
                }
                continue;
            }
            else if (s[i] == 'a')
            {
                poss = false;
                break;
            }
            else if (s[i] == 'c' && t[i] == 'c')
            {
                if (!indA.empty())
                {
                    poss = false;
                    break;
                }
                continue;
            }
            else if (s[i] == 'c' && t[i] == 'b')
            {
                if (!indB.empty())
                {
                    ll val = indB.back();
                    indB.pop_back();
                    swap(s[val], s[i]);
                }
                else
                {
                    poss = false;
                    break;
                }
            }
            else if (s[i] == 'c')
            {
                poss = false;
                break;
            }
            else if (s[i] == 'b' && t[i] == 'b')
            {
                continue;
            }
            else if (s[i] == 'b' && t[i] == 'c')
            {
                if (!indA.empty())
                {
                    poss = false;
                    break;
                }
                if (i == n - 1)
                {
                    poss = false;
                    break;
                }
                else
                {
                    if (s[i + 1] == 'b')
                    {
                        indB.pb(i);
                    }
                    else if (s[i + 1] == 'c')
                    {
                        swap(s[i], s[i + 1]);
                    }
                    else
                    {
                        poss = false;
                        break;
                    }
                }
            }
            else if (s[i] == 'b' && t[i] == 'a')
            {
                if (!indA.empty())
                {
                    ll val = indA.back();
                    indA.pop_back();
                    swap(s[val], s[i]);
                }
                else
                {
                    poss = false;
                    break;
                }
            }
            else
            {
                poss = false;
                break;
            }
        }
        if (!indA.empty() || !indB.empty())
        {
            poss = false;
        }
        if (poss)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}