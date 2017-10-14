#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#define PI 3.14159265358979323846
#define P_N 20
#define SCREEN_X 980
#define SCREEN_Y 700
#define SCREEN_BASE 140
struct POINT_S
{
	int x;
	int y;
};
void change(POINT_S *a, POINT_S *b)
{
	POINT_S t = *a;
	*a = *b;
	*b = t;
}

void picking_point()
{
	int x[7];
	int y[5];
	POINT_S p[10];
	for (int i = 0; i < 7; i++)
		x[i] = i;
	for (int i = 0; i < 5; i++)
		y[i] = i;
	srand((unsigned int)time(NULL));
	p[0].x = x[0];
	p[0].y = y[0];
	p[1].x = x[6];
	p[1].y = y[0];
	p[2].x = x[6];
	p[2].y = y[4];
	p[3].x = x[0];
	p[3].y = y[4];
	for (int i = 4; i < 10; i++)
	{
		p[i].x = x[rand() % 7];
		p[i].y = y[rand() % 5];
		for (int j = 0; j < i; j++)
			if (p[i].x == p[j].x&&p[i].y == p[j].y)
				i--;

	}
	for (int i = 0; i < 10; i++)
		printf("%d,%d	", p[i].x, p[i].y);

	for (int i = 1; i < 10; i++)
		for (int j = i + 1,min=(p[i].x-p[j].x)*(p[i].x - p[j].x)+(p[i].y-p[j].y)*(p[i].y - p[j].y); j < 10; j++)
		{
			if (min > (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y) && atan2(p[i].x - p[j].x, p[i].y - p[j].y) - atan2(p[i].x - p[i - 1].x, p[i].y - p[i - 1].y) >= PI / 6)
			{
				min = (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y);
				change(&p[j], &p[i + 1]);
			}
		}
	for (int i = 0; i < 9; i++)
		line(p[i].x*SCREEN_BASE + SCREEN_BASE / 2, p[i].y*SCREEN_BASE + SCREEN_BASE / 2, p[i + 1].x*SCREEN_BASE + SCREEN_BASE / 2, p[i + 1].y*SCREEN_BASE + SCREEN_BASE / 2);//Connect 0-8 points in turn
	line(p[0].x*SCREEN_BASE + SCREEN_BASE / 2, p[0].y*SCREEN_BASE + SCREEN_BASE / 2, p[9].x*SCREEN_BASE + SCREEN_BASE / 2, p[9].y*SCREEN_BASE + SCREEN_BASE / 2);//Connect 0,9 points
	getchar();
	printf("\n\n\n\n");
	for (int i = 0; i < 10; i++)
		printf("%d,%d	", p[i].x, p[i].y);
	//printf("%lf", atan2(1, 1)*180/PI);
}
int main()
{
	//getchar();
	initgraph(1000, 700, NULL);
	picking_point();
}
