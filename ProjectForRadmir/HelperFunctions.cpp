#include <iostream>
#include <string>
#include "sstream"
#include <bitset>
using namespace std;
using std::wcout;

bool isNumber(string& str) {
	for (char c : str) {
		if (c == ' ' || !isdigit(c)) return false;
	}
	return true;
}
bool stringIsDouble(const string& number) {
	stringstream convert(number);
	double myInt{};
	if (!(convert >> myInt))
		return false;
	return true;
}

bool isIntNum(const bool type, const std::string& string, const char limit_begin, const char limit_end) {
	// const bool type:
	// bool == true означает, что провер€емое число может быть отрицательным
	// bool == false означает, что провер€емое число не может быть отрицательным
	if (string.empty()) {
		return false;
	}

	if (type) {
		// ≈сли первый символ €вл€етс€ минусом, пропускаем его
		size_t start_index = (string[0] == '-') ? 1 : 0;

		for (size_t i = start_index; i < string.length(); ++i) {
			if (string[i] < limit_begin || string[i] > limit_end) {
				return false;
			}
		}
	}
	else {
		for (const char& c : string) {
			if (c < limit_begin || c > limit_end) {
				return false;
			}
		}
	}
	return true;
}

// ¬ыводит двоичную запись числа.
// ¬ыводит каждый бит числа, начина€ со старшего (левого) бита и заканчива€ младшим (правым).
void Print(const int64_t& num) {
	string dec;
	cout << "ƒвоичное представление результата:"s << endl;
	for (int i = 63; i >= 0; i--) {
		int bit = (num >> i) & 1;
		cout << bit;
		dec += to_string(bit);
	}
	cout << endl << "ƒес€тичное представление результата: "s << bitset<64>(dec).to_ullong();
}
