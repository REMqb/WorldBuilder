#include <iostream>
#include <vector>
#include <glm/glm.hpp>

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
//#include <SFML/OpenGL.hpp>
#include <glbinding/gl33core/gl.h>
#include <glbinding/Binding.h>

#include <glm/vec3.hpp>

#include "core/types.hpp"

#include "protocol.pb.h"

#include <boost/asio.hpp>

using wb::i32;
using namespace gl33core;

int main()
{
    boost::asio::io_service ioService;

    boost::asio::ip::tcp::resolver resolver(ioService);

    boost::asio::ip::tcp::acceptor acceptor(ioService);

    sf::Window window(sf::VideoMode(800, 600), "WorldBuilder", sf::Style::Default, sf::ContextSettings(24,8,4,3,3,sf::ContextSettings::Core));
    glbinding::Binding::initialize(false);

    i32 c = 0;

    while (window.isOpen())
    {
        c++;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.setActive(true);
        glClearColor(fabsf(sinf(c/6000.f)),fabsf(sinf(c/10000.f+static_cast<float>(M_PI)*0.33f)),fabsf(sinf(c/13000.f+static_cast<float>(M_PI)*0.67f)),1);
        glClear(GL_COLOR_BUFFER_BIT);

        window.display();
    }

    std::vector<int> vec = {1,2,3,4};

    for(auto val : vec){
        std::cout << val << std::endl;
    }

    glm::vec3 v(1,2,3);

    std::cout << v.x << " " << v.y << " " << v.z << std::endl;

    std::cout << ioService.run() << std::endl;

    return 0;
}
