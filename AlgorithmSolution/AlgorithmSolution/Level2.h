#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
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
