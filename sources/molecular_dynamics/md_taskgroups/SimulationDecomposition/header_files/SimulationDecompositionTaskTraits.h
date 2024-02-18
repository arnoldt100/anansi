#ifndef ANANSI_SimulationDecompositionTaskTraits_INC
#define ANANSI_SimulationDecompositionTaskTraits_INC
//! \file SimulationDecompositionTaskTraits.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <array>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "GenericMDTask.hpp"

// Includes for abstract tasks.
#include "AtomsCommunicator.h"
#include "AtomsDecomposer.h"
#include "ReadAtoms.h"
#include "MacroCommand.hpp"

// Include for concrete tasks. 
#include "PointAtomsCommunicator.h"
#include "PointAtomsDecomposer.h"
#include "ReadPointAtoms.h"

namespace ANANSI
{

class SimulationDecompositionTaskTraits
{
    public:
        using abstract_products = MPL::mpl_typelist<
                                                       ReadPointAtoms::MyParentTask,
                                                       PointAtomsDecomposer::MyParentTask,
                                                       PointAtomsCommunicator::MyParentTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<ReadPointAtoms>,
                                                       GenericMDTask<PointAtomsDecomposer>,
                                                       GenericMDTask<PointAtomsCommunicator>
                                                   >;

        using receiver_results_t = MPL::mpl_typelist<
                                                    	ReadPointAtoms::receiver_result_t,
                                                        PointAtomsDecomposer::receiver_result_t,
                                                        PointAtomsCommunicator::receiver_result_t
                                                     >;

        static constexpr auto LABELS = std::array{
                                                    ReadPointAtoms::TASKLABEL,
                                                    PointAtomsDecomposer::TASKLABEL,
                                                    PointAtomsCommunicator::TASKLABEL
                                                 };

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        SimulationDecompositionTaskTraits ();   // constructor

        //! The copy constructor.
        SimulationDecompositionTaskTraits (const SimulationDecompositionTaskTraits & other);   // copy constructor

        //! The move constructor.
        SimulationDecompositionTaskTraits (SimulationDecompositionTaskTraits && other);   // copy-move constructor

        virtual ~SimulationDecompositionTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        SimulationDecompositionTaskTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        SimulationDecompositionTaskTraits& operator= ( const SimulationDecompositionTaskTraits &other ); // assignment operator

        //! The move assignment operator.
        SimulationDecompositionTaskTraits& operator= ( SimulationDecompositionTaskTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class SimulationDecompositionTaskTraits  -----


}; // End of namespace ANANSI

#endif // ANANSI_SimulationDecompositionTaskTraits_INC
