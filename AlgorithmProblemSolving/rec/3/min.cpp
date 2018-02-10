// CPP program to find Distance between
// two closest minimum
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// function to find Distance between
// two closest minimum
int findClosestMin(int arr[], int n)
{
	int min = INT_MAX;

	// find the min element in the array
	for (int i = 0; i < n; i++)
		if (arr[i] < min)
			min = arr[i];

	// vector to store indexes of occurrences
	// of minimum element in the array
	vector<int> indexes;

	// store indexes of occurrences
	// of minimum element in the array
	for (int i = 0; i < n; i++)
		if (arr[i] == min)
			indexes.push_back(i);

	// if minimum element doesnot occurs atleast
	// two times, return -1.
	if (indexes.size() < 2)
		return -1;

	int min_dist = INT_MAX;

	// calculate minimum difference between
	// any two consecutive indexes
	for (int i = 1; i < indexes.size(); i++) 
		if ((indexes[i] - indexes[i - 1]) < min_dist)
			min_dist = (indexes[i] - indexes[i - 1]);

	return min_dist;
}

// Driver code
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin >> arr[i];
	}
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << findClosestMin(arr, size);
	return 0;
}