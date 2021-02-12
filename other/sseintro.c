/*
Code from http://supercomputingblog.com/optimization/getting-started-with-sse-programming/
*/
#include <xmmintrin.h>
#include <math.h>

/* 
This program calculates sin(x) / x for x \in [0,64000].
It uses SSE intrinsics to compute sin(x)/x simultaneously for 4 32-bit floats.
Taken from http://supercomputingblog.com/optimization/getting-started-with-sse-programming/
The algorithm proceeds simply:
- Start with the 4-vector [1.0,2.0,3.0,4.0]
- Use SSE to compute [sin(1.0)/1.0,sin(2.0)/2.0,sin(3.0)/3.0,sin(4.0)/4.0]
- Add [4.0,4.0,4.0,4.0] to the input 4-vector (with SSE) and continue
*/ 
void main(int argc, char *argv[]) {

  printf("Starting computation...\n");

  const int length = 64000;
  const SSELength = length / 4;

  // Allocate array of 64000 floats and align to 16-byte boundary for SSE
  float *pResult = (float*) _aligned_malloc(length * sizeof(float),16);

  // x will be used to store 4 32-bit floats
  __m128 x;
  // set the delta to (4,4,4,4) for incrementing across loop
  __m128 xDelta = _mm_set1_ps(4.0f);
  // Cast array of floats as an array of a 128-bit vector
  // Then SSE operations can be stored directly into the array
  __m128 *pResultSSE = (__m128*) pResult;

  // stress is used to run this over many iterations for easy timing
  for (int stress = 0; stress <= 100000; stress++) {
#define TIME_SSE
#ifdef TIME_SSE
    // we start in reverse order because SSE actually reverses
    // the order of floats in an array
    x = _mm_set_ps(4.0f,3.0f,2.0f,1.0f);
    for (int i = 0; i < SSELength; i++) {
      __m128 xSqrt = _mm_sqrt_ps(x);

// Division is slow compared to reciprocal + multiplication
// However, it is less accurate.
      pResultSSE[i] = _mm_div_ps(xSqrt,x);
// Compile with -DFAST_METHOD to check the reciprocal method 
#ifdef FAST_METHOD
      __m128 xRecip = _mm_rcp_ps(x);
      pResultSSE[i] = _mm_mul_ps(xRecip,xSqrt);
#endif // FAST_METHOD
    }
#endif //TIME_SSE
#ifndef TIME_SSE
    float xFloat = 1.0f;
    for (int i=0 ; i < length; i++) {
      // Even though division is slow, there are no intrinsic
      // functions like there are in SSE
      pResult[i] = sqrt(xFloat) / xFloat;	
      xFloat += 1.0f;
    }
#endif // !TIME_SSE
  }
  for (int i=0; i < 20; i++) {
    printf("Result[%d] = %f\n", i, pResult[i]);
  }
}

				 
