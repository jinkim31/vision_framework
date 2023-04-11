#include "immapp/immapp.h"
#include "implot/implot.h"
#include "immvision/immvision.h"
#include "imgui_md_wrapper.h"
#include "eventThread.h"
#include <opencv2/opencv.hpp>
#include "custom_widgets.h"

void Gui()
{
    Widget::setStyle();
    ImPlot::ShowDemoWindow();
    ImGui::ShowDemoWindow();
    auto mat = cv::imread("../assets/world.jpg");
    ImmVision::ImageDisplay("image display!", mat);

    ImmVision::ImageParams p;
    ImmVision::Image("image display!", mat, &p);
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
