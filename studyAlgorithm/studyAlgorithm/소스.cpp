#include <stdio.h>
/*
1	3	6	10	15	21 .... �� �����ϴ� ����
1	2	3	4	5	6 �� ��Ÿ��.
�� ������ ���̸�ŭ�� n��°�� ������ ����.

�Է��� 8 �̸� 3��° ������ 4��° ���� ���̿� ����.
�̴� 8�� ���� 4�� �ش��ϴ� ���� �ִٴ� ��.
�ش� ���ڿ��� ���° ���� Ȯ�� �Ϸ���
�����ϴ� �� �� 3�� �մ� ������ �󸶳� �������� �� ����ϸ� ����
���� 8�� ���� 3 �� �ִ� ������ ������ 6 ��°���� 2ĭ ������ �������� ���� 4�� �ִ°��̴ϱ�
���� 4 �� �ι�°.

1 22 333 4444 55555

10/23
*/

//���° ����
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

//��� �ִ���
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

	//A, B �� ��� ������ ���ϴ���?

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