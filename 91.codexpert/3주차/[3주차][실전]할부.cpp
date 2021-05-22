// 할부
#include <iostream>
using namespace std;

int N, B;
int solmin, solmax;
void InputData(){
	cin >> N >> B;
}

void Solve(){
	if (B % (N - 1) == 0){
		solmax = B + B / (N - 1);
		solmin = solmax - 1;
	}
	else{
		solmax = solmin = B + B / (N - 1);
	}
}

int main(){
	InputData();// 입력받는 부분
	Solve();
	cout << solmin << " " << solmax;// 출력하는 부분
	return 0;
}