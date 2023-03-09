#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
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
#define N 4

int solution()
{
    int n, l[N], w[N], count = 0, pos[N + 1] = {0}, move[N + 1] = {0};
    cin >> n;
    pos[0] = -7;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        pos[w[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
        move[w[i]] = l[i];
    }
    if (n == 2)
    {
        if (w[0] > w[1])
        {
            if (l[0] == 1)
            {
                cout << 2 << endl;
                return 0;
            }
            else
            {
                cout << 1 << endl;
                return 0;
            }
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            while (pos[i] <= pos[i - 1])
            {
                pos[i] += move[i];
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}
int main()
{
    amazing;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }

    return 0;
}