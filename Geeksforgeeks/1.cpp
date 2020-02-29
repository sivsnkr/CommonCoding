#include<bits/stdc++.h>

using namespace std;

void bfs(vector<int> &numbers,int m){
	queue<int> q;

	int i;
	for(i = 0; i < numbers.size(); i++){
		q.push(numbers[i]);
	}

	q.pop();

	int number;
	char a;

	int counter = 0;

	while(!q.empty()){
		int top = q.front();

		// cout<<"top "<<top<<endl;
		q.pop();

		int lastIndex = top%10;

		if(lastIndex+1 < 10){
			a = lastIndex+1+48;
			string n = to_string(top)+a;
			number = stoi(n);
			// cout<<"string "<<n<<endl;
			if(number <= m){
				q.push(number);
				cout<<number<<" ";
			}
		}

		if(lastIndex-1 >= 0){
			lastIndex--;
			a = lastIndex+48;
			string n = to_string(top)+a;
			// cout<<"string "<<n<<endl;
			number = stoi(n);
			if(number <= m){
				q.push(number);
				cout<<number<<" ";
			}
		}
		// counter++;
		// if(counter>10)
		// 	break;
	}

	cout<<endl;
}
int main(){
	int n,m;
	cin>>n>>m;

	int number = 0;

	vector<int> numbers;

	while(number <= 9 && number <= m){
		numbers.push_back(number);
		number++;
	}

	for(int i = n; i < numbers.size(); i++){
		cout<<numbers[i]<<" ";
	}

	// print all the numbers added till now

	bfs(numbers,m);
}