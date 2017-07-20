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
		//�ܵ���
		for (int i = 1; i <= n&&vec[i].d <= maxDis; ++i) {
			//����Ҫ����Զ
			if (vec[i].d <= nowDis)continue;
			//�б��Ҹ��ͼ۸�ģ��ͼ��ͼӵ��պ��ܵ�����ͼ۸����վ����
			if (vec[i].p < nowPrice) {
				totalPri += (vec[i].d - nowDis - leftDis)*nowPrice / davg;
				nowPrice = vec[i].p;
				nowDis = vec[i].d;
				leftDis = 0.0;
				flag = 1;
				break;
			}
			//�ҳ�����վ������˵�
			if (vec[i].p < minPrice) {
				minPrice = vec[i].p;
				minPriceDistance = vec[i].d;
			}
		}
		//ȥ����˵ļ���վ
		if (flag == 0 && minPrice != inf) {
			totalPri += (nowPrice * (cmax - leftDis / davg));
			leftDis = cmax * davg - (minPriceDistance - nowDis);
			nowPrice = minPrice;
			nowDis = minPriceDistance;
		}
		//û�м���վ�˵��ǻ�û���յ�
		if (flag == 0 && minPrice == inf) {
			nowDis += cmax*davg;
			printf("The maximum travel distance = %.2f", nowDis);
			return 0;
		}
	}
	printf("%.2f", totalPri);
	return 0;
}
