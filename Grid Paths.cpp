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

// vector<string> vec;
vector<vector<bool>> visited(7, vector<bool>(7, false));
ll cnt = 0;

void helper(int i, int j, string curr)
{
    if (i > 5 || j > 5 || i < 0 || j < 0)
    {
        return;
    }
    if (visited[i][j])
        return;

    if (i == 5 && j == 0)
    {
        cnt++;
        // vec.push_back(curr);
        return;
    }
    visited[i][j] = true;

    if (i > 0 && !visited[i - 1][j])
    {
        helper(i - 1, j, curr + "L");
    }

    if (j > 0 && !visited[i][j - 1])
    {
        helper(i, j - 1, curr + "U");
    }

    if (i < 5 && !visited[i + 1][j])
    {

        helper(i + 1, j, curr + "R");
    }

    if (j < 5 && !visited[i][j + 1])
    {

        helper(i, j + 1, curr + "D");
    }

    visited[i][j] = false;
}

void solve()
{
    string s;
    cin >> s;
    helper(0, 0, "");

    cout << cnt << ln;

    // for (auto &i : vec)
    // {
    //     cout << i << ln;
    // }
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