#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;

	bool arr[2][n];

	memset(arr,0,8*n);

	set<pair<int,int>> blocker;

	int blocked = 0;

	for(int i = 0; i <n ; i++){
		int x,y;
		cin>>y>>x;
		y--,x--;

		if(arr[y][x]){
			set<pair<int,int>>::iterator it;

			it = blocker.find({y,x});

			if(it!=blocker.end()){
				blocker.erase(it);
				blocked--;
			}
		}else{

			if(y-1>=0&&x-1>=0&&arr[y-1][x-1]){
				blocker.insert({y,x});
				blocked++;
			}else if(y-1>=0&&x+1<n&&arr[y-1][x+1]){
				blocker.insert({y,x});
				blocked++;
			}else if(y-1>=0&&arr[y-1][x]){
				blocker.insert({y,x});
				blocked++;
			}


			if((x-1>=0)&&(y+1<=1)&&arr[y+1][x-1]){
				blocker.insert({y,x});
				blocked++;
			}else if(x+1<n&&y+1<=1&&arr[y+1][x+1]){
				blocker.insert({y,x});
				blocked++;
			}else if(y+1<n&&arr[y+1][x]){
				blocker.insert({y,x});
				blocked++;
			}
		}

		arr[y][x] = !arr[y][x];

		if(blocked){
			cout<<"No";
		}else{
			cout<<"Yes";
		}
		cout<<endl;
	}
}