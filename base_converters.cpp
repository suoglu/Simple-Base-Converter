 // Yigit Suoglu
// Funcions for base convertions

#include "common.hpp"

long long hexToDec(string hex)//converts hexadecimal number to decimal
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

string singleHexToBin(char hex)//converts hex digit to binary
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

string hexToBin(string hex)//converts hexadecimal number to binary
{
    toLower(hex);
    string bin = "";
    for(int j = 0; j < hex.size(); j++)
    {
        bin = bin + singleHexToBin(hex[j]);
    }
    
    return bin;
}

string decToHex(long long dec)//convert decimal digit to hex
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

long long binToDec(string bin)
{
    long long dec  = 0;
    
    for (long i = 0; i < bin.length(); i++)
    {
        dec *= 2;
        
        if(bin[i] == '1')
            dec++;
    }
    return dec;
}

string binToHex(string bin)
{
    /*string hex = "";
    
    while ((bin.length() % 4) != 0)
    {
        bin = "0" + bin;
    }
    
    return hex;*/
    
    return decToHex(binToDec(bin));
}
