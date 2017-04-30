#include "iostream" 
#include "algorithm"  
#include "math.h"
using namespace std;

char sym[4] = { '+','-','*','/' };

int Common(long long a, long long b) {  
    int r;  
    if (a<b) {  
        r = a;  
        a = b;  
        b = r;  
    }  
    while (b != 0)  
    {  
        r = a%b;  
        a = b;  
        b = r;  
    }  
    return a;  
}  

int Printbefore(long long a, long long b) {
	int f = a / b;
	int r = a%b;
	if (f == 0) {
		if (r == 0){
		cout << "0";}
		else {
			int c = Common(r, b);
			if (a*b < 0) {
				cout << "(-" << abs(r / c) << "/" << abs(b / c) << ")";
			}
			else {
				cout << abs(r / c) << "/" << abs(b / c);
			}
		}
	}
	else {
		if (f < 0) {
			cout << "(";
		}
		cout << f;
		if (r != 0) {
			int c = Common(r, b);
			cout << " " << abs(r / c) << "/" << abs(b / c);
		}
		if (f < 0) {
			cout << ")";
		}
	}
	return 0;
}

void Print(long long a, long long b, long long c, long long d, long long i) {
	Printbefore(a, b);
	cout << " " << sym[i] << " ";
	Printbefore(c, d);
	cout << " = ";
	if (i == 0) Printbefore(a*d + c*b, b*d);
	else if (i == 1) Printbefore(a*d - c*b, b*d);
	else if (i == 2) Printbefore(a*c, b*d);
	else {
		if (b*c == 0) {
			cout << "Inf";
		}
		else {
			Printbefore(a*d, b*c);
		}
	}
	cout << endl;
}

int main() {
	long long a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);  
	for (int i = 0; i < 4; i++) {
		Print(a, b, c, d, i);
	}
	return 0;
}
