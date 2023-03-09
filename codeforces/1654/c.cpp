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
        ll n;
        cin >> n;
        priority_queue<ll> pq2;
        ll sum = 0;
        fo(i, n)
        {
            ll x;
            cin >> x;
            sum += x;
            pq2.push(x);
        }
        priority_queue<ll> pq;
        vl vec2;
        pq.push(sum);
        while (n > 1)
        {
            ll x = pq.top();
            pq.pop();
            ll y = pq2.top();
            if (x != y)
            {
                ll num1 = x / 2;
                ll num2 = x - num1;
                pq.push(num1);
                pq.push(num2);
            }
            else
            {
                pq2.pop();
                while (!pq.empty())
                {
                    ll x = pq.top();
                    pq.pop();
                    ll y = pq2.top();
                    if (x != y)
                    {
                        ll num1 = x / 2;
                        ll num2 = x - num1;
                        pq.push(num1);
                        pq.push(num2);
                        break;
                    }
                    else
                    {
                        pq2.pop();
                    }
                }
            }
            n--;
        }
        bool check = true;
        while (!pq.empty())
        {
            ll x = pq.top();
            pq.pop();
            ll y = pq2.top();
            pq2.pop();
            if (x != y)
            {
                check = false;
                break;
            }
        }
        if (pq2.empty() && check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}