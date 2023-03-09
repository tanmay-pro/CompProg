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
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll q;
    cin >> q;
    while (q--)
    {
        ll m;
        char c;
        cin >> m >> c;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        vl leftContinuous(n, 0);
        if (str[0] == c)
        {
            leftContinuous[1] = 1;
        }
        Fo(i, 2, n)
        {
            if (str[i - 1] == c)
            {
                leftContinuous[i] = leftContinuous[i - 1] + 1;
            }
            else
            {
                leftContinuous[i] = 0;
            }
        }
        vl rightContinuous(n, 0);
        if (str[n - 1] == c)
        {
            rightContinuous[n - 2] = 1;
        }
        Fo(i, n - 3, -1)
        {
            if (str[i + 1] == c)
            {
                rightContinuous[i] = rightContinuous[i + 1] + 1;
            }
            else
            {
                rightContinuous[i] = 0;
            }
        }
        ll change = m;
        ll sp = 0;
        ll begPointer = -1;
        while (change > 0)
        {
            if (str[sp] != c)
            {
                change--;
                if (begPointer == -1)
                {
                    begPointer = sp;
                }
            }
            sp++;
            if (sp == n)
            {
                break;
            }
        }
        ll currAns = 0;
        if (sp == n)
        {
            cout << n << endl;
            continue;
        }
        sp--;
        sp += rightContinuous[sp];
        currAns = sp + 1;

        ll i = sp + 1;
        // cout << " Beg: " << begPointer << " End: " << i << " CurrAns: " << currAns << endl;

        ll ans = currAns;
        while (i < n)
        {
            currAns = currAns - leftContinuous[begPointer] - 1;
            begPointer = begPointer + rightContinuous[begPointer] + 1;
            currAns = currAns + rightContinuous[i] + 1;
            i = i + rightContinuous[i] + 1;

            // cout << " Beg: " << begPointer << " End: " << i << " CurrAns: " << currAns << endl;
            ans = max(ans, currAns);
            if (i >= n)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
