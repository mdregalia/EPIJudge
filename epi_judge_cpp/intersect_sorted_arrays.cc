#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

bool binarysearch(const vector<int>& A, int t)
{
	int L = 0;
	int R = A.size() - 1;
	while (L <= R)
	{
		int M = L + (R - L)/2;
		if (A[M] == t)
		{
			return true;
		}
		if (t > A[M])
		{
			L = M + 1;
		}
		else if (t < A[M])
		{
			R = M - 1;
		}

	}

	return false;
}

vector<int> matchUnevenArrays(const vector<int> smaller, const vector<int> bigger)
{
	vector<int> intersection;
	for (int i = 0; i < smaller.size(); i++)
	{
		if (binarysearch(bigger, smaller[i]))
		{
			intersection.push_back(smaller[i]);
		}

		while (i < smaller.size() - 1 && smaller[i] == smaller[i + 1])
		{
			i++;
		}
	}

	return intersection;
}

vector<int> matchCloseArrays(const vector<int> A, const vector<int> B)
{
	vector<int> intersection;
	int i = 0;
	int j = 0;
	while (i < A.size() && j < B.size())
	{
		if (A[i] < B[j])
		{
			i++;
		}
		else if (B[j] < A[i])
		{
			j++;
		}
		else if (A[i] == B[j])
		{
			int common = A[i];
			intersection.push_back(common);

			while (A[i] == common && i < A.size())
			{
				i++;
			}

			while(B[j] == common && j < B.size())
			{
				j++;
			}
		}
	}

	return intersection;
}

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  // TODO - you fill in here.
	if (A.size() > B.size()*5)
	{
		return matchUnevenArrays(A, B);
	}
	else if (B.size() > A.size()*5)
	{
		return matchUnevenArrays(B, A);
	}
	else //close in size
	{
		return matchCloseArrays(A, B);
	}
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
