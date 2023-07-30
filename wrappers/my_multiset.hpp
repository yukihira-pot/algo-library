#include <iostream>
#include <set>
#include <vector>
#include <limits>

template <typename T>
struct MyMultiSet {
    constexpr T default_value() {
        const bool is_int = std::is_same_v<T, int>;
        const bool is_ll = std::is_same_v<T, long long>;
        const bool is_pii = std::is_same_v<T, std::pair<int, int>>;
        const bool is_pll = std::is_same_v<T, std::pair<long long, long long>>;
        const bool is_pli = std::is_same_v<T, std::pair<long long, int>>;
        const bool is_pil = std::is_same_v<T, std::pair<int, long long>>;

        if constexpr (is_int or is_ll) {
            return std::numeric_limits<T>::max();
        } else if constexpr (is_pii) {
            return std::make_pair(INT_MAX, INT_MAX);
        } else if constexpr (is_pll) {
            return std::make_pair(LLONG_MAX, LLONG_MAX);
        } else if constexpr (is_pli) {
            return std::make_pair(LLONG_MAX, INT_MAX);
        } else if constexpr (is_pil) {
            return std::make_pair(INT_MAX, LLONG_MAX);
        } else {
            assert();
        }
    }

    using iterator = typename std::multiset<T>::iterator;

    std::multiset<T> data;
    const T NOT_FOUND = default_value();

    MyMultiSet() {}
    MyMultiSet(std::initializer_list<T> l) : data(l) {}
    MyMultiSet(std::vector<T> &v) : data(v.begin(), v.end()) {}

    void insert(T v) { data.insert(v); }
    void erase(T v) { data.erase(data.find(v)); }
    void erase(T v, int cnt) {
        assert(data.size() >= cnt);
        for (int _ = 0; _ < cnt; _++) {
            data.erase(data.find(v));
        }
    }
    void erase_all(T v) { data.erase(v); }

    bool contains(T v) { return data.find(v) != data.end(); }

    iterator begin() {
        return data.begin();
    }
    iterator end() {
        return data.end();
    }

    iterator lower_bound(T v) {
        return data.lower_bound(v);
    }
    iterator upper_bound(T v) {
        return data.upper_bound(v);
    }

    T min_val() { return *data.begin(); }
    T max_val() { return *data.rbegin(); }

    T kth_min_val(int k) {
        assert(data.size() >= k);
        auto it = data.begin();
        std::advance(it, k - 1);
        return *it;
    }
    T kth_max_val(int k) {
        assert(data.size() >= k);
        auto it = data.rbegin();
        std::advance(it, k - 1);
        return *it;
    }

    bool has_leq(const T &v) {
        return data.upper_bound(v) != data.begin();
    }
    bool has_lt(const T &v) {
        return data.lower_bound(v) != data.begin();
    }
    bool has_geq(const T &v) {
        return data.lower_bound(v) != data.end();
    }
    bool has_gt(const T &v) {
        return data.upper_bound(v) != data.end();
    }

    iterator leq(const T &v) {
        return std::prev(data.upper_bound(v));
    }
    iterator lt(const T &v) {
        return std::prev(data.lower_bound(v));
    }
    iterator geq(const T &v) {
        return data.lower_bound(v);
    }
    iterator gt(const T &v) {
        return data.upper_bound(v);
    }

    T leq_val(const T &v) {
        auto it = data.upper_bound(v);
        if (it == data.begin()) return NOT_FOUND;
        return *std::prev(data.upper_bound(v));
    }
    T lt_val(const T &v) {
        auto it = data.lower_bound(v);
        if (it == data.begin()) return NOT_FOUND;
        return *std::prev(data.lower_bound(v));
    }
    T geq_val(const T &v) {
        auto it = data.lower_bound(v);
        if (it == data.end()) return NOT_FOUND;
        return *it;
    }
    T gt_val(const T &v) {
        auto it = data.upper_bound(v);
        if (it == data.end()) return NOT_FOUND;
        return *it;
    }

    void print() {
        std::cout << '[';
        for (auto &e : data) {
            std::cout << e << " ";
        }
        std::cout << "]\n";
    }
};