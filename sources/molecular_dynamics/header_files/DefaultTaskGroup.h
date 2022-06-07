#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskGroup.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  DefaultTaskGroup
//  Description:  
//  =====================================================================================
class DefaultTaskGroup final : public TaskGroup
{
    public:
        // ====================  LIFECYCLE     =======================================

        DefaultTaskGroup ();   // constructor

        DefaultTaskGroup (const DefaultTaskGroup & other)=delete;   // copy constructor

        DefaultTaskGroup (DefaultTaskGroup && other);   // copy-move constructor

        ~DefaultTaskGroup ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DefaultTaskGroup& operator= ( const DefaultTaskGroup &other )=delete; // assignment operator

        DefaultTaskGroup& operator= ( DefaultTaskGroup && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DefaultTaskGroup  -----


}; // namespace ANANSI

#endif // __filepreprocessordefine__
