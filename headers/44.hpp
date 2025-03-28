class S44
{
private:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size(); int i = 0, j = 0; int ipos = -1, jpos = -1;
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) { i++; j++; }
            else if (j < n && p[j] == '*') {
                ipos = i; jpos = j++;
            }
            else if (ipos >= 0) {
                i = ++ipos;
                j = jpos + 1;
            }
            else return i == m;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
public:
    void test()
    {
        string s = "aa", p = "a";
        cout << isMatch(s, p) << endl;
    }

};
