#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include <unordered_map>
using namespace std;

//////////////level 2///////////////////

#pragma region Ÿ�ٳѹ�
void dfs(vector<int> numbers, int target, int sum, int count, int &answer) {
	if (count == numbers.size())
	{
		if (sum == target)
		{
			answer++;
		}
		return;
	}

	dfs(numbers, target, sum + numbers[count], count + 1, answer);
	dfs(numbers, target, sum - numbers[count], count + 1, answer);
}
#pragma endregion

#pragma region  ��� �׵θ� ȸ���ϱ�
vector<vector<int>> MakeArray(int rows, int colums)
{
	vector<vector<int>> matrix(rows);

	int n = 1;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < colums; c++)
		{
			matrix[r].push_back(n++);
		}
	}

	return matrix;
}

int Rotation(vector<vector<int>>& matrix, vector<int> quiry)
{
	queue<int> q;

	int y1 = quiry[0] - 1;
	int x1 = quiry[1] - 1;
	int y2 = quiry[2] - 1;
	int x2 = quiry[3] - 1;

	int temp = matrix[y1][x1];
	q.push(temp);
	int min = temp;
	// ��
	for (int mx = x1; mx < x2; mx++)
	{
		temp = matrix[y1][mx + 1];
		q.push(temp);

		matrix[y1][mx + 1] = q.front();
		q.pop();

		if (min > temp) min = temp;
	}
	// ��
	for (int my = y1; my < y2; my++)
	{
		temp = matrix[my + 1][x2];
		q.push(temp);

		matrix[my + 1][x2] = q.front();
		q.pop();

		if (min > temp) min = temp;
	}
	// ��
	for (int mx = x2; mx > x1; mx--)
	{
		temp = matrix[y2][mx - 1];
		q.push(temp);

		matrix[y2][mx - 1] = q.front();
		q.pop();
		if (min > temp) min = temp;
	}
	// ��
	for (int my = y2; my > y1; my--)
	{
		temp = matrix[my - 1][x1];
		q.push(temp);

		matrix[my - 1][x1] = q.front();
		q.pop();
		if (min > temp) min = temp;
	}

	return min;
}
#pragma endregion

#pragma region �Ÿ��α�
struct Pos2
{
	int y, x, d;
	Pos2(int _y, int _x, int _d) : x(_x), y(_y), d(_d)
	{
	}
};
bool BFS(vector<vector<int>>& v, int x, int y)
{
	// 1 ��� 0 ��å�� -1 ��Ƽ��
	bool visited[5][5] = { false, };
	bool menhattan = true;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0,1,0,-1 };

	queue<Pos2> q;

	q.push(Pos2(y, x, 0));
	visited[y][x] = true;

	while (!q.empty())
	{
		int frontX = q.front().x;
		int frontY = q.front().y;
		int dist = q.front().d;

		q.pop();
		visited[frontY][frontX] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextX = frontX + dx[i];
			int nextY = frontY + dy[i];
			if (nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4) continue;
			if (visited[nextY][nextX]) continue;
			if (v[nextY][nextX] == -1) continue;

			if (v[nextY][nextX] == 1)
			{
				if (dist + 1 <= 2)
				{
					menhattan = false;
					break;
				}
			}

			q.push(Pos2(nextY, nextX, dist + 1));
			visited[nextY][nextX] = true;
		}

		if (!menhattan) break;
	}

	return menhattan;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < places.size(); i++)
	{
		vector<vector<int>> v;
		vector<pair<int, int>> startPos;

		for (int j = 0; j < places[i].size(); j++)
		{
			string line = places[i][j];
			vector<int> r;
			for (int s = 0; s < line.length(); s++)
			{
				if (line[s] == 'P')
				{
					r.push_back(1);
					startPos.push_back({ j, s });
				}
				else if (line[s] == 'O')
				{
					r.push_back(0);
				}
				else
				{
					r.push_back(-1);
				}
			}
			v.push_back(r);
		}

		bool isMenhattan = true;
		for (int p = 0; p < startPos.size(); p++)
		{
			isMenhattan = BFS(v, startPos[p].second, startPos[p].first);
			if (isMenhattan == false)
			{
				break;
			}
		}
		answer.push_back(isMenhattan);

	}

	return answer;
}
#pragma endregion

#pragma region ���� ��� ����Ŭ ........................ �̿�
enum class DIR
{
	UP = 0,
	RIGHT,
	DOWN,
	LEFT
};
class Pos
{
public:
	int X;
	int Y;

	Pos(int x, int y) : X(x), Y(y)
	{}

	void Init(int x, int y)
	{
		X = x;
		Y = y;
	}
};

int ChangeDir(int dir, char c)
{
	if (c == 'L')
	{
		dir = (dir + 3) % 4;
	}
	else if (c == 'R')
	{
		dir = (dir + 1) % 4;
	}

	return dir;
}

vector<int> solution(vector<string> grid) {
	vector<int> answer;

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1 ,0, 1, 0 };
	int dir = static_cast<int>(DIR::UP);
	Pos* pos = new Pos(0,0);

	int cant = pow(grid.size() * grid.size(), 2);
	for (int y = 0; y < grid.size(); y++)
	{
		for (int start = 0; start < grid[y].length(); start++)
		{
			// �� �߻�
			for (int i = 0; i < 4; i++)
			{
				dir = i;
				int startX = start;
				int startY = y;
				int count = 0;
				pos->Init(startX, startY);
				bool flag = false;

				while (true)
				{
					pos->X += dx[dir];
					pos->Y += dy[dir];
					count++;

					// �������� ����� �� 
					if (pos->X < 0)
					{
						pos->X = grid[y].length() - 1;
					}
					// �������� ����� ��
					else if (pos->X >= grid[y].length())
					{
						pos->X = 0;
					}
					// ���� ����� ��
					else if (pos->Y < 0)
					{
						pos->Y = grid.size() - 1;
					}
					// �Ʒ��� ����� ��
					else if (pos->Y >= grid.size())
					{
						pos->Y = 0;
					}

					// ���� ��ȯ
					dir = ChangeDir(dir, grid[pos->Y][pos->X]);

					// ����
					if (pos->X == startX && pos->Y == startY)
					{
						// ���⵵ ���ٸ�
						if (dir == i)
						{
							cout << startX << ", " << startY << ", " << i << endl;
							flag = true;										
							break;
						}
					}				

					// grid ���� �Ѿ�� ����ŬX
					if (count > cant)
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					answer.push_back(count);
					break;
				}
			}
		}
	}

	delete pos;
	return answer;
}
#pragma endregion

#pragma region ������
int ������(vector<int> priorities, int location) {
	int answer = 0;
	int biggest = 0;
	vector<pair<int, int>> v;  // �߿䵵, ���� �ε���

	for (int i = 0; i < priorities.size(); i++)
	{
		v.push_back({ priorities[i], i });
		biggest = max(biggest, priorities[i]);
	}

	auto front = 0;
	int index = 0;
	while (v.size() > 0)
	{
		front = v[0].first;
		index = v[0].second;
		if (front == biggest)
		{
			answer++;
			v.erase(v.begin());
			if (location == index) break;

			biggest = v[0].first;
			auto i = max_element(v.begin(), v.end());
			biggest = i->first;
		}
		else
		{
			v.erase(v.begin());
			v.push_back({ front, index });
		}
	}

	return answer;
}

#pragma endregion

#pragma region ���� ū ��

bool compare(int a, int b)
{
	return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}
string ����ū��(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);
	if (numbers[0] == 0)
		return "0";

	for (auto& i : numbers)
	{
		answer += to_string(i);
	}

	return answer;
}
#pragma endregion

#pragma region �Ҽ�ã��
bool isPrime(int n)
{
	if (n <= 1) return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int �Ҽ�ã��(string numbers) {
	int answer = 0;
	unordered_set<int> us;

	sort(numbers.begin(), numbers.end());
	do
	{
		int tmp = 0;
		for (int i = 1; i < numbers.size() + 1; i++)
		{
			tmp = stoi(numbers.substr(0, i));
			us.insert(tmp);
		}

	} while (next_permutation(numbers.begin(), numbers.end()));

	for (auto& i : us)
	{
		if (isPrime(i))
		{
			answer++;
		}
	}

	return answer;
}
#pragma endregion

#pragma region ���̽�ƽ ................ �̿�

int CheckUpDown(char c)
{
	if (c - 'A' > 'Z' - c)
	{
		return 'Z' - c + 1;
	}
	else
	{
		return c - 'A';
	}
}
int solution(string name)
{
	int answer = 0;
	return answer;
}

#pragma endregion

#pragma region ���Ӹ� �ִܰŸ�
int �ִܰŸ�(vector<vector<int> > maps)
{
	int answer = 0;
	int n = maps.size() - 1;
	int m = maps[0].size() - 1;

	int dirX[4] = { 1,0,-1,0 };
	int dirY[4] = { 0,1,0,-1 };

	bool visited[101][101] = { false, };
	int dist[101][101] = { 0, };

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	dist[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
 			int nextX = x + dirX[i];
			int nextY = y + dirY[i];

			if (nextX < 0 || nextX > m || nextY < 0 || nextY > n) continue;
			if (maps[nextY][nextX] == 0) continue;
			if (visited[nextY][nextX]) continue;

			if (dist[nextY][nextX] == 0)
			{
				dist[nextY][nextX] = dist[y][x] + 1;
			}

			q.push({ nextX, nextY });
			visited[nextY][nextX] = true;
		}
	}

	if (dist[n][m] == 0)
	{
		answer = -1;
	}
	else
	{
		answer = dist[n][m];
	}
	return answer;
}


#pragma endregion

#pragma region ��ȣ ȸ���ϱ�

bool algo(string s)
{
	stack<char> st;
	st.push(s[0]);
	char top = st.top();
	if (top == ')' || top == '}' || top == ']') return false;

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != ')' && s[i] != '}' && s[i] != ']')
		{
			st.push(s[i]);
			top = st.top();
		}
		else
		{
			if (top == '(')
			{
				if (s[i] != ')')
				{
					return false;
				}
				else
				{
					if (st.empty())
					{
						return false;
					}
					else
					{
						st.pop();
						if (!st.empty())
						{
							top = st.top();
						}
					}
				}
			}
			else if (top == '{')
			{
				if (s[i] != '}')
				{
					return false;
				}
				else
				{
					if (st.empty())
					{
						return false;
					}
					else
					{
						st.pop();
						if (!st.empty())
						{
							top = st.top();
						}
					}
				}
			}
			else if (top == '[')
			{
				if (s[i] != ']')
				{
					return false;
				}
				else
				{
					if (st.empty())
					{
						return false;
					}
					else
					{
						st.pop();
						if (!st.empty())
						{
							top = st.top();
						}
					}
				}
			}
		}
	}

	if (st.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int sol(string s)
{
	int answer = 0;
	vector<bool> v;
	for (int i = 0; i < s.length(); i++)
	{
		string ns;

		for (int j = i; j < s.length(); j++)
		{
			ns += s[j];
		}
		for (int k = 0; k < i; k++)
		{
			ns += s[k];
		}

		v.push_back(algo(ns));
	}

	for (const auto& i : v)
	{
		if (i)
		{
			answer++;
		}
	}

	return answer;
}
#pragma endregion

#pragma region ���
int ���(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	vector<pair<int, int>> v[51]; // to, dist
	int distance[51];
	fill(&distance[0], &distance[51], 500001);

	distance[1] = 0;

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
	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		for (int i = 0; i < v[n].size(); i++)
		{
			int next = v[n][i].first;
			int nextDistance = v[n][i].second;
			if (nextDistance > K) continue;

			nextDistance += distance[n];

			if (nextDistance < distance[next])
			{
				distance[next] = nextDistance;
				if (nextDistance < K)
				{
					q.push(next);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (distance[i] <= K)
		{
			answer++;
		}
	}

	return answer;
}
#pragma endregion

#pragma region ����
int ����(vector<vector<string>> clothes) {
	int answer = 1;
	multimap<string, string> mm;

	for (int i = 0; i < clothes.size(); i++)
	{
		mm.insert({ clothes[i][1], clothes[i][0] });
	}

	// ����� ��
	// �� 3�� ���� 2��  ���� 2���� ����� ����
	// (3+1) * (2+1) * (2+1)   -  +1�� ���� ������ ���

	string key;
	for (auto iter = mm.begin(); iter != mm.end(); iter++)
	{
		if (key == iter->first) continue;

		key = iter->first;
		int num = 0;
		for (auto i = mm.equal_range(key).first; i != mm.equal_range(key).second; i++)
		{
			num++;
		}

		answer *= (num + 1);
	}

	return answer - 1; // �ƹ��͵� �ȼ����� ���� ����
}
#pragma endregion

#pragma region �ٸ��� ������ Ʈ��
int �ٸ���������Ʈ��(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int index = 0;
	int totalweight = 0;

	for (int i = 0; i < bridge_length; i++)
	{
		q.push(0);
	}

	while (!q.empty())
	{
		answer++;
		totalweight -= q.front();
		q.pop();

		if (index < truck_weights.size())
		{
			if (totalweight + truck_weights[index] <= weight)
			{
				totalweight += truck_weights[index];
				q.push(truck_weights[index++]);
			}
			else
			{
				q.push(0);
			}
		}

	}

	return answer;
}
#pragma endregion

#pragma region H-Index
int HIndex(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); i++)
	{
		if (i + 1 <= citations[i])
		{
			answer = i + 1;
		}
	}

	return answer;
}

#pragma endregion

#pragma region ī��
vector<int> ī��(int brown, int yellow) {
	vector<int> answer;
	int sum = brown + yellow;

	for (int w = 3; w <= sum / 2; w++)
	{
		bool find = false;
		for (int h = 3; h <= sum / 2; h++)
		{
			int y_w = w - 2;
			int y_h = h - 2;

			if (w * h == sum)
			{
				if (y_w * y_h == yellow)
				{
					answer.push_back(w);
					answer.push_back(h);
					find = true;
					break;
				}
			}
		}
		if (find) break;
	}

	sort(answer.begin(), answer.end(), greater<int>());
	return answer;
}

#pragma endregion

#pragma region �Ƿε�

int needEnergy[8];
int useEnergy[8];
bool visited[8];
int answer = 0;
void DFS(int k, int count, vector<vector<int>>& dungeons)
{
	for (int i = 0; i < dungeons.size(); i++)
	{
		if (visited[i]) continue;
		if (k < needEnergy[i]) continue;

		visited[i] = true;
		DFS(k - useEnergy[i], count + 1, dungeons);
		visited[i] = false;
	}

	answer = max(answer, count);
}

int �Ƿε�(int k, vector<vector<int>> dungeons) {

	for (int i = 0; i < dungeons.size(); i++)
	{
		needEnergy[i] = dungeons[i][0];
		useEnergy[i] = dungeons[i][1];
	}
	DFS(k, 0, dungeons);

	return answer;
}
#pragma endregion

#pragma region �ﰢ������
enum Dir
{
	Down = 0,
	Right,
	Up
};

vector<int> �ﰢ������(int n) {
	vector<int> answer;
	Dir dir = Dir::Down;
	vector<int> v[1000];

	for (int i = 0; i < n; i++)
	{
		v[i].resize(n);
	}

	int x = 0;
	int y = 0;
	int number = 1;
	int cnt = n;
	int a = 0;

	while (cnt > 0)
	{
		switch (dir)
		{
		case Down:
			a = 0;
			while (a < cnt)
			{
				v[y][x] = number;

				if (a + 1 < cnt)
				{
					y++;
				}
				number++;
				a++;
			}
			x++;
			dir = Dir::Right;
			break;
		case Right:
			a = 0;
			while (a < cnt)
			{
				v[y][x] = number;

				if (a + 1 < cnt)
				{
					x++;
				}
				number++;
				a++;
			}
			y--;
			x--;
			dir = Dir::Up;
			break;
		case Up:
			a = 0;
			while (a < cnt)
			{
				v[y][x] = number;

				if (a + 1 < cnt)
				{
					y--;
					x--;
				}
				number++;
				a++;
			}
			y++;
			dir = Dir::Down;
			break;
		}
		cnt--;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] != 0)
			{
				answer.push_back(v[i][j]);
			}
			else
			{
				break;
			}
		}
	}


	return answer;
}

#pragma endregion

#pragma region ������ձ�
bool IsUsed(string s, vector<string>& used)
{
	for (int i = 0; i < used.size(); i++)
	{
		if (s == used[i])
			return true;
	}
	return false;
}

vector<int> ������ձ�(int n, vector<string> words) {
	vector<int> answer;

	int arr[100] = { 0, };

	int num = 0;
	bool b = false;
	char w = words[0][0];
	vector<string> used;

	for (int i = 0; i < words.size(); i++)
	{
		arr[num]++;
		if (words[i][0] != w || IsUsed(words[i], used))
		{
			b = true;
			answer.push_back(num + 1);
			answer.push_back(arr[num]);
			break;
		}
		used.push_back(words[i]);
		w = words[i][words[i].length() - 1];
		num += 1;
		num %= n;
	}

	if (!b)
	{
		answer.clear();
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}
#pragma endregion

#pragma region �ֽİ���
vector<int> �ֽİ���(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++)
	{
		if (i == prices.size() - 1)
		{
			answer.push_back(0);
			break;
		}

		int price = prices[i];
		int cnt = 0;
		for (int j = i + 1; j < prices.size(); j++)
		{
			cnt++;

			if (prices[j] < prices[i])
			{
				break;
			}
		}
		answer.push_back(cnt);
	}

	return answer;
}
#pragma endregion

#pragma region ��ȭ��ȣ���
bool ��ȭ��ȣ���(vector<string> phone_book) 
{
	bool find = false;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		string prefix = phone_book[i];
		string next = phone_book[i + 1].substr(0, prefix.length());
		if (prefix == next)
		{
			find = true;
			break;
		}
	}

	return !find;
}

#pragma endregion

#pragma region ���ʰ�
int ���ʰ�(vector<int> scoville, int K) {
	int answer = 0;
	int front = 0;
	int second = 0;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (!pq.empty())
	{
		front = pq.top();
		pq.pop();

		if (front >= K) break;
		if (pq.empty())
		{
			answer = -1;
			break;
		}

		second = pq.top();
		pq.push(front + second * 2);
		pq.pop();

		answer++;
	}

	return answer;
}
#pragma endregion

#pragma region ���ڿ�����
int ���ڿ�����(string s)
{
	int answer = s.length();
	int n = s.length() / 2;

	for (int i = 1; i <= n; i++)
	{
		string t1 = s.substr(0, i);
		string newString;
		int cnt = 1;
		for (int j = i; j <= s.length(); j += i)
		{
			if (t1 == s.substr(j, i))
			{
				cnt++;
			}
			else
			{
				if (cnt > 1)
				{
					newString += to_string(cnt);
				}
				newString += t1;
				t1 = s.substr(j, i);
				cnt = 1;
			}
		}

		if (s.length() % i != 0)
		{
			newString += s.substr((s.length() / i) * i);
		}
		answer = max(answer, (int)newString.length());
	}
	return answer;
}

#pragma endregion

#pragma region ����ä�ù�
vector<string> Split(string s)
{
	istringstream iss(s);
	string buffer;
	vector<string> v;

	while (getline(iss, buffer, ' '))
	{
		v.push_back(buffer);
	}

	return v;
}

vector<string> ����ä�ù�(vector<string> record) {
	vector<string> answer;
	vector<string> state;
	unordered_map <string, string> m;

	for (int i = 0; i < record.size(); i++)
	{
		vector<string> v = Split(record[i]);
		string command = v[0];
		string id = v[1];

		if (command == "Enter")
		{
			string name = v[2];
			m[id] = name;
			state.push_back("���� ���Խ��ϴ�.");

			answer.push_back(id);
		}
		else if (command == "Leave")
		{
			state.push_back("���� �������ϴ�.");
			answer.push_back(id);
		}
		else
		{
			string name = v[2];
			m[id] = name;
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		answer[i] = m[answer[i]] + state[i];
	}
	return answer;
}
#pragma endregion

#pragma region īī���������÷�����
bool cvisited[100][100] = { false, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N = 0;
int M = 0;

void Init(int m, int n)
{
	N = n;
	M = m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cvisited[j][i] = false;
		}
	}
}

int BFS(int n, int x, int y, vector<vector<int>>& picture, map<int, int>& color)
{
	int place = 1;
	queue<pair<int, int>> q;

	q.push({ x,y });
	cvisited[x][y] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = cx + dx[i];
			int nextY = cy + dy[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			if (cvisited[nextX][nextY]) continue;
			if (picture[nextY][nextX] != n) continue;

			q.push({ nextX, nextY });
			cvisited[nextX][nextY] = true;
			place++;
		}
	}

	return place;
}

vector<int> īī���������÷�����(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	Init(m, n);

	map<int, int> color;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int n = picture[i][j];
			if (n != 0)
			{
				if (cvisited[j][i] == false)
				{
					color[n] = max(color[n], BFS(n, j, i, picture, color));
					number_of_area++;
				}
			}
		}
	}

	for (const auto& i : color)
	{
		max_size_of_one_area = max(max_size_of_one_area, i.second);
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
#pragma endregion

#pragma region �����ѻ簢��
long long rec(int w, int h)
{
	if (h % w == 0)
	{
		return w;
	}
	else
	{
		return rec(h % w, w);
	}
}

long long �����ѻ簢��(int w, int h) {
	long long answer = 1;
	long long rect = (long long)w * (long long)h;
	answer = rect - (w + h - rec(w, h));
	return answer;
}
#pragma endregion

#pragma region 124����
string /*124*/����(int n) {
	string answer = "";

	while (n > 0)
	{
		if (n % 3 == 0)
		{
			answer += "4";
			n = (n / 3) - 1;
		}
		else
		{
			answer += to_string(n % 3);
			n = n / 3;
		}
	}

	reverse(answer.begin(), answer.end());
	return answer;
}
#pragma endregion

#pragma region ¦���������ϱ�
int ¦���������ϱ�(string s)
{
	stack<char> st;

	for (int i = 0; i < s.length(); i++)
	{
		if (st.empty() || st.top() != s[i])
		{
			st.push(s[i]);
		}
		else
		{
			st.pop();
		}
	}

	return st.empty() ? 1 : 0;
}
#pragma endregion

#pragma region ��ȣ��ȯ
bool IsRightString(string s)
{
	stack<char> st;
	if (s.length() > 0 && s[0] == ')') return false;

	for (int i = 0; i < s.length(); i++)
	{
		if (st.empty())
		{
			st.push(s[i]);
		}
		else
		{
			if (st.top() == '(')
			{
				if (s[i] == ')')
				{
					st.pop();
				}
				else
				{
					st.push(s[i]);
				}
			}
			else
			{
				st.push(s[i]);
			}
		}
	}
	return st.empty();
}

void Divide(string p, string& u, string& v)
{
	if (p == "") return;

	int leftCnt = 0; // (
	int rightCnt = 0; // )
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == '(')
		{
			leftCnt++;
			u += p[i];
		}
		else
		{
			rightCnt++;
			u += p[i];
		}

		if (leftCnt > 0 && rightCnt > 0 && leftCnt == rightCnt)
		{
			for (int j = i + 1; j < p.length(); j++)
			{
				v += p[j];
			}
			break;
		}
	}
}

string Convert(string p)
{
	string u, v;
	if (p == "")
	{
		return "";
	}
	Divide(p, u, v);

	if (IsRightString(u))
	{
		return u + Convert(v);
	}
	else
	{
		string temp;
		temp = "(" + Convert(v) + ")";
		string nu = u.substr(1, u.length() - 2);
		string n2;
		for (int i = 0; i < nu.length(); i++)
		{
			if (nu[i] == '(')
			{
				n2 += ")";
			}
			else
			{
				n2 += "(";
			}
		}

		temp += n2;
		return temp;
	}
}

string ��ȣ��ȯ(string p) {
	string answer = "";
	if (p.length() <= 0) return answer;
	if (IsRightString(p)) return p;

	answer = Convert(p);

	return answer;
}
#pragma endregion

#pragma region ����Ŭ�����͸�
int ����Ŭ�����͸�(string str1, string str2) {
	double answer = 0;
	vector<string> v1;
	vector<string> v2;

	for (int i = 0; i < str1.size(); i++)
	{
		str1[i] = tolower(str1[i]);
	}
	for (int j = 0; j < str2.size(); j++)
	{
		str2[j] = tolower(str2[j]);
	}

	for (int i = 0; i < str1.size() - 1; i++)
	{
		string t;
		t = str1.substr(i, 2);
		bool flag = false;
		for (int j = 0; j < 2; j++)
		{
			if (t[j] >= 'a' && t[j] <= 'z')
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			v1.push_back(t);
		}
	}

	for (int j = 0; j < str2.size() - 1; j++)
	{
		string t;
		t = str2.substr(j, 2);
		bool flag = false;
		for (int k = 0; k < 2; k++)
		{
			if (t[k] >= 'a' && t[k] <= 'z')
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			v2.push_back(t);
		}
	}

	if (v1.size() == 0 && v2.size() == 0)
	{
		answer = 1;
	}
	else
	{
		int b = 0;
		int t = v1.size() + v2.size();

		for (int i = 0; i < v1.size(); i++)
		{
			auto iter = find(v2.begin(), v2.end(), v1[i]);
			if (iter != v2.end())
			{
				b++;
				v2.erase(iter);
			}
		}
		t -= b;

		answer = static_cast<double>(b) / static_cast<double>(t);
	}

	return static_cast<int>(answer * 65536);
}
#pragma endregion

#pragma region �����ִ�ȭ
void Check(vector<long long>& numbers2, vector<char>& operand2, vector<char> ra)
{
	int priority = 0;
	while (!operand2.empty())
	{
		for (int j = 0; j < operand2.size(); j++)
		{
			if (operand2[j] == ra[priority])
			{
				if (operand2[j] == '*')
				{
					numbers2[j] = numbers2[j] * numbers2[j + 1];
				}
				else if (operand2[j] == '+')
				{
					numbers2[j] = numbers2[j] + numbers2[j + 1];
				}
				else
				{
					numbers2[j] = numbers2[j] - numbers2[j + 1];
				}

				operand2.erase(operand2.begin() + j);
				numbers2.erase(numbers2.begin() + j + 1);
				j--;
			}
		}
		priority++;
	}
}

long long �����ִ�ȭ(string expression) {
	long long answer = 0;
	vector<long long> numbers;
	vector<char> operand;

	string temp;
	vector<char> ra;

	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
		{
			numbers.push_back(stoll(temp));
			operand.push_back(expression[i]);
			temp = "";
			if (find(ra.begin(), ra.end(), expression[i]) == ra.end())
			{
				ra.push_back(expression[i]);
			}
		}
		else
		{
			temp += expression[i];
		}
	}
	numbers.push_back(stoll(temp));

	vector<long long> numbers2;
	vector<char> operand2;
	sort(ra.begin(), ra.end());
	do
	{
		numbers2 = numbers;
		operand2 = operand;

		Check(numbers2, operand2, ra);
		answer = max(abs(numbers2[0]), answer);

	} while (next_permutation(ra.begin(), ra.end()));

	return answer;
}

#pragma endregion

#pragma region Ʃ��
bool Ʃ��cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first > b.first;
	}
	return a.second > b.second;
}

vector<int> Ʃ��(string s) {
	vector<int> answer;
	vector<vector<int>> elements;
	map<int, int> count;

	vector<int> v;
	string temp;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '{')
		{
		}
		else
		{
			if (s[i] != ',')
			{
				if (s[i] == '}')
				{
					if (temp != "")
					{
						count[stoi(temp)]++;
						v.push_back(stoi(temp));
						temp = "";
					}

					if (v.size() > 0)
					{
						elements.push_back(v);
					}
					v.clear();
				}
				else
				{
					temp += s[i];
				}
			}
			else
			{
				if (temp != "")
				{
					int n = stoi(temp);
					count[n]++;
					v.push_back(n);
					temp = "";
				}
			}
		}
	}

	vector<pair<int, int>> vv(count.begin(), count.end());
	sort(vv.begin(), vv.end(), Ʃ��cmp);

	for (const auto& iter : vv)
	{
		answer.push_back(iter.first);
	}

	return answer;
}
#pragma endregion

#pragma region �޴�������
void �޴�������dfs(unordered_map<string, int>& m, string order, vector<bool>& use, string s, int current, int target)
{
	if (s.length() == target)
	{
		m[s]++;
		return;
	}

	for (int i = current; i < order.size(); i++)
	{
		if (use[i]) continue;

		string temp = s;
		s += order[i];
		use[i] = true;

		�޴�������dfs(m, order, use, s, i, target);

		s = temp;
		use[i] = false;
	}
}

bool �޴�������cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.first.length() == b.first.length())
	{
		return a.second > b.second;
	}
	return a.first.length() < b.first.length();
}

vector<string> �޴�������(vector<string> orders, vector<int> course) {
	vector<string> answer;
	unordered_map<string, int> m;

	for (int i = 0; i < course.size(); i++)
	{
		int count = course[i];

		for (int j = 0; j < orders.size(); j++)
		{
			sort(orders[j].begin(), orders[j].end());
			if (orders[j].length() < count) continue;

			string currOrder = orders[j];
			vector<bool> use(currOrder.length(), false);

			�޴�������dfs(m, currOrder, use, "", 0, count);
		}
	}

	vector<pair<string, int>> vv(m.begin(), m.end());
	sort(vv.begin(), vv.end(), �޴�������cmp);
	for (int i = 0; i < course.size(); i++)
	{
		int count = course[i];
		int biggest = 0;
		for (int j = 0; j < vv.size(); j++)
		{
			if (count != vv[j].first.length()) continue;
			if (vv[j].second == 1) continue;

			if (vv[j].second >= biggest)
			{
				biggest = vv[j].second;
				answer.push_back(vv[j].first);
			}
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}

#pragma endregion
