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
        // ll n, k;
        // cin >> n >> k;
        // string str1, str2;
        // cin >> str1 >> str2;
        // priority_queue<char, vector<char>, greater<char>> pq1, pq2;
        // fo(i, str1.size()) pq1.push(str1[i]);
        // fo(i, str2.size()) pq2.push(str2[i]);
        // bool check = true;
        // while (!pq1.empty())
        // {
        //     char x = pq1.top();
        //     pq1.pop();
        //     char y = pq2.top();
        //     pq2.pop();
        //     if (x == y)
        //         continue;
        //     if (x > y)
        //     {
        //         check = 0;
        //         break;
        //     }
        //     ll diff = y - x;
        //     ll temp = k - 1;
        //     while (temp > 0)
        //     {
        //         if (pq1.empty())
        //         {
        //             check = 0;
        //             break;
        //         }
        //         char z = pq1.top();
        //         pq1.pop();
        //         if (z != x)
        //         {
        //             check = 0;
        //             break;
        //         }
        //         z += diff;
        //         pq1.push(z);
        //         temp--;
        //     }
        // }
        // if (check)
        //     cout << "Yes" << endl;
        // else
        //     cout << "No" << endl;
        ll n, k;
        cin >> n >> k;
        string str1, str2;
        cin >> str1 >> str2;
        map<char, ll> freq1;
        map<char, ll> freq2;
        fo(i, str1.size()) freq1[str1[i]]++;
        fo(i, str2.size()) freq2[str2[i]]++;
        bool check = true;
        fo(i, 26)
        {
            if (freq1[i +'a'] < freq2[i + 'a'])
            {
                check = 0;
                break;
            }
            freq1[i + 'a'] -= freq2[i + 'a'];
            if(freq1[i + 'a'] % k != 0)
            {
                check = 0;
                break;
            }
            freq1[i + 1 + 'a'] += freq1[i + 'a'];
        }
        if (check)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}