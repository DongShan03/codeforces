class S60
{
    public:
    string getPermutation(int n, int k) {
        vector<int> temp(n); int x = k-1; string res; vector<int> use(n+1, 1);
        temp[0] = 1;
        for (int i = 1; i < n; i++) {
            temp[i] = temp[i-1] * i;
        }

        for (int i = 1; i <= n; ++i) {
            int s = x / temp[n-i] + 1;
            for (int j = 1; j <= n; ++j) {
                s -= use[j];
                if (!s) {
                    res += to_string(j);
                    use[j] = 0;
                    break;
                }
            }
            x %= temp[n-i];
        }
        return res;
    }
    void test() {
        cout << getPermutation(3, 3) << endl;
    }
};
