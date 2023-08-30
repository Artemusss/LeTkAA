#include "functions.h"

void InputCoefs(struct coeffs* coef)  // TODO assert NULL ptr
{
    assert(coef);

    int flag = -1;

    printf("# Enter a, b, c: ");

    flag = scanf("%lg %lg %lg", &(coef->a), &(coef->b), &(coef->c));
    while (flag != 3)
    {
        printf("ERROR, please try again\n");
        while (getchar() != '\n') {}
        flag = scanf("%lg %lg %lg", &(coef->a), &(coef->b), &(coef->c));
    }

}

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);

    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    if (ToCompare(a, 0) == 1)
    {
        if (ToCompare(b, 0) == 1)
        {
            if (ToCompare(c, 0) == 1)
                return -1;
            else
                return 0;
        }
        else
        {
            return SolveLin(b, c, x1);
        }
    }
    else
    {
        double discrim = NAN;
        discrim = b * b - 4 * a * c;

        if (discrim > 0)
        {
            *x1 = (-b + sqrt(discrim)) / (2 * a);
            *x2 = (-b - sqrt(discrim)) / (2 * a);

            return 2;
        }
    else if (ToCompare(discrim, 0))
        {
            *x1 = -b / (2 * a);
            return 1;
        }
    else
            return 0;
        }
}

int ToCompare (double a, double b)
{
    assert(!isnan(a));
    assert(!isnan(b));

    return fabs(a - b) < EPSIL;
}

int SolveLin (double b, double c, double* x1)
{
     assert(!isnan(b));
     assert(!isnan(c));

    *x1 = -c / b;

    assert(!isnan(*x1));

    if (ToCompare(*x1, 0))
        *x1 = 0;
    return 1;
}

struct roots FullSolveQuad(double a, double b, double c)
{
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    printf("# Square equation solver\n"
		"# (c) AT, 2023\n\n");

    struct roots Ans = {NAN, NAN, -5};

	Ans.num_roots = SolveSquare(a, b, c, &Ans.x1, &Ans.x2);

    return Ans;
}

void OutputAns(struct roots Ans)
{
    assert(!isnan(Ans.num_roots));
    assert(Ans.num_roots > -2);
    assert(Ans.num_roots < 3);

	switch (Ans.num_roots)
		{
		case NOROOTS:  printf("No roots\n");
			break;

		case ONEROOT:  printf("x = %lg\n", Ans.x1);
			break;

		case TWOROOTS: printf("x1 = %lg x2 = %lg\n", Ans.x1, Ans.x2);
			break;

		case INFROOTS: printf("infinite roots\n");
			break;

        default:       printf("EROR\n");
            break;
		}
}

int VerificationOfAnsvers(int num_tests)
{
    assert(!isnan(num_tests));
    assert(num_tests <= NMAS);
    assert(num_tests >= 0);

    struct verif mas[NMAS] = {{1, 0,  1, NAN, NAN,  0},       //A, B, C, X1, X2, nRoots//
                              {1, 0, -1,   1,  -1,  2},
                              {0, 0,  0, NAN, NAN, -1}};
    if (num_tests > 0)
    {
        for (int i = 0; i < (num_tests); i++)
        {
            double x1 = NAN, x2 = NAN;

            int nRootsAns = SolveSquare(mas[i].a, mas[i].b, mas[i].c, &x1, &x2);

            if (nRootsAns == mas[i].n_Roots && nRootsAns < ONEROOT)
            {
                if (!isnan(x1) || !isnan(x2))
                {
                    printf(ANSI_COLOR_RED   "ERROR of roots\n"
                                            "Number of test %i\n"
                                            "Expected: NAN NAN\n"
                                            "Get: %lg %lg\n", i, x1, x2);
                }
                else
                    printf(ANSI_COLOR_GREEN "Test number: %i successful\n", i);
            }

            else if (nRootsAns == mas[i].n_Roots && nRootsAns == ONEROOT)
            {
                if (!ToCompare(mas[i].x1, x1) || !isnan(x2))
                {
                    printf(ANSI_COLOR_RED   "ERROR of roots\n"
                                            "Number of test: %i\n"
                                            "Expected: %lg NAN\n"
                                            "Get: %lg %lg\n", i, mas[i].x1, x1, x2);
                }
                else
                    printf(ANSI_COLOR_GREEN "Test number: %i successful\n", i);
            }

            else if (nRootsAns == mas[i].n_Roots && nRootsAns == TWOROOTS)
            {
                if (!ToCompare(mas[i].x1, x1) || !ToCompare(mas[i].x2, x2))
                {
                    printf(ANSI_COLOR_RED   "ERROR of roots\n"
                                            "Number of test: %i\n"
                                            "Expected: %lg %lg\n"
                }                           "Get: %lg %lg\n", i, mas[i].x1, mas[i].x2, x1, x2);
                else
                    printf(ANSI_COLOR_GREEN "Test number: %i successful"  "\n", i);

            }
            else
            {
                    printf(ANSI_COLOR_RED  "ERROR of number roots\n"
                                           "Number of test %i\n"
                                           "Expected: %i\n"
                                           "Get: %i\n", i, mas[i].n_Roots, nRootsAns);
            }
        }
    }
    return 1;
}

int CountNumberOfTests (const char* num)
{
    char prov[] = "All";

    if (atoi(argv[1]) != 0)
        return atoi(argv[1]);

    else if (!strcmp(argv[1], prov))
    {
        printf("POWEZLO\n");
        return NMAS;
    }
    else
        return 0;
}
