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
int m = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        vl players(4);
        fo(i, 4)
        {
            ll x;
            cin >> x;
            players[i] = x;
        }
        ll max_ind = max_element(players.begin(), players.end()) - players.begin();
        int sec_max = 0;
        fo(i, 4)
        {
            if (i != max_ind)
            {
                if (players[i] > players[sec_max])
                    sec_max = i;
            }
        }
        // cout << sec_max << " " << max_ind << endl;
        if (sec_max == max_ind)
        {
            sec_max = 1;
            fo(i, 4)
            {
                if (i != max_ind)
                {
                    if (players[i] > players[sec_max])
                        sec_max = i;
                }
            }
        }
        if (((max_ind == 0 && sec_max == 1) || (max_ind == 1 && sec_max == 0) || (sec_max == 3 && max_ind == 2) || (sec_max == 2 && max_ind == 3)))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}