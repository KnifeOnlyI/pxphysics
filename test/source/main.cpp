#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "px/physics/util/CollisionUtil.hpp"

#define TARGET point1

void draw(sf::RenderWindow &window, const px::physics::Pos2D &point)
{
    sf::Vertex vertex {
        sf::Vector2f {static_cast<float>(point.getX()), static_cast<float>(point.getY())},
        sf::Color::Red
    };

    window.draw(&vertex, 1, sf::Points);
}

void draw(sf::RenderWindow &window, px::physics::Line2D &line)
{
    sf::Vertex vertex[] {
        sf::Vertex {sf::Vector2f {static_cast<float>(line.getA().getX()), static_cast<float>(line.getA().getY())},
                    sf::Color::Red},
        sf::Vertex {sf::Vector2f {static_cast<float>(line.getB().getX()), static_cast<float>(line.getB().getY())},
                    sf::Color::Red}
    };

    window.draw(vertex, 2, sf::Lines);
}

void draw(sf::RenderWindow &window, px::physics::Circle2D &circle)
{
    sf::CircleShape shape {circle.getRadius()};

    shape.setPosition(
        static_cast<float>(circle.getPos().getX()) - circle.getRadius(),
        static_cast<float>(circle.getPos().getY()) - circle.getRadius()
    );
    shape.setFillColor(sf::Color::Red);

    window.draw(shape);
}

void draw(sf::RenderWindow &window, px::physics::AABB &rectangle)
{
    sf::RectangleShape shape {
        sf::Vector2f(static_cast<float>(rectangle.getW()), static_cast<float>(rectangle.getH()))
    };

    shape.setPosition(static_cast<float>(rectangle.getPos().getX()), static_cast<float>(rectangle.getPos().getY()));
    shape.setFillColor(sf::Color::Red);

    window.draw(shape);
}

int main()
{
    sf::RenderWindow window {sf::VideoMode(800, 600), "My window"};
    sf::Event event {};

    px::physics::Pos2D point1;
    px::physics::Pos2D point2 {50, 50};

    px::physics::Line2D line1 {0, 0, -50, -50};
    px::physics::Line2D line2 {400, 300, 500, 400};

    px::physics::Circle2D circle1 {50};
    px::physics::Circle2D circle2 {700, 150, 50};

    px::physics::AABB aabb1 {50, 50};
    px::physics::AABB aabb2 {150, 150, 200, 200};

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
#if true
                point1.setXY(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
#elif false
                const int lastAX {line1.getA().getX()};
                const int lastAY {line1.getA().getY()};

                line1.getA().setXY(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                line1.getB().setRelativeXY(line1.getA().getX() - lastAX, line1.getA().getY() - lastAY);
#elif false
                circle1.getPos().setXY(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
#elif false
                aabb1.getPos().setXY(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                std::cout << "======================================================================================\n";
                std::cout << "AABB1 {X = " << aabb1.getPos().getX() << ", Y = " << aabb1.getPos().getY() << ", W = " << aabb1.getW() << ", H = " << aabb1.getH() << '\n';
                std::cout << "AABB2 {X = " << aabb2.getPos().getX() << ", Y = " << aabb2.getPos().getY() << ", W = " << aabb2.getW() << ", H = " << aabb2.getH() << '\n';
#endif
            }
        }

        window.clear();

        if (px::physics::CollisionUtil::check(TARGET, point2))
        {
            window.clear(sf::Color::Cyan);
        }

        if (px::physics::CollisionUtil::check(TARGET, line2))
        {
            window.clear(sf::Color::Blue);
        }

        if (px::physics::CollisionUtil::check(TARGET, circle2))
        {
            window.clear(sf::Color::Yellow);
        }

        if (px::physics::CollisionUtil::check(TARGET, aabb2))
        {
            window.clear(sf::Color::Green);
        }

        draw(window, TARGET);

        draw(window, point2);
        draw(window, line2);
        draw(window, circle2);
        draw(window, aabb2);

        window.display();
    }

    return 0;
}
