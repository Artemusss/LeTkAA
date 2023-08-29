#include "default.h"

            /*   TODO
            1) Доделать логику с аргументами командной строки
            2) Правильно разбить на файлы
            3) Гитхаб!
            4) Makefile
            5) везде сделать проверки
            */

int main(int argc, char* argv[])
{
    struct coeffs coef = { NAN, NAN, NAN };

    int num_tests = 0;

    char prov[] = "All";

    if (atoi(argv[1]) != 0)
        num_tests = atoi(argv[1]);

    if (strcmp(argv[1], prov))
    {
        printf("POVEZLO\n");
        num_tests = NMAS;
    }


    InputCoefs(&coef);

    assert(!isnan(coef.a));
    assert(!isnan(coef.b));
    assert(!isnan(coef.c));

    struct roots Ans = { NAN, NAN, -5 };

    Ans = FullSolveQuad(coef.a, coef.b, coef.c);

    OutputAns(Ans);

    VerificationOfAnsvers(num_tests);

    return 1;
}
