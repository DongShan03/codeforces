class S51
{
    private:
    vector<vector<string>> res;
    bool test_position(vector<string>& empty, int row, int col)
    {
        for(int i=0;i<empty.size();i++){//前两个都是行列搜索
            if(empty[i][col] == 'Q'){
                return false;
            }
        }
        for(int i=0;i<empty.size();i++){
            if(empty[row][i] == 'Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){//这里注意，斜向搜索只搜索该坐标上方的区域，下方不搜索
            if(empty[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0&&j<=empty.size();i--,j++){
            if(empty[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void backtrace(vector<string>& empty, int m, int n)
    {
        if (n == m) res.push_back(empty);
        for (int i = 0; i < n; i++) {
            if (test_position(empty, m, i))
            {
                empty[m][i] = 'Q';
                backtrace(empty, m+1, n);
                empty[m][i] = '.';
            } else {
                continue;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp; string t; int i;
        for (i = 0; i < n; i++) {t+=".";}
        for (i = 0; i < n; i++) {temp.push_back(t);}
        backtrace(temp, 0, n);
        return res;
    }

    public:
    void test()
    {
        vector<vector<string>> res = solveNQueens(4);
        for (auto i : res) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n" ;
        }
        solveNQueens(4);
        return ;
    }
};
