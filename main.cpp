#include <iostream>

#define BRANCH_LIMIT 50

using namespace std;

#include "queue.c"


void rule_one(string, CQueue*);
void rule_two(string, CQueue*);
void rule_three(string, CQueue*);
void rule_four(string, CQueue*);
void generate(CQueue*);
void is_mu(string);

int main(int argc, char const *argv[])
{
	string axiom = "MI";

	CQueue* Theorems = new CQueue; 

	Theorems->enqueue(axiom);

	generate(Theorems);

	return 0;
}


void is_mu(string word){
	if (word.length() == 2 and word[1] == 'U')
	{
		cout << "MU encontrado" << word << endl;
		exit(0);
	}
}


void generate(CQueue* Theorems){

	string root = Theorems->dequeue();

	while (root[0] != '0'){

		cout << root << endl;

		is_mu(root);


		rule_one(root, Theorems);
		rule_three(root, Theorems);
		rule_four(root, Theorems);
		rule_two(root, Theorems);

		root = Theorems->dequeue();
	}
}

void rule_one(string word, CQueue* Theorems){
	
	int n = word.length()-1;

	if (word[n] == 'I') {
		word += 'U';
	} else
		return;

	Theorems->enqueue(word);

}

void rule_two( string word, CQueue* Theorems){
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

	Theorems->enqueue(word);
}

void rule_three(string word, CQueue* Theorems){
	
	int j;

	for (int i = 0; i < word.length() - 2; i++)
	{
		for (j = 0; j < 3; ++j)
			if (word[i + j] != 'I') break;

		if (j == 3) {
			string tmp = word;
			tmp.erase(i, 2);
			tmp[i] = 'U';
			Theorems->enqueue(word);
		}

	}

}

void rule_four(string word, CQueue* Theorems){

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

				Theorems->enqueue(word);
				old = neww;
			}
		}

	}

}