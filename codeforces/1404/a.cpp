#include <bits/stdc++.h>
using namespace std;
// code for implementing binary search
/*lli l = -1, r = size;while (r > l + 1){ lli mid = l + (r - l) / 2; if (array[mid] <= val)l = mid;elser = mid;}*/
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
        ll n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        vector<set<char>> vs(k);
        fo(i, n)
        {
            vs[i % k].insert(str[i]);
        }
        vector<char> fs(k);
        bool ch = true;
        fo(i, k)
        {
            if (vs[i].size() == 3)
            {
                ch = false;
                break;
            }
            else if (vs[i].size() == 1)
            {
                char elem = *vs[i].begin();
                fs[i] = elem;
            }
            else
            {
                char el1 = *vs[i].begin();
                char el2 = *vs[i].rbegin();
                if (el1 != '?' && el2 != '?')
                {
                    ch = false;
                    break;
                }
                else if (el1 == '?')
                {
                    fs[i] = el2;
                }
                else
                {
                    fs[i] = el1;
                }
            }
        }
        if (!ch)
        {
            cout << "NO" << endl;
            continue;
        }
        // fo(i, fs.size())
        // {
        //     cout << fs[i] << " ";
        // }
        // br;
        ll qcount = 0;
        ll ocount = 0;
        ll zcount = 0;
        fo(i, k)
        {
            if (fs[i] == '?')
            {
                qcount++;
            }
            else if (fs[i] == '1')
            {
                ocount++;
            }
            else
            {
                zcount++;
            }
        }
        // cout << qcount << " " << ocount << " " << zcount << endl;
        if (ocount <= k / 2 && zcount <= k / 2)
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