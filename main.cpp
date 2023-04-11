#include "immapp/immapp.h"
#include "implot/implot.h"
#include "imgui_md_wrapper.h"

void Gui()
{
    ImPlot::ShowDemoWindow();
    ImGui::ShowDemoWindow();
}

int main(int , char *[])
{
    HelloImGui::SimpleRunnerParams runnnerParams;
    runnnerParams.guiFunction = Gui;
    runnnerParams.windowSize = {600, 800};

    ImmApp::AddOnsParams addOnsParams;
    addOnsParams.withMarkdown = true;
    addOnsParams.withImplot = true;

    ImmApp::Run(runnnerParams, addOnsParams);
    return 0;
}
