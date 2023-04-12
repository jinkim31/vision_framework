#include "immapp/immapp.h"
#include "implot/implot.h"
#include "immvision/immvision.h"
#include "eventThread.h"
#include <opencv2/opencv.hpp>
#include "custom_widgets.h"
#include <imgui_tex_inspect/imgui_tex_inspect.h>

cv::Mat mat;
void Gui()
{
    Widget::setStyle();
    ImPlot::ShowDemoWindow();
    ImGui::ShowDemoWindow();

    ImGui::Begin("Image view");
    {
        //ImmVision::ImageDisplay("", mat, {(int) ImGui::GetContentRegionAvail().x,(int) ImGui::GetContentRegionAvail().y-100}, true, true);
        static ImTextureID textureId = 0;
        if(textureId==0)
            textureId = HelloImGui::ImTextureIdFromAsset("../assets/world.jpg");

        std::cout<<"tex:"<<textureId<<std::endl;
        static ImVec2 textureSize(512.f, 512.f);
        ImGui::Text("texinspect");
        ImGuiTexInspect::InspectorFlags flags=0;
        flags |= ImGuiTexInspect::InspectorFlags_FillVertical;
        flags |= ImGuiTexInspect::InspectorFlags_FillHorizontal;
        ImGuiTexInspect::SizeIncludingBorder inspectorSize({ImGui::GetContentRegionAvail().x,ImGui::GetContentRegionAvail().y});
        if(ImGuiTexInspect::BeginInspectorPanel("Inspector", textureId, textureSize, flags, inspectorSize))
            ImGuiTexInspect::EndInspectorPanel();
    }ImGui::End();
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
    addOnsParams.withTexInspect = true;

    ImmApp::Run(runnerParams, addOnsParams);
    return 0;
}
