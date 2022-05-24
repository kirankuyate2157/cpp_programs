public class heapSorting {
    void heapify(int arr[], int i, int n) {
        int largest = i;
        if ((2 * i + 1) < n && arr[2 * i + 1] > arr[largest]) {
            largest = (2 * i + 1);
        }
        if ((2 * i + 2) < n && arr[2 * i + 2] > arr[largest]) {
            largest = (2 * i + 2);
        }
        if (largest != i) {
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            heapify(arr, largest, n);
        }

    }

    void heapSort(int arr[], int n) {
        for (int i = (n - 1) / 2; i >= 0; i--) {
            heapify(arr, i, n);
        }
        for (int i = 0; i < n; i++) {
            int temp = arr[0];
            arr[0] = arr[n - i - 1];
            arr[n - i - 1] = temp;
            heapify(arr, 0, n - i - 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 3, 7, 2, 85, 12, 4, 23, 1, 9, 33, 24, 67, 222 };
        int n = 13;
        heapSorting ob = new heapSorting();

        ob.heapSort(arr, n);
        for (int x : arr) {
            System.out.print(x + " ");
        }
    }

}