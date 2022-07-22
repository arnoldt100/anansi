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
#include "ForLoopTransferIngredients.hpp"
#include "TransferIngredients.hpp"

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
        template<
            typename taskgroup_t,
            typename ingredients_t,
            typename needed_ingredients_typelist >
        void transferAllIngredients__(
            std::shared_ptr<TaskGroup> taskgroup,
            const std::unique_ptr<ingredients_t> & ingredients) const
        {
            
            using transfer_t = TransferIngredients;
            
            ForLoopOverTransferIngredients<
                needed_ingredients_typelist,
                taskgroup_t,
                transfer_t> my_for_loop;
                my_for_loop. template operator()<ingredients_t>(taskgroup,ingredients);
            return;
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
