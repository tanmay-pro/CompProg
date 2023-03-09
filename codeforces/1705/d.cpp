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
        ll n;
        cin >> n;
        string str;
        cin >> str;
        string final;
        cin >> final;
        vector<bool> toggle(n, false);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        Fo(i, 1, n - 1)
        {
            if (str[i - 1] != str[i + 1])
            {
                toggle[i] = true;
                pq.push(i);
            }
        }

        if (str[0] != final[0] || str[n - 1] != final[n - 1])
        {
            cout << -1;
            br;
            continue;
        }
        // cout << 0;
        bool stat = true;
        ll ans = 0;
        Fo(i, 1, n - 1)
        {
            if (str[i] == final[i])
            {
                if (!pq.empty() && pq.top() == i)
                {
                    pq.pop();
                }
                continue;
            }
            if (toggle[i])
            {
                str[i] = final[i];
                pq.pop();
                if (toggle[i + 1] = true)
                {
                    pq.pop();
                    toggle[i + 1] = false;
                }
                else
                {
                    if (i + 1 < n - 1)
                    {
                        toggle[i + 1] = true;
                        pq.push(i + 1);
                    }
                }
                ans++;
            }
            else
            {
                while (!pq.empty() && i == 3)
                {
                    cout << pq.top();
                    pq.pop();
                    br;
                }
                if (pq.empty())
                {
                    stat = false;
                    break;
                }
                ll ind = pq.top();
                // cout << "for index " << i << " " << ind << endl;
                pq.pop();
                ans += ind - i + 1;
                Fo(j, i, ind + 1)
                {
                    if (str[j] == '1')
                    {
                        str[j] = '0';
                    }
                    else
                    {
                        str[j] = '1';
                    }
                }
                toggle[ind] = false;
                if (toggle[ind + 1] == false && ind + 1 < n - 1)
                {
                    toggle[ind + 1] = true;
                    pq.push(ind + 1);
                }
                else
                {
                    toggle[ind + 1] = false;
                    pq.pop();
                }
            }
        }
        // cout << str;
        // br;
        if (stat && str == final)
        {
            cout << ans;
            br;
        }
        else
        {
            cout << -1;
            br;
        }
    }
    return 0;
}