#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string tx;
	cin >> tx;

	const auto& n = static_cast<int>(tx.length());

	auto pa = int{ 0 };
	auto pb = int{ 0 };
	auto isWinBy2 = bool{ false };
	for (int i = 0; i < n; i += 2) {
		auto p = tx[i];
		auto q = tx[i + 1];

		if ('A' == p) {
			pa += q - '0';
		}
		else {
			pb += q - '0';
		}

		if (pa <= 10 && pb <= 10) {
			if (10 == pa && 10 == pb) {
				isWinBy2 = true;
			}

			continue;
		}

		if (!isWinBy2) {
			if (11 == pa) {
				cout << 'A';
				return 0;
			}
			else if (11 == pb) {
				cout << 'B';
				return 0;
			}
		}

		if (2 <= pa - pb) {
			cout << 'A';
			return 0;
		}
		else if (2 <= pb - pa) {
			cout << 'B';
			return 0;
		}
	}

	return 0;
}