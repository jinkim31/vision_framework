#include "immapp/immapp.h"
#include "implot/implot.h"
#include "immvision/immvision.h"
#include "eventThread.h"
#include <opencv2/opencv.hpp>
#include "custom_widgets.h"

cv::Mat mat;
void Gui()
{
    //Widget::setStyle();
    ImPlot::ShowDemoWindow();
    ImGui::ShowDemoWindow();

    /*
    ImGui::Begin("Image view");
    {
        std::cout << "avail:" << ImGui::GetContentRegionAvail().x << "," << ImGui::GetContentRegionAvail().y
                  << std::endl;
        ImmVision::ImageDisplay("", mat, {(int) ImGui::GetContentRegionAvail().x / 2,
                                          (int) ImGui::GetContentRegionAvail().y / 2}, true);
    }ImGui::End();
     */
}

int main(int , char *[])
{
    mat = cv::imread("../assets/world.jpg");
    HelloImGui::RunnerParams runnerParams;
    runnerParams.callbacks.SetupImGuiStyle = Widget::setStyle;
    runnerParams.callbacks.ShowGui = Gui;
    runnerParams.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::ProvideFullScreenDockSpace;
    runnerParams.imGuiWindowParams.enableViewports = false;

    ImmApp::AddOnsParams addOnsParams;
    addOnsParams.withMarkdown = true;
    addOnsParams.withImplot = true;

    ImmApp::Run(runnerParams, addOnsParams);
    return 0;
}
