#include<iostream>
using namespace std;

char str[100000 + 10];
void InputData(){
	cin >> str;
}

int Solve(){
	int count = 0;
	int sum = 0;
	for (int i = 0; str[i]; i++){
		if (str[i] == '('){
			count++; // �� ����� �� ����
		}
		else{
			count--;
			if (str[i - 1] == '('){ // ������
				sum += count;
			}
			else{
				sum++;
			}
		}
	}

	return sum;
}

int main(){
	int ans;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}