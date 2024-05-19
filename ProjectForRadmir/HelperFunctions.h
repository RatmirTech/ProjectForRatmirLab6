#pragma once

#include <iostream>
#include <bitset>
#include <string>
using namespace std;

bool isNumber(string& str);

bool stringIsDouble(const string& number);

bool isIntNum(const bool type, const std::string& string, const char limit_begin, const char limit_end);

void Print(const int64_t& num);

void CyclicShiftToTheRight(int64_t& num, const int shift);