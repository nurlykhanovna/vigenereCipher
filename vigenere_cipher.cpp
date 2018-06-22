//Alima Seytkhan CSSE 0907r
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

string keyw, msg, encr = "", decr = "";

//checking for repeating letter in keyword
bool check(string s){
	for (int i = 0; i < s.length() - 1; i++){
		for (int j = i+1; j < s.length(); j++){
			if (s[i] == s[j])	return false;
		} s[i] = tolower(s[i]);
	}
	return true;
}

char encrypt (char m, char k){
	int c;
	c = m - 'a';
	if (('z' - k) >= c){
		return c + k;
	} return ('a' + (c - ('z' - k) - 1));
}

char decrypt (char m, char k){
	if (m >= k)
		return (m - (k - 'a')); 
		else return 'a' + ('z' - k + 1) + (m - 'a');
}

int main(){
	cout<<"Input keyword: \n";
	cin>>keyw;
	if (!check(keyw)){
		cout<<"Letters cannot be repeated in keyword!\n";
	} else {
		cout<<"Input message: \n";
		cin>>msg;
		int ii = 0;
		for (int i = 0; i < msg.length(); i++){
			if (ii == keyw.length()) ii = 0;
			msg[i] = tolower(msg[i]);
			if (msg[i] >= 'a' && msg[i] <= 'z'){
				encr += encrypt(msg[i], keyw[ii]);
				decr += decrypt(msg[i], keyw[ii]);
			} else {
				encr += msg[i];
				decr += msg[i];
			}
			ii++;
		}
		cout<<"Encrypted message: "<<encr<<"\n";
		cout<<"Decrypted message: "<<decr<<"\n";
	}
	getch();
}
