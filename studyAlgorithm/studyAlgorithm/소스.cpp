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

	//여기에 체크
	int* checkArr = (int*)malloc(sizeof(int) * A);

	//2차원 배열
	int** resultArr = (int**)malloc(sizeof(int*) * A);
	for (int i = 0; i < A; i++) {
		resultArr[i] = (int*)malloc(sizeof(int) * A);
	}

	//0으로 초기화
	for (int i = 0; i < A; i++) {
		checkArr[i] = 0;
		for (int j = 0; j < A; j++) {
			resultArr[i][j] = 0;
		}
	}

	//입력값을 바탕으로 배열 생성
	for (int i = 0; i < B; i++) {
		scanf_s("%d %d", &input[0], &input[1]);

		resultArr[input[0] - 1][input[1] - 1] = input[1];
		resultArr[input[1] - 1][input[0] - 1] = input[0];
	}

	for (int i = 0; i < A; i++) {
		//현재 인덱스(i+1)가 checkArr의 값중에 하나인지 확인해서 맞으면 넣고(=1) 아니면(=0) 패스 
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

	//체크
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

	//동적할당 해제
	for (int i = 0; i < A; i++) {
		free(resultArr[i]);
	}
	free(resultArr);
	free(checkArr);

	return 0;
}