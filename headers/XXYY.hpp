class XX
{
    protected:
        int k;
    public:
        XX(int n = 5): k(n) {}
        ~XX() { cout << "XX"; }
        virtual void f() const = 0;
};

inline void XX::f() const { cout << k+3; }

class YY : public XX
{
    public:
        ~YY() { cout << "YY"; }
        void f() const { cout << k-3; XX::f();}

};
