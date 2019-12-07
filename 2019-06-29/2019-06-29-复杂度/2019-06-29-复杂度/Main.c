#include <stdio.h>

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void bubbleSort(int a[], int size) {
	// ѭ���� size ��
	for (int i = 0; i < size; i++) {
		// �����Ѿ�������
		int ordered = 1;

		// ����[size - i, size)
		// ����[0, size - i)
		// ð�ݲ��֣�ֻ�����������ڽ���
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a, j, j + 1);
				// �����������������򲻳���
				ordered = 0;
			}
		}

		// ���������Ȼ����������˳���
		if (ordered == 1) {
			break;
		}
	}
}

int binarySearch(int a[], int size, int value) {
	int left = 0;	// �����������߽磬�Ǹ��±꣬����
	int right = size;	// ����������ұ߽磬�Ǹ��±꣬������

	// [left, right)
	while (left < right) {
		int mid = (left + right) / 2;
		if (value == a[mid]) {
			return mid;
		}
		else if (value < a[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

int main() {
	int a[] = { 9, 5, 2, 7, 3, 6, 8, 4 };
	int size = sizeof(a) / sizeof(int);

	bubbleSort(a, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	int index = binarySearch(a, size, 3);
	printf("3 �� %d\n", index);
}