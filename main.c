#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <malloc.h>
#include "VectorOperations.h"
#include "AbstractVector.h"

int main()
{
    Vector* v1 = VectorCtor();
    Vector* v2 = VectorCtor();

    int coordArr1[3] = {1,2,3};
    int coordArr2[3] = {5,6,9};

    int *scalar = malloc(sizeof(int));
    *scalar = 25;

    Assign(v1, coordArr1, 3, &AssignInt);
    Assign(v2, coordArr2, 3, &AssignInt);

    Vector* sum = VectorCtor();
    sum = sum->opers->sum(v1, v2, &SumInt);

    Vector* scalarMult = VectorCtor();
    scalarMult = scalarMult->opers->scalarMult(v1, scalar, ScalarMultInt);

    for (int i=0; i<3; ++i)
    {
        printf("%d\n", ((int*)sum->coords)[i]);
    }

    for (int i=0; i<3; ++i)
    {
        printf("%d\n", ((int*)v1->coords)[i]);
    }
}
