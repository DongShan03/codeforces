class S48
{
    private:
    void rotate(vector<vector<int>>& matrix) {
        int temp; int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 -j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }

    public:
    void test()
    {
        vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        rotate(matrix);
        for (auto i : matrix) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
