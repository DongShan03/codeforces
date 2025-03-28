class S54
{
    private:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size()  == 0) return ans;
        int m = matrix.size(); int n = matrix[0].size();
        int col = 0, row = 0;
        while(1) {
            for (int i = row; i <= n - 1; i++) ans.push_back(matrix[col][i]);
            if (++col >= m) break;
            for (int i = col; i <= m - 1; i++) ans.push_back(matrix[i][n-1]);
            if (--n <= row) break;
            for (int i = n - 1; i >= row; i--) ans.push_back(matrix[m-1][i]);
            if (--m <= col) break;
            for (int i = m - 1; i >= col; i--) ans.push_back(matrix[i][row]);
            if (++row >= n) break;
        }
        return ans;
    }

    public:
    void test()
    {
        vector<vector<int>> matrix{{1, 2 ,3}, {4, 5, 6}, {7, 8, 9}};
        vector<int> ans = spiralOrder(matrix);
        for (auto i : ans) {
            cout << i << "\t";
        }
        return ;
    }
};
