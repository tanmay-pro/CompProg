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

bool isSubSequence(string str1, string str2, ll m, ll n)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);
    return isSubSequence(str1, str2, m, n - 1);
}

int main()
{
    amazing;
    string str1;
    string str2;
    bool at = 0, arr = 0;
    map<char, ll> m;
    cin >> str1 >> str2;
    fo(i, str1.size())
    {
        m[str1[i]]++;
    }
    fo(i, str2.size())
    {
        m[str2[i]]--;
    }
    ll diff = 0;
    tr(m, it)
    {
        diff += abs(it->ss);
    }
    ll n = str1.length();
    ll ma = str2.length();
    if (n == ma && diff == 0)
    {
        cout << "array";
        return 0;
    }
    else if (n == ma && diff != 0)
    {
        cout << "need tree";
        return 0;
    }
    ll neg = 0;
    tr(m, it)
    {
        if (it->ss < 0)
        {
            neg++;
        }
    }
    if (neg == 0)
    {
        at = 1;
        if (isSubSequence(str2, str1, ma, n))
        {
            cout << "automaton";
        }
        else
        {
            cout << "both";
        }
        return 0;
    }
    else
    {
        cout << "need tree";
        return 0;
    }

    return 0;
}