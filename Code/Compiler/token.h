#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class Token
{
    private:
        std::ifstream myFile;
        std::vector<std::string> syntaxLines;
        struct
        {
            const char LeftParth_Token = '(';
            const char RightParth_Token = ')';
            const char Comma_Token = ',';
            const char Equals_Sign_Token = '=';

            const char* Var_Token = "VAR";
            const char* OUT_Token = "OUT";
            const char* Add_String_Token = "add";
            const char* Divide_String_Token = "div";
            const char* Subtract_String_Token = "sub";
            const char* Multiply_String_Token = "mul";
            
            const char Plus_Token = '+';
            const char Subtract_Token = '-';
            const char Multiply_Token = '*';
            const char Division_Token = '/';

            const char LessThan_Token = '<';
            const char GreaterThan_Token = '>';
            const char And_Token = '&';
            const char Or_Token = '|';
            const char Not_Token = '!';
        } TokenList;

        void readFile();

    public:
        Token();
        void Print();
};

