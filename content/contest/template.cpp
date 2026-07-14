#include <bits/stdc++.h>
using namespace std;

// --- User Defined Types & Shorthands ---
using ll = long long;
using ld = long double;
using cd = complex<ld>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;

using vi = vector<int>;
using vd = vector<ld>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vcd = vector<cd>;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

// --- Macros & Utilities ---
#define rep(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<long long>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// --- RNG Seed ---
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// --- Constants ---
const char nl = '\n';
const int N = 2e5+3;
const int MOD = 998244353;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
}
