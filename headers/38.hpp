class S38
{
    private:
    string countAndSay(int n) {
        string temp = "1"; int i = n; int j, k;
        string end = "";
        while (i > 1)
        {
            for (j = 0; j < temp.length();) {
                k = j + 1;
                while (temp[j]==temp[k] && k < temp.length()) k++;
                end += to_string(k-j); end += temp[j];
                if (k == temp.length()) break;
                j = k;
            }
            temp = end;
            end = "";
            i--;
        }
        return temp;
    }
    public:
    void test()
    {
        cout << countAndSay(4) << endl;
    }
};
