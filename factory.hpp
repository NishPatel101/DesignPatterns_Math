#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <algorithm>
#include <stack>
#include <vector>
#include "base.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"

class Factory{
	private:
        std::vector<std::string> shuntingYard(std::vector<std::string> rawexp){
            std::stack<std::string> operatorStack;
            std::vector<std::string> outv;
            for(int i = 0; i < rawexp.size(); i++){
                std::string token = rawexp[i];
                if(isNum(token)){
                    outv.push_back(token);
                }else if(token == "+" || token == "-" || token == "*" || token == "/" || token == "**"){
                    operatorStack.push(token);
                }
            }

            while(!operatorStack.empty()){
                outv.push_back(operatorStack.top());
                operatorStack.pop();
            }

            return outv;
        }
        std::vector<std::string> vectorize(std::string infix){
            std::vector<std::string> infixV;
            std::string token;
            std::vector<std::string> empty;

            for(int i = 0; i < infix.length(); i++){
                char lpToken = infix[i];
                if(std::isdigit(lpToken)){
                    if(std::isdigit(infix[i + 1])){
                        token.push_back(lpToken);
                        continue;
                    }else{
                        token.push_back(lpToken);
                        std::reverse(token.begin(), token.end());
                        infixV.push_back(token);
                        token.clear();
                    }
                }else if(lpToken == '+' || lpToken == '-' || lpToken == '*' || lpToken == '/'){
                    token.push_back(lpToken);
                    if(lpToken == '*'){
                        if(infix[i + 1] == '*'){
                            continue;
                        }
                    }
                    infixV.push_back(token);
                    token.clear();
                }else{
                    return empty;
                }
            }

            return infixV;
        }
        bool isNum(std::string input){
            for(int i = 0; i < input.length(); i++){
                if(std::isdigit(input[i])){
                    continue;
                }else{
                    return false;
                }
            }
            return true;
        }
	public:
		Factory(){}
        Base* parse(char** input, int length){
            Base* empty = new Op(1);
            std::string rawexp = input[1];
            std::reverse(rawexp.begin(), rawexp.end()); //mirror

            std::vector<std::string> infixVector = vectorize(rawexp);

            if(infixVector.empty()){
                return nullptr;
            }

            std::vector<std::string> postfxStr = shuntingYard(infixVector); //shuntingyard infix->postifx
            std::stack<Base*> expressionStack;

            for(int i = 0; i < postfxStr.size(); i++){
                std::string token = postfxStr[i];
                if(isNum(token)){
                    expressionStack.push(new Op(std::stod(token)));
                }else{ 
                    if(token == "+"){
                        Base* t1 = expressionStack.top();
                        expressionStack.pop();
                        Base* t2 = expressionStack.top();
                        expressionStack.pop();
                        Base* opr1 = new Add(t1, t2);
                        expressionStack.push(opr1);
                    }else if(token == "-"){
                        Base* t1 = expressionStack.top();
                        expressionStack.pop();
                        Base* t2 = expressionStack.top();
                        expressionStack.pop();
                        Base* opr1 = new Sub(t1, t2);
                        expressionStack.push(opr1);
                    }else if(token == "*"){
                        Base* t1 = expressionStack.top();
                        expressionStack.pop();
                        Base* t2 = expressionStack.top();
                        expressionStack.pop();
                        Base* opr1 = new Mult(t1, t2);
                        expressionStack.push(opr1);
                    }else if(token == "**"){
                        Base* t1 = expressionStack.top();
                        expressionStack.pop();
                        Base* t2 = expressionStack.top();
                        expressionStack.pop();
                        Base* opr1 = new Pow(t1, t2);
                        expressionStack.push(opr1);
                    }else if(token == "/"){
                        Base* t1 = expressionStack.top();
                        expressionStack.pop();
                        Base* t2 = expressionStack.top();
                        expressionStack.pop();
                        Base* opr1 = new Div(t1, t2);
                        expressionStack.push(opr1);
                    }
                }
            }
            return expressionStack.top();
        }
};

#endif //__FACTORY_HPP__

