#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int n = 0;
typedef struct {
	char no[10], name[10];
	int cj1, cj2, cj3;
}stu;
void ym()
{
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| ������ѡ���ţ�0-6��|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|      1.��ʼ��       |\n");
	printf("|      2.��ʾ         |\n");
	printf("|      3.����         |\n");
	printf("|      4.���         |\n");
	printf("|      5.ɾ��         |\n");
	printf("|      6.����         |\n");
	printf("|      0.�˳�         |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~|\n");
}
void Init(stu d[])
{
	int i;
	for (i = 0; i < 3; i++)
	{
		scanf_s("%s %s %d %d %d", &d[i].no, &d[i].name, &d[i].cj1, &d[i].cj2, &d[i].cj3);
	}
	n = 3;
}
void Add(stu d[])
{
	printf("������ѧ��\n");
	scanf_s("%s", &d[3].no);
	printf("����������\n");
	scanf_s("%s", &d[3].name);
	printf("������ɼ�\n");
	scanf_s("%d %d %d", &d[3].cj1, &d[3].cj2, &d[3].cj3);
	getchar();
	n++;
}
void Del(stu d[])
{
	int i, b;
	printf("������Ҫɾ��ѧ����ѧ��\n");
	scanf_s("%d", &b);
	for (i = b - 1; i < n; i++)
	{
		d[i] = d[i + 1];
	}
	n--;
}
void Print(stu d[])
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s %s %d %d %d\n", d[i].no, d[i].name, d[i].cj1, d[i].cj2, d[i].cj3);
	}

}
void Sort(stu d[])
{
	int i;
	stu tmp;
	for (i = 0; i < n; i++)
	{
		if (strcmp(d[i].no, d[i + 1].no) > 0)
		{
			d[i] = d[i + 1];
			tmp = d[i];
			d[i + 1] = tmp;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %s %d %d %d\n", d[i].no, d[i].name, d[i].cj1, d[i].cj2, d[i].cj3);
	}
}
void Search(stu d[])
{
	printf("������Ҫ��ѯ��ѧ��\n");
	int n;
	scanf_s("%d", &n);
	printf("%s %s %d %d %d\n", d[n - 1].no, d[n - 1].name, d[n - 1].cj1, d[n - 1].cj2, d[n - 1].cj3);
}
int main()
{
	stu stu1[100];
	char choose, yn;

	do
	{
		ym();
		choose = _getche();
		switch (choose)
		{
		case '1':
			printf("\n");
			printf("����������ʼ��ѧ��\n");
			Init(stu1);
			break;

		case '2':
			printf("\n");
			printf("��ǰ��Ϣ���£�\n");
			Print(stu1);
			break;

		case '3':
			printf("\n");
			Search(stu1);
			break;

		case '4':
			printf("\n");
			Add(stu1);
			break;

		case '5':
			printf("\n");
			Del(stu1);
			break;

		case '6':
			printf("\n");
			printf("�������ս��Ϊ:\n");
			Sort(stu1);
			break;

		case '0': exit(0);
		default:
			printf("\n");
			printf("�������˴��������\n");
		}
		printf("�㻹Ҫ������\n");
		yn = _getche();
	} while (yn == 'Y' || yn == 'y');

}