#include <cngine.h>

class Sandbox: public Cngine::Application {
public:
	Sandbox() {
	}

	~Sandbox() {
	}
};

Cngine::Application* Cngine::CreateApplication() {
	return new Sandbox();
}
