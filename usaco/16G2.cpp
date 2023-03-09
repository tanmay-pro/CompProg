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
    freopen("closing.in", "r", stdin); \
    freopen("closing.out", "w", stdout);
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
#define VAL (ll)2e5 + 9

ll parent[VAL];
ll sizeArray[VAL];
ll rankArray[VAL];
ll numberOfComponents = 0;

void createSet(ll v)
{
    parent[v] = v;
    numberOfComponents++;
    // rankArray[v] = 0; // Based on Depth of Tree
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
    // if (a != b)
    // {
    //     if(rankArray[a] < rankArray[b])
    //         swap(a, b);
    //     parent[b] = a;
    //     if (rankArray[a] == rankArray[b])
    //         rankArray[a]++;
    // }
    if (a != b)
    {
        if (sizeArray[a] < sizeArray[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        numberOfComponents--;
        sizeArray[a] += sizeArray[b];
    }
}

int main()
{
    amazing;
    file_read;
    ll n, m;
    cin >> n >> m;

    vvl edges(n + 1);
    fo(i, m)
    {
        ll x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    vl removedOrder;
    fo(i, n)
    {
        ll x;
        cin >> x;
        removedOrder.push_back(x);
    }
    vl ansList;
    reverse(removedOrder.begin(), removedOrder.end());
    createSet(removedOrder[0]);
    ansList.push_back(numberOfComponents);
    unordered_map<ll, ll> listOfAvailElem;
    listOfAvailElem[removedOrder[0]] = 1;
    Fo(i, 1, n)
    {
        createSet(removedOrder[i]);
        listOfAvailElem[removedOrder[i]] = 1;
        for (ll j = 0; j < edges[removedOrder[i]].size(); j++)
        {
            if (listOfAvailElem[edges[removedOrder[i]][j]] == 1)
            {
                unionSets(removedOrder[i], edges[removedOrder[i]][j]);
            }
        }
        ansList.push_back(numberOfComponents);
    }
    reverse(ansList.begin(), ansList.end());
    fo(i, ansList.size())
    {
        if (ansList[i] == 1)
        {
            cout << "YES";
            br;
        }
        else
        {
            cout << "NO";
            br;
        }
    }
    return 0;
}