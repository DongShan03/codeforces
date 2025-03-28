class S50
{
    private:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n == -2147483648) return (1 / x) / myPow(x, -(n+1));
        else if (n < 0) return 1 / myPow(x, -n);

        double temp = myPow(x, n / 2);
        if (n % 2 == 0) return temp * temp;
        else return temp * temp * x;
    }

    public:
    void test()
    {
        double x = 2.00000; int n = 10;
        cout << myPow(x, n) << endl;
        return ;
    }
};
