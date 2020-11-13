#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <queue>
#include <locale.h>
using namespace std;



int G[5][5], dist[5];
void rand_Zap(int* Matrix, int n) {
	srand(time(NULL));
	printf("G\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i * n + j] = 0;
			}
			if (i < j) {
				Matrix[i * n + j] = rand() % 2;
				Matrix[j * n + i] = Matrix[i * n + j];
			}
		}
}
void print_G(int* Matrix, int n) {
	printf("  ");
	for (int i = 0; i < n; i++)
		printf("%3d", i + 1);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++) {

			printf("%3d", Matrix[i * n + j]);
		}
		printf("\n");
	}
	printf("\n");


}
void BFSD(int v)
{
	queue <int> Q;
	Q.push(v);
	dist[v] = 0;
	while (Q.empty() == false) {
		v = Q.front();
		Q.pop();
		printf("%d ", v + 1);
		for (int i = 0; i < 5; i++) {
			if ((G[v][i] == 1) && dist[i] == -1) {
				Q.push(i);
				dist[i] = dist[v]+1;
			}
		}
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	DWORD Start = 0, End = 0;
	int i = 0, j = 0, r = 0, x = 1;
	for (i = 0; i < 5; i++)
		dist[i] = -1;
	rand_Zap(&G[0][0], 5);
	print_G(&G[0][0], 5);
	printf("введите вершину для начала обхода \n");
	scanf("%d", &x);
	x--;
	BFSD(x);
	for (i = 0; i < 5; i++)
	{
		if (dist[i]!=-1)
			printf("%d \t", dist[i]);
		else 
			printf("нет прохода \t");
	}
		
	getchar();
	return 0;
}