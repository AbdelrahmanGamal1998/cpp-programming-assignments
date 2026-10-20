#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string encrypt(string str, int key){
    for(int i = 0; i < str.size(); ++i)
        if(str[i] != ' ')
            str[i] += key;
    return str;
}
string decrypt(string str, int key){
    for(int i = 0; i < str.size(); ++i)
        if(str[i] != ' ')
            str[i] -= key;
    return str;
}
string compress(string str){
    string res = "";
    res += str[0];
    for(int i = 1; i < str.size(); ++i){
        int counter = 1;
        while(i < str.size() && str[i] == str[i-1])
            ++counter, ++i;
        res += counter+'0';
        if(i != str.size())
            res += str[i];
        if(i == str.size()-1 && counter == 1)
            res += '1';
    }
    return res;
}
string decompress(string str){
    string res = "";
    stringstream ss;
    ss << str;
    char c;
    int cnt;
    while(ss >> c >> cnt){
        while(cnt--){
            res += c;
        }
    }
    return res;
}
int main(){
    int repeat;
    do{
        int choice;
        // 1-encrypt 2-decrypt 3-compress 4-decompress
        cout<< "press 1 to encrypt, 2 to decrypt, 3 to compress, 4 to decompress" << endl;
        cin >> choice;
        string s;
        int key;
        switch(choice){
        case 1:
            cin >> s >> key;
            cout << encrypt(s, key) << endl;
            break;
        case 2:
            cin >> s >> key;
            cout << decrypt(s, key) << endl;
            break;
        case 3:
            cin >> s;
            cout << compress(s) << endl;
            break;
        case 4:
            cin >> s;
            cout << decompress(s) << endl;
            break;
        default:
            cout << "wrong choice!!" << endl;
        }
        cout << "do you want to make another operation? [1 = YES / 0 = NO]" << endl;
        cin >> repeat;

    }while(repeat);
    return 0;
}
