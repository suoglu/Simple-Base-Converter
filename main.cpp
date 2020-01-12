  // Yigit Suoglu
 // This programs performs base convertions between binary, decimal and hexadecimal

#include "common.hpp"

int main()
{
    cout << "Welcome to the base converter\n";
help:
    cout << "\nConvertions:\n";
    cout << "1.   Hex -> Bin\n";
    cout << "2.   Hex -> Dec\n";
    cout << "3.   Hex -> Bin & Dec\n";
    cout << "4.   Dec -> Hex\n";
    cout << "5.   Dec -> Bin\n";
    cout << "6.   Dec -> Bin & Hex\n";
    cout << "7.   Bin -> Dec\n";
    cout << "8.   Bin -> Hex\n";
    cout << "9.   Bin -> Dec & Hex\n";
    cout << "10.  Hex calculator\n";
    cout << "0.   Exit\n";
    cout << "333. Help\n";
    short op;
    
    do {
        cout << "Enter conversation code: ";
        cin >> op;
        switch (op) {
            case 1:
                hexBinOp();
                break;
            case 2:
                hexDecOp();
                break;
            case 3:
                hexallOp();
                break;
            case 4:
                dechexOp();
                break;
            case 5:
                decbinOp();
                break;
            case 6:
                decallOp();
                break;
            case 7:
                bindecOp();
                break;
            case 8:
                binhexop();
                break;
            case 9:
                binallop();
                break;
            case 10:
                hexCalc();
                break;
            case 333:
                goto help;
        }
    } while (op != 0);

    cout << "\nGood bye :)\n\n";
    return 0;
}

void hexDecOp()
{
    string hex;
    
    if(hexIn(hex))
       return;
       
    cout << "Decimal: " << hexToDec(hex) << endl;
    
}

void hexBinOp()
{
    string hex;
    
    if(hexIn(hex))
        return;
    
    cout << "Binary: " << hexToBin(hex) << endl;
    
}

void hexallOp()
{
    string hex;
    
    if(hexIn(hex))
        return;

    
    cout << "Binary: " << hexToBin(hex) << endl;
    cout << "Decimal: " << hexToDec(hex) << endl;

}

void decbinOp()
{
    int dec;
    
    if(decIn(dec))
        return;
    
    cout << "Binary: " << hexToBin(decToHex(dec)) << endl;
}
void dechexOp()
{
    int dec;
    
    if(decIn(dec))
        return;
    
    cout << "Hexadecimal: " << decToHex(dec) << endl;
}
void decallOp()
{
    int dec;
    
    if(decIn(dec))
        return;
    
    cout << "Binary: " << hexToBin(decToHex(dec)) << endl;
    cout << "Hexadecimal: " << decToHex(dec) << endl;
}

void bindecOp()
{
    string bin;
    
    if(binIn(bin))
        return;
    
    cout << "Decimal: " << binToDec(bin) << endl;
}

void binhexop()
{
    string bin;
    
    if (binIn(bin))
        return;
    
    cout << "Hexadecimal: " << binToHex(bin) << endl;
}

void binallop()
{
    string bin;
    
    if (binIn(bin))
        return;
    
    long long dec = binToDec(bin);
    
    cout << "Decimal: " << dec << endl;
    cout << "Hexadecimal: " << decToHex(dec) << endl;
}
