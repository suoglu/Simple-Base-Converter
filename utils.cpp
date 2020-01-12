 // Yigit Suoglu
//Some utility functions for base converter

#include "common.hpp"

void toLower(string & in)//convert uppercase latters in in to lowercase
{
    for (int j = 0; j < in.size(); j++)
    {
        if(in[j] <= 'Z' & 'A' <= in[j])
        {
            in[j] = in[j] - ('Y' -  'y');
        }
    }
}

int stringToint(string str)//convert sting to int
{
    int res = 0;
    for(int i = 0; i< str.size();i++)
    {
        res *= 10;
        res = res + str[i] - '0';
    }
    return res;
}

bool binInCheck(string in)//return false if input is in binary format
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

bool decInCheck(string in)//return false if input is in decimal format
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

bool hexInCheck(string in) //return false if input is in hexadecimal format
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

bool hexIn(string & hex)
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

bool decIn(int & dec)
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

bool binIn(string & bin) //take binary input
{
    cout << "\nBinary number: ";
    cin  >> bin;
    if(binInCheck(bin))
    {
        cout << "Returning main menu...\n\n";
        return true;
    }
    return false;
}
