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

#pragma region 14502
//vector<vector<int>> v(8);
//vector<pair<int, int>> wall;
//vector<pair<int, int>> virus;
//int N, M;
//bool visited[8][8] = { false, };
//int dx[4] = { 1, 0, -1 ,0 };
//int dy[4] = { 0, 1, 0, -1 };
//int answer = 0;
//
//int BFS(vector<vector<int>> cv)
//{
//	queue<pair<int, int>> q;
//	for (int i = 0; i < virus.size(); i++)
//	{
//		int x = virus[i].first;
//		int y = virus[i].second;
//		q.push({ x, y });
//		visited[x][y] = true;
//	}
//
//	while (!q.empty())
//	{
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextX = x + dx[i];
//			int nextY = y + dy[i];
//
//			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
//			if (visited[nextX][nextY]) continue;
//			if (cv[nextX][nextY] == 0)
//			{
//				visited[nextX][nextY] = true;
//				cv[nextX][nextY] = 2;
//				q.push({ nextX, nextY });
//			}
//		}
//	}
//
//	int count = 0;;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (cv[i][j] == 0)
//			{
//				count++;
//			}
//		}
//	}
//	return count;
//}
//
//void MakeWall(int index, int wallCount)
//{
//	if (wallCount == 3)
//	{
//		for (int i = 0; i < 8; i++)
//		{
//			for (int j = 0; j < 8; j++)
//			{
//				visited[i][j] = false;
//			}
//		}
//
//		answer = max(answer, BFS(v));
//		return;
//	}
//
//	for (int i = index; i < wall.size(); i++)
//	{
//		int x = wall[i].first;
//		int y = wall[i].second;
//
//		v[x][y] = 1;
//		MakeWall(i + 1, wallCount + 1);
//		v[x][y] = 0;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			int n;
//			cin >> n;
//			v[i].push_back(n);
//
//			if (n == 0)
//			{
//				wall.push_back({ i,j });
//			}
//			else if (n == 2)
//			{
//				virus.push_back({ i, j });
//			}
//		}
//	}
//
//	MakeWall(0, 0);
//	cout << answer;
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

#pragma region 14889
//vector<int> state[20];
//vector<int> total;
//bool isUsed[20] = { false, };
//int N;
//void StartAndLink(int num, int start)
//{
//	if (num == N / 2)
//	{
//		int t1 = 0;
//		int t2 = 0;
//
//		for (int i = 0; i < N; i++)
//		{
//			if (isUsed[i])
//			{
//				for (int j = 0; j < state[i].size(); j++)
//				{
//					if (isUsed[j])
//					{
//						t1 += state[i][j];
//					}
//				}
//			}
//			else
//			{
//				for (int j = 0; j < state[i].size(); j++)
//				{
//					if (!isUsed[j])
//					{
//						t2 += state[i][j];
//					}
//				}
//			}
//		}
//
//		total.push_back(abs(t1 - t2));
//		return;
//	}
//
//	for (int i = start; i < N; i++)
//	{
//		if (isUsed[i]) continue;
//
//		isUsed[i] = true;
//		num += 1;
//		Sol(num, i);
//		isUsed[i] = false;
//		num -= 1;
//	}
//}
#pragma endregion

#pragma region 6603

//int k;
//vector<int> v;
//vector<vector<int>> ss;
//bool isUsed[50] = { false, };
//void Lotto(vector<int>& s, int start)
//{
//	if (s.size() == 6)
//	{
//		ss.push_back(s);
//		return;
//	}
//
//	for (int i = start; i < v.size(); i++)
//	{
//		if (isUsed[v[i]]) continue;
//
//		isUsed[v[i]] = true;
//		s.push_back(v[i]);
//		Lotto(s, i);
//		isUsed[v[i]] = false;
//		s.pop_back();
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	while (1)
//	{
//		cin >> k;
//		if (k == 0) break;
//
//		v.clear();
//		fill(isUsed, isUsed + 50, false);
//		for (int i = 0; i < k; i++)
//		{
//			int n;
//			cin >> n;
//			v.push_back(n);
//		}
//		vector<int> s;
//		Lotto(s, 0);
//		ss.push_back({ -1, -1 });
//	}
//
//
//	for (int i = 0; i < ss.size(); i++)
//	{
//		for (int j = 0; j < ss[i].size(); j++)
//		{
//			if (ss[i][j] == -1) break;
//			cout << ss[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//}
#pragma endregion

#pragma region 1759
//int L, C;
//vector<char> v;
//map<char, int> m;
//bool isUsed[26] = { false, };
//
//bool CheckJaoumCount(vector<char>& c)
//{
//	int cnt = 0;
//	for (int i = 0; i < c.size(); i++)
//	{
//		if (c[i] != 'a' && c[i] != 'e' && c[i] != 'i' && c[i] != 'o' && c[i] != 'u')
//		{
//			cnt++;
//		}
//	}
//
//	if (cnt >= 2)
//		return true;
//
//	return false;
//}
//
//void Sol(vector<char>& c, int start)
//{
//	if (c.size() == L)
//	{
//		if (m['a'] <= 0 && m['e'] <= 0 && m['i'] <= 0 && m['o'] <= 0 && m['u'] <= 0)
//			return;
//		if (!CheckJaoumCount(c)) return;
//
//		for (int i = 0; i < c.size(); i++)
//		{
//			cout << c[i];
//		}
//		cout << "\n";
//		return;
//	}
//
//	for (int i = start; i < v.size(); i++)
//	{
//		if (isUsed[v[i] - 'a']) continue;
//
//		auto iter = m.find(v[i]);
//		if (iter != m.end())
//		{
//			(*iter).second += 1;
//		}
//
//		isUsed[v[i] - 'a'] = true;
//		c.push_back(v[i]);
//		Sol(c, i);
//		c.pop_back();
//		isUsed[v[i] - 'a'] = false;
//
//		if (iter != m.end())
//		{
//			(*iter).second -= 1;
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> L >> C;
//
//	m.insert({ 'a', 0 });
//	m.insert({ 'e', 0 });
//	m.insert({ 'i', 0 });
//	m.insert({ 'o', 0 });
//	m.insert({ 'u', 0 });
//
//	for (int i = 0; i < C; i++)
//	{
//		char c;
//		cin >> c;
//		v.push_back(c);
//	}
//
//	sort(v.begin(), v.end());
//	vector<char> c;
//	Sol(c, 0);
//
//}
#pragma endregion

// DP
#pragma region 1463
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N;
//
//	v[1] = 0;
//	for (int i = 2; i <= N; i++)
//	{
//		v[i] = v[i - 1] + 1;
//		if (i % 3 == 0)
//		{
//			v[i] = min(v[i / 3] + 1, v[i]);
//		}
//		else if (i % 2 == 0)
//		{
//			v[i] = min(v[i / 2] + 1, v[i]);
//		}
//	}
//	cout << v[N];
//}

#pragma endregion

#pragma region 1003
//vector<int> fibo(100);
//vector<pair<int, int>> v(100);
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N;
//
//	fibo[0] = fibo[1] = 1;
//	v[0] = { 1, 0 };
//	v[1] = { 0, 1 };
//	for (int i = 2; i <= 40; i++)
//	{
//		fibo[i] = fibo[i - 1] + fibo[i - 2];
//		v[i] = { v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second };
//	}
//
//	vector<pair<int, int>> answer;
//
//	for (int i = 0; i < N; i++)
//	{
//		int n;
//		cin >> n;
//		answer.push_back({ v[n].first, v[n].second });
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << answer[i].first << " " << answer[i].second << "\n";
//	}
//}
#pragma endregion

#pragma region 9095
//void Func(int sum, int target)
//{
//	if (sum == target)
//	{
//		cnt++;
//		return;
//	}
//
//	if (sum + 1 <= target)
//	{
//		Func(sum + 1, target);
//	}
//	if (sum + 2 <= target)
//	{
//		Func(sum + 2, target);
//	}
//	if (sum + 3 <= target)
//	{
//		Func(sum + 3, target);
//	}
//}
#pragma endregion

#pragma region 11726
//int N;
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N;
//
//	vector<int> v(1001);
//	v[1] = 1;
//	v[2] = 2;
//	int cnt = 1;
//	for (int i = 3; i <= N; i++)
//	{
//		v[i] = (v[i - 1] + v[i - 2]) % 10007;
//	}
//
//	cout << v[N];
//}
#pragma endregion

#pragma region 1149
//int N;
//vector<vector<int>> cost;
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		int r, g, b;
//		cin >> r >> g >> b;
//		cost.push_back({ r,g,b });
//	}
//
//	vector<vector<int>> v(1000, { 0,0,0 });
//	v[0][0] = cost[0][0];
//	v[0][1] = cost[0][1];
//	v[0][2] = cost[0][2];
//	for (int i = 1; i < N; i++)
//	{
//		v[i][0] = min(v[i - 1][1], v[i - 1][2]) + cost[i][0];
//		v[i][1] = min(v[i - 1][0], v[i - 1][2]) + cost[i][1];
//		v[i][2] = min(v[i - 1][0], v[i - 1][1]) + cost[i][2];
//	}
//
//	cout << *min_element(v[N - 1].begin(), v[N - 1].end());
//}
#pragma endregion

#pragma region 2579
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int N;
//	cin >> N;
//
//	vector<int> stair;
//	for (int i = 0; i < N; i++)
//	{
//		int n;
//		cin >> n;
//		stair.push_back(n);
//	}
//
//	vector<int> v(N);
//	v[0] = stair[0];
//	v[1] = max(stair[0] + stair[1], stair[1]);
//	v[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
//	for (int i = 3; i < N; i++)
//	{
//		int next1 = v[i - 3] + stair[i - 1] + stair[i];
//		int next2 = v[i - 2] + stair[i];
//		v[i] = max(next1, next2);
//	}
//
//	cout << v[N - 1];
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
