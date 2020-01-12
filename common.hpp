 // Yigit Suoglu
// Common header file for all functions

#ifndef common_hpp
#define common_hpp

#include <iostream>
#include <string>

using namespace std;

//main.cpp
void hexBinOp();
void hexDecOp();
void hexallOp();
void decallOp();
void decbinOp();
void dechexOp();
void bindecOp();
void binhexop();
void binallop();

//utils.cpp
void toLower(string & in);
int stringToint(string str);

void getOperants(string & x, string & y);

bool intIn(int & in);
bool hexIn(string & hex);
bool decIn(int & dec);
bool binIn(string & bin);

//Input check funcions
bool binInCheck(string in);
bool decInCheck(string in);
bool hexInCheck(string in);

//base_converters.cpp
long long hexToDec(string hex);
string hexToBin(string hex);
string decToHex(long long dec);
long long binToDec(string bin);
string binToHex(string bin);

//hex_calc.cpp
void hexCalc();
void addHex();
void subHex();
void mltHex();
void divHex();



#endif /* common_hpp */
