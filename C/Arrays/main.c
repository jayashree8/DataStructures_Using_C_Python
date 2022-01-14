#include <stdio.h>
#include <conio.h>

void traverse_arr(int[], int);
void print_arr(int[], int);
float mean_arr(int[], int);
void smallest_arr(int[], int, float *, int *);
void largest_arr(int[], int, float *, int *);
void insert_arr(int[], int, int, int);
void delete_arr(int[], int, int);
int merge_arr(int[], int[], int[], int, int);

int main()
{
    int num, pos, value, num1, num2, num3;
    float mean, small, large;

    printf("Enter the number of elements in the array: ");
    scanf("%d",&num);

    int arr[num];

    // Traverse array
    traverse_arr(arr,num);

    // Print array
    print_arr(arr,num);

    // Find mean of the array
    mean = mean_arr(arr, num);
    printf("\nThe mean of the array is: %f", mean);

    // Find the smallest number and its position in the array
    smallest_arr(arr, num, &small, &pos);
    printf("\nThe smallest element of the array is %f at position %d", small, pos);

    // Find the largest number and its position in the array
    largest_arr(arr, num, &large, &pos);
    printf("\nThe largest element of the array is %f at position %d", large, pos);

    // Insert an element in the array
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &value);
    printf("\nEnter the position to be inserted at: ");
    scanf("%d", &pos);
    insert_arr(arr, num, pos, value);
    printf("\nThe new array is: ");
    print_arr(arr,num);

    // Delete an element in the array
    printf("\nEnter the position of the element to be deleted at: ");
    scanf("%d", &pos);
    delete_arr(arr, num, pos);
    printf("\nThe new array is: ");
    print_arr(arr,num);

    // Merge two unsorted elements
    printf("\nEnter the length of the first array: ");
    scanf("%d", &num1);
    int arr1[num1];
    printf("\nEnter the elements of the first array: ");
    traverse_arr(arr1, num1);

    printf("\nEnter the length of the second array: ");
    scanf("%d", &num2);
    int arr2[num2], arr3[num1+num2];
    printf("\nEnter the elements of the second array: ");
    traverse_arr(arr2, num2);

    num3 = merge_arr(arr1, arr2, arr3, num1, num2);
    printf("\nThe merged unsorted array is: ");
    print_arr(arr3,num3);
}

// Function to traverse the array
void traverse_arr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++){
        printf("\nEnter the array element: ");
        scanf("%d",&arr[i]);
    }
}

// Function to print the array
void print_arr(int arr[], int n)
{
    int i;
    printf("The array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

// Function to find the mean of the array
float mean_arr(int arr[], int n)
{
    int i, sum = 0;
    float avg;

    for(i=0; i<n; i++){
        sum = sum + arr[i];
    }

    avg = sum/n;
    return avg;
}

// Function to find the smallest element and its position in the array
void smallest_arr(int arr[], int n, float *small, int *pos)
{
    int i;

    *pos = 0;
    *small=arr[0];

    for(i=1; i<n; i++){
        if (arr[i]<*small){
            *small = arr[i];
            *pos = i;
        }
    }
}

// Function to find the largest element and its position in the array
void largest_arr(int arr[], int n, float *large, int *pos)
{
    int i;

    *pos = 0;
    *large=arr[0];

    for(i=1; i<n; i++){
        if (arr[i]>*large){
            *large = arr[i];
            *pos = i;
        }
    }
}

// Function to insert element in an array
void insert_arr(int arr[], int n, int pos, int value)
{
    int i;
    for(i=n;i>=pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
}

// Function to delete element in an array
void delete_arr(int arr[], int n, int pos)
{
    int i;
    for(i=pos;i<n;i++){
        arr[i] = arr[i+1];
    }
}

// Function to merge 2 unsorted arrays
int merge_arr(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
    int i, n3 = n1+n2;

    for(i=0; i<n1; i++){
        arr3[i] = arr1[i];
    }

    for(i=0; i<n2; i++){
        arr3[n1+i] = arr2[i];
    }

    return n3;
}
