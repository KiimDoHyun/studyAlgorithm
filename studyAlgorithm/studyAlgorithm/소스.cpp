#include <stdio.h>
#include <stdlib.h>

//10/24

int main() {
	int A, B;
	int input[2];
	int result = 0;
	int check = 1;

	scanf_s("%d", &A);
	scanf_s("%d", &B);

	//���⿡ üũ
	int* checkArr = (int*)malloc(sizeof(int) * A);

	//2���� �迭
	int** resultArr = (int**)malloc(sizeof(int*) * A);
	for (int i = 0; i < A; i++) {
		resultArr[i] = (int*)malloc(sizeof(int) * A);
	}

	//0���� �ʱ�ȭ
	for (int i = 0; i < A; i++) {
		checkArr[i] = 0;
		for (int j = 0; j < A; j++) {
			resultArr[i][j] = 0;
		}
	}

	//�Է°��� �������� �迭 ����
	for (int i = 0; i < B; i++) {
		scanf_s("%d %d", &input[0], &input[1]);

		resultArr[input[0] - 1][input[1] - 1] = input[1];
		resultArr[input[1] - 1][input[0] - 1] = input[0];
	}

	for (int i = 0; i < A; i++) {
		//���� �ε���(i+1)�� checkArr�� ���߿� �ϳ����� Ȯ���ؼ� ������ �ְ�(=1) �ƴϸ�(=0) �н� 
		if (i != 0) {
			for (int j = 0; j < A; j++) {
				if (checkArr[j] == i + 1) {
					check = 1;
					break;
				}
				else
					check = 0;
			}
		}

		if (check == 1) {
			for (int j = 0; j < A; j++) {
				if (resultArr[i][j] != 0) {
					checkArr[j] = resultArr[i][j];
				}
			}
		}
		else
			continue;
	}

	//üũ
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			printf("%d ", resultArr[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < A; i++) {
		printf("%d ", checkArr[i]);
	}
	printf("\n");


	//count
	for (int i = 0; i < A; i++) {
		if (i > 0)
			if (checkArr[i] != 0)
				result++;
	}

	printf("%d\n", result);

	//�����Ҵ� ����
	for (int i = 0; i < A; i++) {
		free(resultArr[i]);
	}
	free(resultArr);
	free(checkArr);

	return 0;
}