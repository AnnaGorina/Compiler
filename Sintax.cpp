#include "sintax.h"

Sintax::Sintax()
{

}

GenerateCode generateCode;

void Sintax::S(std::vector<lex> *lexems)
{
    Lex = lexems;
    if (Lex->at(pozision).lexem == "<html") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            B();
            if (Lex->at(pozision).lexem == "</html>") {
                if (!Proverka()) {
                    exit(0);
                }
                std::cout << "Синтаксический анализ выполнен успешно!" << std::endl;

                generateCode.Generation(lexems);
                return;
            }
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else {
        std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '<html'" << std::endl;
        exit(0);
    }
}

void Sintax::A()
{
    if ((Lex->at(pozision).lexem[0] >= 'A' && Lex->at(pozision).lexem[0] <= 'Z') || (Lex->at(pozision).lexem[0] >= 'a' && Lex->at(pozision).lexem[0] <= 'z') || Lex->at(pozision).lexem[0] == 39) {
        J();
        A();
    } else {
        return;
    }
}

void Sintax::B()
{
    if (Lex->at(pozision).lexem == "<head" || Lex->at(pozision).lexem == "<body") {
        C();
        D();
    } else {
        std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось одно из зарезервированных слов '<head', '<body'" << std::endl;
        exit(0);
    }
}

void Sintax::C()
{
    if (Lex->at(pozision).lexem == "<head") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            E();
            if (Lex->at(pozision).lexem == "</head>") {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else {
                std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '</head>'" << std::endl;
                exit(0);
            }
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else {
        return;
    }
}

void Sintax::D()
{
    if (Lex->at(pozision).lexem == "<body") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            G();
            if (Lex->at(pozision).lexem == "</body>") {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else {
                std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '</body>'" << std::endl;
                exit(0);
            }
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else {
        std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '<body'" << std::endl;
        exit(0);
    }
}

void Sintax::E()
{
    if (Lex->at(pozision).lexem == "<title" || Lex->at(pozision).lexem == "<meta" || Lex->at(pozision).lexem == "<link" || Lex->at(pozision).lexem == "<base" || Lex->at(pozision).lexem == "<basefont") {
        F();
        E();
    } else {
        return;
    }

}

void Sintax::F()
{
    if (Lex->at(pozision).lexem == "<title") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            G();
            if (Lex->at(pozision).lexem == "</title>") {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else {
                std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '</title>'" << std::endl;
                exit(0);
            }
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else if (Lex->at(pozision).lexem == "<meta") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            return;
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else if (Lex->at(pozision).lexem == "<link") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            return;
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else if (Lex->at(pozision).lexem == "<base") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            return;
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else if (Lex->at(pozision).lexem == "<basefont") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            return;
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else {
        std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось одно из зарезервированных слов '<title', '<meta', '<link', '<base', '<basefont'" << std::endl;
        exit(0);
    }
}

void Sintax::G()
{
    if (Lex->at(pozision).lexem == "<img" || Lex->at(pozision).lexem == "<br" || Lex->at(pozision).lexem == "<p" || Lex->at(pozision).lexem == "<h1" || Lex->at(pozision).lexem == "<h2" || Lex->at(pozision).lexem == "<h3") {
        H();
        G();
    } else if (Lex->at(pozision).lexem[0] == 39) {
        I();
        G();
    } else {
        return;
    }
}

void Sintax::H()
{
    if (Lex->at(pozision).lexem == "<img" || Lex->at(pozision).lexem == "<br" || Lex->at(pozision).lexem == "<p") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            return;
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else if (Lex->at(pozision).lexem == "<h1") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            G();
            if (Lex->at(pozision).lexem == "</h1>") {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else {
                std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '</h1>'" << std::endl;
                exit(0);
            }
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else if (Lex->at(pozision).lexem == "<h2") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            G();
            if (Lex->at(pozision).lexem == "</h2>") {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else {
                std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '</h2>'" << std::endl;
                exit(0);
            }
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else if (Lex->at(pozision).lexem == "<h3") {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        A();
        if (Lex->at(pozision).lexem == ">") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            G();
            if (Lex->at(pozision).lexem == "</h3>") {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else {
                std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '</h3>'" << std::endl;
                exit(0);
            }
        } else {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался '>'" << std::endl;
            exit(0);
        }
    } else {
        std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось одно из зарезервированных слов '<img', '<br', '<p', '<h1', '<h2', '<h3'" << std::endl;
        exit(0);
    }
}

void Sintax::I()
{
    if (Lex->at(pozision).lexem[0] == 39) {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        return;
    } else {
        std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалась строка" << std::endl;
        exit(0);
    }
}

void Sintax::J()
{
    if ((Lex->at(pozision).lexem[0] >= 'A' && Lex->at(pozision).lexem[0] <= 'Z') || (Lex->at(pozision).lexem[0] >= 'a' && Lex->at(pozision).lexem[0] <= 'z')) {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        if (Lex->at(pozision).lexem == "=") {
            pozision++;
            if (!Proverka()) {
                exit(0);
            }
            if (Lex->at(pozision).lexem[0] == 39) {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
             } else if (Lex->at(pozision).lexem[0] == '#') {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else if ((Lex->at(pozision).lexem[0] >= 'A' && Lex->at(pozision).lexem[0] <= 'Z') || (Lex->at(pozision).lexem[0] >= 'a' && Lex->at(pozision).lexem[0] <= 'z')) {
                pozision++;
                if (!Proverka()) {
                    exit(0);
                }
                return;
            } else if (isdigit(Lex->at(pozision).lexem[0])) {
                for (int j = 1; j < Lex->at(pozision).lexem.size();) {
                    if (isdigit(Lex->at(pozision).lexem[j])) {
                        if (Lex->at(pozision).lexem.max_size() - 1) {
                            pozision++;
                            if (!Proverka()) {
                                exit(0);
                            }
                            return;
                        }
                    }
                }
                //for (int j = 1; j < Lex->at(pozision).lexem.size(); j++) {
                    //if (isdigit(Lex->at(pozision).lexem[j])) {
                      //  if (j + '0' == Lex->at(pozision).lexem[j - 1]) {
                           // pozision++;
                            //if (!Proverka()) {
                              //  exit(0);
                            //}
                            //return;
                        //}
                  //  }
                //}
            } else {
                std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался идентификатор, или идентификатор цвета, или строка, или константа" << std::endl;
                exit(0);
            }
        } else {
            return;
        }
    } else if (Lex->at(pozision).lexem[0] == 39) {
        pozision++;
        if (!Proverka()) {
            exit(0);
        }
        return;
    } else {
        std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидался идентификатор или строка" << std::endl;
        exit(0);
    }
}

bool Sintax::Proverka()
{
    if (pozision == Lex->size() - 1) {
        if (Lex->at(pozision).lexem != "</html>") {
            std::cout << "Ошибка в строке №" << Lex->at(pozision).countStr << ", ожидалось зарезервированное слово '</html>'" << std::endl;
            exit(0);
        }
    }
    return pozision < Lex->size();
}

Sintax::~Sintax() = default;
