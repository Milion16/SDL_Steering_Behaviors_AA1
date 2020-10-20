#pragma once
#include "Agent.h"
#include "Pursuer.h"
#include "Obstacle.h"

class Flocking :
	public Pursuer::SteeringBehavior_2
{
public:

	float min_distance;
	float max_distance;

	Vector2D my_pos;
	Vector2D bro_pos;

	std::vector<Vector2D> sep_force;
	std::vector<Vector2D> coh_force;
	std::vector<Vector2D> ali_force;

	std::vector<Vector2D> flock_force;

	float sep_const, coh_const, ali_const, flock_const;

public:
	Flocking();
	~Flocking();
public:
	void Separation(int p, std::vector<Pursuer>& bros);
	void Cohesion(int p, std::vector<Pursuer>& bros);
	void Alignment(int p, std::vector<Pursuer>& bros);
	void PursueForce(Pursuer *pursuer, float dtime);
	void FlockingForce(int p, std::vector<Pursuer>& bros, float dtime);

};
