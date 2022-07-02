#include <stdio.h>
#include <string.h>
#include "csv_practice.h"

void printResult(dict *values,int i_count) {

	long double sumArea = 0;
	unsigned int sumPrice = 0;
	unsigned int sumYears = 0;
	char place[10];	//place name
	int year;		//year
	char month[3];		//month

	int i = 0;	//count number of search data
	int i_count_temp = 0;	//for storing search data's previous i_count

	unsigned int minPrice = 0;
	unsigned int maxPrice = 0;
	

	printf("Input 'place(동 이름)' 'year(0000)' 'month(00)': ");
	scanf("%s %d %s", place, &year, month);

	while (i_count >= 0) {
		char* bool_place = strstr(values[i_count].address, place);	//check the user's input(place)
		int bool_year = (values[i_count].year = year);				//check the user's input(year)
		char valueDate_cut[3] = { values[i_count].date[4],values[i_count].date[5] };	//cut only month from the date(ex.201010) data
		char* bool_month = strstr(valueDate_cut, month);	//check the user's input(month)

		
		if ((bool_place != 0) && bool_year && (bool_month != 0)) {

			//printf("찾았다 %s %s %d %d\n", values[i_count].address, values[i_count].date, values[i_count].year, values[i_count].price);

			sumArea += values[i_count].area;
			sumPrice += values[i_count].price;
			sumYears += values[i_count].year;

			//find maxPrice
			int maxtemp= values[i_count].price;
			if (maxtemp>=maxPrice) maxPrice = maxtemp;

			//find minPrice
			int mintemp = values[i_count].price;
			if (i_count_temp == 0) {
				minPrice = mintemp;
			}else {
				if (minPrice >= mintemp) {
					minPrice = mintemp;
				}
			}
			i++; 
			i_count_temp = i_count;
		}
		i_count--;
	}
	if (sumArea != 0) {
		printf("[%s동 매매가 검색결과 (total %d)]\n", place,i);
		//printf("area average: %lf\nprice average: %.4lf\nyear average: %.4lf\nthe number of total data: %d\n\n", sumArea / i, (long double)sumPrice / i, (long double)sumYears / i, i);
		printf("min: %d\nmax: %d\naverage: %.4lf\n\n", minPrice,maxPrice,(long double)sumPrice / i);
	}
	else printf("error: 일치하는 동을 찾을 수 없습니다.\n\n");
	
	return 0;
}