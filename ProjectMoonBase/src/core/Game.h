#pragma once
#include "../render/Common.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Game {
private:
	enum class GameState
	{
		GAME_BEGIN,
		GAME_RUNNING,
		GAME_EXIT
	};
	GameState currentState;
	bool beginExecuted;
	bool runningExecuted;

	void beginState();
	void runningState();
	void exitState();
	
public:
	Common common;

	Game() : currentState(GameState::GAME_BEGIN), beginExecuted(false), runningExecuted(false) {}


	void setGameState(GameState state) {
		currentState = state;
	}

	GameState getGameState() const {
		return currentState;
	}

	void update (float deltatime);
	void Input (float deltatime, GLFWwindow* window);
};
