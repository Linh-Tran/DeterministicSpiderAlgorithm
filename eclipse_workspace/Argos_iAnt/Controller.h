#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/* Central Place Foraging Algorithm: state-not-state machine. */
#include "CPFA.h"
/* Implements navigation data container object. */
#include "NavigationData.h"
/* Implements food data container object. */
#include "FoodData.h"
/* Implements food source location tracking. */
#include "PheromoneWaypoint.h"
/* Base class for controller objects. */
#include <argos3/core/control_interface/ci_controller.h>
/* Updates the motor speed settings. */
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
/* Collision detection sensors. */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
/* Detect color changes on the ground for food & nest detection. */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_motor_ground_sensor.h>
/* Used in navigation to locate targets, light is fixed at the nest. */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_light_sensor.h>
/* Class for random number generator objects. */
#include <argos3/core/utility/math/rng.h>
/* The 2D vector definition used in ARGoS. */
#include <argos3/core/utility/math/vector2.h>
/* Provides LOG and LOGERR print out capability to the ARGoS GUI screen. */
#include <argos3/core/utility/logging/argos_log.h>

/* Provide access to ARGoS 3 classes and objects. */
using namespace argos;
/* Provide access to std::endl and std::vector, etc. */
using namespace std;

/* The controller class for iAnt robots. This is the "brain" for individual robot behavior,
 * and it implements the iAnt CPFA. */
class Controller : public CCI_Controller {

private:

	/* robot actuator and sensor components */
	CCI_DifferentialSteeringActuator *steeringActuator; // controls the robot's motor speeds
	CCI_FootBotProximitySensor       *proximitySensor;  // detects nearby objects to prevent collision
	CCI_FootBotMotorGroundSensor     *groundSensor;     // detects food items & nest (color changes)
	CCI_FootBotLightSensor           *lightSensor;      // detects nest-light for navigation control

	/* TODO note: you may need to move RNG to the "NavigationData"
	 * or the "CPFA" class to make this class less cluttered. */
	/* random number generator used for random walking, etc. */
	CRandom::CRNG *RNG;

	CPFA              CPFA_data; // CPFA data container.
	NavigationData    navData;   // Navigation data container object.
	FoodData          foodData;  // Food source data container.

	/* TODO note: you may want to move this pheromone object into the
	 * "foodData" or "navdata objects... */
	PheromoneWaypoint pheromone; // Food source location tracking.

public:

	/* Constructor function. */
	Controller();

	/* Destructor function. */
	~Controller();

    /* Initializes the controller.
     * You should always perform all your memory allocation and configuration in this method,
     * and not in the constructor.
     * @param t_node The XML tree associated to this controller.
     * @see Reset()
     * @see Destroy() */
	void Init(TConfigurationNode& node);

	/* Executes a control step.
     * The logic of your controller goes here. */
    void ControlStep();

    /* Resets the state of the controller to what it was right after Init() was executed.
     * Note that the state of the robot, as well as the state of sensors and actuators
     * is automatically reset by ARGoS outside this class.
     * @see Init()
     * @see Destroy() */
    void Reset();

    /* You should perform memory deallocation and clean up in this function.
     * @see Init()
     * @see Reset() */
    void Destroy();

};

#endif /* CONTROLLER_H_ */