//#include "Level2.h"
#include "Baekjoon.h"

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> town;

    vector<pair<int,int>> v[50]; // to, dist
    priority_queue<int> pq;

    for (int i = 0; i < road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int dist = road[i][2];

        v[a].push_back({ b, dist });
        v[b].push_back({ a, dist });
    }

    queue<int> q;
    q.push(1);
    int d = 0;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (int i = 0; i < v[n].size; i++)
        {

        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> road =
    {
        {1,2,1},
        {2,3,3},
        {5,2,2},
        {1,4,2},
        {5,3,1},
        {5,4,2}
    };
    
    solution(5, road, 3);

}