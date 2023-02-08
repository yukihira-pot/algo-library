template <typename T>
struct Accumulate2D {
    int h, w;
    vector<vector<T>> accum;
    Accumulate2D(vector<vector<T>>& _field) {
        h = _field.size();
        w = _field[0].size();
        accum.resize(h + 1, vector<T>(w + 1, 0));
        init(_field);
    }

    void init(vector<vector<T>>& _field) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                accum[i + 1][j + 1] +=
                    accum[i + 1][j] + accum[i][j + 1] - accum[i][j] + _field[i][j];
            }
        }
    }

    /// @brief [ i1, i2 ), [ j1, j2 ) の範囲にある和を求める
    T query(int i1, int i2, int j1, int j2) {
        return accum[i2][j2] - accum[i1][j2] - accum[i2][j1] + accum[i1][j1];
    }
};