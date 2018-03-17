#include "oil.h"
#include <stdio.h>
#include <stdlib.h>

int min = 0;
int max = 0;

void checkOil(int left, int right) {
	int pivot = (left + right) / 2;
	int v1;
	int v2;

	v1 = observe(left, pivot);
	v2 = observe(pivot + 1, right);
	if (v1 == 1) {
		printf("v1 == %d %d\n", left, pivot);
		
		if (min == 0 || min > left)
			min = left;
		if (max == 0 || max < pivot)
			max = pivot;
	}
	if (v2 == 1) {
		printf("v2 == 1, %d %d\n", pivot + 1, right);
		if (min == 0 || min > pivot + 1)
			min = pivot + 1;
		if (max == 0 || max < right)
			max = right;
	}

	if (v1 == 2) {
		if (v2 > 0)
			left += 1;
		checkOil(left, pivot);
	}
	if (v2 == 2) {
		if (v1 > 0)
			right -= 1;
		checkOil(pivot + 1, right);
		
	}
}

int main() {
	initial();
	int N = oil_size();
	

	int sVal = 1;
	int cnt = 0;
	int tf = 1;
	checkOil(0, N - 1);

	oil_report(min, max);
	system("pause");
	return 0;
}