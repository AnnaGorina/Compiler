#ifndef GENERATECODE_H
#define GENERATECODE_H
#include <lexem.h>
#include <sintax.h>
#include <vector>
#include <fstream>
#include <clocale>

class Lexem;
class Sintax;

class GenerateCode
{
    lex Lexems;
    int pozition = 0;
    int index = 0;

    std::vector<lex>* Lex;

public:
    GenerateCode();

    void Generation(std::vector<lex> *lexems);

    ~GenerateCode();
};

#endif // GENERATECODE_H
