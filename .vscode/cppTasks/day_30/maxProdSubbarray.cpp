#include <bits/stdc++.h>
using namespace std;

int maxProdSub(int arr[], int n)
{
    int total = arr[0];
    int min_sub = arr[0];
    int max_sub = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = max_sub;
        max_sub = max({arr[i], arr[i] * max_sub, arr[i] * min_sub});
        // cout << max_sub << " =  max ( " << arr[i] << " ," << arr[i] * temp << " ," << arr[i] * min_sub << ")\t";
        // long long temp2=min_sub;
        min_sub = min({arr[i], arr[i] * temp, arr[i] * min_sub});
        // cout << min_sub << " =  min ( " << arr[i] << " ," << arr[i] * temp << " ," << arr[i] * temp2 << ") \n";
        total = max(total, max_sub);
        // cout<<"total : "<<total<<"\n";
    }
    return total;
}


int maxSubarrayProduct(int arr[], int n)
{
	int max_ending_here = 1;
	int min_ending_here = 1;
	// Initialize overall max product
	int max_so_far = 0;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			max_ending_here = max_ending_here * arr[i];
			min_ending_here
				= min(min_ending_here * arr[i], 1);
			flag = 1;
		}
		else if (arr[i] == 0) {
			max_ending_here = 1;
			min_ending_here = 1;
		}
		else {
			int temp = max_ending_here;
			max_ending_here
				= max(min_ending_here * arr[i], 1);
			min_ending_here = temp * arr[i];
		}

		// update max_so_far, if needed
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	if (flag == 0 && max_so_far == 0)
		return 0;
	return max_so_far;
}


int main()
{
    int arr[] = {2, 3, 4, 5, -1, 0};
    int n = sizeof(arr) / sizeof(int);
    // cout << maxProdSub(arr, n);
    printf("Maximum Sub array product is %d",
		maxSubarrayProduct(arr, n));

    return 0;
}