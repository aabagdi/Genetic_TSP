#include "tournament_deme.hh"

TournamentDeme::TournamentDeme(const Cities *cities_ptr, unsigned int pop_size, double mut_rate) : Deme(cities_ptr,
                                                                                                        pop_size,
                                                                                                        mut_rate) {
	// Do we need to re-implement the Deme constructor here, or will referencing the parent constructor do that for us?
}

TournamentDeme::~TournamentDeme() {
	for(Chromosome* chrom:pop_){ // Free memory used by the population.
		delete chrom;
	}
}

ClimbChromosome *TournamentDeme::select_parent() { // Currently, this select_parent() uses ClimbChromosome, though we are permitted to use Chromosome if we choose!
	// Amount of parents we're going to take
	unsigned P = 16; // P must be a constant power of 2

	std::vector<ClimbChromosome*> parent_pop(P); // Make a vector for our parents, of size P.


}
