#include "oil.h"
#include <stdio.h>
#include <stdlib.h>

int checkOil(int left, int right) {
	int pivot = (left + right) / 2;
	int v1;
	int v2;
	int ret = 0;
	v1 = observe(left, pivot);
	v2 = observe(pivot + 1, right);
	if (v1 == 1) {
		//printf("%d %d\n", left, pivot);
		ret += 1 << left;
		ret += 1 << pivot;
	}
	if (v2 == 1) {
		//printf("%d %d\n", pivot + 1, right);
		ret += 1 << (pivot + 1);
		ret += 1 << (right);
	}

	if (v1 == 2) {
		if (v2 > 0)
			left += 1;
		ret += checkOil(left, pivot);
	}
	if (v2 == 2) {
		if (v1 > 0)
			right -= 1;
		ret += checkOil(pivot + 1, right);
		
	}
	return ret;
}

int main() {
	initial();
	int N = oil_size();
	int val = checkOil(0, N - 1);
	int min = 0;
	int max = 0;
	int sVal = 1;
	int cnt = 0;
	int tf = 1;
	while (val > sVal) {
		sVal = 1 << cnt;
		
		if(tf)
			if (val & sVal) {
				min = cnt;
				tf = 0;
			}
		cnt++;
	}
	max = cnt - 2; // cnt++로 1증가와 초과분 1을 빼줘야한다.
	oil_report(2, 11);
	system("pause");
	return 0;
}