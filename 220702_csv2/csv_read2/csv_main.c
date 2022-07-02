/*220630 과제.
csv파일 읽고 전용면적 평균,거래금액 평균, 건축년도의 평균과 총 몇 건인지 count하기
220702 scanf로 동이름, year, month 받아서 해당 조건의 매매가 min max average
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "csv_practice.h"



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

	dict values[1010];	//array to structs to store values
	int i = 0;	//column index
	int i_count = 0;	//the number of total index

	while (fgets(str_tmp, 1024, fp)) {	 	//read one line at a time

		//printf("%s", str_tmp);	//print str_tmp
		column_count = 0;
		row_count++;
		if (row_count <= 16) continue;	//pass explain lables(not using data)
		//printf("%s", str_tmp);	

		char* column = strtok(str_tmp, ","); //seperate column with commas
		char* ptr=0;
			while (column) {
				if (column_count == 0) 
					strcpy(values[i].address, column);
				if (column_count == 5)
					values[i].area = atof(column);
				if (column_count == 6)
					strcpy(values[i].date, column);
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
	while (i>0) {	//print parsing datas
		--i;
		printf("%s %f %s %d %d\n", values[i].address, values[i].area, values[i].date, values[i].price, values[i].year);
	}
	*/
	fclose(fp);


	while (1) {
		printResult(values, i_count);
	};
	
	return 0;
}
