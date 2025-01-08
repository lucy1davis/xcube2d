#include "MyGame.h"

MyGame::MyGame() : AbstractGame() {
	TTF_Font* font = ResourceManager::loadFont("res/fonts/arial.ttf", 30);
	gfx->useFont(font);
	gfx->setVerticalSync(true);
	//my code
	dialogueQueue.readTextFile("demoScript.txt", dialogueQueue, manager);
	numOflines = dialogueQueue.textList.size();
	textBox = ResourceManager::loadTexture("images/textbox.png", SDL_COLOR_AQUA);
	background = ResourceManager::loadTexture("images/singleBedroomv2.png", SDL_COLOR_AQUA);
	clickSound = ResourceManager::loadSound("res/click.wav");
	bgMusic = ResourceManager::loadSound("res/003_Vaporware.wav");
	sfx->playSound(bgMusic, 5);
}

MyGame::~MyGame() {

}

void MyGame::handleKeyEvents() {
	if (eventSystem->MouseClick(Mouse::BTN_LEFT) || linesPrinted == 0) {
		sfx->playSound(clickSound, 5);
		dialogueQueue.wrapLines(dialogueQueue, 75);
		imagePath = manager.returnImageFilePath(manager);
		linesPrinted += 1;
		if (imagePath != "")
		{
			dialogue.image = ResourceManager::loadTexture(imagePath, SDL_COLOR_AQUA);
		}
		dialogue.name = manager.getName(manager);
	}
}

void MyGame::update() {

	if (linesPrinted > numOflines) {
		running = false;
	}
}

void MyGame::render() {
	gfx->drawTexture(background, &backgroundRect);
	if (!imagePath.empty())
	{
		dialogue.drawDialogueImage(gfx, dialogue, 400, -80, 667, 1000);
	}
}

void MyGame::renderUI() {
	gfx->drawTexture(textBox, &textboxRect);
	dialogue.drawDialogueText(gfx, dialogueQueue, 200, 500, 30);
	dialogue.drawCharacterName(gfx, dialogue, 300, 420);
}



