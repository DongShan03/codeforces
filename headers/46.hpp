class S46
{
    private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& nums, int index, vector<int> rest) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        } else {
            for (int i = 0; i < rest.size(); i++) {
                path.push_back(rest[i]);
                rest.erase(rest.begin() + i);
                dfs(nums, index + 1, rest);
                rest.insert(rest.begin() + i, path.back());
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> rest = nums;
        dfs(nums, 0, rest);
        return res;
    }

    public:
    void test()
    {
        vector<int> nums{1,2,3};
        vector<vector<int>> res = permute(nums);
        for (auto i : res) {
            for (auto j : i) {
                cout << j << ", ";
            }
            cout << " / ";
        }
    }
};
