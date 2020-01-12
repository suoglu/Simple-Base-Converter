 // Yigit Suoglu
// Hexadecimal calculator functions: calculation done by converting to decimal

#include "common.hpp"

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

