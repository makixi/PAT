#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 999999;
int cmax;			//the maximum capacity of the tank
int d;			//the distance to destination
int davg;	//the average distance per unit gas that the car can run
int n;			//total number of gas stations
struct node {
	double p;		//the unit gas price
	double d;		//distance to the station
};
bool cmp(node a, node b) {
	return a.d < b.d;
}
int main() {
	double cheapestPrice=0.0;
	cin >> cmax >> d >> davg >> n;
	vector<node> vec(n+1);
	vec[0].d = d;
	vec[0].p = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> vec[i].p >> vec[i].d;
	}
	sort(vec.begin(), vec.end(), cmp);
	if (vec[0].d != 0) {
		cout << "The maximum travel distance = 0.00";
		return 0;
	}
	double nowPrice = vec[0].p;
	double nowDis = 0.0, leftDis = 0.0, totalPri = 0.0;
	double maxDis = 0.0;
	while (nowDis < d) {
		maxDis = nowDis + cmax*davg;
		double minPrice = inf, minPriceDistance = 0.0;
		bool flag = 0;
		//能到达
		for (int i = 1; i <= n&&vec[i].d <= maxDis; ++i) {
			//距离要比我远
			if (vec[i].d <= nowDis)continue;
			//有比我更低价格的，就加油加到刚好能到达更低价格加油站的油
			if (vec[i].p < nowPrice) {
				totalPri += (vec[i].d - nowDis - leftDis)*nowPrice / davg;
				nowPrice = vec[i].p;
				nowDis = vec[i].d;
				leftDis = 0.0;
				flag = 1;
				break;
			}
			//找出加油站中最便宜的
			if (vec[i].p < minPrice) {
				minPrice = vec[i].p;
				minPriceDistance = vec[i].d;
			}
		}
		//去最便宜的加油站
		if (flag == 0 && minPrice != inf) {
			totalPri += (nowPrice * (cmax - leftDis / davg));
			leftDis = cmax * davg - (minPriceDistance - nowDis);
			nowPrice = minPrice;
			nowDis = minPriceDistance;
		}
		//没有加油站了但是还没到终点
		if (flag == 0 && minPrice == inf) {
			nowDis += cmax*davg;
			printf("The maximum travel distance = %.2f", nowDis);
			return 0;
		}
	}
	printf("%.2f", totalPri);
	return 0;
}
