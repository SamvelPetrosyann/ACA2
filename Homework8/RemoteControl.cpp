#include "RemoteControl.h"
#include <iostream>

RemoteControl::RemoteControl() {}

RemoteControl::~RemoteControl() {}

// Getters
bool RemoteControl::GetTurnOn() 
{
    return turnOn;
}

bool RemoteControl::GetTurnOff() 
{
    return turnOff;
}

bool RemoteControl::GetVolUp() 
{
    return volUp;
}

bool RemoteControl::GetVolDown() 
{
    return volDown;
}

bool RemoteControl::GetChannelUp() 
{
    return channelUp;
}

bool RemoteControl::GetChannelDown() 
{
    return channelDown;
}

// Setters
void RemoteControl::SetTurnOn(bool a) 
{
    turnOn = a;
}

void RemoteControl::SetTurnOff(bool a) 
{
    turnOff = a;
}

void RemoteControl::SetVolUp(bool a) 
{
    volUp = a;
}

void RemoteControl::SetVolDown(bool a) 
{
    volDown = a;
}

void RemoteControl::SetChannelUp(bool a) 
{
    channelUp = a;
}

void RemoteControl::SetChannelDown(bool a) 
{
    channelDown = a;
}

void RemoteControl::PowerOn() 
{
    if (turnOn)
        std::cout << "Power is on" << std::endl;
}

void RemoteControl::PowerOff() 
{
    if (turnOff)
        std::cout << "Power is off" << std::endl;
}

void RemoteControl::VolumeUp() 
{
    if (volUp) 
    {
        if (vol < 100) 
        {
            vol++;
        }
    }
}

void RemoteControl::VolumeDown() 
{
    if (volDown) 
    {
        if (vol > 0) 
        {
            vol--;
        }
    }
}

void RemoteControl::ChannelUp() 
{
    if (channelUp) 
    {
        if (numchannel < 15) 
        {
            numchannel++;
        } 
        else if (numchannel == 15) 
        {
            numchannel = 1;
        }
    }
}

void RemoteControl::ChannelDown() 
{
    if (channelUp) 
    {
        if (numchannel > 1) 
        {
            numchannel--;
        } 
        else if (numchannel == 1) 
        {
            numchannel = 15;
        }
    }
}

void RemoteControl::PrintVol() 
{
    std::cout << "Volume is " << vol << std::endl;
}

void RemoteControl::PrintChannel() 
{
    std::cout << "Channel is " << numchannel << std::endl;
}
