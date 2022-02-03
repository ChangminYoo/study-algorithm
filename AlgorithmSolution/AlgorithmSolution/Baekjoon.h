#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

// Graph
#pragma region 2178
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

#pragma endregion

#pragma region 2667
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
#pragma endregion

#pragma region 2606
//int cnt = 0;
//vector<int> v[100];
//bool visited[100];
//void DFS(int start, int n)
//{
//	if (start != 1)
//	{
//		cnt++;
//	}
//	visited[start] = true;
//
//	for (int i = 0; i < v[start].size(); i++)
//	{
//		int next = v[start][i];
//		if (visited[next] == false)
//		{
//			DFS(next, n);
//		}
//	}
//
//}
//
//int main()
//{
//	int n, l;
//	cin >> n;
//	cin >> l;
//
//	for (int i = 0; i < l; i++)
//	{
//		int l1, l2;
//
//		cin >> l1 >> l2;
//	
//		v[l1].push_back(l2);
//		v[l2].push_back(l1);
//	}
//
//	DFS(1, n);
//
//	cout << cnt;
//}
#pragma endregion

#pragma region 7576
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int arr[1001][1001];
//int dist[1001][1001] = { 0, };
//int n, m;
//int day = 0;
//queue<pair<int, int>> q;
//void BFS(int sx, int sy)
//{
//	
//	q.push({ sx, sy });
//
//	while (!q.empty())
//	{
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
//			if (arr[ny][nx] != 0) continue;
//
//			arr[ny][nx] = 1;			
//			
//			dist[ny][nx] = dist[y][x] + 1;
//
//			q.push({ nx, ny });
//		}
//
//	}
//}
//
//int main()
//{
//	scanf("%d %d", &m, &n);
//
//	int sx = -1;
//	int sy = -1;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		
//			if (arr[i][j] == 1)
//			{
//				sx = j;
//				sy = i;
//				q.push({ sx, sy });
//			}
//		}
//	}
//
//	BFS(sx, sy);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (arr[i][j] == 0)
//			{
//				day = -1;
//				break;
//			}
//			else
//			{
//				day = max(dist[i][j], day);
//			}
//		}
//
//		if (day == -1) break;
//	}
//
//	printf("%d", day);
//}
#pragma endregion

#pragma region 1697
//bool visited[100001];
//int time[100001];
//void Sol(int n, int k)
//{
//    queue<int> q;
//    q.push(n);
//    visited[n] = true;
//    while (!q.empty())
//    {
//        int front = q.front();
//        q.pop();
//
//        if (front < 0 || front > 100000) continue;
//        if (front == k)
//        {
//            break;
//        }
//
//        if (front - 1 >= 0 && front - 1 <= 100000 && visited[front - 1] == false)
//        {
//            visited[front - 1] = true;
//            q.push(front - 1);
//            time[front - 1] = time[front] + 1;
//        }
//        if (front + 1 >= 0 && front + 1 <= 100000 && visited[front + 1] == false)
//        {
//            visited[front + 1] = true;
//            q.push(front + 1);
//            time[front + 1] = time[front] + 1;
//        }
//        if (front * 2 >= 0 && front * 2 <= 100000 && visited[front * 2] == false)
//        {
//            visited[front * 2] = true;
//            q.push(front * 2);
//            time[front * 2] = time[front] + 1;
//        }
//
//    }
//}
#pragma endregion

#pragma region 11724
//vector<int> v[1001];
//bool visited[1001];
//
//void dfs(int n)
//{
//    for (int i = 0; i < v[n].size(); i++)
//    {
//        int next = v[n][i];
//        if (visited[next]) continue;
//
//        visited[next] = true;
//        dfs(next);
//    }
//}
//
//int main()
//{
//    int N, M;
//    cin >> N >> M;
//
//    for (int i = 0; i < M; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//
//        v[a].push_back(b);
//        v[b].push_back(a);
//    }
//    int cnt = 0;
//    for (int i = 1; i <= N; i++)
//    {
//        if (visited[i] == false)
//        {
//            visited[i] = true;
//            dfs(i);
//            cnt += 1;
//        }
//    }
//
//    cout << cnt;
//}
#pragma endregion

// Greedy
#pragma region 11399
//int main()
//{
//    int N;
//    int time = 0, tmp = 0;
//    int* arr = new int[N];
//
//    scanf("%d", &N);
//
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    sort(arr, arr + N);
//
//    for (int i = 0; i < N; i++)
//    {
//        tmp += arr[i];
//        time += tmp;
//    }
//    printf("%d\n", time);
//}
#pragma endregion
