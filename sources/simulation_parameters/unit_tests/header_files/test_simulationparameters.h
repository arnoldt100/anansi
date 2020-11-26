#ifndef  test_simulationparameters_INC
#define  test_simulationparameters_INC


#define BOOST_TEST_MODULE Simulation Parameters

#include <boost/test/included/unit_test.hpp>
#include <iostream>

namespace utf = boost::unit_test;

class SimulationParametersFixture 
{
    public:
        SimulationParametersFixture()
        {
           return; 
        }

        ~SimulationParametersFixture()
        {
           return; 
        }

        void setup()
        {
            std::cout << "setup of SimulationParametersFixture." << std::endl;
        }

        void teardown()
        {
            std::cout << "teardown of SimulationParametersFixture." << std::endl;
        }
};

#endif   // ----- #ifndef test_simulationparameters_INC  ----- 
