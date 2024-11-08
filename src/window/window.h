#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Taskly {
	sf::RenderWindow window;
	sf::Clock deltaClock;
	sf::Event evnt;

	bool isRunning = false;

	void Exit() { ImGui::SFML::Shutdown(); }

public:
	Taskly() {}
	~Taskly() {}

	void Start();
};