#include <stdio.h>
#include <cuda_runtime.h>

__global__ void addVectors(int *A, int *B, int *C, int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < N) {
        C[i] = A[i] + B[i];
    }
}

int main() {
    int N = 1024;
    int blockSize = 256;
    int numBlocks = (N + blockSize - 1) / blockSize;
    int size = N * sizeof(int);
    int A[N], B[N], C[N];

    // Initialize vectors A and B
    for (int i = 0; i < N; i++) {
        A[i] = i;
        B[i] = N - i;
    }

    int *d_A, *d_B, *d_C;

    cudaMalloc((void **)&d_A, size);
    cudaMalloc((void **)&d_B, size);
    cudaMalloc((void **)&d_C, size);

    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, size, cudaMemcpyHostToDevice);

    addVectors<<<numBlocks, blockSize>>>(d_A, d_B, d_C, N);

    cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);

    // Print first 10 elements of C
    for (int i = 0; i < 10; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    return 0;
}

