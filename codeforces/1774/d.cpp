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
        ll n, m;
        cin >> n >> m;
        vvl a(n, vl(m));
        ll totalOnes = 0;
        vl onesArray;
        fo(i, n)
        {
            fo(j, m)
            {
                cin >> a[i][j];
            }
            ll ones = count(a[i].begin(), a[i].end(), 1);
            onesArray.push_back(ones);
            totalOnes += ones;
        }
        if (totalOnes % n != 0)
        {
            cout << -1 << endl;
            continue;
        }
        ll eachLine = totalOnes / n;
        queue<ll> excess;
        queue<ll> def;
        vvl ans;
        fo(i, n)
        {
            ll cnt = onesArray[i];
            if (cnt == eachLine)
                continue;
            else
            {
                if (cnt > eachLine)
                    excess.push(i);
                else
                    def.push(i);
            }
        }
        bool status = true;
        while (def.size() > 0)
        {
            ll currInd = def.front();
            if (excess.empty())
            {
                status = false;
                cout << -1 << endl;
                break;
            }
            ll currInd2 = excess.front();
            ll need = eachLine - onesArray[currInd];
            ll give = onesArray[currInd2] - eachLine;
            bool ch =false;
            fo(i, m)
            {
                if (a[currInd2][i] == 1 && a[currInd][i] == 0)
                {
                    a[currInd2][i] = 0;
                    a[currInd][i] = 1;
                    give--;
                    need--;
                    onesArray[currInd]++;
                    onesArray[currInd2]--;
                    ans.push_back({currInd, currInd2, i});
                    if (give == 0)
                    {
                        excess.pop();
                        break;
                    }
                }
                if (need == 0)
                {
                    def.pop();
                    ch = true;
                    break;
                }
            }
            if (need == 0 && ch == false)
            {
                def.pop();
            }
            // fo(i, m)
            // {

            //     if (a[currInd2][i] == 1 && a[currInd][i] == 0)
            //     {
            //         a[currInd2][i] = 0;
            //         a[currInd][i] = 1;
            //         onesArray[currInd]++;
            //         onesArray[currInd2]--;
            //         ans.push_back({currInd, currInd2, i});
            //         def.pop();
            //         excess.pop();
            //         break;
            //     }
            // }
        }
        if (status)
        {
            cout << ans.size() << endl;
            fo(i, ans.size())
            {
                fo(j, ans[i].size())
                {
                    cout << ans[i][j] + 1 << " ";
                }
                br;
            }
        }
    }
    return 0;
}