#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int EveryCost[25]={0};

struct call {
	string name;
	int month, day, hour, minute;
	int now;//on-lineΪ1  
	int alltime;
};

bool cmp(call a, call b) {
	return a.name != b.name ? a.name < b.name : a.alltime < b.alltime;
}
double billFromZero(call call1, int *rate) {
	double total = rate[call1.hour] * call1.minute + rate[24] * 60 * call1.day;
	for (int i = 0; i < call1.hour; i++)
		total += rate[i] * 60;
	return total / 100.0;
}
int main() {
	int n;
	for (int i = 0; i < 24; ++i)
		{
			cin >> EveryCost[i];
			EveryCost[24]+=EveryCost[i]; 
		} 
	cin >> n;
	vector<call> data(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
		string stu;
		cin >> stu;
		data[i].now = (stu == "on-line") ? 1 : 0;
		data[i].alltime = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
	}
	sort(data.begin(), data.end(), cmp);
	map<string, vector<call> > custom;
	for (int i = 1; i < n; ++i) {
		if (data[i].name == data[i - 1].name && data[i - 1].now == 1 && data[i].now == 0) {
			custom[data[i - 1].name].push_back(data[i - 1]);
			custom[data[i].name].push_back(data[i]);
		}
	}
	for (auto it : custom) {
		vector<call> temp = it.second;
		cout << it.first;
		printf(" %02d\n", temp[0].month);
		double total = 0.0;
		for (size_t i = 1; i < temp.size(); i += 2) {
			double t = billFromZero(temp[i], EveryCost) - billFromZero(temp[i - 1], EveryCost);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].alltime - temp[i - 1].alltime, t);
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}

