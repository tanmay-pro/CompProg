#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define sp cout << " "
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
int p = 31;

int main()
{
    amazing;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        ll freq[26] = {0};
        fo(i, str.length())
        {
            freq[str[i] - 'a']++;
        }
        ll ans = 0;
        ll lone_sum = 0;
        ll pair_sum = 0;
        fo(i, 26)
        {
            if (freq[i] % 2 != 0)
            {
                lone_sum++;
            }
            pair_sum += freq[i] / 2;
        }
        ans += 2 * (pair_sum / k);
        lone_sum += 2*(pair_sum % k);
        if(lone_sum >= k)
        {
            ans++;
        }
        cout << ans;
        br;
    }
}