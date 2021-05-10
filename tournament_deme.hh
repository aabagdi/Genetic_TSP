#pragma once
#include "deme.hh"
//Assignment:
// This class inherits from the Deme class and overrides whatever is necessary in your judgement for
// your class to replace the parent selection algorithm.
// It can use either Chromosome or ClimbChromosome: experiment with both when you're done and pick the best one.

//"Tournament Selection" method:
// A. Select P parents at random, where P is a constant power of two that you choose (no bigger than the population size).
// B. Take the first pair in the set of P parents and discard the parent with the lower fitness of the two.
// C. Do the same for the next pair, and so forth. You should have P/2 parents in the resulting set.
// D. Repeat steps B - C until you're left with only one parent.

class TournamentDeme : public deme{

}
