#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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


//2667
//int N;
//int arr[26][26];
//bool visited[26][26] = { false, };
//int dirX[4] = { 1,0,-1,0 };
//int dirY[4] = { 0,1,0,-1 };
//
//int BFS(int x, int y)
//{
//	int group = 1;
//	queue<pair<int, int>> q;
//	q.push({ y,x });
//	visited[y][x] = true;
//	while (!q.empty())
//	{
//		int ny = q.front().first;
//		int nx = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextX = nx + dirX[i];
//			int nextY = ny + dirY[i];
//
//			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
//			if (visited[nextY][nextX]) continue;
//			if (arr[nextY][nextX] == 0) continue;
//
//			q.push({ nextY, nextX });
//			visited[nextY][nextX] = true;
//			group++;
//		}
//	}
//
//	return group;
//}
//
//int main()
//{
//	cin >> N;
//	int cnt = 0;
//	vector<int> v;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			scanf("%1d", &arr[i][j]);
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (arr[i][j] == 1 && visited[i][j] == false)
//			{
//				cnt++;
//				v.push_back(BFS(j, i));
//			}
//		}
//	}
//	sort(v.begin(), v.end());
//	cout << cnt << "\n";
//	for (auto& i : v)
//	{
//		cout << i << "\n";
//	}
//}