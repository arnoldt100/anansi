/*
 * Identification.h
 *
 */

#ifndef  Identification_INC
#define  Identification_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

enum class MASTER_SLAVE_IDENTITIES
{ 
    master_mpi_task, 
    slave_mpi_task
};

template<typename T>
class Identification 
{
    public:
        //===== LIFECYCLE ======
        Identification();

        Identification(Identification const & other);

        virtual ~Identification();

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======
        MASTER_SLAVE_IDENTITIES getMyIdentity() const
        {
            return this->_getMyIdentity();
        }

        //===== MUTATORS =======

        //===== OPERATORS ======
        Identification& operator=(Identification const & other);

        //===== STATIC METHODS =

    protected:
        //===== LIFECYCLE ======

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======

        //===== MUTATORS =======

        //===== OPERATORS ======

    private:
        //===== LIFECYCLE ======

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======
        virtual MASTER_SLAVE_IDENTITIES _getMyIdentity() const=0;

        //===== MUTATORS =======

        //===== OPERATORS ======

        //===== STATIC METHODS =
};


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

template<typename T>
Identification<T>::Identification() 
{
	return;
}

template<typename T>
Identification<T>::Identification(Identification<T> const & other)
{
    if ( this != &other )
    {
        
    }
    return;
}

template<typename T>
Identification<T>::~Identification() {
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================
template<typename T>
Identification<T>& Identification<T>::operator=(Identification<T> const & other)
{
    if ( this != &other )
    {
        
    }
    return *this;
}

//============================= STATIC METHODS ===============================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC METHODS ===============================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC METHODS ===============================


} /* namespace COMMUNICATOR */

#endif   /* ----- #ifndef Identification_INC  ----- */
