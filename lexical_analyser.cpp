#include <bits/stdc++.h>
using namespace std;

bool checkIdentifier(string lexeme)
{
    return regex_match(lexeme, regex("[a-zA-Z][a-zA-Z0-9]*"));
}
bool checkNumber(string lexeme)
{
    return regex_match(lexeme, regex("[0-9]+"));
}

int main()
{
    ifstream t("input.txt");
    freopen("output.txt", "w", stdout);

    stringstream buffer;
    buffer << t.rdbuf();

    string input = buffer.str();

    unordered_map<string, string> tokens = {
        {"int", "keyword"},
        {"main", "keyword"},
        {"begin", "keyword"},
        {"for", "keyword"},
        {"if", "keyword"},
        {"endif", "keyword"},
        {"endfor", "keyword"},
        {"return", "keyword"},
        {"End", "keyword"},
        {"do", "keyword"},
        {"to", "keyword"},
        {"(", "popen"},
        {")", "pclose"},
        {";", "semicolon"},
        {"=", "operator"},
        {"-", "operator"},
        {">", "relop"},
        {"[","sopen"},  
        {"]","sclose"},
        };

    int len = input.length();

    string lexeme = "";
    string temp="+-=/()[]";

    for (int i = 0; i < len; ++i)
    {

        if (temp.find(input[i])!=string::npos || input[i]=='\n' || input[i]=='\t' || input[i]==' ')
        {
            if (lexeme.length() == 0)
                continue;

            if (tokens.find(lexeme) != tokens.end())
            {
                cout << lexeme << " " << tokens[lexeme] << endl;
            }
            else
            {
                if(checkIdentifier(lexeme))  cout<<lexeme<<" identifier"<<endl;
                else if(checkNumber(lexeme)) cout<<lexeme<<" number"<<endl;
            }
            string t;
            t.push_back(input[i]);
            if(temp.find(input[i])!=string::npos) cout<<input[i] <<" "<< tokens[t] <<endl;
            lexeme="";
        }
        else
        {
            lexeme.push_back(input[i]);
        }
    }

    return 0;
}