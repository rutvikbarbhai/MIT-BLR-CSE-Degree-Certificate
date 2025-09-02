#include <stdio.h>
#include <cuda_runtime.h>
#include <math.h>

__global__ void calculateSine(float *angles, float *sineResults, int N) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < N) {
        sineResults[i] = sin(angles[i]);
    }
}

int main() {
    int N = 5;
    int size = N * sizeof(float);
    float angles[] = {0.0, 0.5236, 1.5708, 2.0944, 3.1416}; // Angles in radians
    float sineResults[N];

    float *d_angles, *d_sineResults;

    cudaMalloc((void **)&d_angles, size);
    cudaMalloc((void **)&d_sineResults, size);

    cudaMemcpy(d_angles, angles, size, cudaMemcpyHostToDevice);

    calculateSine<<<1, N>>>(d_angles, d_sineResults, N);

    cudaMemcpy(sineResults, d_sineResults, size, cudaMemcpyDeviceToHost);

    printf("Sine results: ");
    for (int i = 0; i < N; i++) {
        printf("%.4f ", sineResults[i]);
    }
    printf("\n");

    cudaFree(d_angles);
    cudaFree(d_sineResults);

    return 0;
}


commands

sudo apt update
sudo apt install nvidia-cuda-toolkit
nvcc -o vectorAdd vectorAdd.cu
