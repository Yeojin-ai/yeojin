
typedef struct fileinfo {
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

void printResult(dict* values,int i_count);