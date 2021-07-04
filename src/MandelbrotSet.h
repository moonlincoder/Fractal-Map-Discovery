// Created by moonlin on 23.06.2021.

#ifndef FRACTAL_MAP_DISCOVERY_MANDELBROTSET_H
#define FRACTAL_MAP_DISCOVERY_MANDELBROTSET_H

#include <chrono>
#include <complex>
#include <iostream>
#include "RenderNode.h"
#include "MainMenu.h"
//#include <SFML/Text.hpp>

#define FL128

#ifdef FL128
    #include <quadmath.h>
    typedef __float128 float128;
#else
    typedef float float128;
#endif //FL128

// Clion (2020.3) cannot inspect this code, and displays it as an error
typedef std::complex<float128> complex;
struct Coord { float128 x, y; };


class MandelbrotSet : public RenderNode {
    size_t max_iteration = 128;
    float128 width = 3;
    complex center = {-1, 0};
    Coord size = {static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)};
    float128 step = width / size.x;

public:
    explicit MandelbrotSet(sf::RenderWindow *renderWindow) : RenderNode(renderWindow) {};

    RenderNode *eventPoll(sf::Event &event) override;
    void draw() override;
};


#endif //FRACTAL_MAP_DISCOVERY_MANDELBROTSET_H
