// https://codeforces.com/contest/1949/problem/D

#include <bits/stdc++.h>
using namespace std;
set<int> other;
constexpr int M = 24;
char mat[M][M];
int n; int r;
char mainC = 'F', subC = 'S';

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cntF = 0, cntS = 0;
    char temp;
    cin >> n;
    // input char matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp=='F') cntF++;
            if (temp=='S') cntS++;
            mat[i][j] = temp;   
        }
                 
    }
    if (cntF < cntS) swap(mainC, subC);
    // 探查出次要元素的位置     but why?
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][j]==subC){
                other.insert(i);
                other.insert(j);
            } 
        }
                 
    }

    int expectedMain = n / 4 - 1;
    int expectedSub = n - expectedMain;
    int limit = ceil(3*n/4);
    // 在单行中主元素和此元素的数量都不能超过 n *0.75
    while (expectedSub - 1 > limit) expectedMain++, expectedSub--;

    for (int i = 0; i < n; i++)
    {
        if (expectedSub > other.size())
            other.insert(i);
        else
            break;
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1;j < n; j++)
        {
            if (mat[i][j] != '?')
                continue;
            if (other.count(i) && other.count(j))
                mat[i][j] = subC, mat[j][i] = subC;
            else
                mat[i][j] = mainC, mat[j][i] = mainC;
        }

    // for output the char matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j];
            if (j==n-1)
                cout << "\n";  
        }        
    }


    return 0;
}
