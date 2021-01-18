#include<iostream>
using namespace std;

//1913
int main() {
	int N = 0;
	int find = 0;
	int x = 0, y = 0;
	cin >> N;
	cin >> find;

	int** arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		memset(arr[i], 0, sizeof(int) * N);
	}

	int arrx = 0, arry = 0;

	//�Է°� ������
	int N2 = N * N;
	arr[arrx++][arry] = N2--;
	
	/*
	1. �Ʒ�
	2. ������
	3. ��
	4. ����
	������ ���鼭 ���� 0�� �ƴҶ� ���� �ݺ�
	
	*/

	while (N2 > 1) {
		//1.
		while (arrx < N) {
			if (arr[arrx][arry] == 0) {
				arr[arrx][arry] = N2--;
				arrx++;
			}
			else {
				break;
			}
		}
		arry++;
		arrx--;

		//2.
		while (arry < N) {
			if (arr[arrx][arry] == 0) {
				arr[arrx][arry] = N2--;
				arry++;
			}
			else {
				break;
			}
		}
		arrx--;
		arry--;

		//3.
		while (arrx >= 0) {
			if (arr[arrx][arry] == 0) {
				arr[arrx][arry] = N2--;
				arrx--;
			}
			else {
				break;
			}
		}
		arrx++;
		arry--;

		//4.
		while (arry >= 0) {
			if (arr[arrx][arry] == 0) {
				arr[arrx][arry] = N2--;
				arry--;
			}
			else {
				break;
			}
		}
		arrx++;
		arry++;
	}
	arr[arrx][arry] = 1;

	//ǥ ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//�׸��ٰ� ���� ���� ���� find �� i,j ���� x,y �� ����.
			cout << arr[i][j] << " ";
			if (arr[i][j] == find) {
				x = i+1;
				y = j+1;
			}
		}
		cout << "\n";
	}

	//�� ���
	cout << x << " " << y << "\n";

	//����
	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}
	return 0;
}