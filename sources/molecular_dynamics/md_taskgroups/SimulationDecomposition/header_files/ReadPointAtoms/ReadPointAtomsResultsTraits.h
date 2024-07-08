#ifndef ANANSI_ReadPointAtomsResultsTraits_INC
#define ANANSI_ReadPointAtomsResultsTraits_INC
//! \file ReadPointAtomsResultsTraits.h
//!
//! \brief Brief description
//!
//! \details  Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PhysicalDataStructure.h"
#include "SimulationDecompositionPrecisionPolicy.h"
#include "SimulationDecompositionExecutionPolicy.h"
#include "Atoms.h"
#include "PointAtoms.h"
#include "ParticlesConfigurationFiles.hpp"
#include "XMLFileReader.h"
#include "XMLFileWriter.h"
#include "PointAtomsConfigurationFileNodeKeys.h"
#include "FilePicklerPropertyTreePointAtoms.hpp"

namespace ANANSI
{

class ReadPointAtomsResultsTraits
{
    public:
        // ====================  ALIASES       =======================================

        using result_t = PhysicalDataStructure<DataStoragePolicy::Type,PrecisionPolicy::Type>;
        using Atoms_t = PointAtoms<SimulationDecompositionExecutionPolicy::Type,
                                   SimulationDecompositionPrecisionPolicy::Type>;
        using ParticlesConfigurationFiles_t = ParticlesConfigurationFiles<PointAtomsConfigurationFileNodeKeys,
                                                                          XMLFileReader,
                                                                          XMLFileWriter,
                                                                          FilePickler<boost::property_tree::ptree,Atoms>
                                                                         >;

        using copy_result_t = result_t;
        using share_result_t = result_t;
        using transfer_result_t = result_t;

        // ====================  LIFECYCLE     =======================================

        ReadPointAtomsResultsTraits ();   // constructor

        ReadPointAtomsResultsTraits (const ReadPointAtomsResultsTraits & other);   // copy constructor

        ReadPointAtomsResultsTraits (ReadPointAtomsResultsTraits && other);   // copy-move constructor

        ~ReadPointAtomsResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================
        ReadPointAtomsResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReadPointAtomsResultsTraits& operator= ( const ReadPointAtomsResultsTraits &other ); // assignment operator

        ReadPointAtomsResultsTraits& operator= ( ReadPointAtomsResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----  End of class ReadPointAtomsResultsTraits  -----
}; // ----- End of namespace ANANSI -----

#endif // ANANSI_ReadPointAtomsResultsTraits_INC
