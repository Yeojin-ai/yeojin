
typedef struct fileinfo {
	char address[300];	//�ñ���
	int num1;			//����
	int	num2;			//����
	int num3;			//�ι�
	char aptName[30];		//������
	double area;			//�������(m^2) ***
	double date;		//�����
	double day;		//�����
	int price;		//�ŷ��ݾ�(����) ***
	int floor;		//��
	int year;		//����⵵ ***
	char roadName[30];		//���θ�
	double num4;		//�������� �߻���
	char kind[30];		//�ŷ�����
	char place[50];		//�߰��������
}dict;

void printResult(dict* values,int i_count);