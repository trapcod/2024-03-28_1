#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 101 // ���׽��� �ִ����� + 1
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;
polynomial a = { 5, {10, 0, 0, 0, 6, 3} };

polynomial poly_multiply(polynomial A, polynomial B)
{
	polynomial C;
	C.degree = A.degree + B.degree; // ��� ���׽� ����
	for (int i = 0; i <= C.degree; i++) {
		C.coef[i] = 0; // ��� ���׽��� ����� 0���� �ʱ�ȭ
	}
	for (int i = 0; i <= A.degree; i++) {
		for (int j = 0; j <= B.degree; j++) {
			C.coef[i + j] += A.coef[i] * B.coef[j]; // ���׽� ���� ����
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}
// ���Լ�
int main(void)
{
	polynomial a = { 3, {4, 3, 2, 1} };
	polynomial b = { 2,{ 3, 2, 8} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_multiply(a, b);
	printf("---------------------------------------------------------------------------- - \n");
	print_poly(c);
	return 0;
}

int MAX(int a, int b) {
	return (a > b) ? a : b;
}