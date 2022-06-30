#include <stdio.h>
#include "csv_practice.h"

void printResult(dict *values,int i_count) {
	long double sumArea = 0;
	unsigned int sumPrice = 0;
	unsigned int sumYears = 0;
	int i = 0;
	char search[10];
	printf("검색할 동을 입력하세요: ");
	scanf("%s", search);

	while (i_count >= 0) {
		char* ptr=strstr(values[i_count].address,search);
		if (ptr != 0) {
			//printf("찾았다 %s %f\n", values[i_count].address,values[i_count].area);
			sumArea += values[i_count].area;
			sumPrice += values[i_count].price;
			sumYears += values[i_count].year;
			i++;
		}
		i_count--;
	}
	if (sumArea != 0) {
		printf("[%s동 검색결과]\n", search);
		printf("area average: %lf\nprice average: %.4lf\nyear average: %.4lf\nthe number of total data: %d\n", sumArea / i, (long double)sumPrice / i, (long double)sumYears / i, i);
	}
	else printf("error: 일치하는 동을 찾을 수 없습니다.\n");
	
	return 0;
}