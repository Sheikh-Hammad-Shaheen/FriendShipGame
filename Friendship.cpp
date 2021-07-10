#include<iostream>
using namespace std;
void input(bool arr[][5], int row, int col);
void display(bool arr[][5], int row, int col,char r,char c);
void change_type(char ch,int &n);
void int_to_char(char &ch3,int i);
void p_count(bool arr[][5], int row, int col);
bool common_check(bool arr[][5],int r,int c,int i );
int main(){
	const int row = 5, col = 5;
	bool arr[row][col];
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			arr[i][j] = false;
		}
	}
	input(arr, 5, 5);
	p_count(arr, 5, 5);
}
void input(bool arr[][5], int row, int col){
	bool check=false;
	char ch1,ch2,ch3;
	int r=0,c=0,cnt=0;
	char option;
	while(true){
		while(true){
			cout<<"Choose A/B/C/D/E for friendship:  ";
			cin>>ch1;
			change_type(ch1,r);
			if(ch1>='A'&&ch1<='E' ||ch1>='a'&&ch1<='e'){
				cout<<"Choose a pair from A/B/C/D/E to make friendship with '"<<ch1<<"': ";
				cin>>ch2;
				while(true){
					if(ch2>='A'&&ch2<='E' ||ch2>='a'&&ch2<='e'){
						change_type(ch2,c);
						if(arr[r][c]==true)
						cout<<"Friendship pair Already Exist."<<endl<<endl;
						display(arr, 5, 5,r,c);
						break;
					}
					else{			
							cout<<"You Press a wrong Key please Enter Again: ";
							cin>>ch2;	
					}
				}
				break;
			}
			else{
				cout<<"You Press a wrong Key please Enter Again: "<<endl<<endl;
			}
		}
		cout<<"Press 1 to make more pairs or any key to Exit: ";
		cin>>option;
		if(option!='1')
		break;
	}
	while(true){
		cout<<endl<<"To check common relation choose A/B/C/D/E: ";
		cin>>ch1;
		change_type(ch1,r);
		if(ch1>='A'&&ch1<='E' ||ch1>='a'&&ch1<='e'){
			while(true){
				cout<<"choose A/B/C/D/E To find common friend with "<<ch1<<": ";
				cin>>ch2;
				if(ch1>='A'&&ch1<='E' ||ch1>='a'&&ch1<='e'){
					for(int i=0;i<col;i++){
						check=common_check(arr,c,r,i);
						if(check==true){
							int_to_char(ch3,i);
							cout<<endl<<"Common Friend b/w "<<ch1<<" and "<<ch2<<" is: "<<ch3;
							cnt++;
						}
					}
					if(cnt==0)
					cout<<endl<<"There is no common Friend b/w "<<ch1<<" and "<<ch2;
					break;
				}
				else
				cout<<endl<<"You choose wrong option Enter again."<<endl<<endl;
			}
			break;
		}
		else
		cout<<endl<<"You choose wrong option Enter again."<<endl<<endl;	
	}
}
void display(bool arr[][5], int row, int col,char r,char c){
	char dis[5][5];
	if(r==c){
		cout<<"friendship pair can't be made"<<endl<<endl; 
	}
	else{
		arr[r][c]=1;
		arr[c][r]=1;
	}
	char ch='A';
	cout << "   ";
	for (int i = 0; i<row; i++){
		cout << ch << " ";
		ch++;
	}
	cout << endl;
	ch='A';

	for (int i = 0; i<row; i++){
		cout << ch << "  ";
		for (int j = 0; j<col; j++){
			if(arr[i][j]==0){
				dis[i][j]=' ';
				cout << dis[i][j] <<" ";
			}
			else{
				dis[i][j]='*';
				dis[j][i]='*';
				cout << dis[i][j] <<" ";
			}		
		}
		ch++;
		cout << endl;
	}
}
void change_type(char ch,int &n){
	if(ch=='A'||ch=='a')
	n=0;
	else if(ch=='B'||ch=='b')
	n=1;
	else if(ch=='C'||ch=='c')
	n=2;
	else if(ch=='D'||ch=='d')
	n=3;
	else
	n=4;
}
void p_count(bool arr[][5], int row, int col){
	int count = 0;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (arr[i][j] == 1){
				count++;
			}
		}
	}
	count=count/2;
	cout << endl <<"Total Friendship pairs are: "<< count;
}
void int_to_char(char &ch3,int i){
	if(i==0)
	ch3='A';
	else if(i==1)
	ch3='B';
	else if(i==2)
	ch3='C';
	else if(i==3)
	ch3='D';
	else
	ch3='E';
}
bool common_check(bool arr[][5],int r,int c,int i ){
	if(arr[r][i]==true && arr[c][i]==true)
	return true;
	
	return false;
}
