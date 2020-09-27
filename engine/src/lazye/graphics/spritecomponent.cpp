#include <lazye/graphics/spritecomponent.h>

#include <lazye/core/entity.h>

#include <lazye/graphics/graphicsfactory.h>
#include <lazye/graphics/sprite.h>

namespace lazye
{
	SpriteComponent::SpriteComponent(const std::string& spritePath)
    {
		m_Sprite = std::make_unique<Sprite>(spritePath);
    }

	SpriteComponent::~SpriteComponent() = default;

	void SpriteComponent::Render(RenderingContext& context)
	{
		if (m_Sprite != nullptr)
		{
			const auto [view, projection] = context.GetViewProjectionMatrices();
			m_Sprite->Draw(GetOwner()->GetTransform().GetMatrix(), view, projection);
		}
	}
}