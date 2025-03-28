class S59
{
    public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        res.resize(n);
        for (int u = 0; u < n; u++) res[u].resize(n);
        int i = 0, j = 0, x = n - 1, y = n - 1; int t = 1;
        while (i <= x && j <= y) {
            for (int k = j; k <= y; k++) {
                res[i][k] = t++;
            }
            i++;
            for (int k = i; k <= x; k++) {
                res[k][y] = t++;
            }
            y--;
            for (int k = y; k >= j; k--) {
                res[x][k] = t++;
            }
            x--;
            for (int k = x; k >= i; k--) {
                res[k][j] = t++;
            }
            j++;
        }
        return res;
    }
    void test() {
        int n = 6;
        vector<vector<int>> res = generateMatrix(n);
        for (auto i :res) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
