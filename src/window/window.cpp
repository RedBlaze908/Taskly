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



    bool testbool = false;
    bool logged = false;

    char inputusername[60] = "";
    char inputpassword[60] = "";

    std::string username = "test";
    std::string password = "1234";

    int inttest = 10;
    float floattest = 5.5f;
    /*ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImVec4(255, 0, 0, 255 );
    style.WindowRounding = 0.100;*/


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

        ImGui::SetNextWindowSize(ImVec2(500, 500));
        if (ImGui::Begin("Test", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {
            ImGui::Text("Input Username >");
            ImGui::InputText("##usernameinput", inputusername, sizeof(inputusername));
            ImGui::Text("Input Password >");
            ImGui::InputText("##passwordinput", inputpassword, sizeof(inputpassword), ImGuiInputTextFlags_Password);

            if (ImGui::Button("Login")) {
                if (std::strstr(inputusername, username.c_str()) &&
                    std::strstr(inputpassword, password.c_str())) {
                    logged = true;
                }
            }
        }
        ImGui::End();

        if (logged) {
            ImGui::SetNextWindowSize(ImVec2(500, 500));
            if (ImGui::Begin("Window 2", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {
                ImGui::Checkbox("Test Bool", &testbool);
                if (ImGui::Button("Click Me!")) {
                    testbool = true;
                }
                ImGui::Text("Int");
                ImGui::SliderInt("Choose Number", &inttest, 1, 25);
                ImGui::Text("Float");
                ImGui::SliderFloat("Choose Number", &floattest, 1, 25);

                ImGui::SetCursorPos(ImVec2(400, 150));
                if (ImGui::Button("Test", ImVec2(50, 50))) {

                }
            }
            ImGui::End();
        }

        /* Rendering Area */
        window.clear();
        ImGui::SFML::Render(window);
        window.draw(shape);
        window.display();
    }

    Exit();
}
