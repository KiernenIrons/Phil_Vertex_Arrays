#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
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

Vector3 m_points[] = { {vertices[0], vertices[1], vertices[2]},
					   {vertices[3], vertices[4], vertices[5]},
					   {vertices[6], vertices[7], vertices[8]} ,
					   {vertices[9], vertices[10], vertices[11]} ,
					   {vertices[12], vertices[13], vertices[14]} ,
					   {vertices[15], vertices[16], vertices[17]} ,
					   {vertices[18], vertices[19], vertices[20]} ,
					   {vertices[21], vertices[22], vertices[23]}
};

// Colors for those vertices
float colors[] = { 1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f 
					};

// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2, 
								2, 3, 0,
								2, 6, 3,
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

	sf::Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
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
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::RotationX(rotationAngle) * m_points[index];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::RotationY(rotationAngle) * m_points[index];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::RotationZ(-rotationAngle) * m_points[index];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::Translate(0, -1) * m_points[index];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::Translate(0, 1) * m_points[index];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::Translate(-1, 0) * m_points[index];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::Translate(1, 0) * m_points[index];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::Scale(99.0, 99.0) * m_points[index];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
	{
		for (int index = 0; index < 8; index++)
		{
			m_points[index] = Matrix3::Scale(110.0, 110.0) * m_points[index];
		}
	}

	for (int i = 0, j = 0; i < 4, j < 24; i++)
	{
		vertices[j] = m_points[i].m_x;
		j++;

		vertices[j] = m_points[i].m_y;
		j++;

		vertices[j] = m_points[i].m_z;
		j++;
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