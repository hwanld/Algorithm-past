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

	std::list <char> l; //push, pop에 따라 +,-를 출력하는 값을 저장하는 list

	int index = 1; //stack에 push하는 숫자들은 오름차순으로 한 숫자당 한번만 들어가기 때문에 index 변수를 1로 지정, arr[n]까지 push

	for (int i = 0; i < n; i++) {
		if (i == 0) { //가장 처음의 경우 (i==0의 경우) 해당되는 숫자까지 push
			for (index; index <= arr[i]; index++) { //처음의 경우기 때문에 index는 0, arr[i]까지 push하기 때문에 중간식은 index<=arr[i]
				st.push(index); //해당되는 숫자까지 계속 push
				l.push_back('+'); //push 1회당 list에 + push
			}
			st.pop(); //해당되는 숫자를 pop
			l.push_back('-'); //pop 1회당 list에 - push
		}
		else { //가장 처음을 제외한 경우
			if (arr[i] < arr[i - 1]) { //현재의 경우가 전의 경우보다 작은 경우는 1회의 pop으로 안되면 불가능 
				if (st.top() == arr[i]) { //1회의 pop의 결과값이 현재의 경우와 같은 값이라면 가능.
					st.pop(); //arr[i]의 값을 pop
					l.push_back('-'); //pop 1회당 list에 - push
				}
				else { //1회의 pop의 결과값이 현재의 경우와 다른 경우는 불가능한 경우.
					std::cout << "NO"; //즉시 불가능 message를 출력한 후
					return 0; //프로그램을 종료
				}
			}
			else { //현재의 경우가 전의 경우보다 큰 경우는 해당 숫자까지 push
				for (index; index <= arr[i];index++) {
					st.push(index); //해당되는 숫자까지 계속 push
					l.push_back('+'); //push 1회당 list에 + push
				}
				st.pop(); //해당되는 숫자를 pop
				l.push_back('-'); //pop 1회당 list에 - push
			}
		}
	}
	for (std::list<char>::iterator it = l.begin();it != l.end(); it++)
		std::cout << *it << "\n";
}