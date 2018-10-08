#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
  // TODO - you fill in here.
	int L = 0;
	int R = A.size() - 1;
	int first = A.size();

	while (L <= R)
	{
		int M = L + (R - L)/2;

		if (A[M] == k)
		{
			if (M < first)
			{
				first = M;
			}
			// treat like a k < A[M] case
			R = M - 1;
		}
		else if (k < A[M])
		{
			R = M - 1;
		}
		else
		{
			L = M + 1;
		}
	}

	if (first == A.size())
	{
		return -1;
	}

	return first;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
