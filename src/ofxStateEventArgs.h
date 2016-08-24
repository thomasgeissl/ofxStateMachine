#pragma once
#include "ofMain.h"
#include "ofxState.h"

class ofxState;
class ofxStateEnteredEventArgs : public ofEventArgs {
	public:
		ofxStateEnteredEventArgs(ofxState * currentState, ofxState * fromState) :
			_currentState(currentState),
			_fromState(fromState){
		}

		ofxState * _currentState;
		ofxState * _fromState;
};

class ofxStateExitedEventArgs : public ofEventArgs {
	public:
		ofxStateExitedEventArgs(ofxState * currentState, ofxState * toState) :
			_currentState(currentState),
			_toState(toState){
		}
		ofxState * _currentState;
		ofxState * _toState;
};
