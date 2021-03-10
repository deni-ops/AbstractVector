#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <malloc.h>

typedef struct AbstractVector Vector;

struct VectorOpers
{
    Vector* (*sum)(Vector* v1, Vector* v2, Vector* (*SumType)(Vector*, Vector*) );
    Vector* (*scalarMult)(Vector* v1, Vector* v2, Vector* (*ScalarMultType)(Vector*, Vector*) );
    Vector* (*dotProduct)(Vector* v1, Vector* v2, Vector* (*DotProductType)(Vector*, Vector*) );

    void (*assign)(Vector* v, void* coords, size_t size, void (*AssignType)(Vector* v, void* coords, size_t size) );
};

struct AbstractVector
{
    size_t size;
    void* coords;

    struct VectorOpers* opers;
};

Vector* Sum(Vector* v1, Vector* v2, Vector* (*SumType)(Vector*, Vector*) )
{
    return SumType(v1, v2);
}

Vector* DotProduct(Vector* v1, Vector* v2, Vector* (DotProductType)(Vector*, Vector*) )
{
    return DotProductType(v1, v2);
}

Vector* SumInt(Vector* v1, Vector* v2)
{
    Vector* v = NULL;

    if (v1->size == v2->size && v1->size != 0)
    {
        v = malloc(sizeof(Vector));
        v->coords = malloc(sizeof(int)*v1->size);
        v->size = v1->size;

        for (size_t i=0; i<v1->size; ++i)
        {
            int coord1 = ((int*)v1->coords)[i];
            int coord2 = ((int*)v2->coords)[i];

            ((int*)v->coords)[i] = coord1 + coord2;
        }
    }
    else if (v1->size == 0)
    {
        printf("Error occurred: can't sum vectors with zero dimensions.\n");
        exit(1);
    }
    else
    {
        printf("Error occurred: can't sum vectors with different dimensions.\n");
        exit(1);
    }
    return v;
}

Vector* SumDouble(Vector* v1, Vector* v2)
{
    Vector* v = NULL;

    if (v1->size == v2->size && v1->size != 0)
    {
        v = malloc(sizeof(Vector));
        v->coords = malloc(sizeof(double)*v1->size);
        v->size = v1->size;

        for (size_t i=0; i<v1->size; ++i)
        {
            double coord1 = ((double*)v1->coords)[i];
            double coord2 = ((double*)v2->coords)[i];

            ((double*)v->coords)[i] = coord1 + coord2;
        }
    }
    else if (v1->size == 0)
    {
        printf("Error occurred: can't sum vectors with zero dimensions.\n");
        exit(1);
    }
    else
    {
        printf("Error occurred: can't sum vectors with different dimensions.\n");
        exit(1);
    }
    return v;
}

Vector* SumDoubleComplex(Vector* v1, Vector* v2)
{
    Vector* v = NULL;

    if (v1->size == v2->size && v1->size != 0)
    {
        v = malloc(sizeof(Vector));
        v->coords = malloc(sizeof(double complex)*v1->size);
        v->size = v1->size;

        for (size_t i=0; i<v1->size; ++i)
        {
            double complex coord1 = ((double complex*)v1->coords)[i];
            double complex coord2 = ((double complex*)v2->coords)[i];

            ((double complex*)v->coords)[i] = coord1 + coord2;
        }
    }
    else if (v1->size == 0)
    {
        printf("Error occurred: can't sum vectors with zero dimensions.\n");
        exit(1);
    }
    else
    {
        printf("Error occurred: can't sum vectors with different dimensions.\n");
        exit(1);
    }
    return v;
}

Vector* DotProductInt(Vector* v1, Vector* v2)
{
    Vector* v = NULL;

    if (v1->size == v2->size && v1->size != 0)
    {
        v = malloc(sizeof(Vector));
        v->coords = malloc(sizeof(int)*v1->size);
        v->size = v1->size;

        for (size_t i=0; i<v1->size; ++i)
        {
            int coord1 = ((int*)v1->coords)[i];
            int coord2 = ((int*)v2->coords)[i];

            ((int*)v->coords)[i] = coord1 * coord2;
        }
    }
    else if (v1->size == 0)
    {
        printf("Error occurred: can't multiply vectors with zero dimensions.\n");
        exit(1);
    }
    else
    {
        printf("Error occurred: can't multiply vectors with different dimensions.\n");
        exit(1);
    }
    return v;
}

Vector* DotProductDouble(Vector* v1, Vector* v2)
{
    Vector* v = NULL;

    if (v1->size == v2->size && v1->size != 0)
    {
        v = malloc(sizeof(Vector));
        v->coords = malloc(sizeof(double)*v1->size);
        v->size = v1->size;

        for (size_t i=0; i<v1->size; ++i)
        {
            double coord1 = ((double*)v1->coords)[i];
            double coord2 = ((double*)v2->coords)[i];

            ((double*)v->coords)[i] = coord1 * coord2;
        }
    }
    else if (v1->size == 0)
    {
        printf("Error occurred: can't multiply vectors with zero dimensions.\n");
        exit(1);
    }
    else
    {
        printf("Error occurred: can't multiply vectors with different dimensions.\n");
        exit(1);
    }
    return v;
}

Vector* DotProductDoubleComplex(Vector* v1, Vector* v2)
{
    Vector* v = NULL;

    if (v1->size == v2->size && v1->size != 0)
    {
        v = malloc(sizeof(Vector));
        v->coords = malloc(sizeof(double complex)*v1->size);
        v->size = v1->size;

        for (size_t i=0; i<v1->size; ++i)
        {
            double complex coord1 = ((double complex*)v1->coords)[i];
            double complex coord2 = ((double complex*)v2->coords)[i];

            ((double complex*)v->coords)[i] = coord1 * coord2;
        }
    }
    else if (v1->size == 0)
    {
        printf("Error occurred: can't multiply vectors with zero dimensions.\n");
        exit(1);
    }
    else
    {
        printf("Error occurred: can't multiply vectors with different dimensions.\n");
        exit(1);
    }
    return v;
}


void Assign(Vector* v, void* coords, size_t size, void (*AssignType)(Vector* v, void* coords, size_t size))
// Vector is passed and filled
{
    AssignType(v, coords, size);
}

void AssignInt(Vector* v, int* coords, size_t size)
{
    v->coords = malloc(sizeof(int)*size);
    v->size = size;

    for (size_t i=0; i<size; ++i)
    {
        ((int*)v->coords)[i] = coords[i];
    }
}

void AssignDouble(Vector* v, double* coords, size_t size)
{
    v->coords = malloc(sizeof(double)*size);
    v->size = size;

    for (size_t i=0; i<size; ++i)
    {
        ((double*)v->coords)[i] = coords[i];
    }
}

void AssignDoubleComplex(Vector* v, double complex* coords, size_t size)
{
    v->coords = malloc(sizeof(double complex)*size);
    v->size = size;

    for (size_t i=0; i<size; ++i)
    {
        ((double complex*)v->coords)[i] = coords[i];
    }
}

Vector* VectorCtor()
{
    Vector* v = malloc(sizeof(Vector));
    v->opers = malloc(sizeof(struct VectorOpers));

    v->opers->sum = malloc(sizeof(Sum));
    v->opers->dotProduct = malloc(sizeof(DotProduct));
    v->opers->assign = malloc(sizeof(Assign));

    v->opers->sum = &Sum;
    v->opers->sum = &DotProduct;

    v->coords = NULL;
    v->size = 0;

    return v;
}


int main()
{
    Vector* v1 = VectorCtor();
    Vector* v2 = VectorCtor();

    int coordArr1[3] = {1,2,3};
    int coordArr2[3] = {5,6,9};

    Assign(v1, coordArr1, 3, &AssignInt);
    Assign(v2, coordArr2, 3, &AssignInt);

    Vector* res = Sum(v1, v2, &SumInt);

    for (int i=0; i<3; ++i)
    {
        printf("%d\n", ((int*)res->coords)[i]);
    }

    for (int i=0; i<3; ++i)
    {
        printf("%d\n", ((int*)v1->coords)[i]);
    }
}
