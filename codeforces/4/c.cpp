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

vpl hashval;

ll get_hash(string s)
{
    int p = 27; // Take 53 if both uppercase and lowercase letters
    int m = 1e9 + 9;
    ll hash_value = 0;
    char c;
    ll power[s.length()];
    power[0] = 1;
    for (int i = 1; i < s.length(); i++)
        power[i] = (power[i - 1] * p) % m;
    for (int i = 0; i < s.length(); ++i)
    {
        c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * power[i]) % m;
    }
    return hash_value;
}

ll check(ll a)
{
    bool set = false;
    int i = 0;
    for (i = 0; i < hashval.size(); i++)
    {
        if (a == hashval[i].first)
        {
            set = true;
            break;
        }
    }
    if (set == true)
    {
        return i;
    }
    else
        return -1;
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        ll hash_str = get_hash(str);
        ll set = check(hash_str);
        if (set == -1)
        {
            hashval.push_back(make_pair(hash_str, 0));
            cout << "OK";
            br;
        }
        else
        {
            cout << str << hashval[set].second + 1;
            br;
            (hashval[set].second)++;
        }
    }
    return 0;
}