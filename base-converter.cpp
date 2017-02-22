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

int main()
{
    cout << "Welcome to the base converter\n";
    cout << "****************\n";
    cout << "NOTICE: This program is still under developlent all features are not available\n";
    cout << "****************\n\n";
    cout << "Convertions:\n";
    cout << "1. Hex -> Bin\n";
    cout << "2. Hex -> Dec\n";
    cout << "3. Hex -> Bin & Dec\n";
    cout << "0. Exit\n";
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
        }
    } while (op != 0);
    
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
//return false if input is in decimal format
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
    toLower(hex);
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









