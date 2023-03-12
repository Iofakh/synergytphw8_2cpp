#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileWasNotOpenedException : public exception
{
public:
    FileWasNotOpenedException(string const &message) : msg_(message) {}
    virtual char const *what() const noexcept { return msg_.c_str(); }

private:
    string msg_;
};

void open_file(string path){
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()){
        throw FileWasNotOpenedException("Файл не открылся");
    }
}

int main()
{
    string path = "myfile.txt";
    try
    {
        open_file(path);
    }
    catch (const exception &ex)
    {
        cout << ex.what() << endl;
    }
    return 1;
}