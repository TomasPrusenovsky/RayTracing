#include "Layer/Layer.h"
#include <filesystem>

class SkyboxLayer : public Layer
{
public:
	SkyboxLayer() = default;

	~SkyboxLayer() override = default;
	void OnUpdate() override;
	void OnImGuiUpdate() override;

private:
	std::filesystem::path m_assetsDir = "assets";
	std::filesystem::path m_currentDir = "assets";
};