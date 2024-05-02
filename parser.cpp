#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

map<pair<int,string>,pair<int,int>> action = {
    {{0,"datatype"},{2,0}},
    {{6,"datatype"},{9,0}},
    {{8,"datatype"},{9,0}},
    {{19,"datatype"},{14,1}},
    {{20,"datatype"},{10,1}},
    {{21,"datatype"},{11,1}},
    {{24,"datatype"},{5,1}},
    {{34,"datatype"},{7,1}},
    {{36,"datatype"},{9,0}},
    {{37,"datatype"},{14,1}},
    {{41,"datatype"},{4,1}},
    {{45,"datatype"},{12,1}},
    {{46,"datatype"},{13,1}},
    {{48,"datatype"},{6,1}},
    {{50,"datatype"},{9,1}},
    {{51,"datatype"},{9,0}},
    {{53,"datatype"},{8,1}},

    {{2,"main_k"},{3,0}},
    {{3,"popen"},{4,0}},
    {{13,"popen"},{22,0}},
    {{4,"pclose"},{5,0}},
    {{31,"pclose"},{40,0}},
    {{5,"begin_k"},{6,0}},
    
    {{6,"return_k"},{3,1}},
    {{7,"return_k"},{13,0}},
    {{8,"return_k"},{3,1}},
    {{14,"return_k"},{2,1}},
    {{19,"return_k"},{15,1}},
    {{20,"return_k"},{10,1}},
    {{21,"return_k"},{11,1}},
    {{24,"return_k"},{5,1}},
    {{34,"return_k"},{7,1}},
    {{36,"return_k"},{3,1}},
    {{37,"return_k"},{14,1}},
    {{41,"return_k"},{4,1}},
    {{45,"return_k"},{12,1}},
    {{46,"return_k"},{13,1}},
    {{48,"return_k"},{6,1}},
    {{50,"return_k"},{9,1}},
    {{51,"return_k"},{3,1}},
    {{53,"return_k"},{8,1}},

    {{6,"identifier"},{10,0}},
    {{8,"identifier"},{10,0}},
    {{9,"identifier"},{15,0}},
    {{11,"identifier"},{17,0}},
    {{12,"identifier"},{20,0}},
    {{16,"identifier"},{20,0}},
    {{19,"identifier"},{15,1}},
    {{20,"identifier"},{10,1}},
    {{21,"identifier"},{11,1}},
    {{22,"identifier"},{31,0}},
    {{23,"identifier"},{20,0}},
    {{24,"identifier"},{5,1}},
    {{27,"identifier"},{20,0}},
    {{28,"identifier"},{20,0}},
    {{29,"identifier"},{20,0}},
    {{30,"identifier"},{39,0}},
    {{34,"identifier"},{7,1}},
    {{36,"identifier"},{10,0}},
    {{37,"identifier"},{14,1}},
    {{41,"identifier"},{4,1}},
    {{43,"identifier"},{20,0}},
    {{45,"identifier"},{12,1}},
    {{46,"identifier"},{13,1}}, 
    {{48,"identifier"},{6,1}},
    {{50,"identifier"},{9,1}},  
    {{51,"identifier"},{10,0}},
    {{53,"identifier"},{8,1}},
    
    {{40,"End_k"},{47,0}},
    {{10,"assign_op"},{16,0}},
    {{15,"assign_op"},{23,0}},
    {{17,"assign_op"},{27,0}},

    {{15,"semicolon"},{24,0}},
    {{19,"semicolon"},{15,1}},
    {{20,"semicolon"},{10,1}},
    {{21,"semicolon"},{11,1}},
    {{26,"semicolon"},{34,0}},
    {{32,"semicolon"},{41,0}},
    {{37,"semicolon"},{14,1}},
    {{42,"semicolon"},{48,0}},
    {{45,"semicolon"},{12,1}},
    {{46,"semicolon"},{13,1}},

    {{6,"for_k"},{11,0}},
    {{8,"for_k"},{11,0}},
    {{19,"for_k"},{15,1}},
    {{20,"for_k"},{10,1}},
    {{21,"for_k"},{11,1}},
    {{24,"for_k"},{5,1}},

    {{34,"for_k"},{7,1}},
    {{36,"for_k"},{11,0}},
    {{37,"for_k"},{14,1}},
    {{41,"for_k"},{4,1}},
    {{45,"for_k"},{12,1}},
    {{46,"for_k"},{13,1}},
    {{48,"for_k"},{6,1}},
    {{50,"for_k"},{9,1}},
    {{51,"for_k"},{11,0}},
    {{53,"for_k"},{8,1}},

    {{19,"to_k"},{15,1}},
    {{20,"to_k"},{10,1}},
    {{21,"to_k"},{11,1}},
    {{35,"to_k"},{43,0}},
    {{37,"to_k"},{14,1}},
    {{45,"to_k"},{12,1}},
    {{46,"to_k"},{13,1}},

    {{19,"do_k"},{15,1}},
    {{20,"do_k"},{10,1}},
    {{21,"do_k"},{11,1}},
    {{37,"do_k"},{14,1}},
    {{45,"do_k"},{12,1}},
    {{46,"do_k"},{13,1}},
    {{49,"do_k"},{51,0}},

    {{6,"endfor_k"},{3,1}},
    {{8,"endfor_k"},{3,1}},
    {{14,"endfor_k"},{2,1}},
    {{19,"endfor_k"},{15,1}},
    {{20,"endfor_k"},{10,1}},
    {{21,"endfor_k"},{11,1}},
    {{24,"endfor_k"},{5,1}},
    {{34,"endfor_k"},{7,1}},
    {{36,"endfor_k"},{3,1}},
    {{37,"endfor_k"},{14,1}},
    {{41,"endfor_k"},{4,1}},
    {{45,"endfor_k"},{12,1}},
    {{46,"endfor_k"},{13,1}},
    {{48,"endfor_k"},{6,1}},
    {{50,"endfor_k"},{9,1}},
    {{51,"endfor_k"},{3,1}},
    {{52,"endfor_k"},{53,0}},
    {{53,"endfor_k"},{8,1}},

    {{6,"if_k"},{12,0}},
    {{8,"if_k"},{12,0}},
    {{19,"if_k"},{15,1}},
    {{20,"if_k"},{10,1}},
    {{21,"if_k"},{11,1}},
    {{24,"if_k"},{5,1}},
    {{34,"if_k"},{7,1}},
    {{36,"if_k"},{12,0}},
    {{37,"if_k"},{14,1}},
    {{41,"if_k"},{4,1}},
    {{46,"if_k"},{12,1}},
    {{46,"if_k"},{13,1}},
    {{48,"if_k"},{6,1}},
    {{50,"if_k"},{9,1}},
    {{51,"if_k"},{12,0}},
    {{53,"if_k"},{8,1}},

    {{18,"relop"},{28,0}},
    {{19,"relop"},{15,1}},
    {{20,"relop"},{10,1}},
    {{21,"relop"},{11,1}},
    {{37,"relop"},{14,1}},
    {{45,"relop"},{12,1}},
    {{46,"relop"},{13,1}},

    {{6,"endif_k"},{3,1}},
    {{8,"endif_k"},{3,1}},
    {{14,"endif_k"},{2,1}},
    {{19,"endif_k"},{15,1}},
    {{20,"endif_k"},{10,1}},
    {{21,"endif_k"},{11,1}},
    {{24,"endif_k"},{5,1}},
    {{34,"endif_k"},{7,1}},
    {{36,"endif_k"},{3,1}},
    {{37,"endif_k"},{14,1}},
    {{41,"endif_k"},{4,1}},
    {{44,"endif_k"},{50,0}},
    {{45,"endif_k"},{12,1}},
    {{46,"endif_k"},{13,1}},
    {{48,"endif_k"},{6,1}},
    {{50,"endif_k"},{9,1}},
    {{51,"endif_k"},{3,1}},
    {{53,"endif_k"},{8,1}},

    {{12,"number"},{21,0}},
    {{16,"number"},{21,0}},
    {{23,"number"},{21,0}},
    {{25,"number"},{33,0}},
    {{27,"number"},{21,0}},
    {{28,"number"},{21,0}},
    {{29,"number"},{21,0}},
    {{30,"number"},{38,0}},
    {{43,"number"},{21,0}},

    {{15,"sopen"},{25,0}},
    {{20,"sopen"},{30,0}},

    {{33,"sclose"},{42,0}},
    {{38,"sclose"},{45,0}},
    {{39,"sclose"},{46,0}},

    {{19,"operator"},{29,0}},
    {{20,"operator"},{10,1}},
    {{21,"operator"},{11,1}},
    {{45,"operator"},{12,1}},
    {{46,"operator"},{13,1}},

    {{1,"$"},{-1,-1}},
    {{47,"$"},{1,1}},
};

map<pair<int,string>,int> go_to = {
    {{0,"G"},1},
    {{6,"STMT"},7},
    {{8,"STMT"},14},
    {{36,"STMT"},44},
    {{51,"STMT"},52},
    {{6,"ST"},8},
    {{8,"ST"},8},
    {{36,"ST"},8},
    {{51,"ST"},8},
    {{12,"VAL"},19},
    {{16,"VAL"},19},
    {{23,"VAL"},19},
    {{27,"VAL"},19},
    {{28,"VAL"},19},
    {{29,"VAL"},19},
    {{43,"VAL"},19},
    {{12,"EXP"},18},
    {{16,"EXP"},26},
    {{23,"EXP"},32},
    {{27,"EXP"},35},
    {{28,"EXP"},36},
    {{29,"EXP"},37},
    {{43,"EXP"},49},
};

unordered_map<int,int> no_of_grammar_sym = {
    {0,1},
    {1,11},
    {2,2},
    {3,0},
    {4,5},
    {5,3},
    {6,6},
    {7,4},
    {8,9},
    {9,6},
    {10,1},
    {11,1},
    {12,4},
    {13,4},
    {14,3},
    {15,1}
};

unordered_map<int,string> g_sym = {
    {0,"G'"},
    {1,"G"},
    {2,"STMT"},
    {3,"STMT"},
    {4,"ST"},
    {5,"ST"},
    {6,"ST"},
    {7,"ST"},
    {8,"ST"},
    {9,"ST"},
    {10,"VAL"},
    {11,"VAL"},
    {12,"VAL"},
    {13,"VAL"},
    {14,"EXP"},
    {15,"EXP"}
};

vector<string> splitString(const string& input) {
    vector<string> words;
    istringstream iss(input);
    string word;
    bool flag = false;
    while (iss >> word) {
        if(flag) {
            words.push_back(word);
            flag=false;
        }else{
            flag=true;
        }
    }
    return words;
}

unordered_map<int,string> grammar = {
    {0,"G' -> G"},
    {1,"G -> datatype main_k popen pclose begin_k STMT return_k popen identifier pclose End_k"},
    {2,"STMT -> ST STMT "},
    {3,"STMT -> NULL"},
    {4,"ST -> datatype identifier assign_op EXP semicolon"},
    {5,"ST -> datatype identifier semicolon"},
    {6,"ST -> datatype identifier sopen number sclose semicolon"},
    {7,"ST -> identifier assign_op EXP semicolon"},
    {8,"ST -> for_k identifier assign_op EXP to_k EXP do_k STMT endfor_k"},
    {9,"ST -> if_k EXP relop EXP STMT endif_k"},
    {10,"VAL -> identifier"},
    {11,"VAL -> number"},
    {12,"VAL -> identifier sopen number sclose"},
    {13,"VAL -> identifier sopen identifier sclose"},
    {14,"EXP -> VAL operator EXP"},
    {15,"EXP -> VAL"},
};

void changeColor(int desiredColor){ 
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 

int main(){
    
    ifstream t("output.txt");
    stringstream buffer;
    buffer << t.rdbuf();

    string s = buffer.str();
    
    vector<string> input;
    input = splitString(s);
    input.push_back("$");

    vector<int> st;
    st.push_back(0);
    int i=0;
    cout << left << setw(80) << "STACK" << left << setw(20) << "INPUT";
    cout << "ACTION" << endl;
    while(1){
        if (st.size()<1){
            changeColor(5);
            cout << "Error" << endl;
            changeColor(7);
            break;
        }
        string a = input[i];
        int s = st.back();
        string ss = "";
        for (auto j: st) ss += to_string(j)+"|";
        ss.pop_back();
        cout << left << setw(80) << ss ;
        cout << left << setw(20) << a;
        if (action[{s,a}].second==-1){
            changeColor(2);
            cout << "Accepted" << endl;
            changeColor(7);
            break;
        }
        else if (action[{s,a}]!=make_pair(0,0)) {
            if (action[{s,a}].second==0){
                st.push_back(action[{s,a}].first);
                cout<< "Shift " << a << endl;
                i++;
            }else{
                int no = no_of_grammar_sym[action[{s,a}].first];
                while(no--) st.pop_back();
                st.push_back(go_to[{st.back(),g_sym[action[{s,a}].first]}]);
                cout << "Reduce " <<  g_sym[action[{s,a}].first] <<   " : "  << grammar[action[{s,a}].first] << endl;
            }
        }
        else {
            changeColor(4);
            cout << "Error" << endl;
            changeColor(7);
            break;
        }
    }
     
    return 0;
}