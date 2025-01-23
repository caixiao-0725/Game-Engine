#include <Cngine.h>
#include <Cngine/Core/EntryPoint.h>
#include "EditorLayer.h"
namespace Cngine {
	class CngineEditor : public Application
	{
	public:
		CngineEditor()
			: Application("Cngine Editor")
		{
			PushLayer(new EditorLayer());
		}
		~CngineEditor()
		{
		}
	};
	Application* CreateApplication()
	{
		return new CngineEditor();
	}
}