#include "CPFA.h"

CPFA::CPFA() :
	travelProbability(0.0),
	searchProbability(0.0),
	uninformedSearchCorrelation(CRadians::ZERO),
	informedSearchDecay(0.0),
	siteFidelityRate(0.0),
	pheromoneRate(0.0),
	pheromoneDecayRate(0.0),
	state(SET_SEARCH_LOCATION)
{}

CPFA::~CPFA() {
}

void CPFA::Init(TConfigurationNode& node) {
}

/***
 *
 * Major TODO:
 *
 * Make the CPFA functions here accept the "navigation" and
 * "food" objects as a parameters and have it work on those
 * objects (pass by reference, etc)!
 *
 */
void CPFA::setSearchLocation() {
}

void CPFA::travelToSearchSite() {
}

void CPFA::performInformedWalk() {
}

void CPFA::performUninformedWalk() {
}

void CPFA::senseLocalResourceDensity() {
}

void CPFA::travelToNest() {
}