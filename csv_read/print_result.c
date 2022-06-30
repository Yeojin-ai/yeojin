#include <stdio.h>
#include "csv_practice.h"

void printResult(dict *values,int i_count) {
	long double sumArea = 0;
	unsigned int sumPrice = 0;
	unsigned int sumYears = 0;
	int i = 0;
	char search[10];
	printf("�˻��� ���� �Է��ϼ���: ");
	scanf("%s", search);

	while (i_count >= 0) {
		char* ptr=strstr(values[i_count].address,search);
		if (ptr != 0) {
			//printf("ã�Ҵ� %s %f\n", values[i_count].address,values[i_count].area);
			sumArea += values[i_count].area;
			sumPrice += values[i_count].price;
			sumYears += values[i_count].year;
			i++;
		}
		i_count--;
	}
	if (sumArea != 0) {
		printf("[%s�� �˻����]\n", search);
		printf("area average: %lf\nprice average: %.4lf\nyear average: %.4lf\nthe number of total data: %d\n", sumArea / i, (long double)sumPrice / i, (long double)sumYears / i, i);
	}
	else printf("error: ��ġ�ϴ� ���� ã�� �� �����ϴ�.\n");
	
	return 0;
}