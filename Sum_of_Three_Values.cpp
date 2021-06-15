#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pair<int, int> p;
        p.first = a;
        p.second = i;
        // first in pair represents value, second represents index
        arr.push_back(p);
    }
    sort(begin(arr), end(arr));
    for (int i = 0; i < n; i++)
    {
        int l, r;
        l = 0;
        r = n - 1;
        while (l != r)
        {
            int target;
            target = x - arr.at(i).first;
            if (l != i && r != i && arr.at(l).first + arr.at(r).first == target)
            {
                cout << arr.at(i).second << " " << arr.at(l).second
                     << " " << arr.at(r).second << endl;
                return;
            }
            if (arr.at(l).first + arr.at(r).first < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1;
    // cin >> t;
    for (int it = 0; it < t; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}