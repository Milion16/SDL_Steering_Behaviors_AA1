#pragma once
#include "Agent.h"


class Pursuer
{
public:
	class SteeringBehavior
	{
	public:
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual void applySteeringForce(Pursuer *pursuer, float dtime) {};

		virtual void Separation(Agent *agent) {};
		virtual void Cohesion(Agent *agent) {};
		virtual void Alignment(Agent *agent) {};
		virtual void FlockingForce(Agent *agent, float dtime) {};
	};
private:
	SteeringBehavior *steering_behaviour;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;

	float speed;
	float orientation;
	float max_force;
	float max_velocity;
	float mass;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

	int min_pursuers = 20;

public:
	Pursuer();
	~Pursuer();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();
	void setBehavior(SteeringBehavior *behavior);
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Pursuer::loadSpriteTexture(char* filename, int num_frames = 1);

};