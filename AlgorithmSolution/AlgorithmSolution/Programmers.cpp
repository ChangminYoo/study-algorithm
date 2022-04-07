//#include "Level2.h"
#include "Baekjoon.h"
#include <bits/stdc++.h>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers;
    vector<char> operand;
    vector<char> ra;

    string temp;

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

    for (int i = 0; i < ra.size(); i++)
    {
        long long n = 0;
        vector<long long> numbers2 = numbers;
        vector<char> operand2 = operand;
        int priority = i;

        while (!operand2.empty())
        {
            char pr = ra[priority % ra.size()];
            for (int j = 0; j < operand2.size(); j++)
            {
                if (operand2[j] == pr)
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
        answer = max(abs(numbers2[0]), answer);
    }

    return answer;
}
 
int main(void)
{
    cout << solution("1-1+1000000*1000000");
}