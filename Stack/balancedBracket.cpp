#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack <char> s;
	string g;
	getline(cin,g);

	for (int i=0;i<g.length();++i){
		if (g[i]=='(' || g[i]=='{' || g[i] == '[')
			s.push(g[i]);

		else if (g[i]==')'){
			if (s.top()=='(') s.pop();
		}

		else if (g[i]=='}'){
			if (s.top()=='{') s.pop();
		}

		else if (g[i]==']'){
			if (s.top()=='[') s.pop();
		}
		
	}

	if (s.empty()) cout<<"Balanced\n";
	else cout<<"Unbalanced\n";

	return 0;
}