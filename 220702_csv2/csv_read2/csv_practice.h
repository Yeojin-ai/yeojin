
typedef struct fileinfo {
	char address[300];	//0.시군구
	int num1;			//1.번지
	int	num2;			//2.본번
	int num3;			//3.부번
	char aptName[30];		//4.단지명
	double area;			//5.전용면적(m^2) ***
	char date[10];		//6.계약년월 ***
	double day;		//7.계약일
	int price;		//8.거래금액(만원) ***
	int floor;		//9.층
	int year;		//10.건축년도 ***
	char roadName[30];		//11.도로명
	double num4;		//12.해제사유 발생일
	char kind[30];		//13.거래유형
	char place[50];		//14.중개사소재지
}dict;

void printResult(dict* values,int i_count);