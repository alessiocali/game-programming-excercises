#pragma once
#include <lazye/lazye.h>

#include <lazye/graphics/renderingcontext.h>

#include <lazye/backends/sdl/sdlhelper.h>

namespace lazye
{
    class SDLRenderingContext : public RenderingContext
    {
    public:
        void Init(SDL_Window* sdlWindow);
        void Clear() override;
        void Render(const Sprite& sprite) override;
        void Present();

    private:
        SDLHelper::SDL_RendererPtr m_SDLRenderer = nullptr;
    };
}