#include <stdio.h>
/*
1	3	6	10	15	21 .... 로 증가하는 수열
1	2	3	4	5	6 을 나타냄.
각 수열의 차이만큼이 n번째의 숫자의 개수.

입력이 8 이면 3번째 수열과 4번째 수열 사이에 존재.
이는 8이 숫자 4가 해당하는 곳에 있다는 뜻.
해당 숫자에서 몇번째 인지 확인 하려면
시작하는 곳 즉 3이 잇는 곳에서 얼마나 더해졌는 지 계산하면 나옴
따라서 8은 숫자 3 이 있는 곳에서 마지막 6 번째보다 2칸 더가고 마지막이 숫자 4가 있는곳이니깐
숫자 4 의 두번째.

1 22 333 4444 55555

10/23
*/

//몇번째 인지
int cal_cnt(int num)
{
	int add = 1;
	int temp = 0;

	while (1) {
		temp += add;
		if (temp > num) {
			temp -= add;
			return num - temp;
		}
		else if (temp == num) {
			return add;
		}
		add++;
	}

	return 0;
}

//어디에 있는지
int cal_pos(int num)
{
	int add = 1;
	int temp = 0;
	while (1) {
		temp += add;
		if (temp >= num)
			break;
		else
			add++;
	}
	return add;
}

int main() {
	int A = 0, B = 0;
	scanf_s("%d %d", &A, &B);

	int A_cnt = 0, B_cnt = 0;
	int A_pos = 0, B_pos = 0;

	int result = 0;

	//A, B 가 어느 구간에 속하는지?

	A_cnt = cal_cnt(A);
	B_cnt = cal_cnt(B);
	A_pos = cal_pos(A);
	B_pos = cal_pos(B);

	printf(">>%d %d %d %d<<\n", A_pos, A_cnt, B_pos, B_cnt);

	while (A_pos <= B_pos)
	{
		if (A_pos == B_pos) {
			while (A_cnt <= B_cnt) {
				result += A_pos;
				A_cnt++;
			}
		}
		else {
			while (A_cnt <= A_pos) {
				result += A_pos;
				A_cnt++;
			}
		}
		A_pos++;
		A_cnt = 1;
	}

	printf("\n\n%d\n", result);

	return 0;
}