class S52
{
    private:
    void set_pos(vector<vector<int>>& chest, int row, int col, int n)
    {
        chest[row][col] = 1;
        for(int i = 0; i < n;i++){
            chest[i][col] = 1;
            chest[row][i] = 1;
        }
        for(int i = row + 1,j = col + 1; i < n && j < n; i++, j++){
            chest[i][j] = 1;
        }
        for(int i = row + 1, j = col - 1; i < n && j >= 0 ; i++, j--){
            chest[i][j] = 1;
        }
    }

    void backtrace(vector<vector<int>>& chest, int m, int n, int& ans)
    {
        if (n == m) {ans++; return;}
        for (int i = 0; i < n; i++) {
            if (chest[m][i] == 0)
            {
                vector<vector<int>> temp = chest;
                set_pos(chest, m, i, n);
                backtrace(chest, m+1, n, ans);
                chest = temp;
            } else {
                continue;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> chest(n); int ans = 0;
        for (int i = 0; i < n; i++) {
            chest[i].resize(n);
        }
        backtrace(chest, 0, n, ans);
        return ans;
    }

    public:
    void test()
    {
        cout << totalNQueens(4) << endl;
        return ;
    }
};
