// Возвращаем true, если разница между a и b в пределах процента эпсилона
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

bool isFloat(const string& str) {
	//cout << "checking number: " << str << endl;
	bool e = false;
	bool dot = false;
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			continue;
		}
		else {
			if (i == 0 && (str[i] == '-' || str[i] == '+')) {
				continue;
			}
			else if (str[i] == ',' && !dot && !e && !(i == 1 && (str[i - 1] == '-' || str[i - 1] == '+'))) {
				dot = true;
				continue;
			}
			else if (str[i] == 'e' && !e) {
				e = true;
				continue;
			}
			else if (i > 0 && str[i - 1] == 'e' && (str[i] == '-' || str[i] == '+')) {
				continue;

			}
			else {
				return false;
			}
		}
	}

	//cout << stof(str) << endl;

	return true;
}

bool approximatelyEqual(float a, float b, float epsilon)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// Возвращаем true, если разница между a и b меньше absEpsilon
// или в пределах relEpsilon
bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon) {

	float diff = fabs(a - b);
	if (diff <= absEpsilon)
		return true;
	// В противном случае, возвращаемся к алгоритму Кнута
	return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

bool argsAreCorrect(int countArgs, char* args[], int countMeaningfulArgs) {
	if (countArgs < countMeaningfulArgs) return false;

	for (int i = 2; i < countMeaningfulArgs; i++) {
		if (!isFloat(args[i]))
			return false;
	}

	return true;
}

void doApproximatelyEqualAbsRel(int countArgs, char* args[]) {
	if (!argsAreCorrect(countArgs, args, 6)) {
		cout << "Некорректные аргументы";
	}
	else {
		std::cout << std::fixed << std::setprecision(15);
		cout << "Результат сравнения чисел " << stof(args[2]) << " и " << stof(args[3]) << " с absEpsilon " << stof(args[4]) << " и relEpsilon " << stof(args[5]) << ": ";
		cout << (approximatelyEqualAbsRel(stof(args[2]), stof(args[3]), stof(args[4]), stof(args[5])) ? "равны" : "не равны") << endl;
	}
}

void doApproximatelyEqual(int countArgs, char* args[]) {
	if (countArgs == 6) {
		doApproximatelyEqualAbsRel(countArgs, args);
	}
	else if (!argsAreCorrect(countArgs, args, 5)) {
		cout << "Некорректные аргументы";
	}
	else {
		std::cout << std::fixed << std::setprecision(15);
		cout << "Результат сравнения чисел " << stof(args[2]) << " и " << stof(args[3]) << " с точностью " << stof(args[4]) << ": ";
		cout << (approximatelyEqual(stof(args[2]), stof(args[3]), stof(args[4])) ? "равны" : "не равны") << endl;
	}
}