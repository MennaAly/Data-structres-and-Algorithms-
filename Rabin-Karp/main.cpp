#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define d 256
#define q 101

int getCharValue(char Char,int m){
    return (int)Char*pow(d,m);
}

int hashFunc(string substring,char newChar, char oldChar,int oldValue){
    int hashValue = oldValue ;
    if(newChar == ' '){
        for(int i = 0 ; i < substring.length();i++){
            hashValue += getCharValue(substring[i] , substring.length()-(i+1));
        }
    }
    else{
        hashValue = ((hashValue-getCharValue(oldChar,substring.length()-1))*d)+getCharValue(newChar , 0);
    }
    if(hashValue % q < 0)return (hashValue%q)+q;
    else return hashValue%q;
}

bool Compare(string substring , string wordSubString){
   for(int i = 0 ; i < substring.length();i++){
       if(substring[i]  != wordSubString[i]) return false;
   }    
   return true;
}

void rabin_karb(string word , string substring){
    // calculate the substring hash value
    int subStringValue = hashFunc(substring,' ',' ',0);
    // calculate the first window of the string hash value
    int wordSubStringValue = hashFunc(word.substr(0,substring.length()),' ',' ',0);
    int beginIndex = 0 , numOfChar = substring.length();
    while(beginIndex <=  word.length() - numOfChar){
        if(subStringValue == wordSubStringValue){
            Compare(substring , word.substr(beginIndex,numOfChar)) ? 
                    cout<<"the index is "<<beginIndex<<endl : cout<<"";
        }
     wordSubStringValue = hashFunc(word.substr(beginIndex+1,numOfChar),word[beginIndex+numOfChar],word[beginIndex],
                                    wordSubStringValue);
     beginIndex++;
    }
    
}
int main(int argc, char **argv)
{
    
    string word, substring;
    cin>>word>>substring;
    rabin_karb(word,substring);
    
	return 0;
}
