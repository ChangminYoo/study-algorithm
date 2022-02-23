//#include "Level2.h"
#include "Baekjoon.h"
#include <bits/stdc++.h>
using namespace std;

int L,S;
vector<int> v;
int cnt = 0;
void Sol(int sum, int start)
{
    if (sum == S)
    {
        cnt++;
        return;
    }

    if (start == S) return;
    Sol(sum, start + 1);
    Sol(sum + v[start], start +1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> S;

    for (int i = 0; i < L; i++)
    {
        int n = 0;
        cin >> n;
        v.push_back(n);
    }

    Sol(0, 0);
    cout << cnt;
}