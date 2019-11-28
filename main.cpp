#include <QCoreApplication>
#include <fstream>
#include <string>
#include <vector>
#include "lexem.h"
#include <iostream>
#include <clocale>
#include "sintax.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream fin;
    std::ofstream fout;

    std::string nameOfFile;
    std::cin >> nameOfFile;

    int countStr = 1;

    //struct lex;

    lex Lexems;

    std::vector<lex> Lex;
    Sintax sintax;
    
    //std::vector<std::vector<std::string>> Lex();
    

    fin.open("/home/anna/LexAnal/" + nameOfFile);

    std::string s;

    fout.open("/home/anna/LexAnal/Output.txt");

    int j = 0;
    while (!fin.eof())
    {
        getline(fin, s);

        std::string buffer = "";
        bool isTeg = false;
        bool isHexValue = false;
        ClassOfSymbol symbolInWord = ClassOfSymbol::null;

        int countNumeralColor = 0;

        std::vector<std::string> Vec();

        for (uint32_t i = 0; i < s.length(); i++)
        {
            switch (Lexem::classOfSymbol(s[i]))
            {
            case ClassOfSymbol::letter:

                if (buffer[0] == '#')
                {
                    buffer += s[i];

                    if (++countNumeralColor == 6)
                    {
                        fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                        Lexems.lexem = buffer;
                        Lexems.countStr = countStr;
                        Lex.push_back(Lexems);

                        countNumeralColor = 0;
                        buffer.clear();
                    }

                    break;
                }

                symbolInWord = ClassOfSymbol::letter;
                buffer += s[i];
                break;

            case ClassOfSymbol::numeral:

                if (buffer[0] == '#')
                {
                    buffer += s[i];

                    if(countNumeralColor++ == 6)
                    {
                        fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                        Lexems.lexem = buffer;
                        Lexems.countStr = countStr;
                        Lex.push_back(Lexems);

                        countNumeralColor = 0;
                        buffer.clear();
                    }
                    break;
                }

                symbolInWord = ClassOfSymbol::numeral;
                buffer += s[i];
                break;

            case ClassOfSymbol::Equale:

                symbolInWord = ClassOfSymbol::Equale;

                fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                Lexems.lexem = buffer;
                Lexems.countStr = countStr;
                Lex.push_back(Lexems);
                buffer.clear();

                buffer += s[i];

                fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                Lexems.lexem = buffer;
                Lexems.countStr = countStr;
                Lex.push_back(Lexems);
                buffer.clear();
                break;

            case ClassOfSymbol::Separator:

                symbolInWord = ClassOfSymbol::Separator;

                if (buffer[0] == '<' && s[i] == ' ')
                {
                    fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                    Lexems.lexem = buffer;
                    Lexems.countStr = countStr;
                    Lex.push_back(Lexems);
                    buffer.clear();
                }
                if (buffer != "")
                {
                    if(s[i] == ' ' && buffer[buffer.size() - 1] == 39)
                    {
                        fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                        Lexems.lexem = buffer;
                        Lexems.countStr = countStr;
                        Lex.push_back(Lexems);
                        buffer.clear();
                    }
                    else if (s[i] == ' ' && buffer[0] != 39) {
                        break;
                    }


                }
                break;

            case ClassOfSymbol::ServiceSymbol:

                if (buffer.empty())
                {
                    if (s[i] == '<')
                    {
                        buffer += s[i];
                        isTeg = true;
                    }
                    else if (s[i] == 39)
                    {
                        buffer += s[i];
                    }
                    else if (s[i] == '#')
                    {
                        buffer += s[i];
                        isHexValue = !isHexValue;
                        symbolInWord = ClassOfSymbol::ServiceSymbol;

                        if (countNumeralColor == 6)
                        {
                            fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                            Lexems.lexem = buffer;
                            Lexems.countStr = countStr;
                            Lex.push_back(Lexems);
                            buffer.clear();
                        }
                        break;
                    }
                    symbolInWord = ClassOfSymbol::ServiceSymbol;
                    break;
                }
                else
                {
                    if (s[i] == '<')
                    {
                        fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                        Lexems.lexem = buffer;
                        Lexems.countStr = countStr;
                        Lex.push_back(Lexems);
                        buffer.clear();
                    }
                    else if (s[i] == '>')
                    {
                        isTeg = false;

                        if (buffer[1] == '/')
                        {
                            buffer += s[i];
                            fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                            Lexems.lexem = buffer;
                            Lexems.countStr = countStr;
                            Lex.push_back(Lexems);

                            break;
                        }

                        fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                        Lexems.lexem = buffer;
                        Lexems.countStr = countStr;
                        Lex.push_back(Lexems);
                        buffer.clear();
                        buffer += s[i];

                        fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                        Lexems.lexem = buffer;
                        Lexems.countStr = countStr;
                        Lex.push_back(Lexems);
                        buffer.clear();
                        break;
                    }
                    else if (buffer[0] == 39)
                    {
                        buffer += s[i];

                        if (i == s.length() - 1)
                        {
                            if (s[i] == 39)
                            {
                                fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                                Lexems.lexem = buffer;
                                Lexems.countStr = countStr;
                                Lex.push_back(Lexems);
                                buffer.clear();
                            }
                        }
                        break;
                    }
                    else if (symbolInWord == ClassOfSymbol::numeral)
                    {
                        fout << buffer << " = " << static_cast<int>(Lexem::checkLexem(buffer)) << std::endl;
                        Lexems.lexem = buffer;
                        Lexems.countStr = countStr;
                        Lex.push_back(Lexems);
                        buffer = "";
                        buffer += s[i];
                        symbolInWord = ClassOfSymbol::ServiceSymbol;
                        break;
                    }

                    isTeg = true;
                    symbolInWord = ClassOfSymbol::ServiceSymbol;
                    buffer += s[i];

                    break;
                }

            default:
                break;
            }
        }
        countStr++;
    }
    
    sintax.S(&Lex);

    return 0;
}
