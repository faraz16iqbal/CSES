#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

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
    int m, n, diff;
    cin >> m >> n >> diff;

    vi desired(m), sizes(n);

    forn(i, m)
    {
        cin >> desired[i];
    }

    forn(i, m)
    {
        cin >> sizes[i];
    }

    sort(all(sizes));
    sort(all(desired));

    int i = 0, j = 0;
    int cnt = 0;
    while (i < m && j < n)
    {
        int curr = (desired[i] - sizes[j]);

        if (curr < 0)
        {
            if (abs(curr) <= diff)
            {
                cnt++, i++, j++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            if (curr <= diff)
            {
                cnt++;
                i++, j++;
            }
            else
            {
                j++;
            }
        }
    }

    cout << cnt << ln;
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
        // cout << "Case #" << it + 1 << ": ";
        solve();
    }
    return 0;
}