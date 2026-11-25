#define N 10
#define N2 100
#define XMAX 3
#define XMIN 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void task1();
void task2();
int count_positive(float C[N2]);
int count_negative(float C[N2]);
float sum_positive(float C[N2]);
float sum_negative(float C[N2]);
float arithm_mean_positive(float sum_positive, int count_positive);
float arithm_mean_negative(float sum_negative, int count_negative);
float y(float x);

int main() {
	setlocale(LC_CTYPE, "RUS");
	
	int user_inp;

	printf("Выберите задание (1 или 2): ");
	scanf("%d", &user_inp);
	printf("\n\n");

	if (user_inp == 1) task1();
	else if (user_inp == 2) task2();
	else printf("Такого задания нет");

	return 0;
}

void task1() {
	printf("Задание 1\n\n");
	float sum = 0;
	float A[N];
	float B[N];

	printf("Введите элементы массива\n");

	for (int i = 0; i < N; i++) {

		float temp;

		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		printf("\n");

		B[i] = temp;
		A[i] = temp * -1;
		sum += B[i];

	}

	printf("| индекс | исходное значение | новое значение |\n");

	for (int i = 0; i < N; i++) {

		printf("| %6d | %17f | %14f |\n", i, B[i], A[i]);

	}

	printf("Среднее арифметическое: %f\n", sum / N);

}

void task2() { //y = x**3 - 4 * x**2 + 2      [1; 3]
	printf("Задание 2\n\n");
	float C[N2];
	int stime;
	long ltime;
	
	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);

	for (int i = 0; i < N2; i++) {
		float temp;

		temp = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
		C[i] = y(temp);

	}


	printf("Массив C содержит:\n");
	printf("Накопленное значение положительных чисел: %f\n", sum_positive(C));
	printf("Накопленное значение отрицательных чисел: %f\n", sum_negative(C));
	printf("Число положительных чисел: %d\n", count_positive(C));
	printf("Число отрицательных чисел: %d\n", count_negative(C));
	printf("Среднее арифметическое положительных чисел: %f\n", arithm_mean_positive(sum_positive(C), count_positive(C)));
	printf("Среднее арифметическое отрицательных чисел: %f\n", arithm_mean_negative(sum_negative(C), count_negative(C)));

}

float y(float x) {
	float res;

	res = pow(x, 3) - 4 * x * x + 2;

	return res;
}

int count_positive(float C[N2]) {
	int res = 0;

	for (int i = 0; i < N2; i++) {

		if (C[i] > 0) res += 1;

	}

	return res;
}

int count_negative(float C[N2]) {
	int res = 0;

	for (int i = 0; i < N2; i++) {

		if (C[i] < 0) res += 1;

	}

	return res;
}

float sum_positive(float C[N2]) {
	float res = 0;

	for (int i = 0; i < N2; i++) {

		if (C[i] > 0) res += C[i];

	}

	return res;
}

float sum_negative(float C[N2]) {
	float res = 0;

	for (int i = 0; i < N2; i++) {

		if (C[i] < 0) res += C[i];

	}

	return res;
}

float arithm_mean_positive(float sum_positive, int count_positive) {
	if (count_positive == 0) return 0;
	else return sum_positive / count_positive;
}

float arithm_mean_negative(float sum_negative, int count_negative) {
	if (count_negative == 0) return 0;
	else return sum_negative / count_negative;
}