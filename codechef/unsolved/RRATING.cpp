#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define endl "\n"
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    ll number = 0;
    priority_queue<ll> q;
    priority_queue<ll, vector<ll>, greater<ll>> q2;
    while (t--)
    {
        ll c;
        cin >> c;
        if (c == 1)
        {
            number++;
            ll x;
            cin >> x;
            q.push(x);
            if(number % 3 == 0)
            {
                q2.push(q.top());
                q.pop();
            }
            if(!q2.empty() && q2.top() < q.top())
            {
                q.push(q2.top());
                q2.pop();
                q2.push(q.top());
                q.pop();
            }
        }
        else
        {
            if (!q2.empty())
                cout << q2.top() << endl;
            else
                cout << "No reviews yet" << endl;
        }
    }
    return 0;
}