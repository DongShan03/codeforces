class S42
{
    private:
    int left, right, temp1, temp2, ans = 0;
    int trap(vector<int>& height) {
        left = 0; right = height.size() - 1;
        if (left >= right) return ans;
        while (height[left] <= height[left+1]) {
            if (left < right) left++;
            else return ans;
        }
        while (height[right] <= height[right-1]) {
            if (right > 1) right--;
            else return ans;
        }
        if (left >= right) return 0;
        while(left < right) {
            temp1 = left + 1;
            temp2 = right - 1;
            if (height[left] < height[right]) {
                while(height[temp1] < height[left] && temp1 < right) {ans += (height[left] - height[temp1]);temp1++;}
                left = temp1;
            } else {
                while(height[temp2] < height[right] && temp2 > left) {ans += (height[right] - height[temp2]);temp2--;}
                right = temp2;
            }
        }
        return ans;
    }
    public:
    void test() {
        vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
        cout << trap(height) << endl;
    }
};
