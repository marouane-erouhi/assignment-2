#include "UIManager.h"
#include "JSONFileLoader.h"
UIManager * UIManager::instance;
UIManager * UIManager::getInstance() {
	if (!instance)	instance = new UIManager();
	return instance;
}

UIManager::UIManager() {}

UIContainer * UIManager::getUI() {
	return this->currentUI;
}

bool UIManager::setUI(const char * uiName, SDL_Renderer* renderer) {
	//use them factories
	if (uiName == "dota2ui") {
		delete currentUI;
		currentUI = UIContainer::Dota2UIFactory(renderer);
		//JSONFileLoader::loadUIFromFile(currentUI, renderer, "dota2ui.json");
		return true;
	}else if(uiName == "overwatchui"){
		delete currentUI;
		currentUI = UIContainer::OverwatchUIFactory(renderer);
		//JSONFileLoader::loadUIFromFile(currentUI, renderer, "overwatchui.json");
		return true;
	}
	return false;
}