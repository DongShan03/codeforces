class S45
{
private:
    int jump(vector<int>& nums) {
        int res = 0, start = 0, end = 1;
        while (end < nums.size()) {
            int farthest = 0;
            for (int i = start; i < end; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            start = end;
            end = farthest + 1;
            res++;
        }
        return res;
    }
public:
    void test()
    {
        vector<int> nums{2, 3, 1, 1, 4};
        cout << jump(nums) << endl;
    }
};
