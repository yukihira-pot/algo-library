template <typename T>
struct FenwickTree {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    FenwickTree(int n_) : n(), dat(n_ * 4, 0) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    // a_1 + ... + a_i
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += dat[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, T x) {
        while (i <= n) {
            dat[i] += x;
            i += i & -i;
        }
    }

    // a_l + ... + a_{r-1}
    T query(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }
};