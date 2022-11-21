#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#define maxParticles 50			//MAX PARTICLES ALLOWED AT ONE WHEN CREATED
class ParticleSystem {
public: Particle particles[maxParticles];		//CREATING ARRAY OF PARTICLE CLASS
	  sf::Vector2f position;
	  void Initialise(sf::Vector2f pos)
	  {
		  position = pos;
		  for (int i = 0; i < maxParticles; i++) //FOR LOOP OF ALL PARTICLES
		  {
				particles[i] = Particle(position,sf::Vector2f(rand() / double(RAND_MAX) * 6 - 2, rand() / double(RAND_MAX) * 6 - 2));	//SETTING RANDOM POS OF THE PARTICLES
		  }
	  }
	  void Update() { for (int i = 0; i < maxParticles; i++) { particles[i].Update(); } }		//UPDATING ALL PARTICLES
	  void Draw(sf::RenderWindow& win) { for (int i = 0; i < maxParticles; i++) { particles[i].Draw(win); } } ParticleSystem() {}		//DRAWING THE PARTICLES
};