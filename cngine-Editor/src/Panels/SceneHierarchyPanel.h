#pragma once
#include "Cngine/Core/core.h"
#include "Cngine/Core/Log.h"
#include "Cngine/Scene/Scene.h"
#include "Cngine/Scene/Entity.h"
namespace Cngine {
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);
		void SetContext(const Ref<Scene>& scene);
		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}