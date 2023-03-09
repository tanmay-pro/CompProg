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
#define f first
#define s second
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
    bool val;
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
        temp.val = a.val && b.val;
        return temp;
    }

    item giveValue(bool v)
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
        neutralElement = giveValue(true);
    }

    void build(vector<bool> &a, ll x, ll lx, ll rx) // Build segment Tree from given Array
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

    void build(vector<bool> &a) // Responsible for calling the recursive build function
    {
        build(a, 0, 0, size);
    }

    void updateElem(ll i, bool v, ll x, ll lx, ll rx) // Function to update the element at the ith position and rebuild the tree
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

    void updateElem(ll i, bool v) // Responsible for calling the recursive set function
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
    segTree st1, st2;
    st1.init(n);
    st2.init(n);
    vector<bool> x;
    vector<bool> y;
    fo(i, n)
    {
        x.push_back(false);
        y.push_back(false);
    }
    st1.build(x);
    st2.build(y);
    while (q--)
    {
        ll x, y, z;
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            y--;
            z--;
            st1.updateElem(y, true);
            st2.updateElem(z, true);
        }
        else if (x == 2)
        {
            cin >> y >> z;
            y--;
            z--;
            st1.updateElem(y, false);
            st2.updateElem(z, false);
        }
        else
        {
            ll x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            y1--;
            x2--;
            y2--;
            bool forX = st1.calcFunc(x1, x2 + 1).val;
            bool forY = st2.calcFunc(y1, y2 + 1).val;
            // cout << "for X: " << forX << " for Y: " << forY << endl;
            if (forX || forY)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}