#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;

// Funções para os algoritmos de ordenação

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void generateVector(vector<int>& arr, int n, int caseType) {
    switch (caseType) {
        case 1: // Melhor caso (ordenado)
            for (int i = 0; i < n; i++) {
                arr.push_back(i);
            }
            break;
        case 2: // Pior caso (ordem inversa)
            for (int i = n - 1; i >= 0; i--) {
                arr.push_back(i);
            }
            break;
        case 3: // Aleatório
            for (int i = 0; i < n; i++) {
                arr.push_back(rand() % 1000);  // Números aleatórios
            }
            break;
        default:
            cout << "Tipo de caso inválido!" << endl;
            break;
    }
}

int main() {
    int n, caseType, repetitions, algorithmChoice;

    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    cout << "Escolha a situação do vetor (1: Melhor caso, 2: Pior caso, 3: Aleatório): ";
    cin >> caseType;
    cout << "Digite o número de repetições: ";
    cin >> repetitions;

    vector<int> arr;
    generateVector(arr, n, caseType);

    cout << "\nEscolha o algoritmo de ordenacão: \n";
    cout << "1. Inserção Direta\n";
    cout << "2. Shellsort\n";
    cout << "3. BubbleSort\n";
    cout << "4. QuickSort\n";
    cout << "5. Seleção Direta\n";
    cout << "6. Heapsort\n";
    cout << "7. MergeSort\n";
    cout << "Escolha uma opcão (1-7): ";
    cin >> algorithmChoice;

    double totalTime = 0;

    
    for (int i = 0; i < repetitions; i++) {
        vector<int> arrCopy = arr;  // Copia o vetor original p/ preservar os dados

        clock_t start = clock();

        switch (algorithmChoice) {
            case 1:
                insertionSort(arrCopy);
                break;
            case 2:
                shellSort(arrCopy);
                break;
            case 3:
                bubbleSort(arrCopy);
                break;
            case 4:
                quickSort(arrCopy, 0, n - 1);
                break;
            case 5:
                selectionSort(arrCopy);
                break;
            case 6:
                heapSort(arrCopy);
                break;
            case 7:
                mergeSort(arrCopy, 0, n - 1);
                break;
            default:
                cout << "Algoritmo inválido!" << endl;
                return 1;
        }

        clock_t end = clock();
        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    // Média do tempo
    double averageTime = totalTime / repetitions;
    cout << "Tempo médio de execução: " << averageTime << " segundos." << endl;

    return 0;
}
