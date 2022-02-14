#pragma once
#include "Level2.h"

//////////////level 3///////////////////

#pragma region 단어변환
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

int 단어변환(string begin, string target, vector<string> words) {
    int answer = 0;

    for (int i = 0; i < words.size(); i++)
    {
        m.insert({ words[i], 0 });
    }

    answer = BFS(begin, target, words);
    return answer;
}
#pragma endregion

#pragma region 네트워크
bool visited[201] = { false, };
void DFS(int start, vector<vector<int>>& computers)
{
    visited[start] = true;

    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[start][i] == 1)
        {
            if (visited[i] == false)
            {
                DFS(i, computers);
            }
        }
    }
}

int 네트워크(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i, computers);
            answer++;
        }
    }
    return answer;
}
#pragma endregion


