#include <malloc.h>

#include "VectorOperations.h"
#include "AbstractVector.h"

#define SIZE_INT 5
#define SIZE_DOUBLE 3
#define SIZE_DOUBLE_COMPLEX 2

void TestAssign()
{
    Vector* vInt = VectorCtor();
    Vector* vDouble = VectorCtor();
    Vector* vDoubleComplex = VectorCtor();

    int sampleInt[SIZE_INT] = {1,2,3,4,5};
    double sampleDouble[SIZE_DOUBLE] = {5.378, 2.0926, 9.03552};
    double complex sampleDoubleComplex[SIZE_DOUBLE_COMPLEX] = {678.9 + 2 * I, 89.678 + 0.34 * I};

    printf("\n\n---ASSIGN TEST---\n\n");

    vInt->opers->assign(vInt, sampleInt, SIZE_INT, &AssignInt);

    printf("Testing int: \n\n");

    for (int i=0; i<SIZE_INT; ++i)
        printf("%d\n", ((int*)vInt->coords)[i]);

    vDouble->opers->assign(vDouble, sampleDouble, SIZE_DOUBLE, &AssignDouble);

    printf("\nTesting double: \n\n");

    for (int i=0; i<SIZE_DOUBLE; ++i)
        printf("%g\n", ((double*)vDouble->coords)[i]);

    vDoubleComplex->opers->assign(vDoubleComplex, sampleDoubleComplex, SIZE_DOUBLE_COMPLEX, &AssignDoubleComplex);

    printf("\nTesting double complex: \n\n");

    for (int i=0; i<SIZE_DOUBLE_COMPLEX; ++i)
        printf("Real part: %g\t Imaginary part: %gi\n", creal(((double complex*)vDoubleComplex->coords)[i]), cimag(((double complex*)vDoubleComplex->coords)[i]));
}

void TestSum()
{
    Vector* vInt1 = VectorCtor();
    Vector* vInt2 = VectorCtor();

    Vector* vDouble1 = VectorCtor();
    Vector* vDouble2 = VectorCtor();

    Vector* vDoubleComplex1 = VectorCtor();
    Vector* vDoubleComplex2 = VectorCtor();

    int sampleInt1[SIZE_INT] = {1,2,3,4,5};
    int sampleInt2[SIZE_INT] = {12, 678, 78, 2305, 9};

    double sampleDouble1[SIZE_DOUBLE] = {5.378, 2.0926, 9.03552};
    double sampleDouble2[SIZE_DOUBLE] = {6.667, 30.038, 567.02};

    double complex sampleDoubleComplex1[SIZE_DOUBLE_COMPLEX] = {65 + 2 * I, 89.678 + 0.34 * I};
    double complex sampleDoubleComplex2[SIZE_DOUBLE_COMPLEX] = {78 + 5 * I, 2.58259 + 9.56 * I};

    printf("\n\n---SUM TEST---\n\n");

    // ASSIGN SECTION

    vInt1->opers->assign(vInt1, sampleInt1, SIZE_INT, &AssignInt);
    vInt2->opers->assign(vInt2, sampleInt2, SIZE_INT, &AssignInt);

    vDouble1->opers->assign(vDouble1, sampleDouble1, SIZE_DOUBLE, &AssignDouble);
    vDouble2->opers->assign(vDouble2, sampleDouble2, SIZE_DOUBLE, &AssignDouble);

    vDoubleComplex1->opers->assign(vDoubleComplex1, sampleDoubleComplex1, SIZE_DOUBLE_COMPLEX, &AssignDoubleComplex);
    vDoubleComplex2->opers->assign(vDoubleComplex2, sampleDoubleComplex2, SIZE_DOUBLE_COMPLEX, &AssignDoubleComplex);

    // --------------

    Vector* vSum = VectorCtor();

    vSum = vSum->opers->sum(vInt1, vInt2, &SumInt);

    printf("Testing int: \n\n");

    for (int i=0; i<SIZE_INT; ++i)
    {
        printf("%d + %d = %d\n", ((int*)vInt1->coords)[i], ((int*)vInt2->coords)[i], ((int*)vSum->coords)[i] );
    }

    printf("\nTesting double: \n\n");

    vSum = vSum->opers->sum(vDouble1, vDouble2, &SumDouble);

    for (int i=0; i<SIZE_DOUBLE; ++i)
    {
        printf("%g + %g = %g\n", ((double*)vDouble1->coords)[i], ((double*)vDouble2->coords)[i], ((double*)vSum->coords)[i] );
    }

    printf("\nTesting double complex: \n\n");

    vSum = vSum->opers->sum(vDoubleComplex1, vDoubleComplex2, &SumDoubleComplex);

    for (int i=0; i<SIZE_DOUBLE_COMPLEX; ++i)
    {
        printf("Real part: %g + %g = %g\t", creal(((double complex*)vDoubleComplex1->coords)[i]), creal(((double complex*)vDoubleComplex2->coords)[i]), creal(((double complex*)vSum->coords)[i]) );
        printf("Imaginary part: %gi + %gi = %gi\n", cimag(((double complex*)vDoubleComplex1->coords)[i]), cimag(((double complex*)vDoubleComplex2->coords)[i]), cimag(((double complex*)vSum->coords)[i]) );
    }

}

void TestScalarMult()
{
    Vector* vInt = VectorCtor();
    Vector* vDouble = VectorCtor();
    Vector* vDoubleComplex = VectorCtor();

    int sampleInt[SIZE_INT] = {1,2,3,4,5};
    double sampleDouble[SIZE_DOUBLE] = {5.378, 2.0926, 9.03552};
    double complex sampleDoubleComplex[SIZE_DOUBLE_COMPLEX] = {65 + 2 * I, 89.678 + 0.34 * I};

    int* scalarInt = malloc(sizeof(int));
    *scalarInt = 25;

    double* scalarDouble = malloc(sizeof(double));
    *scalarDouble = 13.7546;

    double complex* scalarDoubleComplex = malloc(sizeof(double complex));
    *scalarDoubleComplex = 0.45905 + 78.3*I;

    printf("\n---SCALAR MULT TEST---\n\n");

    // ASSIGN SECTION

    vInt->opers->assign(vInt, sampleInt, SIZE_INT, &AssignInt);
    vDouble->opers->assign(vDouble, sampleDouble, SIZE_DOUBLE, &AssignDouble);
    vDoubleComplex->opers->assign(vDoubleComplex, sampleDoubleComplex, SIZE_DOUBLE_COMPLEX, &AssignDoubleComplex);

    // --------------

    Vector* vScalar = VectorCtor();

    printf("Testing int: \n\n");

    vScalar = vScalar->opers->scalarMult(vInt, scalarInt, &ScalarMultInt);

    for (int i=0; i<SIZE_INT; ++i)
        printf("%d * %d = %d\n", *scalarInt, ((int*)vInt->coords)[i], ((int*)vScalar->coords)[i]);

    printf("\nTesting double: \n\n");

    vScalar = vScalar->opers->scalarMult(vDouble, scalarDouble, &ScalarMultDouble);

    for (int i=0; i<SIZE_DOUBLE; ++i)
        printf("%g * %g = %g\n", *scalarDouble, ((double*)vDouble->coords)[i], ((double*)vScalar->coords)[i]);

    printf("\nTesting double complex: \n\n");

    vScalar = vScalar->opers->scalarMult(vDoubleComplex, scalarDoubleComplex, &ScalarMultDoubleComplex);

    for (int i=0; i<SIZE_DOUBLE_COMPLEX; ++i)
    {
        printf("Real part: %g\t", creal(((double complex*)vScalar->coords)[i]) );
        printf("Imaginary part: %gi\n", cimag(((double complex*)vScalar->coords)[i]) );
    }
}

int main()
{
    TestAssign();
    TestSum();
    TestScalarMult();
}
