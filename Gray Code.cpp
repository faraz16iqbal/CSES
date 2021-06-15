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
    if (n <= 0)
        return;

    vector<string> arr;

    arr.push_back("0");
    arr.push_back("1");

    int i = 0, j = 0;
    for (i = 2; i < (1 << n); i = i << 1)
    {
        // Enter the prviously generated codes again in arr[] in reverse
        // order. Nor arr[] has double number of codes.
        for (j = i - 1; j >= 0; j--)
            arr.push_back(arr[j]);

        // append 0 to the first half
        for (j = 0; j < i; j++)
            arr[j] = "0" + arr[j];

        // append 1 to the second half
        for (j = i; j < 2 * i; j++)
            arr[j] = "1" + arr[j];
    }

    for (i = 0; i < int(arr.size()); i++)
        cout << arr[i] << endl;
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