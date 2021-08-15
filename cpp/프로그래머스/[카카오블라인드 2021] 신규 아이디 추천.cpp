/**
*/

#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

string replaceAll(const string &str, const string &pattern, const string &replace) 
{ 
    string result = str; 
    string::size_type pos = 0; 
    string::size_type offset = 0; 
    while((pos = result.find(pattern, offset)) != string::npos)
    { 
        result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
        offset = pos + replace.size();
    } 
    return result;
} 
string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.size(); i++) { 
        if (isupper(new_id[i])) {               //1단계
            new_id[i] = tolower(new_id[i]);
        }
        if (islower(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') { //2단계
            
        }else{
            new_id[i] = ' ';
        }
    }
    new_id = replaceAll(new_id, " ", ""); // 2단계
    while(new_id.find("..") != string::npos){
        new_id = replaceAll(new_id, "..", ".");   //3단계 
    }
    int size = new_id.size();
    if(new_id != "" && new_id[0] == '.'){
        new_id = new_id.substr(1,size - 1);
    }
    size = new_id.size();
    if(new_id != "" && new_id[size - 1] == '.'){
        int size = new_id.size();
        new_id = new_id.substr(0,size - 1);
    }
    
    if(new_id == ""){
        new_id += 'a';
    }
    if(new_id.size() >= 16) {
        new_id = new_id.substr(0,15);
        if(new_id[14] == '.') new_id = new_id.substr(0,14);
    }
    if(new_id.size() <= 2){
        char temp = new_id[new_id.size() - 1];
        while(new_id.size() != 3){
            new_id += temp;
        }
    }
    
    return new_id;
}
