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
        string str;
        cin >> str;
        ll price;
        cin >> price;
        vl freq(26, 0);
        vl freq2(26, 0);
        ll sum = 0;
        fo(i, str.size())
        {
            freq[str[i] - 'a']++;
            freq2[str[i] - 'a']++;
            sum += (str[i] - 'a' + 1);
        }
        string ans = "";
        Fo(i, 25, -1)
        {
            fo(j, freq[i])
            {
                if (sum <= price)
                    break;
                else
                {
                    freq2[i]--;
                    sum -= (i + 1);
                }
            }
            if (sum <= price)
            {
                break;
            }
        }
        fo(i, str.size())
        {
            if (freq2[str[i] - 'a'] > 0)
            {
                ans += str[i];
                freq2[str[i] - 'a']--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}