#include <vector>
#include <iostream>
#include "test_framework/generic_test.h"
using std::vector;
using namespace std;

void prntArray(vector<int> A)
{
	cout << "\nSorted: ";
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
}

void swap(vector<int>& A, int a, int b)
{
	//cout << "a: "<< a << " b: " << b << "\n";
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}

int partition(vector<int>& A, int start, int end)
{
	int pivot = A[end - 1];
	int i = start;

	while (start < end - 1)
	{
		if (A[start] <= pivot)
		{
			swap(A, i, start);
			i++;
			start++;
		}
		else
		{
			start++;
		}
	}
	swap(A, i, end - 1);
	return i;
}

void quicksort(vector<int>& A, int start, int end)
{
	if (start < end)
	{
		int p = partition(A, start, end);
		quicksort(A, start, p);
		quicksort(A, p + 1, end);
	}
}

bool HasThreeSum(vector<int> A, int t) {
  // TODO - you fill in here.
	//prntArray(A);

	quicksort(A, 0, A.size());

	//prntArray(A);

	for (int i = 0; i < A.size(); i++)
	{
		int j = i;
		int k = A.size() - 1;

		while (j <= k)
		{
			//cout << i << " " << j << " " << k << "\n";
			//cout << A[i] << " " << A[j] << " " << A[k] << "\n";

			if (A[j] + A[k] < t - A[i])
			{
				j++;
			}
			else if (A[j] + A[k] > t - A[i])
			{
				k--;
			}
			else
			{
				return true;
			}
		}
	}

  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.cc", "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
