#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
//20291
int main() {
	int N = 0;
	string input;
	cin >> N;
	vector<string> name;
	int index = 1;

	for (int i = 0; i < N; i++) {
		cin >> input;
		string temp = input.erase(0, input.find(".") + 1);
		name.push_back(temp);
	}

	sort(name.begin(), name.end());

	for (int i = 0; i < N; i++) {
		if (i != 0) {
			if (name[i] == name[i - 1]) {
				index++;
			}
			else if(name[i] != name[i-1]){
				cout << name[i - 1] << " " << index << "\n";
				index = 1;
			}
			if (i + 1 == N)
				cout << name[i] << " " << index << "\n";
		}
	}

	return 0;
}