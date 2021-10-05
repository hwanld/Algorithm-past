#include <iostream>

using ll = long long;
ll func1(ll a, ll b, ll c);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll a, b, c;
	std::cin >> a >> b >> c;
	std::cout << func1(a, b, c);
}

ll func1(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll val = func1(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) return val;
	return val * a % c;
}