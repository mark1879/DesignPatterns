#include "builder2.hpp"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
    cout << endl << "test_builder2..." << endl << endl;

    Direcror *director = new Direcror();
    ThinkPadBuilder *thinkpad_builder = new ThinkPadBuilder();
    YogaBuilder *yoga_builder = new YogaBuilder();

    director->Create(thinkpad_builder);
    director->Create(yoga_builder);

    Computer *thinkpad_computer = thinkpad_builder->GetResult();
    Computer *yoga_computer = yoga_builder->GetResult();


    cout << "-----ThinkPad-----" << endl;
    cout << "CPU: " << thinkpad_computer->cpu() << endl;
    cout << "Mainboard: " << thinkpad_computer->mainboard() << endl;
    cout << "Ram: " << thinkpad_computer->ram() << endl;
    cout << "VideoCard: " << thinkpad_computer->video_card() << endl << endl;

    cout << "-----Yoga-----" << endl;
    cout << "CPU: " << yoga_computer->cpu() << endl;
    cout << "Mainboard: " << yoga_computer->mainboard() << endl;
    cout << "Ram: " << yoga_computer->ram() << endl;
    cout << "VideoCard: " << yoga_computer->video_card() << endl;

    SAFE_DELETE(thinkpad_computer);
    SAFE_DELETE(yoga_computer);
    SAFE_DELETE(thinkpad_builder);
    SAFE_DELETE(yoga_builder);
    SAFE_DELETE(director);

    cout << endl << "done!" << endl << endl;

    return 0;
}