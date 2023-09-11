#include"AGL.h"

int main() {
#ifdef __APPLE__
    std::cout << "This product is only available for windows at the moment" << std::endl;
    return 0;
#endif
    Window window = Init("Hello world", 1920, 1080);

    glm::vec3 lightCol = glm::vec3(1.0f, 0.0f, 0.0f);
    std::vector<Light*> lighting;

    Camera camera(glm::vec3(0, 5, -10), glm::vec3(0, 0, 0), glm::radians(45.0f));
    MainScene mainScene(&camera);

    Light lightT(glm::vec3(-1, 0, -1), lightCol, &mainScene);
    Light light(glm::vec3(3, 0, -1), lightCol, &mainScene);

    float* lightColour[] = { &lightT.colour.x, &lightT.colour.y, &lightT.colour.z };

    lighting.insert(lighting.cend(), &lightT);
    lighting.insert(lighting.cend(), &light);

    Cube cube(glm::vec3(0, 0, 3), lighting, &mainScene);
    Cube cubeT(glm::vec3(5, 1, 5), lighting, &mainScene);
    Cube cubeD(glm::vec3(2, 2, 4), lighting, &mainScene);
    Cube cubeF(glm::vec3(1, 3, 7), lighting, &mainScene);
    Cube cubeG(glm::vec3(3, -1, 7), lighting, &mainScene);
    Cube cubeV(glm::vec3(2, -1, 6), lighting, &mainScene);

    cube.SetTexture("Objects/3D/Cube/container.jpg");
    cubeD.SetTexture("Objects/3D/Cube/container.jpg");
    cubeV.SetTexture("Objects/3D/Cube/container.jpg");
    cubeT.SetTexture("Objects/3D/Cube/teams.jpg");
    cubeG.SetTexture("Objects/3D/Cube/teams.jpg");
    cubeF.SetTexture("Objects/3D/Cube/teams.jpg");

    cube.Rotate(45.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    glEnable(GL_DEPTH_TEST);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    float rotSpeed = 1.0f;

    while (!ShouldWindowClose(window)) {
        SetColour(glm::vec3(0.5961f, 0.5961f, 0.5961f));

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        cubeT.Rotate(0.5f * rotSpeed, glm::vec3(1.0f, 0.0f, 0.0f));

        mainScene.Render();


        ImGui::Begin("Window test");
        ImGui::Text("Hello there this is a test");
        ImGui::SliderFloat("Rot speed", &rotSpeed, 1.0f, 10.0f);
        ImGui::ColorEdit3("Light colour", *lightColour);
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SwapBuffers(window);
        PollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
