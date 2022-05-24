public class shellSorting {

    static void shellSort(int arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                for (int j = i - gap; j >= 0; j -= gap) {
                    if (arr[j] < arr[j + gap]) {
                        break;
                    } else {
                        int temp = arr[j + gap];
                        arr[j + gap] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = { 2, 6, 23, 67, 32, 12, 67, 1, 4, 6, 12, 67, 32, 11 };
        int n = arr.length;
        shellSort(arr, n);
        for (int x : arr)
            System.out.print(x + " ");
    }
}
