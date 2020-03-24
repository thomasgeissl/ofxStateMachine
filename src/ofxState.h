#pragma once
#include "ofMain.h"
#include "ofxStateEventArgs.h"
#include "ofxStateListener.h"

class ofxState
{
public:
	typedef std::shared_ptr<ofxState> pointer;
	static pointer create(std::string name = "")
	{
		return std::make_shared<ofxState>(name);
	}
	ofxState(std::string name = "")
	{
		_name.set("name", name);
		_parameters.add(_name);
        _this = std::make_shared<ofxState>(*this);
	}

	void addListener(ofxStateListener *listener)
	{
		ofAddListener(_enteredEvent, listener, &ofxStateListener::onEnteredEvent);
		ofAddListener(_exitedEvent, listener, &ofxStateListener::onExitedEvent);
	}
	void removeListener(ofxStateListener *listener)
	{
		ofRemoveListener(_enteredEvent, listener, &ofxStateListener::onEnteredEvent);
		ofRemoveListener(_exitedEvent, listener, &ofxStateListener::onExitedEvent);
	}
	template <class ListenerClass, typename ListenerMethod>
	void addEnteredListener(ListenerClass *listener, ListenerMethod method)
	{
		ofAddListener(_enteredEvent, listener, method);
	}
	template <class ListenerClass, typename ListenerMethod>
	void removeEnteredListener(ListenerClass *listener, ListenerMethod method)
	{
		ofRemoveListener(_enteredEvent, listener, method);
	}
	template <class ListenerClass, typename ListenerMethod>
	void addExitedListener(ListenerClass *listener, ListenerMethod method)
	{
		ofAddListener(_exitedEvent, listener, method);
	}
	template <class ListenerClass, typename ListenerMethod>
	void removeExitedListener(ListenerClass *listener, ListenerMethod method)
	{
		ofRemoveListener(_exitedEvent, listener, method);
	}

	std::string getName()
	{
		return _name;
	}

	ofEvent<ofxStateEnteredEventArgs> _enteredEvent;
	ofEvent<ofxStateExitedEventArgs> _exitedEvent;
	ofParameterGroup _parameters;
	ofParameter<std::string> _name;

	virtual void onEnter(ofxState::pointer fromState) {}
	virtual void onExit(ofxState::pointer toState) {}

	void enter(ofxState::pointer fromState)
	{
        ofxStateEnteredEventArgs args(_this, fromState);
		onEnter(fromState);
		ofNotifyEvent(_enteredEvent, args);
	}
	void exit(ofxState::pointer toState)
	{
        ofxStateExitedEventArgs args(_this, toState);
		onEnter(toState);
        ofNotifyEvent(_exitedEvent, args);
	}

    pointer _this;
protected:
private:
};
