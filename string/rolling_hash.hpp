struct RollingHash {
    string S;
    int N;       // S の長さ
    long long b; // 基数
    static constexpr long long m1 = 998244353;  // 法1
    static constexpr long long m2 = 1000000007; // 法2
    vector<long long> prefix1, prefix2; // prefix1[i] := S[:i] のハッシュ
    vector<long long> power1, power2;  // power1[i] := pow(b, i)
    random_device rand;

    RollingHash(string &S_) : S(S_) {
        b = rand() % min(m1, m2);
        N = (int)S.size();
        prefix1.assign(N + 1, 0);
        prefix2.assign(N + 1, 0);
        power1.assign(N + 1, 1);
        power2.assign(N + 1, 1);
        // prefix と power の前処理
        for (int i = 0; i < N; i++) {
            prefix1[i + 1] = (prefix1[i] * b + (long long)S[i]) % m1;
            prefix2[i + 1] = (prefix2[i] * b + (long long)S[i]) % m2;
            power1[i + 1] = (power1[i] * b) % m1;
            power2[i + 1] = (power2[i] * b) % m2;
        }
    }

    // S[l, r) のハッシュ値を求める. O(1)
    long long get1(int l, int r) {
        return ((prefix1[r] - power1[r - l] * prefix1[l]) % m1 + m1) % m1;
    }
    long long get2(int l, int r) {
        return ((prefix2[r] - power2[r - l] * prefix2[l]) % m2 + m2) % m2;
    }

    // S1 + S2 のハッシュ値を求める. O(1)
    // h1 : S1 のハッシュ値, h2 : S2 のハッシュ値
    // l2 : S2 の長さ
    long long concat1(long long h1, long long h2, int l2) {
        return (power1[l2] * h1 % m1 + h2) % m1;
    }
    long long concat2(long long h1, long long h2, int l2) {
        return (power2[l2] * h1 % m2 + h2) % m2;
    }

    // S[l1, r1) と S[l2, r2) のハッシュ値が等しいか調べる. O(1)
    bool is_same(int l1, int r1, int l2, int r2) {
        return (get1(l1, r1) == get1(l2, r2)) && (get2(l1, r1) == get2(l2, r2));
    }

    // S[l1, r1) と S[l2, r2) の最大共通接頭辞を求める. O(log N)
    int get_lcp(int l1, int r1, int l2, int r2) {
        int ok = 0;
        int ng = min(r1 - l1, r2 - l2) + 1;
        while (ng - ok > 1) {
            int mid = (ng + ok) >> 1;
            if (is_same(l1, l1 + mid, l2, l2 + mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }
};