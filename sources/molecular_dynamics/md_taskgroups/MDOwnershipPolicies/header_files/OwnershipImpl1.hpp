#ifndef ANANSI_OwnershipImpl1_INC
#define ANANSI_OwnershipImpl1_INC
//! @file OwnershipImpl1.hpp
//!
//! Implements the 
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorOwnershipPolicy.hpp"

namespace ANANSI
{

template<typename Underlyingtype>
class OwnershipImpl1
{
    public:

        using Copytype = Underlyingtype;
        using Sharedtype = Underlyingtype;
        using Transfertype = Underlyingtype;

        // ====================  LIFECYCLE     =======================================

        OwnershipImpl1 ()   // constructor
        {
            return;
        }

        OwnershipImpl1( OwnershipImpl1 const & other)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        OwnershipImpl1( OwnershipImpl1 && other)
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method OwnershipImpl1::OwnershipImpl1  -----

        ~OwnershipImpl1()  // destructor
        {
            return;
        }

        // ====================  STATIC        =======================================

        static Copytype copy(Underlyingtype const & result)
        {
            // Underlyingtype* tmp_obj = new Underlyingtype(*result);
            Underlyingtype tmp_obj;
            return tmp_obj; 
        }

        template <typename T>
        static Transfertype transfer(T const & result)
        {
            Transfertype tmp_obj = std::move(result);
            return tmp_obj; 
        }

        template <typename T>
        static Sharedtype share(T const & result)
        {
            Sharedtype shared_obj = std::move(result);
            return result;
        }

        template <typename OwnershipPolicyType>
        static Sharedtype throwSharingError(std::string error_message)
        {
            throw ANANSI::ErrorOwnershipPolicy<OwnershipPolicyType>(error_message);
            Sharedtype tmp_obj;
            return tmp_obj;
        }

        template <typename OwnershipPolicyType>
        static Copytype throwCopyingError(std::string error_message)
        {
            throw ANANSI::ErrorOwnershipPolicy<OwnershipPolicyType>(error_message);
            Copytype tmp_obj;
            return tmp_obj;
        }

        template <typename OwnershipPolicyType>
        static Transfertype throwTransferringError(std::string error_message)
        {
            throw ANANSI::ErrorOwnershipPolicy<OwnershipPolicyType>(error_message);
            Transfertype tmp_obj;
            return tmp_obj;
        }

        // template <typename OwnershipPolicyType>
        // static Underlyingtype accessResult( std::shared_ptr<Underlyingtype> & value)
        // {
        //     Underlyingtype retval = *value;
        //     return retval;
        // };

        template <typename OwnershipPolicyType>
        static Underlyingtype accessResult( std::unique_ptr<Underlyingtype> && value)
        {
            Underlyingtype* retval = value.release();
            return retval;
        };


        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        OwnershipImpl1& operator= ( const OwnershipImpl1 &other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        OwnershipImpl1& operator= ( OwnershipImpl1 && other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

        template <typename UnderLyingType,typename ResultType,typename CopiedType>
        CopiedType operator( )(ResultType const & result)
        {
            UnderLyingType* tmp_obj = new UnderLyingType(*result);
            CopiedType obj(tmp_obj);
            return obj; 
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class OwnershipImpl1  -----

// template<typename Underlyingtype>
// OwnershipImpl1<Underlyingtype>::~OwnershipImpl1()
// {
//     return;
// }


}; // namespace ANANSI

#endif // ANANSI_OwnershipImpl1_INC
