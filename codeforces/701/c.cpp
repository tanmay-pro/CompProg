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

bool isPossible(string str, ll k, ll uniq)
{
    map<char, ll> mp;
    ll ans = 0;
    fo(i, k)
    {
        mp[str[i]]++;

        if (mp[str[i]] == 1)
            ans++;
    }
    if (ans == uniq)
        return true;
    Fo(ep, k, str.size())
    {
        char remove = str[ep - k];
        // cout << "for character " << remove << " map value is " << mp[remove];
        // br;
        if (mp[remove] == 1)
            ans--;
        // cout << "removing character " << remove;
        // br;
        mp[remove]--;

        // cout << "for character " << remove << " map value is " << mp[remove];
        char add = str[ep];
        // cout << "adding character " << add;
        // br;       
        mp[add]++;
        if (mp[add] == 1)
            ans++;
        // cout << "new ans = " << ans;
        // br;
        if (ans == uniq)
            return true;
    }
    return false;
}

int main()
{
    amazing;
    ll n;
    cin >> n;
    string str;
    cin >> str;
    set<char> st;
    fo(i, str.size())
        st.insert(str[i]);
    ll uniq = st.size();
    ll l = 0, r = n + 1;
    while (r > l + 1)
    {
        ll mid = l + (r - l) / 2;
        if (isPossible(str, mid, uniq))
        {
            r = mid;
            // cout << "Satisfied for Mid = " << mid;
            // br;
        }
        else
            l = mid;
    }
    cout << r;
    return 0;
}