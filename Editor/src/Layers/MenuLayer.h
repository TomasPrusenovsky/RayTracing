#pragma once 
#include "Layer/Layer.h"

class MenuLayer : public Layer
{
public:
	void OnUpdate() override;
	void OnImGuiUpdate() override;

private:
	void SavePng();
	void MenuBar();

	bool m_ShowSavePopup = false;
	bool m_SaveEmpty = false;
	bool m_ShowStats = false;

	std::string m_Filename;
};