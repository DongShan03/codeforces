class S53
{
    private:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }

    public:
    void test()
    {
        vector<int> nums{5,4,-1,7,8};
        cout << maxSubArray(nums) << endl;
        return ;
    }
};
