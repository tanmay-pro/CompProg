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
        ll n;
        cin >> n;
        string str;
        cin >> str;
        vl before;
        vl after;
        ll number_of_m = 0;
        ll number_of_t = 0;
        ll count = 0;
        fo(i, n)
        {
            if (str[i] != 'M')
            {
                count++;
                number_of_t++;
            }
            else
            {
                before.push_back(count);
                number_of_m++;
            }
        }
        if (number_of_t == (2 * number_of_m))
        {
            count = 0;
            fo(i, n)
            {
                if (str[n - i - 1] != 'M')
                {
                    count++;
                }
                else
                {
                    after.push_back(count);
                }
            }
            vl final_after;
            fo(i, after.size())
            {
                final_after.push_back(after[after.size() - i - 1]);
            }
            bool set = true;
            fo(i, before.size())
            {
                if (before[i] >= (i + 1))
                {
                    ;
                }
                else
                {
                    set = false;
                }
            }
            fo(i, final_after.size())
            {
                if (after[i] >= (i + 1))
                {
                    ;
                }
                else
                {
                    set = false;
                }
            }
            if (set == true)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
            br;
        }
        else
        {
            cout << "NO";
            br;
        }
    }
    return 0;
}