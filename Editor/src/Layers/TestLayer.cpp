#include "TestLayer.h"

using namespace rt;

TestLayer::TestLayer() {
	auto& world = s_RayTracer.RtWorld();
	Material red{ Color::Red };
	Material cyan{ Color::Cyan };
	Material yellow{ Color::Yellow };
	Material magenta{ Color::Magenta };
	Material blue{ Color::Blue };
	Material white{ Color::White };
	Material green{ Color::Green };


	Sphere redSphere(1.5f, point(0, 0, 0.0f), red);
	Sphere blueSphere(0.6f, point(1.0f, 0.0f, -1.0f), cyan);
	Sphere cSphere(0.6f, point(1.0f, 0.0f, -1.0f), yellow);
	Sphere mSphere(0.6f, point(1.0f, 0.0f, -1.0f), magenta);

	Plane plane{ point{0.0f, -5.0f, 0.00f}, glm::vec3(0.0f, 1.0f, 0.0f), white};
	Plane plane2{ point{0.0f, 5.0f, 0.0f}, glm::vec3(0.0f, 1.0f, 0.0f), white};
	Plane plane3{ point{0.0f, 0.0f, 10.0f}, glm::vec3(0.0f, 0.0f, 1.0f), white};
	Plane plane4{ point{0.0f, 0.0f, -5.0f}, glm::vec3(0.0f, 0.0f, 1.0f), blue};
	Plane plane5{ point{5.0f, 0.0f, 0.0f}, glm::vec3(1.0f, 0.0f, 0.0f), red};
	Plane plane6{ point{-5.0f, 0.0f, 0.0f}, glm::vec3(1.0f, 0.0f, 0.0f), green};


	world.Add(plane);
	world.Add(plane2);
	world.Add(plane3);
	world.Add(plane4);
	world.Add(plane5);
	world.Add(plane6);
	world.Add(redSphere);



}

void TestLayer::OnUpdate()
{
}

void TestLayer::OnImGuiUpdate()
{
}
