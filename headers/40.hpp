class S40
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
            if (i > index && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i+1, ans, path);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans; vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, ans, path);
        return ans;
    }
    public:
    void test() {
        vector<int> candidates{10,1,2,7,6,1,5};
        int target = 8;
        vector<vector<int>> ans = combinationSum(candidates, target);
        cout << ans.size() << endl;
    }
};
