// �Һ�
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
	InputData();// �Է¹޴� �κ�
	Solve();
	cout << solmin << " " << solmax;// ����ϴ� �κ�
	return 0;
}