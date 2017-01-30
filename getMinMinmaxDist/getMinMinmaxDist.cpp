// getMinMinmaxDist.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

class getDistance {
private:double s[3], t[3], p[3];
public:void setS() {
		cout << "first end point S : ";
		cin >> s[0] >> s[1] >> s[2];
	};
public:void setT() {
		cout << "second end point T : ";
		cin >> t[0] >> t[1] >> t[2];
	};
public:void setP() {
		cout << "point P : ";
		cin >> p[0] >> p[1] >> p[2];
	};
public:double minDist() {
		int i;
		double result = 0, ri;
		for (i = 0; i < 3; i++) {
			if (p[i] < s[i]) {
				ri = s[i];
			}
			else if (p[i]>t[i]) {
				ri = t[i];
			}
			else {
				ri = p[i];
			}
			result = result + ((p[i] - ri) * (p[i] - ri));
		}
		return result;
	};
public:double minmaxDist() {
		int i,k;
		double result = 0,resultTmp,tmp, rmk, RMi;
		for (k = 0; k < 3; k++) {
			tmp = 0;
			for (i = 0; i < 3; i++) {
				if (i == k) continue;
				if (p[i] >= (s[i] + t[i]) / 2) RMi = s[i];
				else RMi = t[i];
				tmp += (p[i] - RMi)*(p[i] - RMi);
			}
			if (p[k] <= (s[k] + t[k]) / 2) rmk = s[k];
			else rmk = t[k];
			resultTmp = (p[k] - rmk)*(p[k] - rmk) + tmp;

			if (k == 0) result = resultTmp;
			else result = min(result, resultTmp);
		}
		return result;
	};
};
int main()
{
	getDistance proj1;
	proj1.setS();
	proj1.setT();
	proj1.setP();
	cout << "min dinstance is : " << proj1.minDist() << endl;
	cout << "minmax distance is : " << proj1.minmaxDist() << endl;
    return 0;
}

