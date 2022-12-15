project(MachineLib)

set(SOURCE_FILES
        pch.h
        MachineSystem.h MachineSystem.cpp MachineSystemFactory.cpp MachineSystemFactory.h MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h MachineSystemActual.cpp MachineSystemActual.h Polygon.cpp Polygon.h Component.cpp Component.h Motor.cpp Motor.h Sink.cpp Sink.h Source.cpp Source.h Shape.cpp Shape.h MachineInterpret.cpp MachineInterpret.h Pulley.cpp Pulley.h PegWheel.cpp PegWheel.h Lever.cpp Lever.h Machine1Factory.cpp Machine1Factory.h Machine.cpp Machine.h Machine2Factory.cpp Machine2Factory.h Instrument.cpp Instrument.h Peg.cpp Peg.h Winch.cpp Winch.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

# Fetch miniaudio from Github
include(FetchContent)
FetchContent_Declare(
        miniaudio
        GIT_REPOSITORY https://github.com/mackron/miniaudio.git
        GIT_TAG 1778a5e839514f35f41d31449f3573e3adffc51a # Version 0.11.10
)

FetchContent_MakeAvailable(miniaudio)

target_include_directories(${PROJECT_NAME} PUBLIC "${miniaudio_SOURCE_DIR}")
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)