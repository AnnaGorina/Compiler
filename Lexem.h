#ifndef LEXEM_H
#define LEXEM_H
#include "map"
#include <cctype>
#include <locale>
#include <string>

enum class TypeOfLexem {Error = -1, ID, String, ServiceWord, ServiceSymbol, ConstValue, IDofColor, Separator};
enum class ClassOfSymbol {null, letter, numeral, ServiceSymbol, Separator, Equale, HexNumeral};

struct lex
{
    std::string lexem;
    int countStr;
};

class Lexem
{
    virtual void foo() = 0;

public:
    Lexem();

    ~Lexem();

    static ClassOfSymbol classOfSymbol (char ch);

    static TypeOfLexem checkLexem (std::string& word);
};

#endif // LEXEM_H
