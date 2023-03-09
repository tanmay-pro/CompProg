#include <bits/stdc++.h>
#include <time.h>
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

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    // clock_t start, end;
    // double cpu_time_used;
    // start = clock();
    while (t--)
    {
        string p;
        char ch;
        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ')
                p += ch;
        }
        ll n;
        cin >> n;
        vs l;
        vs r;
        string x;
        fo(i, n)
        {
            string str = "";
            char ch;
            while ((ch = getchar()) != 'M')
            {
                if (ch != ' ')
                    str += ch;
            }
            str += 'M';
            l.push_back(str);
            str = "";
            while ((ch = getchar()) != '\n')
            {
                if (ch != ' ')
                    str += ch;
            }
            r.push_back(str);
        }
        ll time;
        ll num1 = (int)p[0] - 48;
        ll num2 = (int)p[1] - 48;
        time = (num1 * 10 + num2) * 60;
        if (time == 720)
        {
            time = time - 720;
        }
        time += ((int)p[3] - 48) * 10 + ((int)p[4] - 48);
        if (p[5] == 'P')
        {
            time += 720;
        }
        vl left_check;
        fo(i, n)
        {
            ll temp = 0;
            ll num1 = (int)l[i][0] - 48;
            ll num2 = (int)l[i][1] - 48;
            temp = (num1 * 10 + num2) * 60;
            if (temp == 720)
            {
                temp = temp - 720;
            }
            temp += ((int)l[i][3] - 48) * 10 + ((int)l[i][4] - 48);
            if (l[i][5] == 'P')
            {
                temp += 720;
            }
            left_check.push_back(temp);
        }
        vl right_check;
        fo(i, n)
        {
            ll temp;
            ll num1 = (int)r[i][0] - 48;
            ll num2 = (int)r[i][1] - 48;
            temp = (num1 * 10 + num2) * 60;
            if (temp == 720)
            {
                temp = temp - 720;
            }
            temp += ((int)r[i][3] - 48) * 10 + ((int)r[i][4] - 48);
            if (r[i][5] == 'P')
            {
                temp += 720;
            }
            right_check.push_back(temp);
        }
        fo(i, n)
        {
            if (time >= left_check[i] && time <= right_check[i])
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        br;
    }
    // end = clock();
    // cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // cout << cpu_time_used;
    // br;
    return 0;
}