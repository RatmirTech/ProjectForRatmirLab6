#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <limits>
#include <iomanip>

#include "tasks.h"
using namespace std;
int main(int argc, char* argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "");
	doTaskDependOnArgsOrPrintError(argc, argv);
	return 0;
}
