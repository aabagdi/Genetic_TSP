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

//The new mutation operator we’ll try is called “local hill climbing”, because it searches for the best solution in
// a small local “neighborhood” of the current chromosome. It works as follows (assuming N cities, i.e. a chromosome with N genes):
	// A. evaluate the fitness of the current (original) chromosome.
	// B. Pick a random point p in the chromosome.
	// C. Swap the city at index p with the city at index p-1 and evaluate the resulting chromosome's fitness. If p==0, swap with the city at index N-1 instead of at index p-1.
	// D. Swap the city at index p (from the original chromosome) with the city at index p+1 and evaluate the resulting chromosome's fitness. If p==N-1, swap with the city at index 0 instead of at index N. (hint: use modulus).
	// E. Find which of the three chromosomes (i.e., chromosomes from steps A, C, and D) produced the fittest ordering and choose that fittest chromosome as the resulting mutated chromosome.
//void ClimbChromosome::mutate() {
//	double original_fitness = get_fitness(); // Get initial fitness of chromosome.
//
//	std::uniform_int_distribution<int> distr(0, order_.size() - 1); // For picking a random point .
//
//	int p = distr(generator_); // Pick a random point p in the chromosome.
//
//	auto left_swapped = clone();
//
//
//}


