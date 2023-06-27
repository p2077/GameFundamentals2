#pragma once

#include <vector>
#include "States.h"

using namespace std;

class State;

class StateManager
{
private: // Public properties
	static vector<State*>s_states;

public: // public methods
	static void Update(float deltaTime);
	static void Render();
	static void PushState(State* pauseState); // Used when going to PauseState
	static void PopState(); // Used when leaving PauseState
	static void ChangeState(State* pauseState);
	static void Quit(); // Used for cleanup
	static vector<State*>& GetStates(); // returns a reference to our State* vector

private: // Private methods
	StateManager() {}
};