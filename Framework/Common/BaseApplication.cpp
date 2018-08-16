#include "BaseApplication.hpp"
#include <iostream>

bool My::BaseApplication::m_bQuit = false;

My::BaseApplication::BaseApplication(GfxConfiguration& cfg):m_Config(cfg)
{
}

//
// Parse command line, read configuration, initialize all sub modules
//
int My::BaseApplication::Initialize()
{
    std::cout << m_Config;

    m_bQuit = false;
    
    return 0;
}

//
// Finalize all sub modules and clean up all runtime temporary files
//
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
