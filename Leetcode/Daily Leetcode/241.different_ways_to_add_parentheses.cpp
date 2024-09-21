#include<bits/stdc++.h>
using namespace std;

//turn numbers from string to int
int numRetrieve(string s, int& id) { //id: the position from which the num is retrieved
	string num;
	while (id < (int) s.size()) {
		if ((int) (s[id] - '0') >= 0 && (int) (s[id] - '0') <= 9) {
			num = num + s[id];
			id++;
		}
		else break;
	}
	return stoi(num);
}

int basicCalculate(int num1, int num2, char op) {
	if (op == '+') return num2 + num1;
	else if (op == '-') return num2 - num1;
	else return num2 * num1;
}

int infixCalculation (string s) {
	stack<int> nums;
	stack<char> operators;
	int id = 0;

	while (id < (int)s.size()) {
		if ((int) (s[id] - '0') >= 0 && (int) (s[id] - '0') <= 9) {
			int num = numRetrieve(s, id);
			nums.push(num);
		} else {
			if (operators.empty()) {
				operators.push(s[id]);
				id++;
			} else {
				if (s[id] == '(') {
					operators.push(s[id]);
					id++;
				} else if (s[id] == ')') {
					while (operators.top() != '(') {
						char topOp = operators.top();
						int num1 = nums.top();
						nums.pop();
						int num2 = nums.top();
						nums.pop();
						int num = basicCalculate(num1, num2, topOp);
						nums.push(num);
						operators.pop();
					}
					operators.pop();
					id++; 
				} else {
					char precedence = operators.top();
					if ((s[id] == '+' && precedence == '*') || (s[id] == '-' && precedence == '*')) {
						int num1 = nums.top();
						nums.pop();
						int num2 = nums.top();
						nums.pop();
						int num = basicCalculate(num1, num2, precedence);
						nums.push(num);
						operators.pop();
						operators.push(s[id]);
						id++;
					} else {
						operators.push(s[id]);
						id++;
					}
				}
			}
		}
	}

	while (!operators.empty()) {
		char topOp = operators.top();
		int num1 = nums.top();
		nums.pop();
		int num2 = nums.top();
		nums.pop();
		int num = basicCalculate(num1, num2, topOp);
		nums.push(num);
		operators.pop();
	}

	int res = nums.top();
	return res;
}

string recursion_helper (string sub1, string sub2, int sub1_op, int sub2_op, char op) {
	if (sub1_op == 0 && sub2_op == 0) return "(" + sub1 + op + sub2 + ")";
    string result = "";
    for (int i = 0; i < sub1.size(); i++) {
        string left = sub1.substr(0, i);
        string right = sub1.substr(i);
        char sub_op = sub1[i];
        result += recursion_helper(left, right, sub1_op - 1, sub2_op, op) + op + sub2;
        result += sub1 + op + recursion_helper(left, right, sub1_op, sub2_op - 1, op);
    }
    return result;
}


vector<int> diffWaysToCompute(string expression) {

}

int main()
{
	string s;
	cin >> s;
	cout << infixCalculation(s) << endl;
	return 0;
}

//---Alternative Approach---
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
    vector<int> results;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            string left = expression.substr(0, i);
            string right = expression.substr(i + 1);
            vector<int> leftResults = diffWaysToCompute(left);
            vector<int> rightResults = diffWaysToCompute(right);
            for (int l : leftResults) {
                for (int r : rightResults) {
                    if (expression[i] == '+') {
                        results.push_back(l + r);
                    } else if (expression[i] == '-') {
                        results.push_back(l - r);
                    } else {
                        results.push_back(l * r);
                    }
                }
            }
        }
    }
    if (results.empty()) {
        results.push_back(stoi(expression));
    }
    return results;
}
};