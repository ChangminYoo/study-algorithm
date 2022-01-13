#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

// Level 2
#pragma region 타겟넘버
void dfs(vector<int> numbers, int target, int sum, int count, int& answer) {
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

#pragma region  행렬 테두리 회전하기
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
	// 상
	for (int mx = x1; mx < x2; mx++)
	{
		temp = matrix[y1][mx + 1];
		q.push(temp);

		matrix[y1][mx + 1] = q.front();
		q.pop();

		if (min > temp) min = temp;
	}
	// 우
	for (int my = y1; my < y2; my++)
	{
		temp = matrix[my + 1][x2];
		q.push(temp);

		matrix[my + 1][x2] = q.front();
		q.pop();

		if (min > temp) min = temp;
	}
	// 하
	for (int mx = x2; mx > x1; mx--)
	{
		temp = matrix[y2][mx - 1];
		q.push(temp);

		matrix[y2][mx - 1] = q.front();
		q.pop();
		if (min > temp) min = temp;
	}
	// 좌
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

int main()
{
    
}
