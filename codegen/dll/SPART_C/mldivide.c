/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mldivide.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

/* Include Files */
#include "mldivide.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[36]
 *                double B[6]
 * Return Type  : void
 */
void mldivide(const double A[36], double B[6])
{
  double b_A[36];
  double smax;
  int a;
  int b_k;
  int j;
  int jA;
  int k;
  signed char ipiv[6];
  memcpy(&b_A[0], &A[0], 36U * sizeof(double));
  for (k = 0; k < 6; k++) {
    ipiv[k] = (signed char)(k + 1);
  }
  for (j = 0; j < 5; j++) {
    int A_tmp;
    int b;
    int jj;
    int jp1j;
    int mmj;
    signed char i;
    mmj = 4 - j;
    b = j * 7;
    jj = j * 7;
    jp1j = b + 2;
    jA = 7 - j;
    a = 0;
    smax = fabs(b_A[jj]);
    for (b_k = 2; b_k < jA; b_k++) {
      double s;
      s = fabs(b_A[(b + b_k) - 1]);
      if (s > smax) {
        a = b_k - 1;
        smax = s;
      }
    }
    if (b_A[jj + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = (signed char)(jA + 1);
        for (k = 0; k < 6; k++) {
          a = j + k * 6;
          smax = b_A[a];
          A_tmp = jA + k * 6;
          b_A[a] = b_A[A_tmp];
          b_A[A_tmp] = smax;
        }
      }
      jA = (jj - j) + 6;
      for (k = jp1j; k <= jA; k++) {
        b_A[k - 1] /= b_A[jj];
      }
    }
    jA = jj;
    for (b_k = 0; b_k <= mmj; b_k++) {
      smax = b_A[(b + b_k * 6) + 6];
      if (smax != 0.0) {
        a = jA + 8;
        A_tmp = (jA - j) + 12;
        for (k = a; k <= A_tmp; k++) {
          b_A[k - 1] += b_A[((jj + k) - jA) - 7] * -smax;
        }
      }
      jA += 6;
    }
    i = ipiv[j];
    if (i != j + 1) {
      smax = B[j];
      B[j] = B[i - 1];
      B[i - 1] = smax;
    }
  }
  for (k = 0; k < 6; k++) {
    jA = 6 * k;
    if (B[k] != 0.0) {
      a = k + 2;
      for (b_k = a; b_k < 7; b_k++) {
        B[b_k - 1] -= B[k] * b_A[(b_k + jA) - 1];
      }
    }
  }
  for (k = 5; k >= 0; k--) {
    jA = 6 * k;
    smax = B[k];
    if (smax != 0.0) {
      smax /= b_A[k + jA];
      B[k] = smax;
      for (b_k = 0; b_k < k; b_k++) {
        B[b_k] -= B[k] * b_A[b_k + jA];
      }
    }
  }
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
