  // Yigit Suoglu
 // This programs converts numbers in following bases:
// hex -> bin, hex -> dec


#include <iostream>
#include <string>

using namespace std;

bool binInCheck(string in);
bool decInCheck(string in);
bool hexInCheck(string in);
void toLower(string & in);
long long hexToDec(string hex);
string hexToBin(string hex);
void hexBinOp();
void hexDecOp();
void hexallOp();
void decallOp();
void decbinOp();
void dechexOp();
string decToHex(long long dec);
int stringToint(string str);
bool intIn(int & in);
void hexCalc();
void addHex();
void subHex();
void mltHex();
void divHex();
void getOperants(string & x, string & y);


int main()
{
    cout << "Welcome to the base converter\n";
    cout << "****************\n";
    cout << "NOTICE: This program is still under developlent all features are not available\n";
    cout << "****************\n";
help:
    cout << "\nConvertions:\n";
    cout << "1.   Hex -> Bin\n";
    cout << "2.   Hex -> Dec\n";
    cout << "3.   Hex -> Bin & Dec\n";
    cout << "4.   Dec -> Hex\n";
    cout << "5.   Dec -> Bin\n";
    cout << "6.   Dec -> Bin & Hex\n";
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
            case 10:
                hexCalc();
                break;
            case 333:
                goto help;
        }
    } while (op != 0);

    cout << "\nGood bye :)\n";
    return 0;
}

bool binInCheck(string in)
//return false if input is in binary format
{
    for(int j = 0; j < in.size(); j++)
    {
        if(in[j] != '0' & in[j] != '1')
        {
            cout << '\n' << in[j] << " inside " << in << " is not a binary number!\n";
            return true;
        }
    }
    return false;
}

bool decInCheck(string in)
//return false if input is in decimal format
{
    for(int j = 0; j < in.size(); j++)
    {
        if(in[j] < '0' | in[j] > '9')
        {
            cout << '\n' << in[j] << " inside " << in << " is not a decimal number!\n";
            return true;
        }
    }
    return false;

}

bool hexInCheck(string in)
//return false if input is in hexadecimal format
{
    for(int j = 0; j < in.size(); j++)
    {
        if((in[j] < '0' | in[j] > '9') & (in[j] < 'a' | in[j] > 'f') & (in[j] < 'A' | in[j] > 'F'))
        {
            cout << '\n' << in[j] << " inside " << in << " is not a hexadecimal number!\n";
            return true;
        }
    }
    return false;
    
}

void toLower(string & in)
//convert uppercase latters in in to lowercase
{
    for (int j = 0; j < in.size(); j++)
    {
        if(in[j] <= 'Z' & 'A' <= in[j])
        {
            in[j] = in[j] - ('Y' -  'y');
        }
    }
}

long long hexToDec(string hex)
//converts hexadecimal number to decimal
{
    long long dec = 0;
    toLower(hex);
    for(int j = 0; j < hex.size(); j++)
    {
        dec *= 16;
        if((hex[j] >= '0') & ('9' >= hex[j]))
        {
            dec = dec + hex[j] - '0';
        }
        else if((hex[j] >= 'a') & ('f' >= hex[j]))
        {
            dec = dec + hex[j] - 'a' + 10;
        }
    }
    return dec;
}

string singleHexToBin(char hex)
//converts hex digit to binary
{
    switch (hex) {
        case '0':
            return "0000";

        case '1':
            return "0001";

        case '2':
            return "0010";

        case '3':
            return "0011";
            
        case '4':
            return "0100";
            
        case '5':
            return "0101";
            
        case '6':
            return "0110";
            
        case '7':
            return "0111";
            
        case '8':
            return "1000";
            
        case '9':
            return "1001";
            
        case 'a':
            return "1010";
            
        case 'b':
            return "1011";
            
        case 'c':
            return "1100";
            
        case 'd':
            return "1101";
            
        case 'e':
            return "1110";
            
        case 'f':
            return "1111";
    }
    return "    ";
}

string hexToBin(string hex)
//converts hexadecimal number to binary
{
    toLower(hex);
    string bin = "";
    for(int j = 0; j < hex.size(); j++)
    {
        bin = bin + singleHexToBin(hex[j]);
    }
    
    return bin;
}

bool hexIn(string & hex)
//take hex input
{
    cout << "\nHexadecimal number: ";
    cin >> hex;
    if(hexInCheck(hex))
    {
        cout << "Returning main menu...\n\n";
        return true;
    }
    return false;
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

string decToHex(long long dec)
//convert decimal digit to hex
{
    string hex = "";
    do
    {
        int digit = dec % 16;
        
        if(digit < 10)
        {
            char dig = (digit + '0');
            hex = dig + hex;
        }
        else
        {
            char dig = (digit + 'A' - 10);
            hex = dig + hex;
        }
        dec = dec / 16;
    }while(dec != 0);
    
    return hex;
}

int stringToint(string str)
//convert sting to int
{
    int res = 0;
    for(int i = 0; i< str.size();i++)
    {
        res *= 10;
        res = res + str[i] - '0';
    }
    return res;
}

bool decIn(int & dec)
//take hex input
{
    string dec_s;
    cout << "\nDecimal number: ";
    cin >> dec_s;
    if(decInCheck(dec_s))
    {
        cout << "Returning main menu...\n\n";
        return true;
    }
    dec = stringToint(dec_s);
    return false;
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

void getOperants(string & x, string & y)
{
    while(true)
    {
        cout << "x = ";
        cin >> x;
        if(!hexInCheck(x))
        {
            break;
        }
    }
    
    while(true)
    {
        cout << "y = ";
        cin >> y;
        if(!hexInCheck(y))
        {
            break;
        }
    }
}

void addHex()
{
    cout << "Format: x + y\n";
    string x, y;
    getOperants(x, y);
    cout << x << " + " << y << " = ";
    long long result_d = hexToDec(x) + hexToDec(y);
    string result_h = decToHex(result_d);
    cout << result_h << endl << "Result = " << result_h << endl;
}
void subHex()
{
    cout << "Format: x - y\n";
    string x, y;
    getOperants(x, y);
    cout << x << " - " << y << " = ";
    long long result_d = hexToDec(x) - hexToDec(y);
    string result_h = "";
    if(0 > result_d)
    {
        result_h = "-";
        result_d *= -1;
    }
    result_h = result_h + decToHex(result_d);
    cout << result_h << endl << "Result = " << result_h << endl;
}
void mltHex()
{
    cout << "Format: x * y\n";
    string x, y;
    getOperants(x, y);
    cout << x << " * " << y << " = ";
    long long result_d = hexToDec(x) * hexToDec(y);
    string result_h = decToHex(result_d);
    cout << result_h << endl << "Result = " << result_h << endl;
}
void divHex()
{
    cout << "Notice: Only integer part of the result will be calculated\n";
    cout << "Format: x / y\n";
    string x, y;
    getOperants(x, y);
    cout << x << " / " << y << " = ";
    long long result_d = hexToDec(x) / hexToDec(y);
    string result_h = decToHex(result_d);
    cout << result_h << endl << "Result = " << result_h << endl;

}

void hexCalc()
{
    char op;
    cout << "\nWelcome to hexadecimal calculator\n";
    cout << "I can do following operations\n";
    cout << "+ or 1 ~ Addition\n";
    cout << "- or 2 ~ Subtraction\n";
    cout << "* or 3 ~ Multipication\n";
    cout << "/ or 4 ~ Division\n";
    cout << "   0   ~ Exit\n";
    cout << "Notice: Hexadecimal calculator only works with positive integers\n";
    
    do {

        cout << "Please enter operation: ";
        cin >> op;
        
        
        if(op == '+')
        {
            op = '1';
        }
        else if(op == '-')
        {
            op = '2';
        }
        else if(op == '*')
        {
            op = '3';
        }
        else if(op == '/')
        {
            op = '4';
        }


        switch (op) {
            case '0':
                return;
            case '1':
                addHex();
                break;
            case '2':
                subHex();
                break;
            case '3':
                mltHex();
                break;
            case '4':
                divHex();
                break;
            default:
                cout << "Operation not found!\n";
                break;
        }
    } while (true);
}

