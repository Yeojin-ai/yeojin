
typedef struct fileinfo {
	char address[300];	//0.�ñ���
	int num1;			//1.����
	int	num2;			//2.����
	int num3;			//3.�ι�
	char aptName[30];		//4.������
	double area;			//5.�������(m^2) ***
	char date[10];		//6.����� ***
	double day;		//7.�����
	int price;		//8.�ŷ��ݾ�(����) ***
	int floor;		//9.��
	int year;		//10.����⵵ ***
	char roadName[30];		//11.���θ�
	double num4;		//12.�������� �߻���
	char kind[30];		//13.�ŷ�����
	char place[50];		//14.�߰��������
}dict;

void printResult(dict* values,int i_count);