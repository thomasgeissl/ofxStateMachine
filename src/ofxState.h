#pragma once
#include "ofMain.h"
#include "ofxStateEventArgs.h"
#include "ofxStateListener.h"

class ofxState {
	public:
		ofxState(std::string name = "") :
			_name(name){

		}

		void addListener(ofxStateListener * listener){
			ofAddListener(_enteredEvent, listener, &ofxStateListener::onEnteredEvent);
			ofAddListener(_exitedEvent, listener, &ofxStateListener::onExitedEvent);
		}
		void removeListener(ofxStateListener * listener){
			ofRemoveListener(_enteredEvent, listener, &ofxStateListener::onEnteredEvent);
			ofRemoveListener(_exitedEvent, listener, &ofxStateListener::onExitedEvent);
		}
		template <class ListenerClass, typename ListenerMethod>
		void addEnteredListener(ListenerClass * listener, ListenerMethod method){
			ofAddListener(_enteredEvent, listener, method);
		}
		template <class ListenerClass, typename ListenerMethod>
		void removeEnteredListener(ListenerClass * listener, ListenerMethod method){
			ofRemoveListener(_enteredEvent, listener, method);
		}
		template <class ListenerClass, typename ListenerMethod>
		void addExitedListener(ListenerClass * listener, ListenerMethod method){
			ofAddListener(_exitedEvent, listener, method);
		}
		template <class ListenerClass, typename ListenerMethod>
		void removeExitedListener(ListenerClass * listener, ListenerMethod method){
			ofRemoveListener(_exitedEvent, listener, method);
		}
		void enter(ofxState * fromState){
			ofxStateEnteredEventArgs args(this, fromState);
			ofNotifyEvent(_enteredEvent, args);
		}
		void exit(ofxState * toState){
			ofxStateExitedEventArgs args(this, toState);
			ofNotifyEvent(_exitedEvent, args);
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
