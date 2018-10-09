#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;
using namespace std;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
	unordered_map<char, int> letterCount;

	for (int i = 0; i < magazine_text.length(); i++)
	{
		if (!letterCount.count(magazine_text[i]))
		{
			letterCount[magazine_text[i]] = 1;
		}
		else
		{
			letterCount[magazine_text[i]]++;
		}
	}

	for (int i = 0; i < letter_text.length(); i++)
	{
		if (!letterCount.count(letter_text[i]))
		{
			return false;
		}

		letterCount[letter_text[i]]--;
		if (letterCount[letter_text[i]] < 0)
		{
			return false;
		}
	}

  // TODO - you fill in here.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  return GenericTestMain(args, "is_anonymous_letter_constructible.cc",
                         "is_anonymous_letter_constructible.tsv",
                         &IsLetterConstructibleFromMagazine,
                         DefaultComparator{}, param_names);
}
