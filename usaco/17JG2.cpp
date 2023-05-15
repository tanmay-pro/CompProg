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

int main()
{
    amazing;
    ll n, k;
    cin >> n >> k;
    vl a;
    fo(i, n)
    {
        char c;
        cin >> c;
        if (c == 'H')
            a.push_back(0);
        else if (c == 'P')
            a.push_back(1);
        else
            a.push_back(2);
    }

    vl scissor(n, 0), hoof(n, 0), paper(n, 0);
    if (a[n - 1] == 0)
    {
        scissor[n - 1] = 0;
        paper[n - 1] = 1;
        hoof[n - 1] = 0;
    }
    else if (a[n - 1] == 1)
    {
        scissor[n - 1] = 1;
        paper[n - 1] = 0;
        hoof[n - 1] = 0;
    }
    else
    {
        scissor[n - 1] = 0;
        paper[n - 1] = 0;
        hoof[n - 1] = 1;
    }

    Fo(i, n - 2, -1)
    {
        if (a[i] == 0)
        {
            scissor[i] = scissor[i + 1];
            paper[i] = paper[i + 1] + 1;
            hoof[i] = hoof[i + 1];
        }
        else if (a[i] == 1)
        {
            scissor[i] = scissor[i + 1] + 1;
            paper[i] = paper[i + 1];
            hoof[i] = hoof[i + 1];
        }
        else
        {
            scissor[i] = scissor[i + 1];
            paper[i] = paper[i + 1];
            hoof[i] = hoof[i + 1] + 1;
        }
    }
    ll currSelect = 0;
    if(paper[0] >= hoof[0] && paper[0] >= scissor[0])
        currSelect = 1;
    else if(scissor[0] >= hoof[0] && paper[0] <= scissor[0])
        currSelect = 2;
    
    Fo(i, 1, n)
    {
        
    }
    return 0;
}