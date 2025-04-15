#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calculate_mean(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

float calculate_median(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
    if (size % 2 == 0)
        return (arr[size/2 - 1] + arr[size/2]) / 2.0;
    else
        return arr[size/2];
}

void calculate_mode(int arr[], int size) {
    int maxCount = 0;
    int mode[size], modeCount = 0;

    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(arr[j] == arr[i])
                count++;
        }
        if(count > maxCount) {
            maxCount = count;
            modeCount = 0;
            mode[modeCount++] = arr[i];
        } else if(count == maxCount && count > 1) {
            int alreadyAdded = 0;
            for(int k = 0; k < modeCount; k++) {
                if(mode[k] == arr[i]) {
                    alreadyAdded = 1;
                    break;
                }
            }
            if(!alreadyAdded)
                mode[modeCount++] = arr[i];
        }
    }

    if(maxCount <= 1) {
        printf("No mode\n");
    } else {
        printf("Mode: ");
        for(int i = 0; i < modeCount; i++) {
            printf("%d ", mode[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {1, 3, 3, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Mean: %.2f\n", calculate_mean(arr, size));
    printf("Median: %.2f\n", calculate_median(arr, size));
    calculate_mode(arr, size);

    return 0;
}
