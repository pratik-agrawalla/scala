#include<bits/stdc++.h>

using namespace std;

int isKeyword(char buffer[]){
    char keywords[16][10] = {"case","class","def","do","else","for","if","import","main",
                            "object","println","readInt","readLine","val","var","while"};
    int flag = 0;
    for(int i = 0; i < 15; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int isDataType(char buffer[]){
    char types[10][8] = {"Bool","Double","Float","Int",
				 						   "Long","String","Unit","val","var"};
    int flag = 0;
    for(int i = 0; i < 9; ++i){
        if(strcmp(types[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int ispara(char c){
    char types[6] = {'(',')','{','}','[',']'};
    int flag = 0;
    for(int i = 0; i < 9; ++i){
        if(types[i] == c){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    char ch, buffer[15], operators[] = "+-*/%=";
    ifstream fin("program.txt");   
    if(!fin){
        cout<<"error while opening the file\n";
        exit(0);
    }
    int j = 0;
    while(!fin.eof()){
        ch = fin.get();
        for(int i = 0; i < 6; ++i){
               if(ch == operators[i])
                   cout<<ch<<" is operator\n";
        }
        if(isalnum(ch)){
          buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n' || ispara(ch)) && (j != 0)){
            buffer[j] = '\0';
            j = 0;                          
            if(isKeyword(buffer) == 1)
              cout<<buffer<<" is a keyword\n";
            else if(isDataType(buffer) == 1)
                cout<<buffer<<" is a datatype\n";
            else
                cout<<buffer<<" is a indentifier\n";
        }   
    }
    fin.close();
    return 0;
}
