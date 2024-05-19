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
	// bool == true ��������, ��� ����������� ����� ����� ���� �������������
	// bool == false ��������, ��� ����������� ����� �� ����� ���� �������������
	if (string.empty()) {
		return false;
	}

	if (type) {
		// ���� ������ ������ �������� �������, ���������� ���
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

// ������� �������� ������ �����.
// ������� ������ ��� �����, ������� �� �������� (������) ���� � ���������� ������� (������).
void Print(const int64_t& num) {
	std::string binary;
	bool leading_zero = true; // ���� ��� �������� ������� �����

	std::cout << "�������� ������������� ����������:" << std::endl;

	for (int i = 63; i >= 0; --i) {
		int bit = (num >> i) & 1;
		if (bit == 1) {
			leading_zero = false;
		}
		if (!leading_zero) {
			std::cout << bit;
			binary += std::to_string(bit);
		}
	}

	if (binary.empty()) {
		binary = "0";
		std::cout << "0";
	}

	std::cout << std::endl << "���������� ������������� ����������: " << std::bitset<64>(binary).to_ullong() << std::endl;
}

//void Print(const int64_t& num) {
//	string dec;
//	cout << "�������� ������������� ����������:"s << endl;
//	for (int i = 63; i >= 0; i--) {
//		int bit = (num >> i) & 1;
//		cout << bit;
//		dec += to_string(bit);
//	}
//	cout << endl << "���������� ������������� ����������: "s << bitset<64>(dec).to_ullong();
//}