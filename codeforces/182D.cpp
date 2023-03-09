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
int p = 27;
int m = 1e9 + 7;

ll get_hash(string s, string t, ll p_pow[])
{
    ll S = s.length();
    ll T = t.length();
    ll hash_of_t[T + 1];
    hash_of_t[0] = 0;
    for (int i = 0; i < T; i++)
    {
        hash_of_t[i + 1] = (hash_of_t[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    } 
    ll hash_of_s = 0;
    for (int i = 0; i < S; i++)
    {
        hash_of_s = (hash_of_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    ll count = 0;
    for (int i = 0; i + S - 1 < T; i = i + S)
    {
        ll current_hash_value = (hash_of_t[i + S] + m - hash_of_t[i]) % m;
        if (current_hash_value == hash_of_s * p_pow[i] % m)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    amazing;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    if (s1.length() > s2.length())
    {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    string str;
    int count = 0;
    ll p_pow[s2.length()];
    p_pow[0] = 1;
    for (int i = 1; i < s2.length(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    fo(i, s1.length())
    {
        str += s1[i];
        ll l = str.length();
        if (s1.length() % l == 0 && s2.length() % l == 0)
        {
            if (l * get_hash(str, s1, p_pow) == s1.length() && l * get_hash(str, s2, p_pow) == s2.length())
            {
                count++;
            }
        }
    }
    cout << count;
    br;
    return 0;
}