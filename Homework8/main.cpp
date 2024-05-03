#include "RemoteControl.h"

int main() 
{
    RemoteControl p;
    p.SetTurnOn(true);
    p.GetTurnOn();
    p.SetVolUp(true);
    p.GetVolUp();
    p.SetChannelUp(true);
    p.GetChannelUp();
    Controller* ptr = &p;
    ptr->PowerOn();
    ptr->VolumeUp();
    ptr->ChannelUp();
    ptr->PrintVol();
    ptr->PrintChannel();
    return 0;
}
