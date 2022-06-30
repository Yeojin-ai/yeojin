/*220630 과제.
csv파일 읽고 전용면적 평균,거래금액 평균, 건축년도의 평균과 총 몇 건인지 count하기*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "csv_practice.h"

typedef struct fileinfo{
	char address[300];	//시군구
	int num1;			//번지
	int	num2;			//본번
	int num3;			//부번
	char aptName[30];		//단지명
	double area;			//전용면적(m^2) ***
	double date;		//계약년월
	double day;		//계약일
	int price;		//거래금액(만원) ***
	int floor;		//층
	int year;		//건축년도 ***
	char roadName[30];		//도로명
	double num4;		//해제사유 발생일
	char kind[30];		//거래유형
	char place[50];		//중개사소재지
}dict;

int main() {

	char* filename = "apt_price2.csv";	//set file with filename

	FILE* fp = fopen(filename, "r"); //input file as read mode //"w""wr"

	if (!fp) {	//missing file error
		printf("error: missing input file '%s'\n", filename);
		return -1;
	}
	char str_tmp[1024]; //one line temp variable
	int row_count = 0;
	int column_count = 0;

	dict values[1100];	//array to structs to store values
	int i = 0;	//column index
	int i_count = 0;	//the number of total index

	while (fgets(str_tmp, 1024, fp)) {	 	//read one line at a time

		//printf("%s", str_tmp);	//print str_tmp
		column_count = 0;
		row_count++;
		if (row_count <= 16) continue;	//pass explain lables(not using data)
		//printf("%s", str_tmp);	

		char* column = strtok(str_tmp, ","); //seperate column with commas
		while (column) {
			if (column_count == 5)
				values[i].area= atof(column);
			if (column_count == 8)
				values[i].price = atoi(column);
			if (column_count == 10)
				values[i].year = atoi(column);
			column = strtok(NULL, ",");	//column: poining pointer address
			column_count++;
		}
		i++;
	}
	i_count = i-1;
	/*
	while (i) {	//print parsing datas
		printf("%f %d %d\n", values[i].area, values[i].price, values[i].year);
		i--;
	}
	*/
	fclose(fp);
	
	long double sumArea = 0;
	unsigned int sumPrice = 0;
	unsigned int sumYears = 0;

	while (i_count>=0) {

		sumArea += values[i_count].area;
		sumPrice += values[i_count].price;
		sumYears += values[i_count].year;

		i_count--;
	}
	i_count = i;

	printf("area average: %lf\nprice average: %.4lf\nyear average: %.4lf\nthe number of total data: %d\n", sumArea/i_count, (long double)sumPrice/i_count, (long double)sumYears/i_count,i_count);
	
	return 0;
}
