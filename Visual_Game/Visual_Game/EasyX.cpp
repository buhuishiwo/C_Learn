#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14
int main()
{
	//initgraph(800, 600);
	//setorigin(400, 300);
	//circle(0, 0, 300);
	//getchar();
	//closegraph();

	double theta = PI / 2;
	double delta = 2 * PI / 5;
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	int x, y,r=200;
	POINT points[3];
	for (int i = 0; i < 3; i++)
	{
		scanf("%d,%d", &points[i].x, &points[i].y);
	}
	polygon(points, 3);
	//for (int i = 0; i < 1000; i++)             //�������1000����
	//{
	//	x = rand() % (800 + 1) - 400;
	//	y = rand() % (600 + 1) - 300;
	//	putpixel(x, y, WHITE);
	//}
/*	rectangle(-200, 100, 200, -100); */           //����
	//for (r = 10; r <= 300; r=r+10)			//���ɰ뾶��10��300ÿ10������Բ
	//{
	//	circle(0, 0, r);
	//}
	//ellipse(-200, 100, 200, -100);              //��Բ
	//roundrect(-200, 200, 200, -200, 300, 200);  //Բ�Ǿ���
/*	pie(-200, 200, 200, -200, 0, PI ); */       //��������
/*	arc(-200, 200, 200, -200, 0, PI/3);*/			//����Բ��
	//POINT points[] = { {0,200},{200,-200},{-200,-200} };
	//polygon(points,3);
	getchar();
	closegraph();
	return 0;
}