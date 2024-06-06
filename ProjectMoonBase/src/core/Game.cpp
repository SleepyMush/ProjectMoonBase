#include "Game.h"

void Game::update(float deltatime)
{
    Game game;

    game.setGameState(Game::GameState::GAME_BEGIN);

	switch (currentState)
	{
	case Game::GameState::GAME_BEGIN:
		if (!beginExecuted) {
			beginState();
			beginExecuted = true; 
		}
		break;
	case Game::GameState::GAME_RUNNING:
		if (!runningExecuted) {
			runningState();
			runningExecuted = true;
		}
		break;
	case Game::GameState::GAME_EXIT:
		exitState();
		break;

	default:
		break;
	}

}

void Game::Input(float deltatime, GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Game::beginState()
{
	common.initialize();
}

void Game::runningState()
{
	common.render();
}

void Game::exitState()
{
	common.~Common();
}