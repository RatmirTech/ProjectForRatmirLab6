#include <iostream>
#include "string"
#include <bitset>
#include "HelperFunctions.h"
#include "task13.h"
using namespace std;

void CyclicShiftToTheRight(int64_t& num, const int shift) {
	uint8_t bitset = 0x80; // 8 bit � 16-������ �������, �������� ��� 1000'000
	uint8_t mask_even = 0xAA; // 8 bit ������ �����
	uint8_t mask_odd = 0x55; // 8 bit �������� �����

	mask_even &= num; // � mask_even �������� ��� ������ ����� ����� num
	mask_odd &= num; // � mask_odd �������� ������ �������� �����

	for (int i = 0; i < shift; i++) {
		if ((mask_odd & 1) == 1) { // ���� ������� ����� ������ 1, ��
			mask_odd >>= 1; // �������� ������ (����������� �� 1)
			mask_odd |= bitset; // � ��������� ������� � ������� ����� ���������
		}
		else {
			mask_odd >>= 1; // ���� ������ ��� ����, �� ������ �������� ������
		}
	}

	num = mask_even | mask_odd; // ������ ���������� �������� � ������ �����
	Print(num);
}
void firstTask(int& argc, char* argv[]) {
	setlocale(LC_ALL, "RUS");
	if (argc != 4) {
		std::cerr << "�����������: "s << argv[0] << " <"s << "����������_�����"s << "> <"s << "����������_�����������_�������_���_��������_�����" << ">\n"s;
		exit(1);
	}
	int64_t num = std::stoll(argv[1]);

	CyclicShiftToTheRight(num, std::stoi(argv[2]));
}