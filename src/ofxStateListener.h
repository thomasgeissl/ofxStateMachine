#pragma once

#include "ofxStateEventArgs.h"
class ofxState;

class ofxStateListener {
	public:
		virtual void onEnteredEvent(ofxStateEnteredEventArgs & args) = 0;
		virtual void onExitedEvent(ofxStateExitedEventArgs & args) = 0;
	protected:
	private:
};
