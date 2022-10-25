#include "builder1.hpp"

int main(){
    cout << endl << "test_builder1..." << endl << endl;

    Director* director= new Director();
    ClientCode(*director);
    delete director;

    cout << "done!" << endl << endl;

    return 0;    
}