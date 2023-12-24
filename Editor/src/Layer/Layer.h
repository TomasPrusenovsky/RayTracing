#pragma once
#include "RayTracer.h"

class Layer
{
public:
	virtual ~Layer() = default;
	virtual void OnUpdate() = 0;
	virtual void OnImGuiUpdate() = 0;

protected:
	static rt::RayTracer s_RayTracer;
};
