#include <iostream>
#include <stack>

using namespace std;

int main(){
<<<<<<< HEAD
	stack <pair<int,char> > s;
	string g;
	int k=-1;
	getline(cin,g);
	if (g.length()==1) cout<<1<<"\n";
	else{
	for (int i=0;i<g.length();++i){
		if (g[i]=='(' || g[i]=='{' || g[i] == '['){
			s.push(make_pair(i,g[i]));
		}

		if (g[i]==')' || g[i]=='}' || g[i] == ']'){	
			if (!s.empty()){
				if (g[i]==')' && s.top().second=='('){
					s.pop();
				}

				else if (g[i]=='}' && s.top().second=='{'){
					s.pop();
				}

				else if (g[i]==']' && s.top().second=='['){
					s.pop();
				}

				else {
					k=i+1;
					//error occured due to closing bracket
					cout<<k<<"\n";
					return 0;
				}
			}

			else{
				k=i+1;
				cout<<k<<"\n";
				return 0;
			}
		}

		
	}
	int c;
	//if (k) 
	//else{
		if (s.empty()) cout<<"Success";
		else{
			while(!s.empty()){
				c = s.top().first;
				s.pop();
			}

			cout<<c+1<<"\n";
		}
	}

=======
	stack <char> s;
	string g;
	int ans,k=1;
	getline(cin,g);

	for (int i=0;i<g.length();++i){
		if (g[i]=='(' || g[i]=='{' || g[i] == '['){
			s.push(g[i]);
		}

		else if (g[i]==')'){
			if (s.top()=='('){
				s.pop();
				if (s.empty()) k=i+1; 
			}

		}

		else if (g[i]=='}'){
			if (s.top()=='{'){
				s.pop();
				if (s.empty()) k=i+1;
			}
		}

		else if (g[i]==']'){
			if (s.top()=='[') {
				s.pop();
				if (s.empty()) k=i+1;
			}
		}

		//else{
		//	if (g[i]=='(' || g[i]=='{' || g[i]=='[' || g[i]=='}' || g[i]==']' || g[i] == ')') ans = i+1;
		//}
	}


	if (s.empty()) cout<<"SUCCESS";
	else cout<<k<<"\n";

>>>>>>> 5f7c2547daacf5ab8011f05f9e5f9a14a79e1bdf
	return 0;
}