#include <iostream>
#include <cctype>
using namespace std;
#include <string>
#include <algorithm>


void reveseString(string &s){
    int st = 0;
    int end = s.length() - 1;

    while(st < end){
        swap(s[st] , s[end]);
        st++;
        end--;
    }
}


bool palimdrom(string &s){
    int end = s.length() - 1;
    int st = 0;


    while(st < end){

        if(s[st] != s[end]){
            return false;
        }
        st++;
        end--;
    }

    return true;
}


int main(){

    char ch = 'a';
    cout <<  (int)ch << endl;

    cout << (char)tolower(ch) << endl;


    char st1[] = "Hellow";
    cout << st1 << endl;

    char st2[7] = {'h', 'e', 'l', 'l', 'o', '\0'};
    cout << st2 << endl;
     


    // for string library  std::string

    string s = "leetcode";
    cout << s.length() << endl;
   
     s.push_back('r');
    cout << "String : " <<  s << endl;

    s.pop_back();
    cout << "String : " <<  s << endl;

   string sub =  s.substr(0, 4); // s.sunstr(strting_index , length) // index start and how many characters take -> leet
    cout << "String : " <<  sub << endl;

    string sub2 =  s.substr(1, 4); // -> eetc


    cout << s.find(sub) << endl;

   sort(s.begin() , s.end());
   cout << "String : " <<  s << endl;


   // reverse a string using two pointer
   string str = "code";
   reveseString(str);
   cout << str << endl;

   // palimdrom number
   cout << palimdrom(str) << endl;

    return 0;
}