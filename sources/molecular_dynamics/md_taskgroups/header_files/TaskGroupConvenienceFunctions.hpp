#ifndef  ANANSI_TaskGroupConvenienceFunctions_INC
#define  ANANSI_TaskGroupConvenienceFunctions_INC

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
#include "TaskGroup.h"
namespace ANANSI
{

// =====================================================================================
//        Class:  TaskGroupConvenienceFunctions
//  Description:  
//  =====================================================================================
template<typename Derived>
class TaskGroupConvenienceFunctions 
{
    public:
        // ====================  LIFECYCLE     =======================================

        TaskGroupConvenienceFunctions ()   // constructor
        {
            return;
        }

        TaskGroupConvenienceFunctions (const TaskGroupConvenienceFunctions & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        TaskGroupConvenienceFunctions (TaskGroupConvenienceFunctions && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method TaskGroupConvenienceFunctions::TaskGroupConvenienceFunctions  -----

        virtual ~TaskGroupConvenienceFunctions()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        template<typename taskgroup_t,typename ingredients_t,typename needed_ingredients_typelist>
        std::unique_ptr<taskgroup_t> transferAllIngredients(std::unique_ptr<taskgroup_t> & taskgroup,
            std::unique_ptr<ingredients_t> & ingredients) const
        {
            const Derived& underlying = static_cast<const Derived&>(*this); 
            return underlying. template transferAllIngredients__<taskgroup_t,ingredients_t,needed_ingredients_typelist>(taskgroup,ingredients);
        }
        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TaskGroupConvenienceFunctions& operator= ( const TaskGroupConvenienceFunctions &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator


        TaskGroupConvenienceFunctions& operator= ( TaskGroupConvenienceFunctions && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator

        // ====================  STATIC        =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskGroupConvenienceFunctions  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TaskGroupConvenienceFunctions_INC  ----- 
