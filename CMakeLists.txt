cmake_minimum_required(VERSION 3.12)
project(vision_framework)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
        imgui_bundle
        GIT_REPOSITORY https://github.com/pthom/imgui_bundle.git
        GIT_PROGRESS TRUE
        GIT_TAG main
)
FetchContent_MakeAvailable(imgui_bundle)
list(APPEND CMAKE_MODULE_PATH ${IMGUIBUNDLE_CMAKE_PATH})
include(imgui_bundle_add_app)
set(IMGUI_BUNDLE_FETCH_OPENCV ON)

add_subdirectory(lib/event_thread)
find_package(OpenCV REQUIRED)

imgui_bundle_add_app(${PROJECT_NAME}
        src/main.cpp
        src/custom_widgets.cpp
        )
target_link_libraries(${PROJECT_NAME} PRIVATE
        ${OpenCV_LIBS}
        event_thread
        )
