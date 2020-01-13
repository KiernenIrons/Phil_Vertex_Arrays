#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include <Matrix3.h>

using namespace std;
using namespace sf;
using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	const int NUM_OF_POINTS = 36;

	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};