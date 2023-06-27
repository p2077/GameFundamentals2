#include "StateManager.h"
#include "States.h"

std::vector<State*> StateManager::s_states;

void StateManager::Update(float deltaTime)
{
	if (!s_states.empty())
	{
		// s_states.back() represents the current state, by pointer
		s_states.back()->Update(deltaTime);
	}
}
// Invokes Render() of the current state
void StateManager::Render()
{
	if (!s_states.empty())
	{
		s_states.back()->Render();
	}
}
void StateManager::PushState(State* pauseState)
{
	s_states.push_back(pauseState);
	s_states.back()->Enter();
}
void StateManager::PopState()
{
	// If only one state in vector, return
	if (s_states.size() <= 1)
		return;

	if (!s_states.empty())
	{
		s_states.back()->Exit();
		delete s_states.back();
		s_states.back() = NULL;
		s_states.pop_back();
	}
	s_states.back()->Resume();
}; // Used when leaving PauseState
void StateManager::ChangeState(State* pauseState)
{
	if (!s_states.empty())
	{
		s_states.back()->Exit();
		delete s_states.back();
		s_states.back() = NULL;
		s_states.pop_back();
	}
	s_states.push_back(pauseState);
	s_states.back()->Enter();
};
void StateManager::Quit()
{
	while (!s_states.empty())
	{
		s_states.back()->Exit();
		delete s_states.back();
		s_states.back() = NULL;
		s_states.pop_back();
	}
}; // Used for cleanup
std::vector<State*>& StateManager::GetStates()
{
	return s_states;
}; // returns a reference to our State* vector
