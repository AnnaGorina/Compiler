#include "lexem.h"

std::map<std::string, TypeOfLexem> lexems =
{
    {"<html", TypeOfLexem::ServiceWord}, {"</html>", TypeOfLexem::ServiceWord},
    {"<head", TypeOfLexem::ServiceWord}, {"</head>", TypeOfLexem::ServiceWord},
    {"<title", TypeOfLexem::ServiceWord}, {"</title>", TypeOfLexem::ServiceWord},
    {"<body", TypeOfLexem::ServiceWord}, {"</body>", TypeOfLexem::ServiceWord},
    {"<h1", TypeOfLexem::ServiceWord}, {"</h1>", TypeOfLexem::ServiceWord},
    {"<h2", TypeOfLexem::ServiceWord}, {"</h2>", TypeOfLexem::ServiceWord},
    {"<h3", TypeOfLexem::ServiceWord}, {"</h3>", TypeOfLexem::ServiceWord},
    {"<meta", TypeOfLexem::ServiceWord}, {"<link", TypeOfLexem::ServiceWord},
    {"<base", TypeOfLexem::ServiceWord}, {"<basefont", TypeOfLexem::ServiceWord},
    {"<br", TypeOfLexem::ServiceWord}, {"<p", TypeOfLexem::ServiceWord},
    {">", TypeOfLexem::ServiceSymbol}, {"=", TypeOfLexem::ServiceSymbol},
    {"<img", TypeOfLexem::ServiceWord}, {" ", TypeOfLexem::Separator},
    {"\n", TypeOfLexem::Separator}, {"\t", TypeOfLexem::Separator},
    {"#", TypeOfLexem::ServiceSymbol}, {"'", TypeOfLexem::ServiceSymbol}
};

Lexem::Lexem()
{

}

TypeOfLexem Lexem::checkLexem(std::string& word)
{

    if(lexems.find(word) == lexems.end())
    {
        //char ch;
        if (word[0] == 39) {
            for (uint32_t i = 1; i < word.size(); i++) {
                //if (i == word.size() - 1) {
                    if (word[i] == 39) {
                        return TypeOfLexem::String;
                    }
                //}
            }
        }
        else if (isdigit(word[0])) {
                 for (uint32_t i = 0; i < word.size(); i++) {
                         if(!isdigit(word[i])) {
                             return TypeOfLexem::Error;
                          }
                    }
                 return TypeOfLexem::ConstValue;
    }
        else if ((word[0] >='A' && word[0] <= 'Z') || (word[0] >='a' && word[0] <='z')) {
            for (uint32_t i = 0; i < word.size(); i++) {
                    if (((word[i] < 'A' && word[i] > 'Z') || (word[i] < 'a' && word[i] > 'z')) && !isdigit(word[i])) {
                            return TypeOfLexem::Error;
                    }
            }
            return TypeOfLexem::ID;
        }

        else if (word == "=") {
            return TypeOfLexem::ServiceSymbol;
        }


        else if (word[0] == '#') {

            for (uint32_t i = 1; i < word.size(); i++) {
                if ((word[i] < 'A' && word[i] > 'F') || (word[i] < 'a' && word[i] > 'f') && !isdigit(word[i])) {
                    return TypeOfLexem::Error;
                }
            }
            return TypeOfLexem::IDofColor;
        }
        else {
            return TypeOfLexem::Error;
        }

    }
    else
    {
        return lexems[word];
    }
}

ClassOfSymbol Lexem::classOfSymbol(char ch)
{
    if (ch == ' ' || ch == '\n' || ch == '\t') {
        return ClassOfSymbol::Separator;
    }

    else if (ch == '>' || ch == '<' || ch == '/' || ch == '#' || ch == 39) {
             return ClassOfSymbol::ServiceSymbol;
    }

    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= 'А' && ch <= 'я')) {
        return ClassOfSymbol::letter;
    }

    else if (/*ch > 47 && ch < 58*/ isdigit(ch)) {
        return ClassOfSymbol::numeral;
    }

    else if (ch == '=') {
        return ClassOfSymbol::Equale;
    }

}

Lexem::~Lexem() = default;
