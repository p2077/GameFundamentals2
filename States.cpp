#include "states.h"
#include "StateManager.h"
#include "Game.h"
#include <iostream>

using namespace std;
float timer = 0.0f;

// Begin TitleState

void TitleState::Enter()
{
	cout << "Entering TitleState..." << endl;
	timer = 0;
}

void TitleState::Update(float deltaTime)
{

	if (timer > 4)
	{
		cout << "Changing to MainMenuState" << endl;
		StateManager::ChangeState(new MainMenuState());// Change to Main Menu State
	}
	timer += deltaTime;
}

void TitleState::Render()
{
	cout << "Rendering Title State" << endl;
	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 255, 0, 255);
	SDL_RenderClear(Game::GetInstance().GetRenderer());
}

void TitleState::Exit()
{
	cout << "Exiting Title State..." << endl;

}

// End TitleState -- Begin MainMenuState

void MainMenuState::Enter()
{
	cout << "Entering Main Menu State" << endl;
}

void MainMenuState::Update(float deltaTime)
{

	if (Game::GetInstance().KeyDown(SDL_SCANCODE_C))
	{
		cout << "Chnging to Credit State" << endl;
		StateManager::ChangeState(new CreditState());// Change to New Credit State
	}

	else if (Game::GetInstance().KeyDown(SDL_SCANCODE_G))
	{
		cout << "Chnging to Game State" << endl;
		StateManager::ChangeState(new GameState());// Change to New Game State
	}
}
void MainMenuState::Render()
{
	cout << "Rendering Menu State" << endl;
	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 128,0, 128, 255);
	SDL_RenderClear(Game::GetInstance().GetRenderer());
}
void MainMenuState::Exit()
{
	cout << "Exiting Menu State..." << endl;
}

// End MainMenuState -- Begin CreditState

void CreditState::Enter()
{
	cout << "Entering Credit State" << endl;
}
void CreditState::Update(float deltaTime)
{
	if (Game::GetInstance().KeyDown(SDL_SCANCODE_ESCAPE))
	{
		cout << "Changing to Menu State" << endl;
		StateManager::ChangeState(new MainMenuState());
	}
}
void CreditState::Render()
{
	cout << "Rendering Credit State" << endl;
	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 192, 203, 1);
	SDL_RenderClear(Game::GetInstance().GetRenderer());

}
void CreditState::Exit()
{
	cout << "Exiting Credit State..." << endl;
}

// End CreditState -- Begin GameState

void GameState::Enter()//used for initilization
{
	timer = 0.0f;
	cout << "Entering Game State" << endl;

}
void GameState::Update(float deltaTime)
{
	if (timer > 20)
	{
		StateManager::ChangeState(new WinState);
	}

	if (Game::GetInstance().KeyDown(SDL_SCANCODE_P))
	{
		StateManager::PushState(new PauseState());
	}
	timer += deltaTime;
}
void GameState::Render()
{
	cout << "Rendering Game State..." << endl;

	SDL_Renderer* rendererPtr = Game::GetInstance().GetRenderer();
	SDL_SetRenderDrawColor(rendererPtr, 0, 0, 255, 255);
	SDL_RenderClear(rendererPtr);
}
void GameState::Exit()
{
	cout << "Exiting Game State..." << endl;
}
void GameState::Resume()
{
	cout << "Resuming Game State..." << endl;
}

// End GameState -- Begin PauseState 

void PauseState::Enter()
{
	cout << "Entering Pause State" << endl;
}
void PauseState::Update(float deltaTime)
{
	if (Game::GetInstance().KeyDown(SDL_SCANCODE_ESCAPE))
	{
		StateManager::PopState;
	}
}
void PauseState::Render()
{
	cout << "Rendering Pause State" << endl;
	// First we render the game state 
	StateManager::GetStates().front()->Render();
	// Then we render the rest of pause state 
	SDL_SetRenderDrawBlendMode(Game::GetInstance().GetRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 128, 128, 128, 255);
	SDL_Rect rect = { 256, 128, 512, 512 };
	SDL_RenderFillRect(Game::GetInstance().GetRenderer(), &rect);

	if (Game::GetInstance().KeyDown(SDL_SCANCODE_ESCAPE))
	{
		StateManager::ChangeState(new GameState());
	}
}
void PauseState::Exit()
{
	cout << "Exiting Pause State..." << endl;
}

// End PauseState -- Begin WinState

void WinState::Enter()
{
	cout << "Entering Win State" << endl;
}
void WinState::Update(float deltaTime)
{
	if (Game::GetInstance().KeyDown(SDL_SCANCODE_SPACE))
	{
		StateManager::ChangeState(new MainMenuState);
	}
}
void WinState::Render()
{
	cout << "Rendering Win State" << endl;
	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(Game::GetInstance().GetRenderer());
}
void WinState::Exit()
{
	cout << "Exiting Win State" << endl;
}

// End WinState -- Begin LosState

void LoseState::Enter()
{
	cout << "Entering Lose State" << endl;
}
void LoseState::Update(float deltaTime)
{
	if (Game::GetInstance().KeyDown(SDL_SCANCODE_SPACE))
	{
		StateManager::ChangeState(new MainMenuState);
	}
}
void LoseState::Render()
{
	cout << "Rendering Lose State" << endl;
	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 0, 0, 255);
	SDL_RenderClear(Game::GetInstance().GetRenderer());
}
void LoseState::Exit()
{
	cout << "Exiting Lose State" << endl;
}