#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

#include "../engine/AbstractGame.h"

struct GameKey {
	Point2 pos;
	bool isAlive;
};

class MyGame : public AbstractGame {
private:
	//my attributes
	QueueManager dialogueQueue;
	Dialogue dialogue;
	int numOflines;
	int linesPrinted = 0;
	CharacterManager manager;
	SDL_Rect textboxRect = { 75,400,1200,400 };
	SDL_Rect backgroundRect = { 0, 0, 1400, 788 };
	SDL_Texture* image;
	SDL_Texture* textBox;
	SDL_Texture* background;
	Mix_Chunk* clickSound;
	Mix_Chunk* bgMusic;
	std::string imagePath;
	std::string characterName;

	std::vector<std::shared_ptr<GameKey>> gameKeys;

	void handleKeyEvents();
	void update();
	void render();
	void renderUI();
public:
	MyGame();
	~MyGame();
};

#endif