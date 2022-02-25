
#include "CantorPairing.h"


namespace MEMORY_MANAGEMENT
{

    //////////////////////////////////////////////////////////////////////////////
    /////////////////////////////// PUBLIC ///////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////


    //============================= LIFECYCLE ====================================

    CantorPairing::CantorPairing() 
    {
        return;
    }


    CantorPairing::~CantorPairing() 
    {
        return;
    }


    CantorPairing::CantorPairing( CantorPairing const & other) 
    {
        if (this != &other)
        {

        }
        return;
    }
    //============================= ACCESSORS ====================================

    std::size_t  CantorPairing::calculatePairValue(std::size_t const x, 
                                                   std::size_t const y) const
    {
        const auto t1 = x + y;
        const auto t2 = t1 + 1;
        const std::size_t value = (t1*t2)/2 + y;
        return value;
    } /* -----  end of method CantorPairing::calculatePairValue  ----- */


    std::tuple<std::size_t,std::size_t> CantorPairing::calculateInverse ( const std::size_t z )
    {
        const std::size_t t1 = 8*z+1;
        const double t2 = (std::sqrt(t1) - 1.0)*0.5;
        const double w1 = std::floor(t2);
        const std::size_t w = static_cast<std::size_t>(std::lround(w1));
        const std::size_t t = (w*w + w)/2;
        const std::size_t y = z - t;
        const std::size_t x = w - y;
        return std::make_tuple(x,y);
    }		/* -----  end of method CantorPairing::calculateInverse  ----- */

    //============================= MUTATORS =====================================

    //============================= OPERATORS ====================================
    CantorPairing& CantorPairing::operator=( const CantorPairing &other )
    {
        if (this != &other)
        {

        }
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////////
    /////////////////////////////// PROTECTED ////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

    //============================= LIFECYCLE ====================================

    //============================= ACCESSORS ====================================

    //============================= MUTATORS =====================================

    //============================= OPERATORS ====================================

    //////////////////////////////////////////////////////////////////////////////
    /////////////////////////////// PRIVATE //////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////
        
    //============================= LIFECYCLE ====================================

    //============================= ACCESSORS ====================================

    //============================= MUTATORS =====================================

    //============================= OPERATORS ====================================

}; /* -----  end of namespace MEMORY_MANAGEMENT  ----- */
