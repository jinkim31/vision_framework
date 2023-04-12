#include "immapp/immapp.h"
#include "implot/implot.h"
#include "immvision/immvision.h"
#include "eventThread.h"
#include <opencv2/opencv.hpp>
#include "custom_widgets.h"
#include <imgui_tex_inspect/imgui_tex_inspect.h>

cv::Mat mat;
int count =0;

void Gui()
{
    Widget::setStyle();
    ImPlot::ShowDemoWindow();
    ImGui::ShowDemoWindow();

    mat = cv::Mat::zeros(300, 300, CV_8UC1);
    cv::putText(mat, std::to_string(count++), cv::Point(10, mat.rows), cv::FONT_HERSHEY_DUPLEX,2.0,255, 2);


    ImGui::Begin("Image view");
    {
        static ImmVision::ImageParams p;
        p.RefreshImage = true;
        p.ImageDisplaySize = {(int) ImGui::GetContentRegionAvail().x,(int) ImGui::GetContentRegionAvail().y-50};
        p.ShowSchoolPaperBackground = false;
        p.ShowOptionsInTooltip = true;
        p.ShowOptionsButton = false;
        p.ShowImageInfo = false;
        p.ShowPixelInfo = false;
        ImmVision::Image("", mat, &p);
    }ImGui::End();
}

int main(int , char *[])
{
    HelloImGui::RunnerParams runnerParams;
    runnerParams.callbacks.SetupImGuiStyle = Widget::setStyle;
    runnerParams.callbacks.ShowGui = Gui;
    runnerParams.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::ProvideFullScreenDockSpace;
    runnerParams.imGuiWindowParams.enableViewports = false;
    runnerParams.fpsIdling.enableIdling = false;

    ImmApp::AddOnsParams addOnsParams;
    addOnsParams.withMarkdown = true;
    addOnsParams.withImplot = true;
    addOnsParams.withTexInspect = true;

    ImmApp::Run(runnerParams, addOnsParams);
    return 0;
}
