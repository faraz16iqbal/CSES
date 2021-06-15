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
ll MOD = 1e9 + 7;
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
    int n, m;
    cin >> n >> m;

    vi arr(n + 1);
    forsn(i, 1, n + 1)
    {
        cin >> arr[i];
    }

    int dp[n + 1][m + 1]; // position && value

    memset(dp, 0, sizeof(dp));

    if (arr[1] != 0)
    {
        dp[1][arr[1]] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i] == 0 || arr[i] == j) // arr[i] == j because this position is fixed and no other element can be placed here
            {
                if (j >= 2)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

                if (j <= m - 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    ll totalWays = 0;

    for (int i = 1; i <= m; i++)
    {
        totalWays = (totalWays + dp[n][i]) % MOD;
    }

    cout << totalWays;
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