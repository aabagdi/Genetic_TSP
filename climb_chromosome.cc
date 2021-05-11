#include "climb_chromosome.hh"

ClimbChromosome::ClimbChromosome(const Cities * cities_ptr) : Chromosome(cities_ptr) // Constructor of derived class calls constructor of parent
{
// IS THIS CODE NECESSARY? If we're calling the Chromosome constructor, will it automatically do all of this stuff?
	cities_ptr_ = cities_ptr;
	order_ = Cities::random_permutation(cities_ptr->size());
	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine randEngine (seed1);
	generator_ = randEngine;
	assert(is_valid());
}