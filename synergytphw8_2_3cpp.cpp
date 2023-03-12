#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Some_Error : public exception
{
public:
    Some_Error(string const &message) : msg_(message) {}
    virtual char const *what() const noexcept { return msg_.c_str(); }

private:
    string msg_;
};

int pars(string str){
    char dig[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char math[] = {'+', '-', '*', '/'};


    bool exists1 = count(begin(dig), end(dig), str[0]) > 0;
    bool exists2 = count(begin(dig), end(dig), str[2]) > 0;
    bool exists3 = count(begin(math), end(math), str[1]) > 0;

    if ((str.size()-1) != 3){
        throw Some_Error("Длинна выражения должна быть 3 символа");
    }
    if (!(exists1 & exists2 & exists3)){
        throw Some_Error("Первым и третьим символом дожны быть цифры, вторым символом дожен быть математический знак (+, -, *, /)");
    }
    
    int a, b;
    a = str[0] -'0';
    b = str[2] -'0';

    switch (str[1])
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
    return 0;
}


int main()
{
    string str;
    int a, b;
    cout << "Ведите строку вида \"1+2\", \"4-5\", \"6/7\" или \"8*9\"" << endl;
    cin >> str;
    try
    {
        cout << pars(str) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 1;
}