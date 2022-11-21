#pragma once
#include <SFML/Graphics.hpp>
class Particle {
public:
	int timetoLive;		//TIME OF THE PARTICLE TO LIVE
	sf::Vector2f velocity;		//SPEED OF THE PARTICLE
	sf::CircleShape shape;	//SHAPE
	void Draw(sf::RenderWindow& win)	//DRAW FUNC
	{
		if (timetoLive > 0)				//DRAWING SHAPE
		{
			win.draw(shape);
		}
	}
	void Update() {						//UPDATE FUNC
		if (timetoLive > 0)			
		{	
			shape.move(velocity);		//MOVING THE PARTICLE
			timetoLive--;
		}
	}
	Particle() {}
	Particle(sf::Vector2f pos, sf::Vector2f vel) {
		shape.setRadius(5.0f);			//SIZE OF EACH PARTICLE
		shape.setPosition(pos);						//SETTING ITS POSITION
		shape.setFillColor(sf::Color::Yellow);		//SETTING COLOUR
		velocity = vel; //timetoLive = 200;			SPEED
		timetoLive = rand() % 50;					//RANDOM NUMBER OF LIVE FOR THE PARTICLES
	}
};