#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2 ";

int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	srand(time(nullptr));
	//�����
	const size_t size = 5;
	CircleShape arr_circles[size];
	for (int i = 0; i < size; i++) {
		float radius = 200.f - 40.f * i;
		arr_circles[i].setRadius(radius);
		arr_circles[i].setFillColor(
			Color{(Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256)}
		);
		arr_circles[i].setPosition(
			(WINDOW_WIDTH - 2 * radius) / 2, (WINDOW_HEIGHT - 2 * radius) / 2);

	}

	//����� ��������������
	RectangleShape arr_rect[size];
	const float a = 50.f;
	for (int i = 0; i < size; i++) {
		arr_rect[i].setSize(Vector2f(a,a));
		arr_rect[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) }
		);
		arr_rect[i].setPosition(750, 100*i);
	}

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ��������� ����
		/*for (int i = 0; i < size; i++) {
			window.draw(arr_circles[i]);
		}*/
		for (int i = 0; i < size; i++) {
			window.draw(arr_rect[i]);
		}
		window.display();
	}

	return 0;hhj
}