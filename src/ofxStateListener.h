#pragma once

class ofxStateListener
{
public:
    virtual void onEnteredEvent(bool &value) = 0;
    virtual void onExitedEvent(bool &value) = 0;
protected:
private:
};
