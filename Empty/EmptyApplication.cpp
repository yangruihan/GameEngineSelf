#include "BaseApplication.hpp"

namespace My 
{
    GfxConfiguration conf;
    BaseApplication g_App(conf);
    IApplication* g_pApp = &g_App;
}