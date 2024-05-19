#include <iostream>
#include "string"
#include <bitset>
#include "HelperFunctions.h"
#include "task13.h"
using namespace std;

void CyclicShiftToTheRight(int64_t& num, const int shift) {
	uint8_t bitset = 0x80; // 8 bit в 16-ричной системе, читается как 1000'000
	uint8_t mask_even = 0xAA; // 8 bit четные числа
	uint8_t mask_odd = 0x55; // 8 bit нечетные числа

	mask_even &= num; // в mask_even хранятся все четные цифры числа num
	mask_odd &= num; // в mask_odd хранятся только нечетные цифры

	for (int i = 0; i < shift; i++) {
		if ((mask_odd & 1) == 1) { // если крайнее число справа 1, то
			mask_odd >>= 1; // сдвигаем вправо (избавляемся от 1)
			mask_odd |= bitset; // и добавляем единицу в крайнее левое положение
		}
		else {
			mask_odd >>= 1; // если справа был ноль, то просто сдвигаем вправо
		}
	}

	num = mask_even | mask_odd; // теперь объединяем нечётные и чётные цифры
	Print(num);
}
void firstTask(int& argc, char* argv[]) {
	setlocale(LC_ALL, "RUS");
	if (argc != 4) {
		std::cerr << "Используйте: "s << argv[0] << " <"s << "десятичное_число"s << "> <"s << "количество_циклических_сдвигов_для_нечётных_битов" << ">\n"s;
		exit(1);
	}
	int64_t num = std::stoll(argv[1]);

	CyclicShiftToTheRight(num, std::stoi(argv[2]));
}