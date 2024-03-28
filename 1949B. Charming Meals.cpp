//https://codeforces.com/contest/1949/problem/B

#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e3+3;
int n, w, v, t;
int appetizers[N]; int meals[N];

int main(){
    cin >> t;
    while(t--)
    {    
        cin>>n;
        for (int i = 0; i < n ; i++)
            cin>>appetizers[i];
        for (int i = 0; i < n ; i++)
            cin>>meals[i];
        
        sort(appetizers, appetizers+n);
        sort(meals, meals+n);

        v = 0;

        for (int i = 0; i<n; i++)
        {
            w = 1e9;
            for (int j = 0; j < n; j++) w=min(w, abs(appetizers[j]-meals[(j+i)%n]));
            v = max(v, w);
        }
        cout << v << "\n";
    }
    return 0;
}