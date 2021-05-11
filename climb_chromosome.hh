/*
Climb_chromosme inherits from chromsome
*/
#pragma once
#include "chromosome.hh"

class ClimbChromosome : public Chromosome {


//Always explicitly write a virtual destructor
virtual ~ClimbChromosome() = default;

//Overide mutate
virtual void mutate() override
{
    //Evaluate fitness of original chromosome
    auto original_fitness = get_fitness();
    std::uniform_int_distribution<int> distr(0, order_.size() - 1); 
    //Pick a random point p in the chromosme
    auto p = distr(generator_);
    //Clone original chromosome for swap
    auto left_swapped = clone();
    if(p == 0){
        //If random index is 0, swap it with the last element of order_
        std::iter_swap(left_swapped->get_ordering().begin(), left_swapped->get_ordering().end());
    }
    //Else swap element at p with element at p - 1
    std::iter_swap(left_swapped->get_ordering().begin()+ p, left_swapped->get_ordering().begin() + (p - 1));
    auto left_fitness = left_swapped->get_fitness();    
    //Clone original chromosome for second swap
    auto right_swapped = clone();
    if(p == right_swapped->get_ordering().size() - 1){
        //If random index is last element, swap it with the first element
        std::iter_swap(right_swapped->get_ordering().end(), right_swapped->get_ordering().begin());
    }
    //Else swap element p with element p + 1
    std::iter_swap(right_swapped->get_ordering().begin() + p, right_swapped->get_ordering().begin() + (p + 1));
    auto right_fitness = right_swapped->get_fitness();

    //Determine the fittest of the 3 possibilities
    double max = original_fitness;
    if(left_fitness > max){
        max = left_fitness;
    }
    if(right_fitness > max){
        max = right_fitness;
    }
    if(max == original_fitness){
        //order_ is unchanged
        return;
    }
    if(max == right_fitness){
        //right_swapped is fittest
        order_ = right_swapped->get_ordering();     //Might be issue with get ordering returning an immutable reference?
        return;
    }
    if(max == left_fitness){
        //left_swapped is fittest   
        order_ = left_swapped->get_ordering();
        return;
    }
    return;
}








}























}

