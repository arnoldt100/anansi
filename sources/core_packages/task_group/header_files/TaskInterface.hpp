#ifndef ANANSI_TaskInterface_INC
#define ANANSI_TaskInterface_INC
//! @file TaskInterface.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

// =====================================================================================
//        Class:  TaskInterface
//  Description:  
//  =====================================================================================
template <typename Derived>
class TaskInterface
{
    public:
        // ====================  LIFECYCLE     =======================================

        TaskInterface ()   // constructor
        {
            return;
        }

        TaskInterface (const TaskInterface & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        TaskInterface (TaskInterface && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TaskInterface::TaskInterface  -----

        ~TaskInterface ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TaskInterface& operator= ( const TaskInterface &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        TaskInterface& operator= ( TaskInterface && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskInterface  -----


}; // namespace ANANSI

#endif // ANANSI_TaskInterface_INC
