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
        temp.val = a.val + b.val;
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
        neutralElement = giveValue(0);
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
    ll n, q;
    cin >> n >> q;
    vl a;
    fo(i, n)
    {
        ll temp;
        cin >> temp;
        a.pb(temp);
    }
    segTree st;
    st.init(n);
    st.build(a);
    while (q--)
    {
        ll type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            st.updateElem(l - 1, r);
        }
        else
        {
            ll ans = st.calcFunc(l - 1, r).val;
            cout << ans << endl;
        }
    }
    return 0;
}