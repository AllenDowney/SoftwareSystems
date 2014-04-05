/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    double **data;
    int rows, cols;
} Matrix;


// Makes a new matrix and sets all elements to zero.
Matrix *make_matrix(int rows, int cols) {
    // Fill this in
    return NULL;
}

// Prints the elements of a matrix.
void print_matrix(Matrix *matrix) {
    int i, j;

    for (i=0; i<matrix->rows; i++) {
	for (j=0; j<matrix->cols; j++) {
	    printf("%lf ", matrix->data[i][j]);
	}
	printf("\n");
    }
}

// Adds a scalar to all elements of a matrix.
void increment_matrix(Matrix *matrix, int incr) {
    int i, j;

    for (i=0; i<matrix->rows; i++) {
	for (j=0; j<matrix->cols; j++) {
	    matrix->data[i][j] += incr;
	}
    }
}

// Sets the elements of a matrix to consecutive numbers.
void consecutive_matrix(Matrix *matrix) {
    int i, j;

    for (i=0; i<matrix->rows; i++) {
	for (j=0; j<matrix->cols; j++) {
	    matrix->data[i][j] = i * matrix->cols + j;
	}
    }
}

// Adds two matrices elementwise and stores the result in the given
// destination matrix (C).
void add_matrix(Matrix *A, Matrix *B, Matrix *C) {
    int i, j;

    assert(A->rows == B->rows && B->rows == C->rows);
    assert(A->cols == B->cols && B->cols == C->cols);

    for (i=0; i<A->rows; i++) {
	for (j=0; j<A->cols; j++) {
	    C->data[i][j] =  A->data[i][j] + B->data[i][j];
	}
    }
}

// Adds two matrices elementwise and returns a new matrix.
Matrix *add_matrix_func(Matrix *A, Matrix *B) {
    Matrix *C = make_matrix(A->rows, A->cols);
    add_matrix(A, B, C);
    return C;
}

// Performs matrix multiplication and stores the result in the given
// destination matrix (C).
void mult_matrix(Matrix *A, Matrix *B, Matrix *C) {
    // Fill this in
    // Note that it is asking for matrix multiplication, not
    // elementwise multiplication
}

// Performs matrix multiplication and returns a new matrix.
Matrix *mult_matrix_func(Matrix *A, Matrix *B) {
    // Fill this in
    return NULL;
}

int main() {
    Matrix *A = make_matrix(3, 4);
    consecutive_matrix(A);
    printf("A\n");
    print_matrix(A);

    Matrix *C = add_matrix_func(A, A);
    printf("A + A\n");
    print_matrix(C);

    Matrix *B = make_matrix(4, 3);
    increment_matrix(B, 1);
    printf("B\n");
    print_matrix(B);

    Matrix *D = mult_matrix_func(A, B);
    printf("D\n");
    print_matrix(D);
}
