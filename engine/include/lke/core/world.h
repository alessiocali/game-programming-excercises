#pragma once
#include <lke/lke.h>

#include <chrono>
#include <vector>
#include <memory>

namespace lke
{
    class Window;
    class Entity;
    class RenderingContext;

    /**
     * @brief A set of Entities that run at the same time
     */
    class lkedll World
    {
    public:
        static World& GetInstance();

        ~World();

        World(const World& world) = delete;
        World& operator=(const World& world) = delete;

        void SetWindow(std::unique_ptr<Window> window);
        RenderingContext& GetRenderingContext();

        std::weak_ptr<Entity> CreateEntity();

        void Play();
        bool IsAlive() const;
        void Update(float dt);

    private:
        World();

        std::unique_ptr<Window> m_Window;
        std::vector<std::shared_ptr<Entity>> m_Entities;
        std::chrono::time_point<std::chrono::steady_clock> m_LastFrameIstant;
        std::chrono::duration<float> m_CurrentDt;
    };
}