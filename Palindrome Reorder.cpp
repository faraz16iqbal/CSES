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

    string s;
    cin >> s;

    int n = int(s.length());

    vi freq(26, 0);

    for (auto &x : s)
    {
        freq[x - 'A']++;
    }

    int oddcnt = 0, oddind = -1;
    forn(i, 26)
    {
        oddcnt += (freq[i] % 2);
        if (freq[i] % 2)
        {
            oddind = i;
        }
    }

    if (oddcnt > 1)
    {
        cout << "NO SOLUTION\n";
        return;
    }

    vector<char> ans(n);

    if (oddcnt != 0)
    {
        ans[(n / 2)] = oddind + 'A';
        freq[oddind]--;
    }

    int x = 0;

    int i = 0, j = n - 1;

    while (i < j && x < 26)
    {

        if (freq[x])
        {
            ans[i++] = x + 'A';
            ans[j--] = x + 'A';
            freq[x] -= 2;
        }

        if (freq[x] <= 0)
        {
            ++x;
        }
    }

    for (auto &x : ans)
    {
        cout << x;
    }
}

int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    for (int it = 0; it < t; it++)
    {
        //  cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}