template <typename T>
struct SimplePrimeFact {
    bool is_prime(T M) {
        if (M == 1) return false;
        for (T i = 2; i * i <= M; i++) {
            if (M % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector<T> get_divisor(T M) {
        vector<T> res;
        for (T i = 1; i * i <= M; i++) {
            if (M % i == 0) {
                res.push_back(i);
                if (i != M / i) {
                    res.push_back(M / i);
                }
            }
        }
        return res;
    }

    vector<pair<T, int>> get_prime_factrization(T M) {
        vector<pair<T, int>> res;
        for (T i = 2; i * i <= M; i++) {
            pll pu = {i, 0};
            while (M % i == 0) {
                M /= i;
                pu.second++;
            }
            if (pu.second > 0) res.push_back(pu);
        }
        if (M != 1) res.push_back({M, 1});
        return res;
    }
};

/*  PrimeFact
    init(N): 初期化。O(N log log N)
    get(n): クエリ。素因数分解を求める。O(log n)
 */
struct RapidPrimeFact {
    vector<int> spf;
    RapidPrimeFact(int N) { init(N); }
    void init(int N) { // 前処理。spf を求める
        spf.assign(N + 1, 0);
        for (int i = 0; i <= N; i++) spf[i] = i;
        for (int i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    bool is_prime(int n) {
        if (n == 1) return false;
        return spf[n] == n;
    }

    vector<pair<int, int>> get_prime_factorization(int n) { 
        vector<pair<int, int>> res;
        pair<int, int> cur = {spf[n], 0};
        while (n != 1) {
            if (spf[n] == cur.first) {
                cur.second++;
            } else {
                res.push_back(cur);
                cur = {spf[n], 1};
            }
            n /= spf[n];
        }
        res.push_back(cur);
        return res;
    }
};