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



// recursion
#pragma region 1629
// 분할 정복
long long Sol(long long a, long long b, long long c)
{
	if (b <= 0)
	{
		return a % c;
	}

	long long val = Sol(a, b / 2, c);
	val = val * val % c;
	if (val % 2 == 0)
	{
		return val;
	}

	return val * a % c;
}
#pragma endregion

#pragma region 11729
//Hanoi

void Hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return;
	}

	Hanoi(n - 1, from, to, by);
	cout << from << " " << to << "\n";
	Hanoi(n - 1, by, from, to);
}

#pragma endregion

#pragma region 1074
int Z(int n, int r, int c)
{
	if (n == 0) return 0;
	int half = 1 << (n - 1);

	if (r < half && c < half) // 1
	{
		return Z(n - 1, r, c);
	}
	else if (r < half && c >= half) // 2
	{
		return half * half + Z(n - 1, r, c - half);
	}
	else if (r >= half && c < half) // 3
	{
		return 2 * half * half + Z(n - 1, r - half, c);
	}
	else // 4
	{
		return 3 * half * half + Z(n - 1, r - half, c - half);
	}
}
#pragma endregion


// string
#pragma region 1157
int arr[26];

void 단어공부(string s)
{
	string answer;
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}


	for (int i = 0; i < s.length(); i++)
	{
		arr[s[i] - 'A']++;
	}

	int m = -1;
	for (int i = 0; i < 26; i++)
	{
		if (m < arr[i])
		{
			m = arr[i];
			answer = 'A' + i;
		}
		else if (m == arr[i])
		{
			answer = "?";
		}
	}

	cout << answer;
}

#pragma endregion

#pragma region 1152
//int 단어의개수()
//{
//	string s;
//	getline(cin, s);
//
//	stringstream ss(s);
//	string sbuffer;
//	vector<string> v;
//
//	while (getline(ss, sbuffer, ' '))
//	{
//		if (sbuffer != "")
//		{
//			v.push_back(sbuffer);
//		}
//	}
//
//	return v.size();
//}
#pragma endregion

#pragma region 1613
bool 그룹단어체커(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		int j = i;
		while (s[i] == s[j])
		{
			j++;
			if (j >= s.length()) break;
		}

		while (j < s.length())
		{
			if (s[i] == s[j])
				return false;
			j++;
		}

	}

	return true;
}
#pragma endregion


// math
#pragma region 9092
void 골드바흐()
{
	vector<int> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int m = 0;
		cin >> m;
		v.push_back(m);
	}

	vector<bool> arr(10001, false);
	arr[1] = true;
	for (int i = 2; i <= 10000; i++)
	{
		if (arr[i]) continue;

		for (int j = i + i; j <= 10000; j += i)
		{
			arr[j] = true;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i] / 2; j > 0; j--)
		{
			if (!arr[j] && !arr[v[i] - j])
			{
				cout << j << " " << v[i] - j << "\n";
				break;
			}
		}
	}
}
#pragma endregion

#pragma region 2869
void 달팽이는올라가고싶다(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, V;
	cin >> A >> B >> V;

	int day = 0;
	if ((V - B) % (A - B) != 0)
	{
		day = (V - B) / (A - B) + 1;
	}
	else
	{
		day = (V - B) / (A - B);
	}

	cout << day << endl;
}
#pragma endregion

// backTracking
#pragma region 15649
//int N = 0;
//int M = 0;
//vector<int> number;
//bool isUsed[9] = { false, };
//void NAndM()
//{
//	if (number.size() == M)
//	{
//		for (int i = 0; i < M; i++)
//		{
//			cout << number[i] << " ";
//		}
//		cout << "\n";
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (isUsed[i]) continue;
//
//		isUsed[i] = true;
//		number.push_back(i);
//
//		NAndM();
//
//		isUsed[i] = false;
//		number.pop_back();
//	}
//
//}
#pragma endregion

#pragma region 9663
//int N;
//int answer;
//int visited[15];
//
//bool Check(int col)
//{
//	for (int i = 0; i < col; i++)
//	{
//		if (visited[i] == visited[col] || col - i == abs(visited[col] - visited[i]))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//void NQueen(int cnt)
//{
//	if (cnt == N)
//	{
//		answer++;
//		return;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		visited[cnt] = i;
//		if (Check(cnt))
//		{
//			NQueen(cnt + 1);
//		}
//	}
//}
#pragma endregion

#pragma region 14888
//vector<int> cal(4);
//vector<int> v;
//bool isUsed[101] = { false, };
//vector<int> r;
//void Func(int cnt, int result)
//{
//	if (cnt == v.size())
//	{
//		r.push_back(result);
//		return;
//	}
//
//	for (int j = 0; j < 4; j++)
//	{
//		if (cal[j] <= 0) continue;
//
//		int prev = result;
//		if (j == 0)
//		{
//			result += v[cnt];
//		}
//		else if (j == 1)
//		{
//			result -= v[cnt];
//		}
//		else if (j == 2)
//		{
//			result *= v[cnt];
//		}
//		else
//		{
//			result /= v[cnt];
//		}
//		cal[j]--;
//		isUsed[v[cnt]] = true;
//		Func(cnt + 1, result);
//
//		isUsed[v[cnt]] = false;
//		cal[j]++;
//		result = prev;
//	}
//}

#pragma endregion

// etc
#pragma region 2292
void BeeHouse(long long n)
{
	if (n == 1)
	{
		cout << 1;
		return;
	}

	int room = 0;
	int num = 2;
	int mul = 6;

	while (num <= n)
	{
		num += mul * room;
		room++;
	}

	cout << room;
}
#pragma endregion
