#include "window.h"

void Taskly::Start() {
	window.create(sf::VideoMode(sf::Vector2u(1280, 720)), "Taskly");
    if (!window.isOpen()) {
        std::cerr << "Error: While trying to open the SFML Window" << std::endl;
        exit(EXIT_FAILURE);
    }
    isRunning = true;
    window.setFramerateLimit(60);
	ImGui::SFML::Init(window);

	ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_::ImGuiConfigFlags_DockingEnable;

    //Shape Test
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color(255, 127, 80));
    shape.setPosition(sf::Vector2f(200.f, 100.f));

    while (isRunning) {
        
        while (window.pollEvent(evnt)) {
            ImGui::SFML::ProcessEvent(evnt);

            if (evnt.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time deltaTime = deltaClock.restart();

        ImGui::SFML::Update(window, deltaTime);

        /* Add Code Here */

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(200, window.getSize().y));
        ImGui::Begin("Side Area", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

        if (ImGui::Button("Button 1")) {
            std::cout << "Button 1 Pressed!" << std::endl;
        }

        if (ImGui::Button("Button 2")) {
            std::cout << "Button 2 Pressed!" << std::endl;
        }

        ImGui::End();

        /* Rendering Area */
        window.clear();
        ImGui::SFML::Render(window);
        window.draw(shape);
        window.display();
    }

    Exit();
}
