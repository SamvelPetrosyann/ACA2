#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller 
{
public:
    Controller() {}
    virtual ~Controller() {}
    virtual void PowerOn() = 0;
    virtual void PowerOff() = 0;
    virtual void VolumeUp() = 0;
    virtual void VolumeDown() = 0;
    virtual void ChannelUp() = 0;
    virtual void ChannelDown() = 0;
    virtual void PrintVol() = 0;
    virtual void PrintChannel() = 0;
};

#endif // CONTROLLER_H
