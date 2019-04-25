#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	multiset<string> words;
	set<string> words_unique;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		char unwanted_chars[4] = {',', '!', '.', '?'};
		for (int j = 0; j < strlen(unwanted_chars); j++) {
			if (temp.back() == unwanted_chars[j]) {
				temp.erase(temp.length()-1);
			}
		}
		words_unique.insert(temp);
		words.insert(temp);
	}
	for (auto a : words_unique) cout << a << " " << words.count(a) << endl;
}