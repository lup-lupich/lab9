#define _CRT_SECURE_NO_WARNINGS
#define ROW1 9
#define COL1 9
#include <stdio.h>
#include <locale.h>
#include <math.h>

void task1();
void task2();

int main() {
	setlocale(LC_CTYPE, "RUS");

	task1();
	task2();

	return 0;
}

void task1() {
	//task 1.1
	int row, col;

	printf("ЗАДАНИЕ 1\n\n");

	for (row = 1; row <= ROW1; row++) {
		for (col = 1; col <= COL1; col++)
			printf("%5d", col * row);
		printf("\n");
	}

	system("pause");

	//task 1.2
	int row2, col2;

	printf("\n");

	for (row2 = 1; row2 <= ROW1; row2++) {
		for (col2 = 1; col2 <= row2; col2++)
			printf("%5d", col2 * row2);
		printf("\n");
	}
	
	system("pause");

	//task 1.3
	int row3, col3, n;

	printf("\n");
	printf("Введите число: ");
	scanf("%d", &n);

	for (row3 = 1; row3 <= n; row3++) {
		for (col3 = 1; col3 <= row3; col3++)
			printf("%5d", row3);
		printf("\n");
	}

	system("pause");
}

void task2() {
	
	long int n;
	int count = 0;

	printf("ЗАДАНИЕ 2\n\n");
	printf("Введите число: \n");
	scanf("%ld", &n);

	n = labs(n);

	//1
	for (long temp = n; temp != 0; temp /= 10) {
		if (temp % 10 == 3) count += 1;
	}
	printf("1) Количество цифр 3 в числе: %d\n", count);
	count = 0;

	//2
	int last_digit = n % 10;

	for (long temp = n; temp != 0; temp /= 10) {
		if (temp % 10 == last_digit) count += 1;
	}
	printf("2) Число повторений последней цифры в числе: %d\n", count);
	count = 0;
	
	//3
	for (long temp = n; temp != 0; temp /= 10) {
		if ((temp % 10) % 2 == 0) count += 1;
	}
	printf("3) Количество четных цифр в числе: %d\n", count);
	count = 0;

	//4
	for (long temp = n; temp != 0; temp /= 10) {
		if ((temp % 10) > 5) count += 1;
	}
	printf("4) Количество цифр больших 5 в числе: %d\n", count);
	count = 0;

	//5
	for (long temp = n; temp != 0; temp /= 10) {
		if ((temp % 10) % 2 != 0) count += (temp % 10);
	}
	printf("5) Сумма нечетных цифр: %d\n", count);
	count = 0;

	//6
	for (long temp = n; temp != 0; temp /= 10) {
		if ((temp % 10) >= 7) count += (temp % 10);
	}
	printf("6) Сумма цифр больше или равно 7: %d\n", count);
	count = 0;

	//7
	count = 1;
	for (long temp = n; temp != 0; temp /= 10) {
		if ((temp % 10) != 0) count *= (temp % 10);
	}
	printf("7) Произведение всех цифр, исключая 0: %d\n", count);
	count = 0;

	//8
	count = (n / 10) % 10;
	for (long temp = n; temp != 0; temp /= 10) {
		if ((temp / 100) == 0) { count *= (temp % 10); break; }
	}
	printf("8) Произведение предпоследней и второй цифры числа: %d\n", count);
	count = 0;

	//9
	for (long temp = n / 10; temp != 0; temp /= 10) {
		if ((temp % 10) % 2  == 0) count += (temp % 10);
	}
	printf("9) Сумма четных цифр, исключая последнюю: %d\n", count);
	count = 0;

	//10
	int flag = 0;

	for (long temp = n; temp != 0; temp /= 10) {
		if ((temp % 10) == ((temp / 10) % 10)) {
			count = (temp % 10);
			flag = 1;
			break;
		}
	}
	if (flag == 1) printf("10) Рядом расположенные одинаковые цифры: %d%d\n", count, count);
	else printf("10) Рядом расположенных одинаковых цифр нет\n");
	
	count = 0;

	//11
	int first_half = 0;
	int second_half = 0;
	int res;

	for (long temp = n; temp != 0; temp /= 10) 
		count += 1;
	if (count % 2 != 0) printf("11) Количество цифр нечетна, невозможно определить, равна ли сумма первой и второй половины цифр числа\n");
	else {
		for (long temp = n / (int)pow(10., count / 2); temp != 0; temp /= 10)
			first_half += temp % 10;
		for (long temp = n % (int)pow(10., count / 2); temp != 0; temp /= 10)
			second_half += temp % 10;
		res = first_half == second_half;

		printf("11) Равна ли сумма первой и второй половины цифр числа (1 - да, 0 - нет): %d\n", res);
	}
	count = 0;

	//12
	int sum_even = 0;
	int sum_odd = 0;
	int product;

	for (long temp = n; temp != 0; temp /= 100) sum_odd += temp % 10;
	for (long temp = n / 10; temp != 0; temp /= 100) sum_even += temp % 10;
	product = sum_even * sum_odd;

	printf("12) Произведение сумм цифр, четных и нечетных разрядов: %d\n", product);
}