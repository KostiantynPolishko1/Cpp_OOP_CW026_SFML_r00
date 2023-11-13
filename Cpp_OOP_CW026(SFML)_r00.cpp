#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int main()
{
    short size = 255, step = 0;
    short arrRGB[] = { 0, size, 0 };

    sf::RenderWindow TrafficLights(sf::VideoMode(400, 400), "TrafficLight");
    
    while (TrafficLights.isOpen()) 
    {
        sf::Event event;
        while (TrafficLights.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                TrafficLights.close();
        }

        for (short n = 0; n != 2; n++)
            for (short i = 0; i != 3; i++)
            {
                //std::cout << "\t" << i << "\n";

                step = i % 2 == 0 ? 1 : -1;
                step *= n % 2 == 0 ? 1 : -1;

                for (short j = 0; j != size; ++j) {
                    arrRGB[i] += step;

                    TrafficLights.clear(sf::Color(arrRGB[0], arrRGB[1], arrRGB[2]));
                    TrafficLights.display();
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }
            }

        //TrafficLights.clear(sf::Color::Red);
        //TrafficLights.display();
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //
        //TrafficLights.clear(sf::Color::Yellow);
        //TrafficLights.display();
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //
        //TrafficLights.clear(sf::Color::Green);
        //TrafficLights.display();
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //    
        //TrafficLights.clear(sf::Color::Yellow);
        //TrafficLights.display();
        //std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    return 0;
}
