#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

void main() {
	string str;
	TStack <char> s(20);
	int flag = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push('(');
		if (str[i] == ')') {
			if (s.IsEmpty() == 1) {
				flag = 0;
				break;
			}
			else { s.pop(); }
		}if (flag) {
			if (s.IsEmpty() == 0) flag = 0;
		}
	}
}