// 원안의 사각형
// 원의 반지름이 주어질 때 원 안의 사각형 개수를 구하는 문제
#include <iostream>
using namespace std;

int R;//원의 반지름

void InputData(){
	cin >> R;
}

int Solve(){
	int count = 0;
	for (int a = 1; a <= R; a++){
		for (int b = 1; b <= R; b++){
			if (a*a + b*b <= R*R){
				count++;
			}
		}
	}
	return count * 4;
}

int main() {
	int ans;
	InputData();//입력
	ans = Solve();
	cout << ans << endl;//출력
	return 0;
}