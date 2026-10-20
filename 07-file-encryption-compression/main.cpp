#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
int globalKey = 3;
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
struct student {
    string name;
    int id;
    string email;
    int grades[3];
};
int main(){
    //reading file
    string filename;
    cout<< "please input file name:" ; cin >> filename;
    ofstream outFileStream;
    ifstream inFileStream;
    inFileStream.open(filename);
    if(!inFileStream){
        cout << "Error opening file"<<endl;
        return -1;
    }
    string fileContent[13];
    if (inFileStream.is_open()){
        string line;
        int counter = 0;
        while ( getline(inFileStream, line) )
        {
           if(counter >13){
               break;
           }
           fileContent[counter] = line;
           cout<<fileContent[counter]<<endl;
           counter++;
        }
        inFileStream.close();
    }
    //end of reading file to file content array

    //prompting the user to encrypt or decrypt
    string fileContentEncrypted[13];
    int choice;
    cout<<"1.encrypt file \n2.decrypt file"<<endl;
    cin>>choice;
    switch (choice) {
    case 1:
        for (int i = 0; i < 13; ++i) {
            fileContentEncrypted[i] = encrypt(fileContent[i], globalKey);
        }
        outFileStream.open("encryptedFile.txt");
        for (int i = 0; i < 13; ++i) {
            if(i % 6 == 0 && i > 0){
                outFileStream<<"\n";
            }
            outFileStream<<fileContentEncrypted[i]<<endl;
        }
        cout<<"file encrypted to encryptedFile.txt"<<endl;
        break;
    case 2:
        for (int i = 0; i < 13; ++i) {
            fileContent[i] = decrypt(fileContent[i], globalKey);
        }
        outFileStream.open("decryptedFile.txt");
        for (int i = 0; i < 13; ++i) {
            if(i % 6 == 0 && i > 0){
                outFileStream<<"\n";
            }
            outFileStream<<fileContent[i]<<endl;
        }
        cout<<"file decrypted to decryptedFile.txt"<<endl;
        break;
    default:
        cout<<"wrong choice"<<endl;
        break;
    }
    return 0;
}
