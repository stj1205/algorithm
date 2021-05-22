// ���� ȸ����
// �� 124�� �������� 421�� �ǰ� �� �� ���� ���ϸ� 545�� �ȴ�.
// 124�� ���� ���� ���� ������ ���� ���� ���� �¿� ��Ī�� �Ǵ��� �׽�Ʈ �ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <iostream>
using namespace std;

int M;//����

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
		InputData();//�Է�
		ans = Solve();
		OutputData(ans);//���
	}
	return 0;
}