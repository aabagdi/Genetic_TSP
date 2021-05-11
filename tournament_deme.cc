

#include "tournament_deme.hh"

TournamentDeme::TournamentDeme(const Cities *cities_ptr, unsigned int pop_size, double mut_rate) : Deme(cities_ptr,
                                                                                                        pop_size,
                                                                                                        mut_rate) {
	// Do we need to re-implement the Deme constructor here, or will referencing the parent constructor do that for us?
	std::cout << "TournamentDeme Constructed" << std::endl;
	// Make sure mutation rate is within the range [0-1].
	if(mut_rate > 1.0 || mut_rate < 0.0){throw std::invalid_argument("Invalid mutation rate for a Deme. Ensure it's between 0 - 1.0.");}

	mut_rate_ = mut_rate;
	for(unsigned i = 0; i < pop_size; ++i){
		pop_.push_back(new ClimbChromosome(cities_ptr)); // Add a newly-generated Chromosome to pop_.
	}

}

TournamentDeme::~TournamentDeme()  {
	for(ClimbChromosome* climbChromo:pop_){ // Free memory used by the population.
		delete climbChromo;
	}
}

//ClimbChromosome *TournamentDeme::select_parent() { // Currently, this select_parent() uses ClimbChromosome, though we are permitted to use Chromosome if we choose!
//	// Amount of parents we're going to take
//	unsigned P = 16; // P must be a constant power of 2
//
//	std::vector<ClimbChromosome*> parent_pop(P); // Make a vector for our parents, of size P.
//
//
//
//}
