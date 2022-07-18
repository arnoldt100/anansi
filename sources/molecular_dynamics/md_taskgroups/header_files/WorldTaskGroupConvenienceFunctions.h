#ifndef  ANANSI_WorldTaskGroupConvenienceFunctions_INC
#define  ANANSI_WorldTaskGroupConvenienceFunctions_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskGroupConvenienceFunctions.hpp"
#include "MDTaskGroupFactory.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  WorldTaskGroupConvenienceFunctions
//  Description:  
//  =====================================================================================
class WorldTaskGroupConvenienceFunctions : public TaskGroupConvenienceFunctions<WorldTaskGroupConvenienceFunctions>
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorldTaskGroupConvenienceFunctions ();   // constructor

        WorldTaskGroupConvenienceFunctions (std::shared_ptr<MDTaskGroupFactory<>> task_group_factory);   // constructor

        WorldTaskGroupConvenienceFunctions (const WorldTaskGroupConvenienceFunctions & other);   // copy constructor

        WorldTaskGroupConvenienceFunctions (WorldTaskGroupConvenienceFunctions && other);   // copy-move constructor

        ~WorldTaskGroupConvenienceFunctions ();  // destructor

        // ====================  ACCESSORS     =======================================
        template<typename taskgroup_t,typename ingredients_t,typename needed_ingredients_typelist>
        std::unique_ptr<taskgroup_t> transferAllIngredients__(std::unique_ptr<taskgroup_t> & taskgroup,
            std::unique_ptr<ingredients_t> & ingredients) const
        {
            std::unique_ptr<taskgroup_t> tmp_taskgroup();
            return tmp_taskgroup;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorldTaskGroupConvenienceFunctions& operator= ( const WorldTaskGroupConvenienceFunctions &other ); // assignment operator

        WorldTaskGroupConvenienceFunctions& operator= ( WorldTaskGroupConvenienceFunctions && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<MDTaskGroupFactory<>> taskGroupFactory_;

}; // -----  end of class WorldTaskGroupConvenienceFunctions  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldTaskGroupConvenienceFunctions_INC  ----- 
