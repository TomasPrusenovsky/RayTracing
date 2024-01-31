#pragma once 
#include "Layer/Layer.h"

class MenuLayer : public Layer
{
public:
	void OnUpdate() override;
	void OnImGuiUpdate() override;

private:
	void SavePng();

	bool m_ShowSavePopup = false;
	bool m_SaveEmpty = false;

	std::string m_Filename;
};