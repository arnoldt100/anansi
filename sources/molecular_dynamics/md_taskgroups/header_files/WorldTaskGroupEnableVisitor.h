#ifndef  ANANSI_WorldTaskGroupEnableVisitor_INC
#define  ANANSI_WorldTaskGroupEnableVisitor_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <functional>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseVisitor.h"
#include "Visitor.hpp"
#include "WorldTaskGroup.h"
#include "WorldTaskGroupIngredients.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  WorldTaskGroupEnableVisitor
//  Description:  
//  =====================================================================================
class WorldTaskGroupEnableVisitor : public MPL::BaseVisitor,
                                    public MPL::Visitor<ANANSI::WorldTaskGroup>
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorldTaskGroupEnableVisitor ();   // constructor

        WorldTaskGroupEnableVisitor (const std::unique_ptr<ANANSI::Ingredients<WorldTaskGroupIngredients>> & world_task_group_ingredients);   // constructor

        WorldTaskGroupEnableVisitor (const WorldTaskGroupEnableVisitor & other);   // copy constructor

        WorldTaskGroupEnableVisitor (WorldTaskGroupEnableVisitor && other);   // copy-move constructor

        ~WorldTaskGroupEnableVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(WorldTaskGroup & a_task_group) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorldTaskGroupEnableVisitor& operator= ( const WorldTaskGroupEnableVisitor &other ); // assignment operator

        WorldTaskGroupEnableVisitor& operator= ( WorldTaskGroupEnableVisitor && other ); // assignment-move operator


        // ====================  STATIC        =======================================
        template <typename T>
        static auto getIngredient( const WorldTaskGroupEnableVisitor * v)
        {
            T my_args = 
                (v->ingredients_)->giveIngredient<T>();
            return my_args;
        }
        
        template <typename T>
        static auto transferIngredient( const WorldTaskGroupEnableVisitor * v,
                                        WorldTaskGroup & a_task_group)
        {
            T my_args = 
                (v->ingredients_)->giveIngredient<T>();
    
            a_task_group.addIngredient(std::move(my_args));
            return;
        }

        template <typename ingredient_T, 
                  typename taskgroup_ingredients_t,
                  typename taskgroup_t>
        static auto transferIngredient( const std::unique_ptr<taskgroup_ingredients_t> & v,
                                        taskgroup_t & a_task_group)
        {
            auto an_ingredient = v->template giveIngredient<ingredient_T>();
            a_task_group.addIngredient(std::move(an_ingredient));
            return;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<ANANSI::Ingredients<WorldTaskGroupIngredients>> ingredients_;

}; // -----  end of class WorldTaskGroupEnableVisitor  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldTaskGroupEnableVisitor_INC  ----- 
