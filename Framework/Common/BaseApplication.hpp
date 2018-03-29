#pragma once

#include "IApplication.hpp"
#include "GfxConfiguration.hpp"

namespace My {
    class BaseApplication : implements IApplication
    {
    public:
        BaseApplication(GfxConfiguration& cfg);

        virtual int Initialize();
        virtual void Finalize();
        virtual void Tick();

        virtual bool IsQuit();

    protected:
        static bool m_bQuit;
        GfxConfiguration m_Config;

    private:
        BaseApplication() {};
    };
}
