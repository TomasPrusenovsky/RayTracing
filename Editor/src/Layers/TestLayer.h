#include "Layer/Layer.h"

class TestLayer : public Layer
{
public:
	TestLayer();
	~TestLayer() override = default;
	void OnUpdate() override;
	void OnImGuiUpdate() override;

private:
};