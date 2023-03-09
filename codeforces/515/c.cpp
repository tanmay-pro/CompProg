#include <bits/stdc++.h>
using namespace std;
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
    ll n;
    cin >> n;
    ll num;
    cin >> num;
    ll freqOrig[10] = {0};
    ll freq[10] = {0};
    while (num)
    {
        freqOrig[num % 10]++;
        num /= 10;
    }
    freq[2] = freqOrig[2] + 2 * freqOrig[4] + 3 * freqOrig[8] + freqOrig[9];
    freq[3] = freqOrig[3] + freqOrig[4] + freqOrig[6] + 2 * freqOrig[9];
    freq[5] = freqOrig[5] + freqOrig[6];
    freq[7] = freqOrig[7] + freqOrig[8] + freqOrig[9];
    string ans = "";
    while (freq[7])
    {
        ans += "7";
        freq[7]--;
    }
    while (freq[5])
    {
        ans += "5";
        freq[5]--;
    }
    while (freq[3])
    {
        ans += "3";
        freq[3]--;
    }
    while (freq[2])
    {
        ans += "2";
        freq[2]--;
    }
    cout << ans << endl;
    return 0;
}