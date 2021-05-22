// �ۼ��ž��׳�
// N���� ���׳��� �Ϸķ� ��ġ�ؼ� �󸶳� �ۼ����� �������� ����ϴ� ����
// �ۼ��� ���׳� ���� �ִ� 10^5�̹Ƿ� ���� for�����δ� �ð����⵵ ������ ���� -> O(N)�� ����� �ð����⵵�� �ذ� �ʿ�
// ������ ���׳��� ���̸� ����Ͽ� Ȯ���ϴ� ������ stack�� ��� �ʿ�
#include<iostream>
#include<stack>
using namespace std;

int N; // �ۼ��� ���׳� ��
int H[100000 + 10]; // �ۼ��� ���׳� ����

stack<int> s;

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &H[i]);
}

int Solve(){
	int cnt = 0;

	for (int i = 0; i < N; i++){
		while (!s.empty()){
			int v = s.top();
			if (v < H[i]){ // ū ���� ���� ���
				s.pop();
				cnt++;
			}
			else if (v == H[i]){ // ���� ���
				s.pop();
				cnt++; // ó������ ���ӵ� ���� ������ case�� ����
				break;
			}
			else{ // ������ break;
				cnt++;
				break;
			}
		}
		s.push(H[i]);
	}

	return cnt;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	printf("%d\n", ans); // ���
	return 0;
}