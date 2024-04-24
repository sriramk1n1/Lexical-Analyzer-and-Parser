#include<bits/stdc++.h>

using namespace std;

map<pair<int,string>,pair<int,int>> action = {
    {{0,"int"},{1,0}},{{5,"int"},{11,0}},{{7,"int"},{11,0}},{{8,"int"},{3,1}},{{9,"int"},{4,1}},{{10,"int"},{5,1}},{{26,"int"},{11,0}},{{29,"int"},{6,1}},{{34,"int"},{8,1}},{{35,"int"},{7,1}},
    {{1,"main"},{2,0}},
    {{2,"("},{3,0}},{{12,"("},{17,0}},
    {{3,")"},{4,0}},{{21,")"},{26,0}},{{31,")"},{9,1}},
    {{4,"begin"},{5,0}},
    {{5,"return"},{2,1}},{{6,"return"},{14,0}},{{7,"return"},{2,1}},{{8,"return"},{3,1}},{{9,"return"},{4,1}},{{10,"return"},{5,1}},
    {{15,"return"},{1,1}},
    {{26,"return"},{2,1}},
    {{29,"return"},{6,1}},
    {{34,"return"},{8,1}},
    {{35,"return"},{7,1}},
    {{5,"identifier"},{13,0}},
    {{7,"identifier"},{13,0}},
    {{8,"identifier"},{3,1}},
    {{9,"identifier"},{4,1}},
    {{10,"identifier"},{5,1}},
    {{11,"identifier"},{16,0}},
    {{14,"identifier"},{19,0}},
    {{17,"identifier"},{22,0}},
    {{18,"identifier"},{23,0}},
    {{26,"identifier"},{13,0}},
    {{29,"identifier"},{6,1}},
    {{34,"identifier"},{8,1}},
    {{35,"identifier"},{7,1}},
    {{5,"end"},{2,1}},
    {{7,"end"},{2,1}},
    {{8,"end"},{3,1}},
    {{9,"end"},{4,1}},
    {{10,"end"},{5,1}},
    {{15,"end"},{1,1}},
    {{19,"end"},{24,0}},
    {{26,"end"},{2,1}},
    {{29,"end"},{6,1}},
    {{30,"end"},{33,0}},
    {{34,"end"},{8,1}},
    {{35,"end"},{7,1}},
    {{13,"="},{18,0}},
    {{16,"="},{20,0}},
    {{20,"number"},{25,0}},
    {{27,"number"},{31,0}},
    {{28,"number"},{32,0}},
    {{25,";"},{29,0}},
    {{32,";"},{34,0}},
    {{5,"while"},{12,0}},
    {{7,"while"},{12,0}},
    {{8,"while"},{3,1}},
    {{9,"while"},{4,1}},
    {{10,"while"},{5,1}},
    {{26,"while"},{12,0}},
    {{29,"while"},{6,1}},
    {{33,"while"},{35,0}},
    {{34,"while"},{8,1}},
    {{35,"while"},{7,1}},
    {{23,"operator"},{28,0}},
    {{22,"relop"},{27,0}},
    {{24,"$"},{-1,-1}}
};

map<pair<int,string>,int> go_to = {
    {{5,"STMT"},6},
    {{5,"ST"},7},
    {{5,"DEF"},8},
    {{5,"WL"},9},
    {{5,"EXP"},10},
    {{7,"STMT"},15},
    {{7,"ST"},7},
    {{7,"DEF"},8},
    {{7,"WL"},9},
    {{7,"EXP"},10},
    {{17,"COND"},21},
    {{26,"STMT"},30},
    {{26,"ST"},7},
    {{26,"DEF"},8},
    {{26,"WL"},9},
    {{26,"EXP"},10}
};

unordered_map<int,int> no_of_grammar_sym = {
    {0,9},
    {1,2},
    {2,1},
    {3,1},
    {4,1},
    {5,1},
    {6,5},
    {7,7},
    {8,6},
    {9,3}
};

unordered_map<int,string> g_sym = {
    {0,"P"},
    {1,"STMT"},
    {2,"STMT"},
    {3,"ST"},
    {4,"ST"},
    {5,"ST"},
    {6,"DEF"},
    {7,"WL"},
    {8,"EXP"},
    {9,"COND"}
};


vector<string> splitString(const string& input) {
    vector<string> words;
    istringstream iss(input);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

unordered_map<int,string> grammar = {

{0,"P -> int main ( ) begin STMT return identifier end"},
{1,"STMT -> ST STMT "},
{2,"STMT -> ''"},
{3,"ST -> DEF "},
{4,"ST ->  WL "},
{5,"ST ->  EXP"},
{6,"DEF -> int identifier = number ;"},
{7,"WL -> while ( COND ) STMT end while"},
{8,"EXP -> identifier = identifier operator number ;"},
{9,"COND -> identifier relop number}"}
};


int main(){
    
    string s = "int main ( ) begin int identifier = number ; return identifier end";
    s += " $";
    vector<string> input;
    input = splitString(s);
    stack<int> st;
    st.push(0);
    int i=0;

    while(1){
        string a = input[i];
        int s = st.top();
        // cout << s << " " << a << endl;
        if (action[{s,a}].second==-1){
            cout << "Accepted" << endl;
            break;
        }
        else if (action.find({s,a})!=action.end()) {
            if (action[{s,a}].second==0){
                
                st.push(action[{s,a}].first);
                cout<< "Shift " << a << endl;
                i++;
            }else{
                int no = no_of_grammar_sym[action[{s,a}].first];
                while(no--) st.pop();
                st.push(go_to[{st.top(),g_sym[action[{s,a}].first]}]);
                cout << "Reduce " <<  g_sym[action[{s,a}].first] <<   " : "  << grammar[action[{s,a}].first] << endl;
            }
        }
        else {
            cout << "Error" << endl;
            break;
        }
    }
     
    return 0;
}