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
typedef long double ld;
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
#define fi first
#define se second
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
    int n;
    cin >> n;
    vll arr(n);

    ll total = 0;
    for (auto &x : arr)
    {
        cin >> x;
        total += x;
    }

    ll best = INT_MAX;

    for (int i = 0; i < (1 << n); i++)
    {
        // cout << i << " ";
        ll curr = 0;
        for (int j = 0; j <= i; j++)
        {
            if ((1 << j) & i)
            {
                // cout << (1 << j) << " ";
                curr += arr[j];
            }
        }

        best = min(best, abs(total - (2 * curr)));
    }

    cout << best << ln;
}
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    for (int it = 0; it < t; it++)
    {
        // cout << "Case #" << it + 1 << ": ";
        solve();
    }
    return 0;
}