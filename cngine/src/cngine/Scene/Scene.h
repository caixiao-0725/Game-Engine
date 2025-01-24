#pragma once
#include "entt.hpp"
#include "cngine/Core/Timestep.h"
namespace Cngine {

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(Timestep ts);
	private:
		entt::registry m_Registry;
		friend class Entity;
	};
}