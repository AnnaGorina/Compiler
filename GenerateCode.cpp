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
            fout << "DECLARE: " << Lex->at(pozition).lexem;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                fout << Lex->at(pozition).lexem << std::endl;
                pozition++;
            }
            index++;
        }

        if (Lex->at(pozition).lexem == "</html>") {
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            break;
        }

        if (Lex->at(pozition).lexem == "<head") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                fout << Lex->at(pozition).lexem << std::endl;
                pozition++;
                index++;
                if (Lex->at(pozition).lexem == "</head>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "</head>") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            if (Lex->at(pozition).lexem == "</html>") {
                index--;
            }
        }

        if (Lex->at(pozition).lexem == "<body") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                fout << Lex->at(pozition).lexem << std::endl;
                pozition++;
                index++;
                if (Lex->at(pozition).lexem == "</body>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "</body>") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            if (Lex->at(pozition).lexem == "</html>") {
                index--;
            }
        }

        if (Lex->at(pozition).lexem == "<meta") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            index++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</head>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "<title") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                fout << Lex->at(pozition).lexem << std::endl;
                pozition++;
                index++;
                if (Lex->at(pozition).lexem == "</title>") {
                    index--;
                }
            } else {
                fout << std::endl;
                index++;
            }
        }

        if (Lex->at(pozition).lexem == "</title>") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            if (Lex->at(pozition).lexem == "</head>") {
                index--;
            }
        }

        if (Lex->at(pozition).lexem == "<img") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            index++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</title>" || Lex->at(pozition).lexem == "</body>" || Lex->at(pozition).lexem == "</h1>" || Lex->at(pozition).lexem == "</h2>" || Lex->at(pozition).lexem == "</h3>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "<br") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            index++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</title>" || Lex->at(pozition).lexem == "</body>" || Lex->at(pozition).lexem == "</h1>" || Lex->at(pozition).lexem == "</h2>" || Lex->at(pozition).lexem == "</h3>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "<p") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem << std::endl;;
            pozition++;
            index++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</title>" || Lex->at(pozition).lexem == "</body>" || Lex->at(pozition).lexem == "</h1>" || Lex->at(pozition).lexem == "</h2>" || Lex->at(pozition).lexem == "</h3>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "<h1") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                fout << Lex->at(pozition).lexem << std::endl;
                pozition++;
                index++;
                if (Lex->at(pozition).lexem == "</h1>") {
                    index--;
                }
            } else {
                fout << std::endl;
                index++;
            }
        }

        if (Lex->at(pozition).lexem == "</h1>") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            if (Lex->at(pozition).lexem == "</title>" || Lex->at(pozition).lexem == "</body>" || Lex->at(pozition).lexem == "</h1>" || Lex->at(pozition).lexem == "</h2>" || Lex->at(pozition).lexem == "</h3>") {
                index--;
            }
        }

        if (Lex->at(pozition).lexem == "<h2") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                fout << Lex->at(pozition).lexem << std::endl;
                pozition++;
                index++;
                if (Lex->at(pozition).lexem == "</h2>") {
                    index--;
                }
            } else {
                fout << std::endl;
                index++;
            }
        }

        if (Lex->at(pozition).lexem == "</h2>") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            if (Lex->at(pozition).lexem == "</title>" || Lex->at(pozition).lexem == "</body>" || Lex->at(pozition).lexem == "</h1>" || Lex->at(pozition).lexem == "</h2>" || Lex->at(pozition).lexem == "</h3>") {
                index--;
            }
        }

        if (Lex->at(pozition).lexem == "<h3") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                fout << Lex->at(pozition).lexem << std::endl;
                pozition++;
                index++;
                if (Lex->at(pozition).lexem == "</h3>") {
                    index--;
                }
            } else {
                fout << std::endl;
                index++;
            }
        }

        if (Lex->at(pozition).lexem == "</h3>") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            if (Lex->at(pozition).lexem == "</title>" || Lex->at(pozition).lexem == "</body>" || Lex->at(pozition).lexem == "</h1>" || Lex->at(pozition).lexem == "</h2>" || Lex->at(pozition).lexem == "</h3>") {
                index--;
            }
        }

        if (Lex->at(pozition).lexem == "<link") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            index++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</head>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "<base") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem  << std::endl;
            pozition++;
            index++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</head>") {
                    index--;
                }
            }
        }

        if (Lex->at(pozition).lexem == "<basefont") {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "DECLARE: " << Lex->at(pozition).lexem  << std::endl;
            pozition++;
            index++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</head>") {
                    index--;
                }
            }
        }

        if ((Lex->at(pozition).lexem[0] >= 'A' && Lex->at(pozition).lexem[0] <= 'Z') || (Lex->at(pozition).lexem[0] >= 'a' && Lex->at(pozition).lexem[0] <= 'z')) {
            if (Lex->at(pozition - 1).lexem == "<link" || Lex->at(pozition - 1).lexem == "<meta" || Lex->at(pozition - 1).lexem == "<title" || Lex->at(pozition - 1).lexem == "<h1" || Lex->at(pozition - 1).lexem == "<h2" || Lex->at(pozition - 1).lexem == "<h3" || Lex->at(pozition - 1).lexem == "<base" || Lex->at(pozition - 1).lexem == "<basefont" || Lex->at(pozition - 1).lexem == "<p" || Lex->at(pozition - 1).lexem == "<br" || Lex->at(pozition - 1).lexem == "<img") {
                pozition++;
                if (Lex->at(pozition).lexem == "=") {
                    pozition++;
                    if (Lex->at(pozition).lexem[0] == 39) {
                        for (int i = 0; i < index; i++) {
                            fout << "\t";
                        }
                        pozition -= 2;
                        fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                        pozition += 2;
                        fout << Lex->at(pozition).lexem << std::endl;
                        pozition++;
                        if (Lex->at(pozition).lexem == ">") {
                            index--;
                            for (int i = 0; i < index; i++) {
                                fout << "\t";
                            }
                            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                            pozition++;
                            if (Lex->at(pozition).lexem == "</head>" || Lex->at(pozition).lexem == "</body>") {
                                index--;
                            }
                            if (Lex->at(pozition).lexem == "<img" || Lex->at(pozition).lexem == "<br" || Lex->at(pozition).lexem == "<p" || Lex->at(pozition).lexem == "<h1" || Lex->at(pozition).lexem == "<h2" || Lex->at(pozition).lexem == "<h3") {
                                index++;
                            }
                        }
                    } else if ((Lex->at(pozition).lexem[0] >= 'A' && Lex->at(pozition).lexem[0] <= 'Z') || (Lex->at(pozition).lexem[0] >= 'a' && Lex->at(pozition).lexem[0] <= 'z')) {
                        for (int i = 0; i < index; i++) {
                            fout << "\t";
                        }
                        pozition -= 2;
                        fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                        pozition += 2;
                        fout << Lex->at(pozition).lexem << std::endl;
                        pozition++;
                        if (Lex->at(pozition).lexem == ">") {
                            index--;
                            for (int i = 0; i < index; i++) {
                                fout << "\t";
                            }
                            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                            pozition++;
                            if (Lex->at(pozition).lexem == "</head>" || Lex->at(pozition).lexem == "</body>") {
                                index--;
                            }
                        }
                    } else if (Lex->at(pozition).lexem[0] == '#') {
                        for (int i = 0; i < index; i++) {
                            fout << "\t";
                        }
                        pozition -= 2;
                        fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                        pozition += 2;
                        fout << Lex->at(pozition).lexem << std::endl;
                        pozition++;
                        if (Lex->at(pozition).lexem == ">") {
                            index--;
                            for (int i = 0; i < index; i++) {
                                fout << "\t";
                            }
                            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                            pozition++;
                            if (Lex->at(pozition).lexem == "</head>" || Lex->at(pozition).lexem == "</body>") {
                                index--;
                            }
                        }
                    } else if (isdigit(Lex->at(pozition).lexem[0])) {
                        for (int i = 0; i < index; i++) {
                            fout << "\t";
                        }
                        pozition -= 2;
                        fout << "SET_ATR: " << Lex->at(pozition).lexem << ", ";
                        pozition += 2;
                        fout << Lex->at(pozition).lexem << std:: endl;
                        pozition++;
                        if (Lex->at(pozition).lexem == ">") {
                            index--;
                            for (int i = 0; i < index; i++) {
                                fout << "\t";
                            }
                            fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                            pozition++;
                            if (Lex->at(pozition).lexem == "</head>" || Lex->at(pozition).lexem == "</body>") {
                                index--;
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < index; i++) {
                        fout << "\t";
                    }
                    pozition--;
                    fout << "ATR: " << Lex->at(pozition).lexem << std::endl;
                    pozition++;
                    if (Lex->at(pozition).lexem == ">") {
                        index--;
                        for (int i = 0; i < index; i++) {
                            fout << "\t";
                        }
                        fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                        pozition++;
                        if (Lex->at(pozition).lexem == "</head>" || Lex->at(pozition).lexem == "</body>") {
                            index--;
                        }
                    }
                }
            }
        }

        if (Lex->at(pozition).lexem[0] == 39) {
            for (int i = 0; i < index; i++) {
                fout << "\t";
            }
            fout << "ATR: " << Lex->at(pozition).lexem << std::endl;
            pozition++;
            if (Lex->at(pozition).lexem == ">") {
                index--;
                for (int i = 0; i < index; i++) {
                    fout << "\t";
                }
                fout << "END_DECLARE: " << Lex->at(pozition).lexem << std::endl;
                pozition++;
                if (Lex->at(pozition).lexem == "</head>" || Lex->at(pozition).lexem == "</body>") {
                    index--;
                }
            }
            if (Lex->at(pozition).lexem == "</title>" || Lex->at(pozition).lexem == "</h1>" || Lex->at(pozition).lexem == "</h2>" || Lex->at(pozition).lexem == "</h3>") {
                index--;
            }
        }
    }
}

GenerateCode::~GenerateCode() = default;
