#include <iostream>
#include <string>

using namespace std;

class division_zero_exception : public exception
{
public:
    division_zero_exception(string const &message) : msg_(message) {}
    virtual char const *what() const noexcept { return msg_.c_str(); }

private:
    string msg_;
};

double
divide(int a)
{
    if (a == 0)
    {
        throw division_zero_exception("Деление на 0");
    }
    return 1024 / a;
}

int main()
{
    try
    {
        cout << divide(2) << endl;
        cout << divide(0) << endl;

    }
    catch (const exception &ex)
    {
        cout << ex.what() << endl;
    }
    return 1;
}