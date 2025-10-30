
#include <iostream>
#include<string>
using namespace std;

string differentiation_of_general_term(string abc);

void removespaces(string &s){
    string result;
    for(char c : s){
        if (c != ' '){
            result = result + c;
        }
    }
    s = result;
}

bool isdigit(char c){
return ( c >='0' && c <= '9');
}

auto differentiation_of_polynomial_term(string s){
    // ex: 3x^5
    string a,b;
    int n=0,m=s.size(),c,d;
    while(isdigit(s[n]) == 1){
        n=n+1;
    }
    while(isdigit(s[m-1]) == 1){
        m=m-1;
    }
    if (n ==0){
        a="1";
    }else {
        a = s.substr(0,n);
    }
    b = s.substr(m);
    c = stoi(a);
    d = stoi(b);
    c = c*d;
    d = d-1;
    a = to_string(c);
    b = to_string(d);
    s = a + "x^" + b;
    return(s);
}


auto differentiation_of_sin(string s){
    string a,b;
    int n=0,m=0,c,d;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    if (n==0){
        a="1";
    }else {
        a = s.substr(0,n);
    }
    m=n+3;
    while(isdigit(s[m])==1){ 
        m = m+1;
    }
    if (m==n+3){
        b="1";
    }else {
        b=s.substr(n+3,m-n-3);
    }
    c = stoi(a);
    d = stoi(b);
    c = c*d;
    a = to_string(c);
    
    s="";
    if (stoi(a)!=1){
        s = s+a;
    }
    s = s +"cos";
    if (stoi(b)!=1){
        s = s+b;
    }
    s = s + "x";
    return(s);
}

auto differentiation_of_cos(string s){
    string a,b;
    int n=0,m=0,c,d;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    if (n==0){
        a="1";
    }else {
        a = s.substr(0,n);
    }
    m=n+3;
    while(isdigit(s[m])==1){ 
        m = m+1;
    }
    if (m==n+3){
        b="1";
    }else {
        b=s.substr(n+3,m-n-3);
    }
    c = stoi(a);
    d = stoi(b);
    c = c*d;
    a = to_string(c);
    
    s="-";
    if (stoi(a)!=1){
        s = s+a;
    }
    s = s +"sin";
    if (stoi(b)!=1){
        s = s+b;
    }
    s = s + "x";
    return(s);
}

auto differentiation_of_exponential_term(string s){
    string a,b;
    int n=0,m=0,c,d;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    if (n==0){
        a="1";
    }else {
        a = s.substr(0,n);
    }
     m=n+2;
    while(isdigit(s[m])==1){ 
        m = m+1;
    }
    if (m==n+2){
        b="1";
    }else {
        b=s.substr(n+2,m-n-2);
    }
    c = stoi(a);
    d = stoi(b);
    c = c*d;
    a = to_string(c);
    s="";
    if (stoi(a)!=1){
        s = s+a;
    }
    s = s +"e^";
    if (stoi(b)!=1){
        s = s+b;
    }
    s = s + "x";
    return(s);
}

auto differentiation_of_logarithimic_term(string s){
    string a;
    int n=0;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    if (n==0){
        a="1";
    }else {
        a = s.substr(0,n);
    }
    s=a + "/x";
    return(s);
}

auto differentiation_of_constant(string s){
    s = "0";
    return(s);
}

auto differentiation_of_compound_exponential(string s){
    string a,b,c=s;
    int n=0,m;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    a = s.substr(0,n);
    s = s.substr(n);
    b = s.substr(3,s.size()-4);
    if (a==""){s= "(" + differentiation_of_general_term(b) + ")*" + c;}
    else {s = "(" + differentiation_of_general_term(b) + ")*" + c;}
    return (s);

}

auto differentiation_of_compound_logarithm(string s){
    string a,b,c=s;
    int n=0,m;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    a = s.substr(0,n);
    s = s.substr(n);
    b = s.substr(3,s.size()-4);
    if (a==""){s= "(" + differentiation_of_general_term(b) + ")*(1/(" + b + "))" ;}
    else {s = a + "(" + differentiation_of_general_term(b) + ")*(1/(" + b + "))";}
    return (s);
}

auto differentiation_of_compound_sin(string s){
    string a,b,c=s;
    int n=0,m;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    a = s.substr(0,n);
    s = s.substr(n);
    b = s.substr(4,s.size()-5);
    if (a==""){s= "(" + differentiation_of_general_term(b) + ")*(cos(" + b + "))" ;}
    else {s = a + "(" + differentiation_of_general_term(b) + ")*(cos(" + b + "))";}
    return (s);
}

auto differentiation_of_compound_cos(string s){
    string a,b,c=s;
    int n=0,m;
    while(isdigit(s[n])==1){
        n = n+1;
    }
    a = s.substr(0,n);
    s = s.substr(n);
    b = s.substr(4,s.size()-5);
    if (a==""){s= "(" + differentiation_of_general_term(b) + ")*(-sin(" + b + "))" ;}
    else {s = a + "(" + differentiation_of_general_term(b) + ")*(-sin(" + b + "))";}
    return (s);
}

auto differentiation_of_multiplication(string s){
    string a,b,c;
    int n=0,m;
    for (int i=0; i < s.size();i++){
        if (n == 0 && s[i]=='*'){
            m = i;
        }
        if (s[i]=='('){
            n = n + 1;
        }
        if (s[i]==')'){
            n = n - 1;
        }
    }
    a = s.substr(1,m-2);
    b = s.substr(m+2,s.size()-m-3);
    s = "(" + a + ")*(" + differentiation_of_general_term(b) + ")+(" + differentiation_of_general_term(a) + ")*("+ b + ")";
    return (s);
    
}

auto differentiation_of_division(string s){
    string a,b,c;
    int n=0,m;
    for (int i=0; i < s.size();i++){
        if (n == 0 && s[i]=='/'){
            m = i;
        }
        if (s[i]=='('){
            n = n + 1;
        }
        if (s[i]==')'){
            n = n - 1;
        }
    }
    a = s.substr(1,m-2);
    b = s.substr(m+2,s.size()-m-3);
    s = "((" + b + ")*(" + differentiation_of_general_term(a) + ")-(" + differentiation_of_general_term(b) + ")*("+ a + "))/("+ b +")^2";
    return (s);
    
}

auto differentiation_of_addition(string s){
    string a,b,c;
    int n=0,m;
    for (int i=0; i < s.size();i++){
        if (n == 0 && s[i]=='+'){
            m = i;
        }
        if (s[i]=='('){
            n = n + 1;
        }
        if (s[i]==')'){
            n = n - 1;
        }
    }
    a = s.substr(1,m-2);
    b = s.substr(m+2,s.size()-m-3);
    s = "(" + differentiation_of_general_term(a) + ")+(" + differentiation_of_general_term(b) + ")";
    return (s);
    
}

auto differentiation_of_subtraction(string s){
    string a,b,c;
    int n=0,m;
    for (int i=0; i < s.size();i++){
        if (n == 0 && s[i]=='-'){
            m = i;
        }
        if (s[i]=='('){
            n = n + 1;
        }
        if (s[i]==')'){
            n = n - 1;
        }
    }
    a = s.substr(1,m-2);
    b = s.substr(m+2,s.size()-m-3);
    s = "(" + differentiation_of_general_term(a) + ")-(" + differentiation_of_general_term(b) + ")";
    return (s);
    
}

auto differentiation_of_x(string s){
    string a;
    int n=0;
    if (s=="x"){
        s = "1";
    }
    else{
        for (int i = 0; i < s.size(); i ++){
        if (isdigit(s[i]) == 1){
            n = n+1;
        }
        }
    s = s.substr(0,n);
    }
    return (s);
}

auto term_identifier(string s){
    string abc="";
    int n=0;
    for (int i=0; i < s.size(); i++){
        if (s[i]=='('){
            n = n+1;
            if (n==1){abc = abc + "(";}
        }
        if (isdigit(s[i])==0 && n == 0){
            abc = abc + s[i];
        }
        if (s[i]==')'){
            n = n - 1;
            if(n==0){abc = abc +")";}
        }
    }
    return(abc);
}



string differentiation_of_general_term(string abc){
    string s=term_identifier(abc);
    if (s=="x^"){
        abc = differentiation_of_polynomial_term(abc);
    }
    if (s=="e^x"){
        abc = differentiation_of_exponential_term(abc);
    }
    if (s=="sinx"){
        abc = differentiation_of_sin(abc);
    }
    if (s=="cosx"){
        abc = differentiation_of_cos(abc);
    }
    if (s=="lnx"){
        abc = differentiation_of_logarithimic_term(abc);
    }
    if (s==""){
        abc = differentiation_of_constant(abc);
    }
    if (s=="sin()"){
        abc = differentiation_of_compound_sin(abc);
    }
    if (s=="cos()"){
        abc =differentiation_of_compound_cos(abc);
    }
    if (s=="e^()"){
        abc = differentiation_of_compound_exponential(abc);
    }
    if (s=="ln()"){
        abc = differentiation_of_compound_logarithm(abc);
    }
    if (s=="()*()"){
        abc = differentiation_of_multiplication(abc);
    }
    if (s=="()/()"){
        abc = differentiation_of_division(abc);
    }
    if (s=="x"){
        abc = differentiation_of_x(abc);
    }
    if (s=="()+()"){
        abc = differentiation_of_addition(abc);
    }
    if (s=="()-()"){
        abc = differentiation_of_subtraction(abc);
    }
    if (s==""){
        abc == "0";
    }
    return(abc);
}

int main(){
    cout << "This is a Differentiation Calculator.\n";
    cout << "Enter a function:\n";
    string abc,differentiation_of_abc;
    getline (cin , abc);
    removespaces(abc);
    differentiation_of_abc = differentiation_of_general_term(abc);
    cout << differentiation_of_abc;
}