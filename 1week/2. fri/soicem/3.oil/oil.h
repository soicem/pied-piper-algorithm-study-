#pragma once
#include <stdio.h>
#include <stdlib.h>
// 아래 변수 5개는 실제 답안 제출시 접근할 수 없는 변수 입니다.
// 함수만 참고하시기 바랍니다.

int Oil_sz;     /* 전체 땅의 크기 */
int Oil_beg;    /* 원유 구간의 시작 지점 */
int Oil_end;    /* 원유 구간의 끝 지점 */
int call_num;   /* observe() 호출 횟수 */
int call_limit; /* observe() 호출 횟수 제한 */

				/* initial() : 전체 땅의 크기, 원유구간, 호출 횟수 제한 설정 */
void initial() {
	// 답안 제출시, 가장 먼저 반드시 initial() 함수를 호출해야 합니다.
	// 학생이 직접 파일입출력을 할 수 없습니다.

	call_num = 0;

	/* Sample Data 1 */
	Oil_sz = 19;
	Oil_beg = 2;
	Oil_end = 11;
	call_limit = 10;

	/* Sample Data 2 */
	//    Oil_sz      = 1000;
	//    Oil_beg     =  599;
	//    Oil_end     =  599;
	//    call_limit  =   30;

	/* Sample Data 3 */
	//    Oil_sz      = 10000;
	//    Oil_beg     =  1113;
	//    Oil_end     =  1794;
	//    call_limit  =    40;

	/* Sample Data 4 */
	//    Oil_sz      = 100000;
	//    Oil_beg     =  92981;
	//    Oil_end     =  99984;
	//    call_limit  =     50;

}

/* oil_size() : 전체 땅의 크기 반환 */
int oil_size() {
	return Oil_sz;
}

/* observe(i, j) : Oil[i;j]의 상태 반환 */
int observe(int i, int j) {

	call_num++;

	/* 호출 횟수 초과 */
	if (call_num > call_limit) {
		printf("%d %d %d\n", 0, 0, call_num);
		//exit(0);
	}

	/* 3. index 오류 */
	if (i>j || i<0 || j<0 || i >= Oil_sz || j >= Oil_sz)
		return -1;

	if (j< Oil_beg || i> Oil_end) return 0;    /* 1. 전 구간이 모두 '0' : Empty */
	if (i >= Oil_beg && j <= Oil_end) return 1;    /* 2. 전 구간이 모두 '1' : Oil */

	return 2;                                   /* 4. '0'과 '1'이 모두 포함 : Mixed */
}

/* oil_report(i, j) : 답안 출력*/
void oil_report(int i, int j) {
	// 답안 제출시 반드시 oil_report(i, j)를 이용해 정답을 출력하십시요.
	// oil_report(i,j)를 호출하지 않고, 직접 파일 입출력을 할 경우 오답 처리 됩니다.
	// if( Oil_beg==i && Oil_end==j ) printf("정답");

	printf("%d %d", i, j);
}
