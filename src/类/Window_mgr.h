#include<iostream>
#include<vector>

 
 class Screen;

class Window_mgr {

    public :
        void clear();

    private :

        std::vector<Screen> screens{Screen(24,80,'')};



};             


