#include <iostream>
#include <cuda_runtime.h>

#define N 10 // Number of elements

__global__ void oddEvenSortKernel(int *arr, int n, int phase) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int i = 2 * idx + phase; // Compute index for even or odd phase

    if (i + 1 < n) {
        if (arr[i] > arr[i + 1]) {
            // Swap adjacent elements
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

void oddEvenSort(int *arr, int n) {
    int *d_arr;
    cudaMalloc((void**)&d_arr, n * sizeof(int));
    cudaMemcpy(d_arr, arr, n * sizeof(int), cudaMemcpyHostToDevice);

    int blockSize = 256;
    int numBlocks = (n + blockSize - 1) / (2 * blockSize);

    // Perform n iterations for sorting
    for (int phase = 0; phase < n; phase++) {
        oddEvenSortKernel<<<numBlocks, blockSize>>>(d_arr, n, phase % 2);
        cudaDeviceSynchronize();
    }

    cudaMemcpy(arr, d_arr, n * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_arr);
}

int main() {
    int arr[N] = {64, 25, 12, 22, 11, 90, 35, 29, 78, 5};

    std::cout << "Original array: ";
    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    oddEvenSort(arr, N);

    std::cout << "Sorted array: ";
    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
