#include "ofxStateMachine.h"

ofxStateMachine::ofxStateMachine()
{
	_runningB.set("running", false);
	_parameters.add(_runningB);
}

void ofxStateMachine::setInitialState(ofxState::pointer state)
{
	_initialState = state;
}

void ofxStateMachine::addTransition(ofxState::pointer from, std::string action, ofxState::pointer to)
{
    pair<ofxState::pointer, std::string> key(from, action);
	_transitions[key] = to;
}

void ofxStateMachine::removeTransition(ofxState::pointer from, std::string action, ofxState::pointer to)
{
    pair<ofxState::pointer, std::string> key(from, action);
	auto it = _transitions.find(key);
	if (it != _transitions.end() && _transitions[key] == to)
	{
		_transitions.erase(it);
	}
}

void ofxStateMachine::onActionEvent(std::string &action)
{
	if (!_runningB)
	{
		return;
	}
    if (_transitions.find(pair<ofxState::pointer, std::string>(_currentState, action)) != _transitions.end())
	{
		ofxState::pointer fromState = _currentState;
		ofxState::pointer toState = _transitions[pair<ofxState::pointer, string>(_currentState, action)];
		_currentState->exit(toState);
		_currentState = toState;
		_currentState->enter(fromState);
	}
}

void ofxStateMachine::trigger(std::string action)
{
	onActionEvent(action);
}

bool ofxStateMachine::isRunning()
{
	return _runningB;
}

ofxState::pointer ofxStateMachine::getCurrentState() const
{
	return _currentState;
}

bool ofxStateMachine::isCurrentState(ofxState::pointer state)
{
	return _currentState == state;
}

void ofxStateMachine::start()
{
	if (_runningB)
	{
		ofLogWarning("ofxStateMachine") << "state machine is already running";
	}
	else
	{
		_runningB = true;
		_currentState = _initialState;
		_currentState->enter(_initialState); //nullptr?
	}
}

void ofxStateMachine::stop()
{
	_currentState->exit(_initialState);
	if (_runningB)
	{
		_runningB = false;
	}
	else
	{
		ofLogWarning("ofxStateMachine") << "state machine is already stopped";
	}
}

void ofxStateMachine::clear()
{
	_transitions.clear();
	_initialState = nullptr;
}
