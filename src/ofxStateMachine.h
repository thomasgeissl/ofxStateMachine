#pragma once
#include "ofMain.h"
#include "ofxState.h"

class ofxStateMachine
{
public:
    ofxStateMachine() :
        _runningB(false)
    {
    }
    ofxStateMachine* setInitialState(ofxState* state)
    {
        _initialState = state;
        return this;
    }
    ofxStateMachine* addTransition(ofxState* from, string action, ofxState* to)
    {
        pair<ofxState*, string> key(from, action);
        _transitions[key] = to;
        return this;
    }
    void onActionEvent(string &action)
    {
        if(!_runningB)
        {
            return;
        }
        if(_transitions.find(pair<ofxState*, string>(_currentState, action)) != _transitions.end())
        {
            _currentState->exit();
            _currentState = _transitions[pair<ofxState*, string>(_currentState, action)];
            _currentState->enter();
        }
    }
    void transit(string action)
    {
        onActionEvent(action);
    }
    bool isRunning()
    {
        return _runningB;
    }
    ofxState* getCurrentState()
    {
        return _currentState;
    }
    ofxStateMachine* start()
    {
        if(_runningB)
        {
            ofLogWarning("ofxStateMachine")<<"state machine is already running";
        }
        else
        {
            _runningB = true;
            _currentState = _initialState;
            _currentState->enter();
        }
        return this;
    }
    ofxStateMachine* stop()
    {
        _currentState->exit();
        if(_runningB)
        {
            _runningB = false;
        }
        else
        {
            ofLogWarning("ofxStateMachine")<<"state machine is already stopped";
        }
        return this;
    }


protected:
private:
    map<pair<ofxState*, string>, ofxState*> _transitions;
    ofxState *_currentState;//_configuration;
    ofxState *_initialState;
    bool _runningB;
};