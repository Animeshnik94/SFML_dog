#include <SFML/Graphics.hpp>

    

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Dog", sf::Style::Close);

    //-----Создание границ игрового поля----------

    sf::RectangleShape topBorder(sf::Vector2f(500, 10));
    topBorder.setFillColor(sf::Color::Green);
    topBorder.setPosition(0, 0);

    sf::RectangleShape bottomBorder(sf::Vector2f(500, 10));
    bottomBorder.setFillColor(sf::Color::Green);
    bottomBorder.setPosition(0, 490);

    sf::RectangleShape leftBorder(sf::Vector2f(10, 500));
    leftBorder.setFillColor(sf::Color::Green);
    leftBorder.setPosition(0, 0);

    sf::RectangleShape rightBorder(sf::Vector2f(10, 500));
    rightBorder.setFillColor(sf::Color::Green);
    rightBorder.setPosition(490, 10);

    //-----Создание игрока----------
    sf::RectangleShape player(sf::Vector2f(40, 40));
    player.setFillColor(sf::Color::Red);
    player.setPosition(10, 10);

    //-----Цикл игры----------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x > 10)
        {
            player.move(-0.1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x < 450)
        {
            player.move(0.1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.getPosition().y > 10)
        {
            player.move(0, -0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getPosition().y < 450)
        {
            player.move(0, 0.1);
        }

        window.clear();
        window.draw(topBorder);
        window.draw(bottomBorder);
        window.draw(leftBorder);
        window.draw(rightBorder);
        window.draw(player);
        window.display();
    }

    return 0;
}