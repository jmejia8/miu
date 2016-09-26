#include <iostream>

#define BRANCH_LIMIT 20

using namespace std;



void rule_one(string);
void rule_two(string);
void rule_three(string);
void rule_four(string);
void generate(string );
void is_mu(string);

int main(int argc, char const *argv[])
{
	string axiom = "MI";

	cout << axiom << endl;

	generate(axiom);

	return 0;
}

void is_mu(string word){
	if (word.length() == 2 and word[1] == 'U')
	{
		cout << "MU encontrado" << word << endl;
		exit(0);
	}
}


void generate(string axiom){
	rule_one(axiom);
	rule_three(axiom);
	rule_four(axiom);
	rule_two(axiom);
}

void rule_one(string word){

	is_mu(word);
	
	int n = word.length()-1;

	if (word[n] == 'I') {
		word += 'U';
	} else
		return;

	
	cout << word << endl;

	generate(word);

}

void rule_two( string word){
	if (word[0] == 'M')
	{
		word.erase( word.begin() );
		word += word;
		word = 'M' + word;
	} else
		return;

	if (word.length() > BRANCH_LIMIT)
	{
		return;
	}

	cout << word << endl;
	
	is_mu(word);

	generate(word);
}

void rule_three(string word){
	
	int j;

	for (int i = 0; i < word.length() - 2; i++)
	{
		for (j = 0; j < 3; ++j)
			if (word[i + j] != 'I') break;

		if (j == 3) {
			string tmp = word;
			tmp.erase(i, 2);
			tmp[i] = 'U';
			
			cout << tmp << endl;

			is_mu(tmp);

			generate(tmp);
		}

	}

}

void rule_four(string word){

	int j;
	string old = word, neww;

	for (int i = 0; i < word.length() - 1; i++)
	{
		for (j = 0; j < 2; ++j)
			if (word[i + j] != 'U') break;

		if (j == 2) {
			neww = word;
			neww.erase(i, 1);
			if (old.compare(neww) != 0){

				cout << neww << endl;

				is_mu(neww);
				generate(neww);
				old = neww;
			}
		}

	}


	if (old.compare(word) == 1)
	{
		return;
	}

}