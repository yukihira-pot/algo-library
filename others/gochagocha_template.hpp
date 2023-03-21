#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN
#include __FILE__

// #include <atcoder/all>
// const ll MOD = 998244353;
// const ll MOD = 1000000007; // 1e9 + 7
// using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;



void solve() {
    
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false); 
    cout << fixed << setprecision(12);

    int testcases = 1;
    // cin >> testcases;
    while(testcases--) solve();
}

#else // INCLUDED_MAIN

#ifdef poyo

#include "my_pch.h"

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vpl = vector<pll>;

#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define fore(i, a) for (auto&& i : a)
#define all(x) (x).begin(), (x).end()
#define pb push_back

#define UNIQUIFY(v) v.erase(unique(v.begin(), v.end()), v.end());
#define out(x) \
    { cout << fixed << setprecision(12) << x << "\n"; }
#define dbg(x) \
    { cerr << #x << ": " << x << "\n"; }
#define inc(x, l, r) ((l) <= (x) and (x) < (r))

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;

template <typename S, typename T>
bool chmax(S& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename S, typename T>
bool chmin(S& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class... T>
constexpr auto min(T... a) {
    return min(initializer_list<common_type_t<T...>>{a...});
}
template <class... T>
constexpr auto max(T... a) {
    return max(initializer_list<common_type_t<T...>>{a...});
}

int equal_or_smaller_nums(int elem, vector<int> &v) {
    return upper_bound(v.begin(), v.end(), elem) - v.begin();
}
int equal_or_smaller_nums(long long elem, vector<long long> &v) {
    return upper_bound(v.begin(), v.end(), elem) - v.begin();
}

int smaller_nums(int elem, vector<int> &v) {
    return lower_bound(v.begin(), v.end(), elem) - v.begin();
}
int smaller_nums(long long elem, vector<long long> &v) {
    return lower_bound(v.begin(), v.end(), elem) - v.begin();
}

int equal_or_larger_nums(int elem, vector<int> &v) {
    return v.end() - lower_bound(v.begin(), v.end(), elem);
}
int equal_or_larger_nums(long long elem, vector<long long> &v) {
    return v.end() - lower_bound(v.begin(), v.end(), elem);
}

int larger_nums(int elem, vector<int> &v) {
    return v.end() - upper_bound(v.begin(), v.end(), elem);
}
int larger_nums(long long elem, vector<long long> &v) {
    return v.end() - upper_bound(v.begin(), v.end(), elem);
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    int sz = (int)v.size();
    for (int i = 0; i < sz; i++) {
        os << v[i] << (i == sz - 1 ? "" : " ");
    }
    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    int sz = (int)v.size();
    for (int i = 0; i < sz; i++) {
        is >> v[i];
    }
    return is;
}

int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};

#endif // poyo
#endif // INCLUDED_MAIN