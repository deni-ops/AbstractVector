#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <malloc.h>

struct AbstractVector
{
    size_t size;
    void** coords;
};

typedef struct AbstractVector Vector;

// Abstract functions

Vector* Sum(Vector v1, Vector v2, Vector* (*SumType)(Vector, Vector) )
{
    return SumType(v1, v2);
}

Vector* ScalarMult(Vector v1, Vector v2, Vector* (ScalarMultType)(Vector, Vector) )
{
    return ScalarMultType(v1, v2);
}

// Functions to pass to previously implemented abstract functions

Vector* SumInt(Vector v1, Vector v2)
{
    Vector* v = NULL;

    if (v1.size == v2.size)
    {
        v = malloc(sizeof(Vector));
        v->size = v1.size;

        for (int i=0; i<v1.size; ++i)
        {
            *((int*)v->coords[i]) = *((int*)v1.coords[i]) + *((int*)v2.coords[i]);
        }
    }
    else
    {
        printf("Error occurred when summing vectors with different dimensions");
        exit(1);
    }
    return v;
}

Vector* SumDouble(Vector v1, Vector v2)
{
    Vector* v = NULL;

    if (v1.size == v2.size)
    {
        v = malloc(sizeof(Vector));
        v->size = v1.size;

        for (int i=0; i<v1.size; ++i)
        {
            *((double*)v->coords[i]) = *((double*)v1.coords[i]) + *((double*)v2.coords[i]);
        }
    }
    else
    {
        printf("Error occurred when summing vectors with different dimensions");
        exit(1);
    }
    return v;
}

Vector* SumDoubleComplex(Vector v1, Vector v2)
{
    Vector* v = NULL;

    if (v1.size == v2.size)
    {
        v = malloc(sizeof(Vector));
        v->size = v1.size;

        for (int i=0; i<v1.size; ++i)
        {
            *((double complex*)v->coords[i]) = *((double complex*)v1.coords[i]) + *((double complex*)v2.coords[i]);
        }
    }
    else
    {
        printf("Error occurred when summing vectors with different dimensions");
        exit(1);
    }
    return v;
}

Vector* ScalarMultInt(Vector v1, Vector v2)
{
    Vector* v = NULL;

    if (v1.size == v2.size)
    {
        v = malloc(sizeof(Vector));
        v->size = v1.size;

        for (int i=0; i<v1.size; ++i)
        {
            *((int*)v->coords[i]) = *((int*)v1.coords[i]) * *((int*)v2.coords[i]);
        }
    }
    else
    {
        printf("Error occurred when scalar multiplying vectors with different dimensions");
        exit(1);
    }
    return v;
}

Vector* ScalarMultDouble(Vector v1, Vector v2)
{
    Vector* v = NULL;

    if (v1.size == v2.size)
    {
        v = malloc(sizeof(Vector));
        v->size = v1.size;

        for (int i=0; i<v1.size; ++i)
        {
            *((double*)v->coords[i]) = *((double*)v1.coords[i]) * *((double*)v2.coords[i]);
        }
    }
    else
    {
        printf("Error occurred when scalar multiplying vectors with different dimensions");
        exit(1);
    }
    return v;
}

Vector* ScalarMultDoubleComplex(Vector v1, Vector v2)
{
    Vector* v = NULL;

    if (v1.size == v2.size)
    {
        v = malloc(sizeof(Vector));
        v->size = v1.size;

        for (int i=0; i<v1.size; ++i)
        {
            *((double complex*)v->coords[i]) = *((double complex*)v1.coords[i]) * *((double complex*)v2.coords[i]);
        }
    }
    else
    {
        printf("Error occurred when scalar multiplying vectors with different dimensions");
        exit(1);
    }
    return v;
}


void Assign(Vector* v, void** coords, size_t size, void (*AssignType)(Vector* v, void** coords, size_t size))
{
    AssignType(v, coords, size);
}

void AssignInt(Vector* v, int* coords, size_t size)
{
    for (int i=0; i<size; ++i)
    {
        v->coords = realloc(v->coords, sizeof(int)*(i+1));
        *((int*)v->coords[i]) = coords[i];
    }
}

void AssignDouble(Vector* v, double* coords, size_t size)
{
    for (int i=0; i<size; ++i)
    {
        *((double*)v->coords[i]) = coords[i];
    }
}

void AssignDoubleComplex(Vector* v, double complex* coords, size_t size)
{
    for (int i=0; i<size; ++i)
    {
        *((double complex*)v->coords[i]) = coords[i];
    }
}


int main()
{
    Vector* v = malloc(sizeof(Vector)); // create var of type Vector
    v->coords = malloc(sizeof(v->coords));

    int coordArr[3] = {1,2,3};


    Assign(v, coordArr, 3, &AssignInt);

    // ctor for v variable: should fill
    //  - dimensions (size_t dimensions)
    //  - coordinates (void** coordinates - array of void* coordinates)

    //Sum({1,2,3}, int arrSize, Vector* v, &VectorSum, &sumInt);
    // should check whether v.dimension equals to passed array size
    // void Sum(void**, size_t arrSize, Vector* v, &VectorS)

    //Sum({1.4, 5,7}, int arrSize, Vector* v, &VectorSum, &sumDouble);

    //Sum({1 + i*5, 5,7}, int arrSize, Vector* v, &VectorSum, &sumComplex);

    //ScalarMult({1,2,3}, int arrSize, Vector* v, &VectorSum, &scalarMultInt);

    //ScalarMult({13.4,5.5,7.9,1}, int arrSize, Vector* v, &VectorSum, &scalarMultInt);

    //ScalarMult({13.4,5.5,7.9,1}, int arrSize, Vector* v, &VectorSum, &scalarMultComplex);






}
