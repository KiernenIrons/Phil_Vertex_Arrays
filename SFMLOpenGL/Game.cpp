#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

// Vertices for one Triangle
float vertices[] = {
		 -1.0f, -1.0f, 1.0f ,
		 1.0f, -1.0f, 1.0f ,
		 1.0f, 1.0f, 1.0f ,
		 -1.0f, 1.0f, 1.0f ,

		 -1.0f, -1.0f, -1.0f ,
		 1.0f, -1.0f, -1.0f ,
		 1.0f, 1.0f, -1.0f ,
		 -1.0f, 1.0f, -1.0f 
};

// Colors for those vertices
float colors[] = { 1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f 
					};

// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2, 
								0, 2, 4,
								3, 2, 6,
								6, 7, 3,
								7, 6, 5,
								5, 4, 7,
								5, 0, 4,
								0, 5, 1,
								6, 1, 5,
								6, 2, 1,
								4, 0, 3,
								7, 4, 3};

void Game::run()
{
	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}
}

void Game::initialize()
{
	isRunning = true;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -8);
	glEnable(GL_CULL_FACE);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		glRotatef(1.0f, 0.0f, 0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		glRotatef(1.0f, 0.0f, 1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		glRotatef(1.0f, 1.0f, 0.0f, 0.0f);
	}

	cout << "No date" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	glDrawElements(GL_TRIANGLES, NUM_OF_POINTS, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();
}

void Game::unload()
{
	cout << "Dirtying up" << endl;
}