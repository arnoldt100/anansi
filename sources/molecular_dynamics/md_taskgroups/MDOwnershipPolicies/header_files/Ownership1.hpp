#ifndef RECEIVER_Ownership1_INC
#define RECEIVER_Ownership1_INC
//! @file Ownership1.hpp
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

namespace RECEIVER
{

// =====================================================================================
//        Class:  Ownership1
//  Description:  
//  =====================================================================================
template<typename Underlyingtype>
class Ownership1
{
    public:
         using Sharedtype = std::shared_ptr<Underlyingtype>;
         using Uniquetype = std::unique_ptr<Underlyingtype>;

        // ====================  LIFECYCLE     =======================================

        Ownership1 ()   // constructor
        {
            return;
        }

        Ownership1( Ownership1 const & other)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        Ownership1( Ownership1 && other)
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method Ownership1::Ownership1  -----

        ~Ownership1();  // destructor

        // ====================  STATIC        =======================================

        template <typename Resulttype>
        static Uniquetype copy(Resulttype const & result)
        {
            Underlyingtype* tmp_obj = new Underlyingtype(*result);
            Uniquetype obj(tmp_obj);
            return obj; 
        }

        template <typename Resulttype>
        static Uniquetype transfer(Resulttype const & result)
        {
            Uniquetype tmp_obj = std::move(result);
            return tmp_obj; 
        }

        template <typename Resulttype>
        static Sharedtype share(Resulttype const & result)
        {
            Sharedtype shared_obj = result;
            return result;
        }


        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Ownership1& operator= ( const Ownership1 &other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        Ownership1& operator= ( Ownership1 && other )
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

}; // -----  end of class Ownership1  -----

template<typename Underlyingtype>
Ownership1<Underlyingtype>::~Ownership1()
{
    return;
}


}; // namespace RECEIVER

#endif // RECEIVER_Ownership1_INC
