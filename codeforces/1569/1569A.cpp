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
        ll num_a[n] = {0};
        ll num_b[n] = {0};
        if (str[0] == 'a')
        {
            num_a[0] = 1;
        }
        else
        {
            num_b[0] = 1;
        }
        Fo(i, 1, n)
        {
            if (str[i] == 'a')
            {
                num_a[i] = num_a[i - 1] + 1;
                num_b[i] = num_b[i - 1];
            }
            else
            {
                num_a[i] = num_a[i - 1];
                num_b[i] = num_b[i - 1] + 1;
            }
        }
        bool set = false;
        fo(i, n-1)
        {
            Fo(j, i + 1, n)
            {
                if (i >= 1 && num_a [j] - num_a[i - 1] == num_b[j] - num_b[i - 1])
                {
                    cout << i+1 << " " << j+1 << endl;
                    set = true;
                    break;
                }
                else if(num_a[j] == num_b[j] && i == 0)
                {
                    cout << i+1 << " " << j+1 << endl;
                    set  = true;
                    break;
                }
            }
            if (set)
            {
                break;
            }
        }
        if (!set)
        {
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}