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

// set<int> s;
// const int maxN = (1e5 + 5);
// bool dp[105][maxN];

void helper(int id, vi arr, int sum)
{
    if (id == sz(arr))
    {
        // return true;
        cout << sum << " ";
    }

    helper(id + 1, arr, sum + arr[id]);
    helper(id + 1, arr, sum);
}

void solve()
{
    int n;
    cin >> n;
    int max_sum = n * 1000;

    vector<int> x(n);

    for (int &v : x)
        cin >> v;

    vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= max_sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - x[i - 1];
            if (left >= 0 && dp[i - 1][left])
            {
                dp[i][j] = true;
            }
        }
    }

    vector<int> possible;
    for (int j = 1; j <= max_sum; j++)
    {
        if (dp[n][j])
        {
            possible.push_back(j);
        }
    }
    cout << possible.size() << endl;
    for (int v : possible)
    {
        cout << v << ' ';
    }
    cout << endl;
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