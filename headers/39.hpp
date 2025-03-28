
class S39
{
    private:
    void backtracking(vector<int>& candidates, int target, int sum, int index, vector<vector<int>>& ans, vector<int>& path)
    {
        if (sum > target) return ;
        if (sum == target) {
            ans.push_back(path);
            return ;
        }
        for ( int i = index; i < candidates.size(); i++ ) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i, ans, path);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans; vector<int> path;
        backtracking(candidates, target, 0, 0, ans, path);
        return ans;
    }
    public:
    void test() {
        vector<int> candidates{2, 3, 6, 7};
        int target = 7;
        vector<vector<int>> ans = combinationSum(candidates, target);
        cout << ans.size() << endl;
    }
};
