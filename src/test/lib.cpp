#include "hacklib/Main.h"
#include <chrono>
#include <cstdio>
#include <thread>


class TestMain : public hl::Main
{
public:
    bool init() override;
};

static hl::StaticInit<TestMain> g_main;


bool TestMain::init()
{
    printf("Library is running.\n");

    // Give the parent time to test for double inject.
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    printf("Library is detaching.\n");
    return false;
}
