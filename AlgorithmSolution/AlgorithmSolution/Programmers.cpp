//#include "Level2.h"
#include "Baekjoon.h"
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

map<string, int> m;
bool Check(string current, string next)
{
    int cnt = 0;
    for (int i = 0; i < current.length(); i++)
    {
        if (current[i] != next[i])
        {
            cnt++;
        }
    }

    if (cnt == 1)
    {
        return true;
    }
    return false;
}

int BFS(string current, string target, vector<string>& words)
{
    queue<string> q;
    q.push(current);
    
    while (!q.empty())
    {
        string front = q.front();
        q.pop();

        int prev = 0;
        if (m.find(front) != m.end())
        {
            prev = m[front];
        }

        if (front == target)
        {
            break;
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (m[words[i]] != 0) continue;
            if (!Check(words[i], front)) continue;

            q.push(words[i]);
           
            if (m[words[i]] <= prev)
            {
                m[words[i]] = prev + 1;
            }
        }
    }

    return m[target];
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    for (int i = 0; i < words.size(); i++)
    {
        m.insert({ words[i], 0 });
    }

    answer = BFS(begin, target, words);
    return answer;
}

int main(void)
{
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}