#pragma once
#include "ofMain.h"
#include "ofxState.h"

class ofxState;
class ofxStateEnteredEventArgs : public ofEventArgs
{
public:
	ofxStateEnteredEventArgs(std::shared_ptr<ofxState> currentState, std::shared_ptr<ofxState> fromState) : _currentState(currentState),
																											_fromState(fromState)
	{
	}

	std::shared_ptr<ofxState> _currentState;
	std::shared_ptr<ofxState> _fromState;
};

class ofxStateExitedEventArgs : public ofEventArgs
{
public:
	ofxStateExitedEventArgs(std::shared_ptr<ofxState> currentState, std::shared_ptr<ofxState> toState) : _currentState(currentState),
																										 _toState(toState)
	{
	}
	std::shared_ptr<ofxState> _currentState;
	std::shared_ptr<ofxState> _toState;
};
