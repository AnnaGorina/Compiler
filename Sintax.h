#ifndef SINTAX_H
#define SINTAX_H
#include <string>
#include <iostream>
#include "lexem.h"
#include <vector>
#include "generatecode.h"

class Lexem;
class GenerateCode;

class Sintax
{
    //Sintax();

    lex Lexems;
    int pozision = 0;

    std::vector<lex>* Lex;

public:
    Sintax();

    void S(std::vector<lex>* lexems);
    void A();
    void B();
    void C();
    void D();
    void E();
    void F();
    void G();
    void H();
    void I();
    void J();

    bool Proverka();

    ~Sintax();
};

#endif // SINTAX_H
