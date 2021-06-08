#include <iostream>
#include <stack>
#include <list>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::stack <int> st;
	int n;

	std::cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	std::list <char> l; //push, pop�� ���� +,-�� ����ϴ� ���� �����ϴ� list

	int index = 1; //stack�� push�ϴ� ���ڵ��� ������������ �� ���ڴ� �ѹ��� ���� ������ index ������ 1�� ����, arr[n]���� push

	for (int i = 0; i < n; i++) {
		if (i == 0) { //���� ó���� ��� (i==0�� ���) �ش�Ǵ� ���ڱ��� push
			for (index; index <= arr[i]; index++) { //ó���� ���� ������ index�� 0, arr[i]���� push�ϱ� ������ �߰����� index<=arr[i]
				st.push(index); //�ش�Ǵ� ���ڱ��� ��� push
				l.push_back('+'); //push 1ȸ�� list�� + push
			}
			st.pop(); //�ش�Ǵ� ���ڸ� pop
			l.push_back('-'); //pop 1ȸ�� list�� - push
		}
		else { //���� ó���� ������ ���
			if (arr[i] < arr[i - 1]) { //������ ��찡 ���� ��캸�� ���� ���� 1ȸ�� pop���� �ȵǸ� �Ұ��� 
				if (st.top() == arr[i]) { //1ȸ�� pop�� ������� ������ ���� ���� ���̶�� ����.
					st.pop(); //arr[i]�� ���� pop
					l.push_back('-'); //pop 1ȸ�� list�� - push
				}
				else { //1ȸ�� pop�� ������� ������ ���� �ٸ� ���� �Ұ����� ���.
					std::cout << "NO"; //��� �Ұ��� message�� ����� ��
					return 0; //���α׷��� ����
				}
			}
			else { //������ ��찡 ���� ��캸�� ū ���� �ش� ���ڱ��� push
				for (index; index <= arr[i];index++) {
					st.push(index); //�ش�Ǵ� ���ڱ��� ��� push
					l.push_back('+'); //push 1ȸ�� list�� + push
				}
				st.pop(); //�ش�Ǵ� ���ڸ� pop
				l.push_back('-'); //pop 1ȸ�� list�� - push
			}
		}
	}
	for (std::list<char>::iterator it = l.begin();it != l.end(); it++)
		std::cout << *it << "\n";
}