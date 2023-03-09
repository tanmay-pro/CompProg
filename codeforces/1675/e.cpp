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
#define VAL (ll)2e5 + 9

ll parent[VAL];
ll sizeArray[VAL];
ll rankArray[VAL];

void createSet(ll v)
{
    parent[v] = v;
    sizeArray[v] = 1; // Based on size of Tree
}

ll findSet(ll v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(ll a, ll b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (sizeArray[a] < sizeArray[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sizeArray[a] += sizeArray[b];
    }
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        vl maxSofar(n);
        maxSofar[0] = str[0] - 'a';
        int ind = -1;
        Fo(i, 1, n)
        {
            ll val = str[i] - 'a';
            maxSofar[i] = max(maxSofar[i - 1], val);
        }
        if (maxSofar[0] > k)
        {
            fo(i, k)
            {
                // cout << "Str[0] = " << str[0];
                // br;
                Fo(j, 1, n)
                {
                    if (str[j] == str[0])
                    {
                        str[j]--;
                    }
                }
                str[0]--;
            }
            cout << str << endl;
            continue;
        }
        Fo(i, 1, n)
        {
            if (maxSofar[i] > k)
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            fo(i, n)
            {
                cout << "a";
            }
            br;
            continue;
        }
        ll val = maxSofar[ind - 1];
        // cout << "val = " << val << endl;
        k -= val;
        while (val > 0)
        {
            Fo(i, ind, n)
            {
                if (str[i] == ('a' + val))
                {
                    str[i]--;
                }
            }
            val--;
        }
        while (k--)
        {
            Fo(i, ind + 1, n)
            {
                if (str[i] == str[ind])
                {
                    str[i]--;
                }
            }
            str[ind]--;
        }
        fo(i, ind)
        {
            cout << "a";
        }
        Fo(i, ind, n)
        {
            if (str[i] >= 'a')
            {
                cout << str[i];
            }
            else
            {
                cout << "a";
            }
        }
        br;
    }
    return 0;
}