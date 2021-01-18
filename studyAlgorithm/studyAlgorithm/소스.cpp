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

	//입력값 제곱수
	int N2 = N * N;
	arr[arrx++][arry] = N2--;
	
	/*
	1. 아래
	2. 오른쪽
	3. 위
	4. 왼쪽
	순서로 돌면서 값이 0이 아닐때 까지 반복
	
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

	//표 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//그리다가 현재 찍을 값이 find 면 i,j 값을 x,y 에 저장.
			cout << arr[i][j] << " ";
			if (arr[i][j] == find) {
				x = i+1;
				y = j+1;
			}
		}
		cout << "\n";
	}

	//값 출력
	cout << x << " " << y << "\n";

	//해제
	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}
	return 0;
}