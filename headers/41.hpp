class S41
{
    private:
    int i, j, k, temp;
    int firstMissingPositive(vector<int>& nums) {
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 || nums[i] > nums.size()) {    //除去所有负数和超出数组范围的数
                nums[i] = 0;
            }
        }
        for (i = 0; i < nums.size(); i++) {
            j = i;
            while (j + 1 != nums[j] && nums[j] != 0) {
                k = nums[j] - 1;
                if (nums[k] == nums[j]) {
                    nums[j] = 0;
                    break;
                }
                temp = nums[k];
                nums[k] = nums[j];
                nums[j] = temp;
            }
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                return i+1;
        }
        return nums.size()+1;
    }

    public:
    void test() {
        vector<int> nums{1};
        cout << firstMissingPositive(nums) << endl;
    }
};
