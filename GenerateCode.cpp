#include "generatecode.h"

GenerateCode::GenerateCode()
{

}

void GenerateCode::Generation(std::vector<lex>* lexems)
{
    std::ofstream fout;

    fout.open("/home/anna/LexAnal/Generate.txt");

    Lex = lexems;

    while (pozition < Lex->size()) {

        if (Lex->at(pozition).lexem == "<html") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "</html>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            break;
        }

        if (Lex->at(pozition).lexem == "<head") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "</head>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<body") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "</body>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<meta") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<title") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "</title>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<img") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<br") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<p") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<h1") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "</h1>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<h2") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "</h2>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<h3") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "</h3>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<link") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<base") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == "<basefont") {
            fout << "DECLARE: " << Lex->at(pozition).lexem << '>' << std::endl;
            pozition++;
        }

        if (Lex->at(pozition).lexem == ">") {
            pozition++;
        }

        if ((Lex->at(pozition).lexem[0] >= 'A' && Lex->at(pozition).lexem[0] <= 'Z') || (Lex->at(pozition).lexem[0] >= 'a' && Lex->at(pozition).lexem[0] <= 'z')) {
            pozition++;
            if (Lex->at(pozition).lexem == "=") {
                pozition++;
                if (Lex->at(pozition).lexem[0] == 39) {
                    pozition -= 2;
                    fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                    pozition += 2;
                    fout << Lex->at(pozition).lexem << std::endl;
                    pozition++;
                } else if ((Lex->at(pozition).lexem[0] >= 'A' && Lex->at(pozition).lexem[0] <= 'Z') || (Lex->at(pozition).lexem[0] >= 'a' && Lex->at(pozition).lexem[0] <= 'z')) {
                    pozition -= 2;
                    fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                    pozition += 2;
                    fout << Lex->at(pozition).lexem << std::endl;
                    pozition++;
                } else if (Lex->at(pozition).lexem[0] == '#') {
                    pozition -= 2;
                    fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                    pozition += 2;
                    fout << Lex->at(pozition).lexem << std::endl;
                    pozition++;
                } else if (isdigit(Lex->at(pozition).lexem[0])) {
                    pozition -= 2;
                    fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                    pozition += 2;
                    fout << Lex->at(pozition).lexem << std:: endl;
                    pozition++;
                }
            } else {
                pozition--;
                fout << "ATR: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
            }
        }

        if (Lex->at(pozition).lexem[0] == 39) {
            fout << "ATR: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
        }
    }
}

GenerateCode::~GenerateCode() = default;
