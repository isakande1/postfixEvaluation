#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <iterator>
#include <map>


using namespace std;
void PostfixEval(string instr){
map<char,int> map;
stack<int> stack;
stringstream line(instr);
string word;
string arg = instr;
    int result;
while(line>>word){

    if(isdigit(word.at(0))){
        stack.push(stoi(word));
       // stack.push()
    }else if(isalpha(word.at(0) )){
        if(stack.empty()){
            cout<<"Error: Incomplete input postfix expression." <<endl;
            exit(0);
        }
            map[word.at(0)]=stack.top() ;
            stack.pop();
    }else if(word.at(0) =='$'){
        stack.push((map[word.at(1)]));
    }
    else {
        if(stack.empty()){
            cout<<"The evaluation is incomplete, missing input operators." <<endl;
            exit(0);
        }
        int value1 = stack.top();
        stack.pop();
        int value2 = stack.top();
        stack.pop();
        switch (word.at(0)) {

            case '+':
                result = value2 + value1;
                stack.push(result);
                break;
            case '/':
                result = value2 / value1;
                stack.push(result);
                break;
            case '*':
                result = value2 * value1;
                stack.push(result);
                break;
            case '-':
                result = value2 - value1;
                stack.push(result);
                break;
            default:
                cout<<"Error: Invalid string \"" <<arg <<"\"";
        }
    }
}
    if(stack.size()>1){
        cout<<"The evaluation is incomplete, missing input operators." <<endl;
        exit(0);
    }
cout<<"The result of evaluating the postfix expression \""<< arg   <<"\" is the value: "    <<result <<endl;
}

int main ( )
{
	//ifstream file;
	string instr;
	cout<<"Please enter a postfix expression for evalution, using only single lowercase characters as variables:" << endl;
	getline(cin, instr);
	//cout << instr << endl;
	PostfixEval(instr);
	//cout << endl;
	//cout<<"Thank you." << endl;


	return 0;
}
