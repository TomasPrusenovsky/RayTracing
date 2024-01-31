#include "TestLayer.h"

using namespace rt;

TestLayer::TestLayer()
{
	auto& world = s_RayTracer.RtWorld();
	Material red{ Color::Red };
	Material cyan{ Color::Cyan };
	Material yellow{ Color::Yellow };
	Material magenta{ Color::Magenta };


	Sphere redSphere(0.5f, point(0, 0, -1.0f), red);
	Sphere blueSphere(0.6f, point(1.0f, 0.0f, -1.0f), cyan);
	Sphere cSphere(0.6f, point(1.0f, 0.0f, -1.0f), yellow);
	Sphere mSphere(0.6f, point(1.0f, 0.0f, -1.0f), magenta);

	world.Add(blueSphere);
	world.Add(redSphere);
	world.Add(cSphere);
	world.Add(mSphere);
}

void TestLayer::OnUpdate()
{
}

void TestLayer::OnImGuiUpdate()
{
}
