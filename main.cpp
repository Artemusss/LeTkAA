#include "functions.h"

//{---------------------------------------------------------------------------------------------
//! Основная программа
//}---------------------------------------------------------------------------------------------

int main(int argc, const char* argv[])
{
    struct coeffs coef = { NAN, NAN, NAN };

    int num_tests = 0;

    char prov[] = "Tests";

    if (!strcmp(argv[0], prov))
    {
        num_tests = CountNumberOfTests(argv[1]);

        VerificationOfAnsvers(num_tests);
    }

    InputCoefs(&coef);

    assert(!isnan(coef.a));
    assert(!isnan(coef.b));
    assert(!isnan(coef.c));

    struct roots Ans = { NAN, NAN, -5 };

    Ans = FullSolveQuad(coef.a, coef.b, coef.c);

    OutputAns(Ans);


    return 1;
}
