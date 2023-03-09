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
    string str;
    cin >> str;
    ll digits = str.size();
    vector<string> threeDig;
    vector<string> twoDig;
    ll temp = 2;
    while (true)
    {
        if (temp * 8 > 1000)
            break;
        else if (temp * 8 < 100)
            twoDig.pb(to_string(temp * 8));
        else
            threeDig.pb(to_string(temp * 8));
        temp++;
    }
    if (digits == 1)
    {
        if (str[0] == '0' || str[0] == '8')
        {
            cout << "YES";
            br;
            cout << str[0];
            br;
            return 0;
        }
        else
        {
            cout << "NO";
            br;
            return 0;
        }
    }
    else if (digits == 2)
    {
        fo(i, str.size())
        {
            if (str[i] == '8')
            {
                cout << "YES";
                br;
                cout << "8";
                br;
                return 0;
            }
            else if (str[i] == '0')
            {
                cout << "YES";
                br;
                cout << "0";
                br;
                return 0;
            }
        }
        fo(i, twoDig.size())
        {
            char ch0 = twoDig[i][0];
            char ch1 = twoDig[i][1];
            fo(j, digits)
            {
                if (str[j] == ch0)
                {
                    Fo(k, j + 1, digits)
                    {
                        if (str[k] == ch1)
                        {
                            cout << "YES";
                            br;
                            cout << twoDig[i];
                            br;
                            return 0;
                        }
                    }
                }
            }
        }
        cout << "NO";
        br;
        return 0;
    }
    else
    {
        fo(i, str.size())
        {
            if (str[i] == '8')
            {
                cout << "YES";
                br;
                cout << "8";
                br;
                return 0;
            }
            else if (str[i] == '0')
            {
                cout << "YES";
                br;
                cout << "0";
                br;
                return 0;
            }
        }
        fo(i, twoDig.size())
        {
            char ch0 = twoDig[i][0];
            char ch1 = twoDig[i][1];
            fo(j, digits)
            {
                if (str[j] == ch0)
                {
                    Fo(k, j + 1, digits)
                    {
                        if (str[k] == ch1)
                        {
                            cout << "YES";
                            br;
                            cout << twoDig[i];
                            br;
                            return 0;
                        }
                    }
                }
            }
        }
        fo(i, threeDig.size())
        {
            char ch0 = threeDig[i][0];
            char ch1 = threeDig[i][1];
            char ch2 = threeDig[i][2];
            fo(j, digits)
            {
                if (str[j] == ch0)
                {
                    Fo(k, j + 1, digits)
                    {
                        if (str[k] == ch1)
                        {
                            Fo(l, k + 1, digits)
                            {
                                if (str[l] == ch2)
                                {
                                    cout << "YES";
                                    br;
                                    cout << str.substr(0, j) + threeDig[i];
                                    br;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << "NO";
        br;
    }
    return 0;
}