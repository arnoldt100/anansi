#ifndef ANANSI_OwnershipImpl1_INC
#define ANANSI_OwnershipImpl1_INC
//! @file OwnershipImpl1.hpp
//!
//! Brief description
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
         using Sharedtype = std::shared_ptr<Underlyingtype>;
         using Uniquetype = std::unique_ptr<Underlyingtype>;

         using Sharetype = std::shared_ptr<Underlyingtype>;
         using Copytype = std::unique_ptr<Underlyingtype>;
         using Transfertype = std::unique_ptr<Underlyingtype>;

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

        ~OwnershipImpl1();  // destructor

        // ====================  STATIC        =======================================

        template <typename Resulttype>
        static Uniquetype copy(Resulttype const & result)
        {
            Underlyingtype* tmp_obj = new Underlyingtype(*result);
            Uniquetype obj(tmp_obj);
            return std::move(obj); 
        }

        template <typename Resulttype>
        static Uniquetype transfer(Resulttype const & result)
        {
            Uniquetype tmp_obj = std::move(result);
            return std::move(tmp_obj); 
        }

        template <typename Resulttype>
        static Sharedtype share(Resulttype const & result)
        {
            Sharedtype shared_obj = result;
            return result;
        }

        template <typename OwnershipPolicyType>
        static Sharetype throwSharingError(std::string error_message)
        {
            throw ANANSI::ErrorOwnershipPolicy<OwnershipPolicyType>(error_message);
            Sharetype tmp_obj(new Underlyingtype);
            return tmp_obj;
        }

        template <typename OwnershipPolicyType>
        static Copytype throwCopyingError(std::string error_message)
        {
            throw ANANSI::ErrorOwnershipPolicy<OwnershipPolicyType>(error_message);
            Copytype tmp_obj(new Underlyingtype);
            return std::move(tmp_obj);
        }

        template <typename OwnershipPolicyType>
        static Transfertype throwTransferringError(std::string error_message)
        {
            throw ANANSI::ErrorOwnershipPolicy<OwnershipPolicyType>(error_message);
            Transfertype tmp_obj(new Underlyingtype);
            return std::move(tmp_obj);
        }

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

template<typename Underlyingtype>
OwnershipImpl1<Underlyingtype>::~OwnershipImpl1()
{
    return;
}


}; // namespace ANANSI

#endif // ANANSI_OwnershipImpl1_INC
