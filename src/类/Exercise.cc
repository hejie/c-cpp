#include<iostream>
#include<string>

using std::string;

typedef string Type;
Type initVal();

class Exercise {
    public :
        Exercise(){
            std::cout << "ddddddddddd" << std::endl;
        }
        typedef double Type ;

        Type setVal(Type);

        Type initVal(){}

        Exercise  &setExercise(Exercise,int)
        {
            std::cout << "1" << std::endl;
            return *this;
        }
        Exercise &setExercise(Exercise&){
            std::cout << "2" << std::endl;
            return *this;
        }

        const  Exercise &setExercise(const Exercise &a) const{
            std::cout << "3" << std::endl;
            return *this;
        }

        explicit Exercise(const string &s,int){
            std::cout << s << std::endl;
        }
        Exercise(string s)
        {
            std::cout << s << std::endl;
        }
    private:
        int val;

};



Exercise::Type Exercise::setVal(Type parm)
{
    val= parm+initVal();
    return val;
}

int main(void)
{
    Exercise e;

    string bb="bbbbbbbb";
    e.setExercise(bb);


    double dval=3.4;
   const int &r=dval;

    return 0;
}
