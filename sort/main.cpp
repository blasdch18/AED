#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;
vector <int> llenar(vector<int> &a, int tam){
    a.resize(tam);
    cout<<a.size()<<endl;
    srand(time(NULL));
    for (int i=0; i<tam; i++){
        a[i]=rand()%tam;
        cout<<a[i]<<" ";
    }
    return a;
}

vector<int> selectionsort(vector<int> &a, int tam){
    int temp;
    int temp1;
    int temp2;
    for (int i=0; i<tam-1; i++){
        temp=a[i];
        temp1=i;
        for (int j=i+1;j<tam;j++){
            temp2=a[j];
            if(temp>temp2){
                temp=temp2;
                temp1=j;
            }

        }
        swap(a[i],a[temp1]);

    }
    return a;
}

vector<int> bubblesort(vector<int>&a,int tam){
    for (int i=0; i<tam-1; i++) {
        for (int j=i+1; j<tam; j++) {
            int temp;
            if (a[i]>a[j]) {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    return a;
}

void cocktailSort(vector<int> &a, int tam){
    int izq=0;
    int der=tam-1;
    int temp;
    while(izq<der){

        for(int i=izq;i<der;i++){
            temp=a[i];
            if(a[i]>a[i+1]){
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
        der--;
        for(int j=der;j>izq;j--){
            temp=a[j];
            if(a[j]<a[j-1]){
                a[j]=a[j-1];
                a[j-1]=temp;
            }

        }
        izq++;
    }
}

void quickSort(vector<int>& arr, int left, int right) {
    int l = left, r = right;
    int tmp;
    int pivot = arr[(left + right)/2];
    while (l <= r) {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r) {
            tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    };
    if (left < r)
        quickSort(arr, left, r);
    if (l < right)
        quickSort(arr, l, right);
}

void insertionSort(vector<int>&a,int tam){
    int j,temp;
    for(int i=1; i<tam;i++){
        j=i;
        while (j>0 && a[j-1]>a[j]) {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }
    }
}
void merge(vector<int>&arr, int tam, int low, int middle, int high){
    vector<int>tem;
    tem.resize(tam);
    for (int i=low; i<=high; i++) {
        tem[i]=arr[i];
    }
    int i=low;
    int j=middle+1;
    int k=low;
    while (i<=middle && j<=high) {
        if (tem[i]<= tem[j]) {
            arr[k]=tem[i];
            i++;
        }
        else{
            arr[k]=tem[j];
            j++;
        }
        k++;
    }
    while (i<=middle) {
        arr[k]=tem[i];
        k++;
        i++;
    }
}
void mergeSort(vector<int>&arr, int tam, int low, int high){
    if(low<high){
        int middle=(low+high)/2;
        mergeSort(arr, tam, low, middle);
        mergeSort(arr, tam, middle+1, high);
        merge(arr,tam,low,middle,high);
    }
}
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


int main()
{
    /*
    //Radix
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        */
    // 1-5
     vector<int>a;
    int tam=10;
    cout<<"Vector Desordenado"<<endl;
    a=llenar(a, tam);
    cout<<endl;


    cout<<"Algortimo Burbuja"<<endl;
    //bubblesort(a, tam);
    //selectionsort(a, tam);
    //quickSort(a,0,99);
    //insertionSort(a,tam);
    mergeSort(a, tam, 0, tam-1 );
    //cocktailSort(a, tam);

    for (int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }


    return 0;
}
