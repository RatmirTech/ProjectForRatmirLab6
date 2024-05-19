#include <iostream>
#include <string>
#include "helperFunctions.h"
#include "task14.h"

using namespace std;
using std::wcout;

int firstOnePosition(unsigned long long number) {
	unsigned long long leftPtr = ~((~0ull) >> 1);
	while (leftPtr > 0) {
		unsigned long long bit1 = number & leftPtr;

		if (bit1 != 0) {
			return (log2(leftPtr));
		}
		leftPtr >>= 1;
	}
	return 0;
}

void secondTask(int& argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Используйте: " << argv[0] << " <десятичное_число> <имя_функции>" << endl;
		return;
	}
	string number = argv[2];
	string functionName = argv[1];

	if (functionName == "14") {
		int pos = firstOnePosition(stoull(number));
		if (stoull(number) == 0) {
			cout << "not include 1" << endl;
			return;
		}
		cout << "First one position is: " << pos << endl;
		return;
	}
	else
	{
		cout << "not correct input" << endl;
	}
}
