class S43
{
    private:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(); int n = num2.size();
        int res[m + n + 1];
        memset(res, 0, sizeof(res));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for(int i = 0; i < m + n; i++) {
            if(res[i] > 9) {
                int t = res[i];
                res[i] = t % 10;
                res[i + 1] += (t / 10);
            }
        }

        int pos = (res[m + n - 1] == 0 ? m + n - 2 : m + n - 1);

        string aa = "";
        for(; pos >= 0; --pos) {
            aa += (res[pos] + '0');
        }
        return aa;
    }
    public:
    void test() {
        string num1 = "2", num2 = "3";
        cout << multiply(num1, num2) << endl;
    }
};
