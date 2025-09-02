#include <iostream>
#include <cuda_runtime.h>

__global__ void selectionSortKernel(int *arr, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    if (idx < n) {
        // Find the minimum element in the remaining unsorted array
        for (int j = idx + 1; j < n; j++) {
            if (arr[j] < arr[idx]) {
                // Swap if the found minimum is smaller
                int temp = arr[idx];
                arr[idx] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionSort(int *arr, int n) {
    int *d_arr;
    cudaMalloc((void**)&d_arr, n * sizeof(int));
    cudaMemcpy(d_arr, arr, n * sizeof(int), cudaMemcpyHostToDevice);

    // Launch kernel with enough threads for all elements
    int blockSize = 256; // Number of threads per block
    int numBlocks = (n + blockSize - 1) / blockSize;

    selectionSortKernel<<<numBlocks, blockSize>>>(d_arr, n);
    cudaDeviceSynchronize();

    cudaMemcpy(arr, d_arr, n * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_arr);
}

int main() {
    const int n = 10;
    int arr[n] = {64, 25, 12, 22, 11, 90, 35, 29, 78, 5};

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    selectionSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
