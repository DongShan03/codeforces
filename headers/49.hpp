class S49
{
    private:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; unordered_map<string, vector<string>> m;
        vector<string> temp_str = strs;
        for (auto& i : temp_str) {
            sort(i.begin(), i.end());
        }
        for (int i = 0 ; i < temp_str.size(); i++) {
            m[temp_str[i]].push_back(strs[i]);
        }
        for (auto i : m) {
            res.push_back(i.second);
        }
        return res;
    }

    public:
    void test()
    {
        vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
        for (auto i : groupAnagrams(strs)) {
            for (auto j : i) {
                cout << j << "\t";
            }
            cout << endl;
        }

    }
};
