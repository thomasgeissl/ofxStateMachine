#pragma once
#include "ofMain.h"
#include "ofxState.h"

class ofxStateMachine
{
public:
	ofxStateMachine();
	void setInitialState(ofxState::pointer state);
	void addTransition(ofxState::pointer from, std::string action, ofxState::pointer to);
	void removeTransition(ofxState::pointer from, std::string action, ofxState::pointer to);

	void onActionEvent(string &action);
	void trigger(string action);
	bool isRunning();
	ofxState::pointer getCurrentState() const;
	bool isCurrentState(ofxState::pointer state);

	void start();
	void stop();
	void clear();

protected:
private:
	map<pair<ofxState::pointer, string>, ofxState::pointer> _transitions;
	ofxState::pointer _currentState; //_configuration;
	ofxState::pointer _initialState;
	ofParameterGroup _parameters;
	ofParameter<bool> _runningB;
};
