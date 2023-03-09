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

struct item
{
    ll val;
};

struct segTree
{

    ll size;
    vector<item> nodes;

    // Start updating Code from here

    item neutralElement;

    item mergeFunc(item a, item b)
    {
        item temp;
        temp.val = min(a.val, b.val);
        return temp;
    }

    item giveValue(ll v)
    {
        item temp;
        temp.val = v;
        return temp;
    }

    // Stop updating code

    void init(ll n) // Create Nodes Array
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        nodes.resize(2 * size);
        neutralElement = giveValue(LONG_LONG_MAX);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) // Build segment Tree from given Array
    {
        if (rx - lx == 1)
        {
            if (lx < (ll)a.size())
            {
                nodes[x] = giveValue(a[lx]); // Assign values at the bottom layer of the tree
            }
            return;
        }
        ll mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        nodes[x] = mergeFunc(nodes[2 * x + 1], nodes[2 * x + 2]); // Merge the two nodes
    }

    void build(vector<ll> &a) // Responsible for calling the recursive build function
    {
        build(a, 0, 0, size);
    }

    void updateElem(ll i, ll v, ll x, ll lx, ll rx) // Function to update the element at the ith position and rebuild the tree
    {
        if (rx - lx == 1)
        {
            nodes[x] = giveValue(v);
            return;
        }
        ll mid = (lx + rx) / 2;
        if (i < mid)
        {
            updateElem(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            updateElem(i, v, 2 * x + 2, mid, rx);
        }
        nodes[x] = mergeFunc(nodes[2 * x + 1], nodes[2 * x + 2]);
    }

    void updateElem(ll i, ll v) // Responsible for calling the recursive set function
    {
        updateElem(i, v, 0, 0, size);
    }

    item calcFunc(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
        {
            return neutralElement;
        }
        if (lx >= l && rx <= r)
        {
            return nodes[x];
        }
        ll mid = (lx + rx) / 2;
        item left = calcFunc(l, r, 2 * x + 1, lx, mid);
        item right = calcFunc(l, r, 2 * x + 2, mid, rx);
        return mergeFunc(left, right);
    }

    item calcFunc(ll l, ll r) // Responsible for calling the recursive calcFunc function
    {
        return calcFunc(l, r, 0, 0, size);
    }
};

int main()
{
    amazing;
    ll n, m;
    cin >> n >> m;
    vl blocked(m, 0);
    fo(i, m)
    {
        cin >> blocked[i];
    }
    ll q;
    cin >> q;
    segTree st;
    st.init(m);
    vl topmost(m, 0);
    fo(i, m)
    {
        topmost[i] = n - blocked[i];
    }
    st.build(topmost);
    while (q--)
    {
        ll spx, spy, fpx, fpy, k;
        cin >> spx >> spy >> fpx >> fpy >> k;
        bool check = 1;
        if (abs(spx - fpx) % k == 0 && abs(spy - fpy) % k == 0)
        {
            ll currRow = min(n - spx, n - fpx);
            ll val = currRow / k;
            currRow -= val * k;
            bool check = 1;
            ll minimTop = st.calcFunc(min(spy, fpy) - 1, max(fpy, spy)).val;
            if (currRow >= minimTop)
            {
                check = 0;
            }
            if (check)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}