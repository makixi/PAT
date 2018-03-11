#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
map<string, string> variable;
int findright(vector<string> &elem, int left, int right) {//¿®∫≈ ≤√¥ ±∫ÚΩ· ¯
	if (left == right) return right;
	int sig, i = left;
	if (elem[left] == "(") sig = 1;
	else sig = 0;
	while (sig && i <= right) {
		i++;
		if (elem[i] == "(") sig++;
		else if (elem[i] == ")") sig--;
	}
	return i;
}
string cal(vector<string> &elem, int left, int right) {
	if (elem[left] == "(") {
		if (elem[left + 1] == "if") {
			string s;
			int s_left = left + 2;
			int s_right = findright(elem, s_left, right);
			s = cal(elem, s_left, s_right);
			if (s == "Type Mismatch" || s == "Division By Zero" || s == "Unbound Identifier")return s;
			int a_left = s_right + 1;
			int a_right = findright(elem, a_left, right);
			int b_left = a_right + 1;
			int b_right = findright(elem, b_left, right);
			if (s == "true") return cal(elem, a_left, a_right);
			else if (s == "false") return cal(elem, b_left, b_right);
			else return "Type Mismatch";
		}
		else if (elem[left + 1] == "let") {
			string value = elem[left + 3];
			int a_left = left + 4;
			int a_right = findright(elem, a_left, right);
			string a = cal(elem, a_left, a_right);
			if (a == "Type Mismatch" || a == "Division By Zero" || a == "Unbound Identifier")return a;
			variable[value] = a;
			int b_left = a_right + 2;
			int b_right = findright(elem, b_left, right);
			string out = cal(elem, b_left, b_right);
			variable.erase(value);
			return out;
		}
		string op = elem[left + 1];
		int x_left = left + 2;
		int x_right = findright(elem, x_left, right);
		string xRes = cal(elem, x_left, x_right);
		if (xRes == "Type Mismatch" || xRes == "Division By Zero" || xRes == "Unbound Identifier")return xRes;
		int y_left = x_right + 1;
		int y_right = findright(elem, y_left, right);
		string yRes = cal(elem, y_left, y_right);
		if (yRes == "Type Mismatch" || yRes == "Division By Zero" || yRes == "Unbound Identifier")return yRes;
		if (op == "/"&&yRes == "0")  return "Division By Zero"; 
		if (!isdigit(xRes[0]) || !isdigit(yRes[0]))return "Type Mismatch";
		if (op == "+") return to_string(stoi(xRes) + stoi(yRes));
		else if (op == "-") return to_string(stoi(xRes) - stoi(yRes));
		else if (op == "*") return to_string(stoi(xRes) * stoi(yRes));
		else if (op == "/") return to_string(stoi(xRes) / stoi(yRes));
		else if (op == "<") return (stoi(xRes) <  stoi(yRes)) ? "true" : "false";
		else if (op == ">") return (stoi(xRes) >  stoi(yRes)) ? "true" : "false";
		else if (op == "=") return (stoi(xRes) == stoi(yRes)) ? "true" : "false";
	}
	else if (isdigit(elem[left][0]) || elem[left] == "true" || elem[left] == "false")return elem[left];
	else if (elem[left] != "let"&&elem[left] != "if") {
		if (variable[elem[left]] != "")return variable[elem[left]];
		return "Unbound Identifier";
	}
	return "Error";
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	getchar();
	while (t--) {
		string s, word;
		getline(cin, s);
		istringstream in(s);
		vector<string> elem;
		while (in >> word)elem.push_back(word);
		cout << cal(elem, 0, elem.size() - 1) << "\n";
	}
	return 0;
}
