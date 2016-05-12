#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<vector>
#include<iostream>
using std::string;
using std::vector;
using namespace std;

class Screen;

class Window_mgr {

    public :
        using index=vector<Screen>::size_type;
        void clear(index);
        void display();
        Window_mgr();
    private :

        std::vector<Screen> screens;

};

class ConstRef{

    public :
        //ConstRef()=default;
        ConstRef(int index=0){

            std::cout <<"默认构造初始化 "<<index << std::endl;

        }//等价默认构造函数
        //ConstRef(std::ostream &os =std::cout);
    private:
        int index;
};

class Screen {

    //friend class Window_mgr;

    friend void  Window_mgr::clear(index);
    friend void  Window_mgr::display();
    public :
    using pos = std::string::size_type;
    Screen(pos ht,pos wd,const char c) : Screen(ht,wd) {
        std::cout << "Screen 带3个参数初始化" << std::endl;
        contents=string(ht*wd,c);
    }
    Screen(pos ht,pos wd) : height(ht),width(wd){
        std::cout << "Screen 带1个参数初始化" << std::endl;
    }

    std::vector<Screen> screens;
    Screen() :screens{Screen(3,4,'B')}{
        std::cout << "Screen 默认构造"<< screens.size() << std::endl;
    }
    
    vector<int> ival=vector<int>(1);
    char get() const    
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;

    Screen &move(pos r,pos c);

    Screen &set(char);
    Screen &set(pos,pos,char);

    const   Screen &display(std::ostream &os) const;

    Screen &display(std::ostream &os);


    private:
    //ConstRef wm;//当成员属于某种类类型，且该类没定义默认构造函数时，成员必须初始化
    pos cursor =0;
    const pos height=0,width=0;
    std::string contents;
};



std::ostream& print(std::ostream &io,const Screen &s)
{
    s.display(io);
    return io;
}
inline Screen &Screen::set(char c)
{
    contents[cursor]=c;
    return *this;

}
inline Screen &Screen::set(pos r,pos col,char ch)
{
    contents[r*width+col]=ch;
    return *this;
}

inline Screen &Screen::move(pos r,pos c)
{
    pos row =r *width;
    cursor =row +c;
    return *this;
}

char Screen::get(pos r,pos c) const
{
    pos row = r*width;
    return contents[row+c];
}

const Screen &Screen::display(std::ostream &os) const
{
    os<<"cursor"<<cursor<<"contents"<<contents;
    return *this;

}

Screen &Screen::display(std::ostream &os)
{
    os<<"cursor= "<<cursor<<" contents= "<<contents;
    return *this;
}

inline Window_mgr::Window_mgr() :screens{Screen(2,3,'A')}
{
    std::cout << screens.size()<< std::endl;
}

void Window_mgr::display()
{
    for (auto i :screens) {

        std::cout << "contents= "<<i.contents << std::endl;
    }
}
void Window_mgr::clear(index i)
{
    Screen &s=screens[i];
    s.contents=string(s.height*s.width,'\0');
}

int foo( int x, int y );
#endif

