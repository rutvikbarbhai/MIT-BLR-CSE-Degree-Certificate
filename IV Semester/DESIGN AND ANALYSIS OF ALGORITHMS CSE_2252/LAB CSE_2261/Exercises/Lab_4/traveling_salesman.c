#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate total distance for a given path
int calculateTotalDistance(int path[], int numCities, int distances[numCities][numCities]) {
    int totalDistance = 0;
    for (int i = 0; i < numCities - 1; i++) {
        totalDistance += distances[path[i]][path[i + 1]];
    }
    totalDistance += distances[path[numCities - 1]][path[0]]; // Return to the starting city
    return totalDistance;
}

// Function to find the optimal path and minimum distance using brute force
void travelingSalesmanBruteForce(int numCities, int distances[numCities][numCities]) {
    int cities[numCities];
    for (int i = 0; i < numCities; i++) {
        cities[i] = i;
    }

    int minDistance = INT_MAX;
    int optimalPath[numCities];

    do {
        int currentDistance = calculateTotalDistance(cities, numCities, distances);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            for (int i = 0; i < numCities; i++) {
                optimalPath[i] = cities[i];
            }
        }
    } while (next_permutation(cities, cities + numCities));

    // Print the optimal path and minimum distance
    printf("\nOptimal Path: ");
    for (int i = 0; i < numCities; i++) {
        printf("%d ", optimalPath[i]);
    }
    printf("\nMinimum Distance: %d\n", minDistance);
}

int main() {
    // Take user input for the number of cities
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    // Take user input for the distance matrix
    int distances[numCities][numCities];
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &distances[i][j]);
        }
    }

    // Calculate and print the optimal path and minimum distance
    travelingSalesmanBruteForce(numCities, distances);

    return 0;
}
