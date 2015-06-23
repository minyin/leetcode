#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        int nLen = s.size();
        stack<int> mynum;
        stack<char> myoperator;
        char operator_pop = 'x';
        int num_pop = 0;
        int sum = 0;        
        // push number and operator in stack
        // and calculate operation in parentheses
        for(int i=0;i<nLen;i++){
        	if (s[i] == ' '){
        		continue;
        	}
        	else if (s[i] == '+' || s[i] == '-' || s[i] == '('){
        		myoperator.push(s[i]);
        	}
        	else if(s[i] == ')'){ // calculate operation in parentheses
                sum = 0;
                operator_pop = 'x';
        		while(operator_pop != '('){
        			// operator
        			operator_pop = myoperator.top();
        			myoperator.pop();
        			// num
        			num_pop = mynum.top();
        			mynum.pop();
        			// "+" or "-"
        			if(operator_pop == '+'){
        				sum += num_pop;
        			}
        			else if(operator_pop == '-'){
        				sum -= num_pop;
        			}
        		} 
                // Now num_pop is the first number after '('    
                sum += num_pop;          
        		mynum.push(sum);
                //myoperator.pop();
        	}
        	else{
                // add a string2int here!
                int count = 0;
                while (s[i+count] >= '0' && s[i+count] <= '9'){
                    count++;
                }
                string mynumsub = s.substr(i,count);
                int mynumint = atoi(mynumsub.c_str());
                mynum.push(mynumint);
                i += (count-1);
        	}
        }
        // now the stack not contain parentheses
        sum = 0;        
        int numLen = mynum.size();
        if (numLen == 1){
            sum = mynum.top();
            mynum.pop();
            return sum;
        }
        while(mynum.size()>0){
            // operator
            if(myoperator.size()>0){ 
            // when parentheses is removed, 
            // len(mynum)-len(myoperator) == 1
                operator_pop = myoperator.top();
                myoperator.pop();
            }
            else{ // the last element in stack mynum
                operator_pop = '+';
            }
            // num
            num_pop = mynum.top();
            mynum.pop();            
            // "+" or "-"
            if(operator_pop == '+'){
                sum += num_pop;
            }
            else if(operator_pop == '-'){
                sum -= num_pop;
            }            
        }
        return sum;
    }
};

int main(){
	Solution s1;
	string str = "(1-(3-4)+(3-2+100))";
	cout << s1.calculate(str) << endl;
	return 0;
}