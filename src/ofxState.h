#pragma once
#include "ofMain.h"
#include "ofxStateEventArgs.h"
#include "ofxStateListener.h"

class ofxState {
	public:
		ofxState(std::string name = "") :
			_name(name){

		}

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
		ofxState * enter(ofxState * fromState){
			ofxStateEnteredEventArgs args(this, fromState);
			ofNotifyEvent(_enteredEvent, args);
			return this;
		}
		ofxState * exit(ofxState * toState){
			ofxStateExitedEventArgs args(this, toState);
			ofNotifyEvent(_exitedEvent, args);
			return this;
		}

		std::string getName(){
			return _name;
		}

		ofEvent <ofxStateEnteredEventArgs> _enteredEvent;
		ofEvent <ofxStateExitedEventArgs> _exitedEvent;
		std::string _name;

	protected:
	private:
};
