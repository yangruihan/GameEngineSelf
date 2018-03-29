#include "BaseApplication.hpp"
#include <iostream>

bool My::BaseApplication::m_bQuit = false;

My::BaseApplication::BaseApplication(GfxConfiguration& cfg):m_Config(cfg)
{
}

int My::BaseApplication::Initialize()
{
    std::cout << m_Config;
    return 0;
}

void My::BaseApplication::Finalize()
{
}

void My::BaseApplication::Tick()
{
}

bool My::BaseApplication::IsQuit()
{
    return m_bQuit;
}
