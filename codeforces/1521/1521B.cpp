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
int m = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        fo(i, n)
        {
            cin >> a[i];
        }
        vl array_i, array_j, array_x, array_y;
        ll count = 0;
        Fo(i, 1, n)
        {
            if (__gcd(a[i], a[i - 1]) != 1)
            {
                if (a[i] > a[i - 1])
                {
                    ll j = a[i - 1];
                    while (j >= a[i - 1])
                    {
                        if (__gcd(j, a[i - 1]) == 1)
                        {
                            a[i] = j;
                            array_i.push_back(i - 1);
                            array_j.push_back(i);
                            array_x.push_back(a[i - 1]);
                            array_y.push_back(j);
                            count++;
                            break;
                        }
                        j++;
                    }
                }
                else
                {
                    if (i == 1)
                    {
                        ll j = a[i];
                        while (j >= a[i])
                        {
                            if (__gcd(j, a[i]) == 1)
                            {
                                a[i - 1] = j;
                                count++;
                                array_i.push_back(i - 1);
                                array_j.push_back(i);
                                array_x.push_back(j);
                                array_y.push_back(a[i]);
                                break;
                            }
                            j++;
                        }
                    }
                    else
                    {
                        ll j = a[i];
                        while (j >= a[i])
                        {
                            if (__gcd(j, a[i]) == 1 && __gcd(j, a[i - 2]) == 1)
                            {
                                a[i - 1] = j;
                                count++;
                                array_i.push_back(i - 1);
                                array_j.push_back(i);
                                array_x.push_back(j);
                                array_y.push_back(a[i]);
                                break;
                            }
                            j++;
                        }
                    }
                }
            }
        }
        cout << count;
        br;
        fo(i, count)
        {
            cout << array_i[i] + 1 << " " << array_j[i] + 1 << " " << array_x[i] << " " << array_y[i];
            br;
        }
    }
    return 0;
}