#pragma once
#include "ofMain.h"
#include "ofxState.h"

class ofxStateMachine {
	public:
		ofxStateMachine();
		ofxStateMachine * setInitialState(ofxState * state);
		ofxStateMachine * addTransition(ofxState * from, string action, ofxState * to);
		ofxStateMachine * removeTransition(ofxState * from, string action, ofxState * to);

		void onActionEvent(string & action);
		void transit(string action);
		bool isRunning();
		ofxState * getCurrentState() const;
		bool isCurrentState(ofxState * state);

		ofxStateMachine * start();
		ofxStateMachine * stop();
		ofxStateMachine * clear();

	protected:
	private:
		map <pair <ofxState *, string>, ofxState *> _transitions;
		ofxState * _currentState; //_configuration;
		ofxState * _initialState;
		bool _runningB;
};
