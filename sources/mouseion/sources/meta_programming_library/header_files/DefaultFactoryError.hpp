#ifndef  MOUSEION_DefaultFactoryError_INC
#define  MOUSEION_DefaultFactoryError_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

// =====================================================================================
//        Class:  DefaultFactoryError
//  Description:  
//  =====================================================================================
template <typename IdentifierType, typename ProductType>
class DefaultFactoryError
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  DefaultFactoryError
        //      Method:  DefaultFactoryError :: DefaultFactoryError
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        DefaultFactoryError() // constructor
        {
            return;
        }

        DefaultFactoryError(DefaultFactoryError const & other) // copy constructor
        {
            return;
        }		// -----  end of method DefaultFactoryError::DefaultFactoryError  -----

        DefaultFactoryError(DefaultFactoryError && other) // copy-move constructor
        {
            return;
        }		// -----  end of method DefaultFactoryError::DefaultFactoryError  -----

        virtual ~DefaultFactoryError() // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DefaultFactoryError& operator= ( DefaultFactoryError const & other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        DefaultFactoryError& operator= ( DefaultFactoryError && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        // ====================  NESTED CLASS  =======================================
        class Exception : public std::exception
        {
            public: 
                Exception(const IdentifierType & unknownId) : unknownId_(unknownId)
                {
                    return;
                }

                virtual const char* what() const noexcept
                {
                    return "Unknown object type passed to factory.";
                }

                IdentifierType const & getId() const noexcept
                {
                    return this->unknownId_;
                }

            private:
                IdentifierType  unknownId_;
        };

        static ProductType* OnUnknownType(const IdentifierType& id)
        {
            throw Exception(id);
        }
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DefaultFactoryError  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_DefaultFactoryError_INC  ----- 
