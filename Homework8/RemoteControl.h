#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "Controller.h"

class RemoteControl : public Controller
{
private:
    bool turnOn;
    bool turnOff;
    bool volUp;
    bool volDown;
    bool channelUp;
    bool channelDown;
    int vol = 0;
    int numchannel = 1;

public:
    RemoteControl();
    ~RemoteControl();

    // Getters
    bool GetTurnOn();
    bool GetTurnOff();
    bool GetVolUp();
    bool GetVolDown();
    bool GetChannelUp();
    bool GetChannelDown();

    // Setters
    void SetTurnOn(bool a);
    void SetTurnOff(bool a);
    void SetVolUp(bool a);
    void SetVolDown(bool a);
    void SetChannelUp(bool a);
    void SetChannelDown(bool a);

    void PowerOn() override;
    void PowerOff() override;
    void VolumeUp() override;
    void VolumeDown() override;
    void ChannelUp() override;
    void ChannelDown() override;
    void PrintVol() override;
    void PrintChannel() override;
};

#endif // REMOTECONTROL_H
