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
#define file_read                  \
    freopen("hps.in", "r", stdin); \
    freopen("hps.out", "w", stdout);
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
     file_read;
    ll n;
    cin >> n;
    vector<char> john;
    fo(i, n)
    {
        char c;
        cin >> c;
        john.pb(c);
    }
    vl hoof(n + 1, 0), paper(n + 1, 0), scissor(n + 1, 0);
    Fo(i, 1, n + 1)
    {
        if (john[i - 1] == 'H')
        {
            hoof[i] = hoof[i - 1];
            paper[i] = paper[i - 1] + 1;
            scissor[i] = scissor[i - 1];
        }
        if (john[i - 1] == 'P')
        {
            hoof[i] = hoof[i - 1];
            paper[i] = paper[i - 1];
            scissor[i] = scissor[i - 1] + 1;
        }
        if (john[i - 1] == 'S')
        {
            hoof[i] = hoof[i - 1] + 1;
            paper[i] = paper[i - 1];
            scissor[i] = scissor[i - 1];
        }
    }

    vl leftMaxim(n + 1);
    Fo(i, 1, n + 1)
    {
        leftMaxim[i] = max({hoof[i], paper[i], scissor[i]});
    }

    // for (int i = 1; i < leftMaxim.size(); i++)
    // {
    //     cout << leftMaxim[i] << " ";
    // }
    // br;

    hoof.clear();
    paper.clear();
    scissor.clear();
    hoof.resize(n + 1);
    paper.resize(n + 1);
    scissor.resize(n + 1);
    Fo(i, n - 1, -1)
    {
        if (john[i] == 'H')
        {
            hoof[i] = hoof[i + 1];
            paper[i] = paper[i + 1] + 1;
            scissor[i] = scissor[i + 1];
        }
        if (john[i] == 'P')
        {
            hoof[i] = hoof[i + 1];
            paper[i] = paper[i + 1];
            scissor[i] = scissor[i + 1] + 1;
        }
        if (john[i] == 'S')
        {
            hoof[i] = hoof[i + 1] + 1;
            paper[i] = paper[i + 1];
            scissor[i] = scissor[i + 1];
        }
    }

    vl rightMaxim(n + 1);
    Fo(i, n - 1, -1)
    {
        rightMaxim[i + 1] = max({hoof[i], paper[i], scissor[i]});
    }

    // for(int i=1 ; i < rightMaxim.size(); i++)
    // {
    //     cout << rightMaxim[i] << " ";
    // }
    // br;

    ll ans = LONG_LONG_MIN;
    Fo(i, 1, n)
    {
        ans = max(ans, leftMaxim[i] + rightMaxim[i + 1]);
    }
    cout << ans;

    return 0;
}