#include <stdio.h>

// 10/24

int main() {
	int input[8];
	int result = 0;
	int index = 0;
	int temp = 0;
	int inputidx[8] = { 1,2,3,4,5,6,7,8 };

	//입력
	for (int i = 0; i < 8; i++)
		scanf_s("%d", &input[i]);

	//오름차순
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (input[i] < input[j]) {
				temp = input[i];
				index = inputidx[j];

				input[i] = input[j];
				input[j] = temp;

				inputidx[j] = inputidx[i];
				inputidx[i] = index;
			}
		}
	}

	for (int i = 0; i < 5; i++)
		result += input[i];

	printf("%d\n", result);

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (inputidx[i] > inputidx[j]) {
				temp = inputidx[j];
				inputidx[j] = inputidx[i];
				inputidx[i] = temp;
			}
		}
		printf("%d ", inputidx[i]);
	}
	return 0;
}