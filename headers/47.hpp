class S47
{
    private:
    vector<vector<int>> res;
    vector<int> path, visit;
    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                    if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])) {continue;}
                    path.push_back(nums[i]);
                    visit[i] = 1;
                    dfs(nums, index + 1);
                    visit[i] = 0;
                    path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visit.resize(nums.size());
        dfs(nums, 0);
        return res;
    }

    public:
    void test()
    {
        vector<int> nums{1, 1, 2, 3, 3, 5, 5};
        vector<vector<int>> res = permuteUnique(nums);
        for (auto i : res) {
            for (auto j : i) {
                cout << j << ", ";
            }
            cout << " / ";
        }
    }
};
