#include <stdio.h>
#include <cuda_runtime.h>

__global__ void addVectors(int *A, int *B, int *C, int N) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < N) {
        C[i] = A[i] + B[i];
    }
}

int main() {
    int N = 5;
    int size = N * sizeof(int);
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {5, 4, 3, 2, 1};
    int C[N];

    int *d_A, *d_B, *d_C;

    cudaMalloc((void **)&d_A, size);
    cudaMalloc((void **)&d_B, size);
    cudaMalloc((void **)&d_C, size);

    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, size, cudaMemcpyHostToDevice);

    addVectors<<<1, N>>>(d_A, d_B, d_C, N);

    cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);

    printf("Resultant vector C: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
