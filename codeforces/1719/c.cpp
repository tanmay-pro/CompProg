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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, query;
        cin >> n >> query;
        vl a(n);
        fo(i, n) cin >> a[i];
        deque<ll> q;
        Fo(i, 1, n + 1)
        {
            q.push_back(i);
        }
        map<ll, ll> loseRound;
        fo(i, n - 1)
        {
            ll elem1 = q.front();
            q.pop_front();
            ll elem2 = q.front();
            q.pop_front();
            if (a[elem1 - 1] > a[elem2 - 1])
            {
                q.push_back(elem2);
                q.push_front(elem1);
                loseRound[elem2] = i + 1;
            }
            else
            {
                q.push_back(elem1);
                q.push_front(elem2);
                loseRound[elem1] = i + 1;
            }
        }
        while (query--)
        {
            ll a, b;
            cin >> a >> b;
            ll firstFight;
            if (a == 1)
                firstFight = 1;
            else
                firstFight = a - 1;
            if (loseRound[a] == 0)
            {
                cout << max((ll)0, b - firstFight + 1);
                br;
                continue;
            }
            else
            {
                if (b < firstFight)
                {
                    cout << 0;
                    br;
                    continue;
                }
                else
                {
                    ll losingRound = loseRound[a];
                    ll startRound = firstFight;
                    ll wins = losingRound - startRound;
                    if (b < losingRound)
                    {
                        wins = b - startRound + 1;
                        cout << wins;
                        br;
                        continue;
                    }
                    else
                    {
                        cout << wins;
                        br;
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}