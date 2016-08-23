#pragma once
#include "ofMain.h"
#include "ofxStateListener.h"

class ofxState {
	public:
		ofxState * addListener(ofxStateListener * listener){
			ofAddListener(_enteredEvent, listener, &ofxStateListener::onEnteredEvent);
			ofAddListener(_exitedEvent, listener, &ofxStateListener::onExitedEvent);
			return this;
		}
		ofxState * removeListener(ofxStateListener * listener){
			ofRemoveListener(_enteredEvent, listener, &ofxStateListener::onEnteredEvent);
			ofRemoveListener(_exitedEvent, listener, &ofxStateListener::onExitedEvent);
			return this;
		}
		template <class ListenerClass, typename ListenerMethod>
		ofxState * addEnteredListener(ListenerClass * listener, ListenerMethod method){
			ofAddListener(_enteredEvent, listener, method);
			return this;
		}
		template <class ListenerClass, typename ListenerMethod>
		ofxState * removeEnteredListener(ListenerClass * listener, ListenerMethod method){
			ofRemoveListener(_enteredEvent, listener, method);
			return this;
		}
		template <class ListenerClass, typename ListenerMethod>
		ofxState * addExitedListener(ListenerClass * listener, ListenerMethod method){
			ofAddListener(_exitedEvent, listener, method);
			return this;
		}
		template <class ListenerClass, typename ListenerMethod>
		ofxState * removeExitedListener(ListenerClass * listener, ListenerMethod method){
			ofRemoveListener(_exitedEvent, listener, method);
			return this;
		}
		ofxState * enter(){
			ofNotifyEvent(_enteredEvent, this);
			return this;
		}
		ofxState * exit(){
			ofNotifyEvent(_exitedEvent, this);
			return this;
		}

		ofEvent <ofxState * const> _enteredEvent;
		ofEvent <ofxState * const> _exitedEvent;
	protected:
	private:
};
