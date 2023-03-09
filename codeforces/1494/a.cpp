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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        char ch = str[0];
        ll ans = 0;
        fo(i, str.length())
        {
            if (str[i] == ch)
            {
                ans++;
            }
        }
        char ch2 = str[str.length() - 1];
        if (ch2 == ch)
        {
            cout << "NO";
            br;
        }
        else
        {
            fo(i, str.length())
            {
                if (str[i] == ch2)
                {
                    ans--;
                }
            }
            ll remove;
            if (ans < 0)
            {
                remove = 1;
            }
            else
            {
                remove = -1;
            }
            ll final = 0;
            bool set = true;
            fo(i, str.length())
            {
                if (str[i] == ch)
                {
                    final++;
                    // cout << "finalif = " << final << endl;
                }
                else if (str[i] == ch2)
                {
                    final--;
                    // cout << "finalelseif = " << final << endl;
                }
                else
                {
                    final = final + remove;
                }
                if (final < 0)
                {
                    cout << "NO";
                    br;
                    set = false;
                    break;
                }
            }
            if (set == true && final == 0)
            {
                cout << "YES";
                br;
            }
            else if (final >= 0)
            {
                cout << "NO";
                // cout << "Final = " << final;
                br;
            }
        }
    }
    return 0;
}