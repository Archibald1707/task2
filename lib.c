#include "lib.h"

matrixOptional *memoryAllocation(int row, int column)
{
    int i;
    matrixOptional *matrixPointer = malloc(sizeof(matrixOptional));
    if(!matrixPointer)
    {
        printf("Error: fail in allocating memory");
        exit(1);
    }
    matrixPointer->columns = column;
    matrixPointer->rows = row;
    matrixPointer->matrix = calloc(row,sizeof(float*));
    if(!(matrixPointer->matrix))
    {
        printf("Error: fail in allocating memory");
        exit(1);
    }
    for(i=0;i<matrixPointer->rows;++i)
    {
        (matrixPointer->matrix)[i] = calloc(column,sizeof(float));
        if(!((matrixPointer->matrix)[i]))
        {
            printf("Error: fail in allocating memory");
            exit(1);
        }
    }
    return matrixPointer;
}

matrixOptional *matrixInput(int row, int column)
{
    matrixOptional *matrixStructure;
    int i, j;
    if((row < 1)||(column < 1))
    {
        printf("Error: wrong matrix size");
        exit(1);
    }
    matrixStructure = memoryAllocation(row, column);
    for(i=0;i<row;++i)
    {
        for (j=0;j<column;++j)
        {
            scanf("%f", &(matrixStructure->matrix[i][j]));
        }
    }
    return matrixStructure;
}

matrixOptional *matrixFold(matrixOptional *matrix1, matrixOptional *matrix2)
{
    matrixOptional *matrixSum;
    int i, j;
    if(((matrix1->rows)!=(matrix2->rows))||((matrix1->columns)!=(matrix2->columns)))
    {
        printf("Error: matrices of different sizes");
        exit(1);
    }
    matrixSum = memoryAllocation(matrix1->rows, matrix1->columns);
    for(i=0;i<matrix1->rows;++i)
    {
        for(j=0;j<matrix1->columns;++j)
        {
            (matrixSum->matrix[i][j]) = (matrix1->matrix[i][j]) + (matrix2->matrix[i][j]);
        }
    }
    return matrixSum;
}

matrixOptional *matrixProductPerNumber(matrixOptional *matrix1, float factor)
{
    int i, j;
    for(i=0;i<(matrix1->rows);++i)
    {
      for(j=0;j<(matrix1->columns);++j)
        {
            (matrix1->matrix[i][j]) *= factor;
        }
    }
    return matrix1;
}

matrixOptional *matrixMultiplication(matrixOptional *matrix1, matrixOptional *matrix2)
{
    matrixOptional *matrixProduct;
    int i, j, k;
    if((matrix1->columns)!=(matrix2->rows))
    {
        printf("Error: matrices can't multiply in that order");
        exit(1);
    }
    matrixProduct = memoryAllocation(matrix1->rows, matrix2->columns);
    for(i=0;i<matrix1->rows;++i)
    {
        for(j=0;j<matrix2->columns;++j)
        {
            matrixProduct->matrix[i][j] = 0;
            for(k=0;k<matrix1->columns;++k)
            {
                (matrixProduct->matrix[i][j]) += ((matrix1->matrix[i][k]) * (matrix2->matrix[k][j]));
            }
        }
    }
    return matrixProduct;
}

float matrixDeterminant(matrixOptional *matrix1)
{
  float *temp;
  float EPS = 0.0000001;
  int n;
  float det = 1;
  n = matrix1->rows;
  for (int i=0; i<n; ++i) {
    int k = i;
    for (int j=i+1; j<n; ++j)
        if (abs (matrix1->matrix[j][i]) > abs (matrix1->matrix[k][i]))
            k = j;
    if (abs (matrix1->matrix[k][i]) < EPS)
    {
        det = 0;
        break;
    }
    temp = (matrix1->matrix)[i];
    (matrix1->matrix)[i] = (matrix1->matrix)[k];
    (matrix1->matrix)[k] = temp;
    if (i != k)
        det = -det;
    det *= (matrix1->matrix[i][i]);
    for (int j=i+1; j<n; ++j)
      (matrix1->matrix[i][j]) /= (matrix1->matrix[i][i]);
    for (int j=0; j<n; ++j)
      if ((j != i) && abs (matrix1->matrix[j][i]) > EPS)
            for (int k=i+1; k<n; ++k)
	      (matrix1->matrix[j][k]) -= (matrix1->matrix[i][k]) * (matrix1->matrix[j][i]);
  }
  return det;
}

void matrixOutput(matrixOptional *matrix1)
{
    int i, j;
    for(i=0;i<matrix1->rows;++i)
    {
        for (j = 0; j < matrix1->columns; ++j)
        {
            printf("%f ", matrix1->matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixFree(matrixOptional *matrix1)
{
    int i;
    for(i=0;i<matrix1->rows;++i)
    {
        free((matrix1->matrix)[i]);
    }
    free(matrix1->matrix);
    free(matrix1);
}
