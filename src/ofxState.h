#pragma once
#include "ofMain.h"
#include "ofxStateListener.h"

class ofxState
{
public:
    ofxState* addListener(ofxStateListener* listener)
    {
        return this;
    }
    ofxState* removeListener(ofxStateListener* listener)
    {
        return this;
    }
	template<class ListenerClass, typename ListenerMethod>
    ofxState* addEnteredListener(ListenerClass *listener, ListenerMethod method)
    {
        ofAddListener(_enteredEvent, listener, method);
        return this;
    }
	template<class ListenerClass, typename ListenerMethod>
    ofxState* removeEnteredListener(ListenerClass *listener, ListenerMethod method)
    {
        ofRemoveListener(_enteredEvent, listener, method);
        return this;
    }
	template<class ListenerClass, typename ListenerMethod>
    ofxState* addExitedListener(ListenerClass *listener, ListenerMethod method)
    {
        ofAddListener(_exitedEvent, listener, method);
        return this;
    }
	template<class ListenerClass, typename ListenerMethod>
    ofxState* removeExitedListener(ListenerClass *listener, ListenerMethod method)
    {
        ofRemoveListener(_exitedEvent, listener, method);
        return this;
    }
    ofxState* enter()
    {
        bool value = true;
        ofNotifyEvent(_enteredEvent, value, this);
        return this;
    }
    ofxState* exit()
    {
        bool value = true;
        ofNotifyEvent(_exitedEvent, value, this);
        return this;
    }

    ofEvent<bool> _enteredEvent;
    ofEvent<bool> _exitedEvent;
protected:
private:
};
