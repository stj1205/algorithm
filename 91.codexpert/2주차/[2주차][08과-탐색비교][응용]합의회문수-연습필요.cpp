// 합의 회문수
// 수 124를 뒤집으면 421이 되고 이 두 수를 합하면 545가 된다.
// 124와 같이 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되는지 테스트 하는 프로그램을 작성하시오.
#include <iostream>
using namespace std;

int M;//정수

void InputData(){
	cin >> M;
}

void OutputData(int ans){
	if (ans == 0) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int reverse(int num){
	int ret = 0;
	while (num > 0){
		ret = ret * 10 + num % 10;
		num = num / 10;
	}
	return ret;
}

int Solve(){
	int sum = M + reverse(M);
	if (sum == reverse(sum)) return 1;
	return 0;
}

int main() {
	int N, i, ans;
	cin >> N;
	for (i = 0; i < N; i++) {
		InputData();//입력
		ans = Solve();
		OutputData(ans);//출력
	}
	return 0;
}