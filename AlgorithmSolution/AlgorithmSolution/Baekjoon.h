#pragma once
#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;

// 2178
//int arr[100][100] = { 0, };
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, -1, 0, 1 };
//int dist[100][100] = { 0, };
//bool visited[100][100] = { false, };
//int M, N;
//void BFS(int a, int b)
//{
//    queue<pair<int, int>> q;
//    q.push({ a,b });
//    dist[a][b]++;
//    while (!q.empty()) {
//        int x = q.front().first;
//        int y = q.front().second;
//        q.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int nextX = x + dx[i];
//            int nextY = y + dy[i];
//
//            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
//            if (dist[nextX][nextY] == 0 && arr[nextX][nextY] == 1)
//            {
//                dist[nextX][nextY] = dist[x][y] + 1;
//                q.push({ nextX, nextY });
//            }
//        }
//    }
//}