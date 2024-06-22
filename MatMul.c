#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <complex.h>

void initMatrices (complex * a, complex* b, size_t n) {
    // Initalizes matrices with complex numbers
    for (size_t i=0; i<n; i++) {
        for (size_t k=0; k<n; k++) {
            double realNum, imagNum;
            a[i*n + k] = CMPLX(realNum, imagNum);
        }
    }

    for (size_t k=0; k<n; k++) {
        for (size_t j=0; j<n; j++) {
            double realNum, imagNum;
            b[k*n + j] = CMPLX(realNum, imagNum);
        }
    }
}

void matMul (complex* a, complex* b, complex* c, size_t n) {
    // Matrix multiplication logic
    for (size_t i=0; i<n; i++) {
        for (size_t j=0; j<n; j++) {
            complex res = c[i*n + j];
            for (size_t k=0; k<n; k++) {
                res+= a[i*n + k] * b[k*n + j];
                c[i*n + j] = res;
            }
        }
    }

}
int main (int argc, char* argv[]) {
    size_t n = 4;
    complex* a = malloc(n*n * sizeof(complex));
    complex* b = malloc(n*n * sizeof(complex));
    complex* c = malloc(n*n * sizeof(complex));
   
   if ( a == NULL || b == NULL || c == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
   }

   initMatrices(a, b, n);
   matMul(a, b, c, n);

   free(a);
   free(b);
   free(c);
    
}

