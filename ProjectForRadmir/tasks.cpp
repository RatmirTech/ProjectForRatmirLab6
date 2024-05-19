#include <iostream>
#include <cmath>
#include <iostream>
#include <string>

#include "approximatelyEqual.h"
#include "task13.h"
#include "task14.h"

using namespace std;

void doTaskDependOnArgsOrPrintError(int countArgs, char* args[]) {//32 17
	if (countArgs < 2) {
		cout << "Отсутствует имя функции";
		return;
	}

	string function(args[1]);

	cout << "функция " << function << endl << endl;

	if (function == "approximatelyEqual") {
		doApproximatelyEqual(countArgs, args);
	}
	else if (function == "13") {
		firstTask(countArgs, args);
	}
	else if (function == "14") {
		secondTask(countArgs, args);
	}
	else {
		cout << "Введено имя несуществующей функции" << endl;
		return;
	}
}