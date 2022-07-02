#ifndef  ANANSI_WorldTaskGroupEnableVisitor_INC
#define  ANANSI_WorldTaskGroupEnableVisitor_INC


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

        WorldTaskGroupEnableVisitor (const std::unique_ptr<WorldTaskGroupIngredients> & world_task_group_ingredients);   // constructor

        WorldTaskGroupEnableVisitor (const WorldTaskGroupEnableVisitor & other);   // copy constructor

        WorldTaskGroupEnableVisitor (WorldTaskGroupEnableVisitor && other);   // copy-move constructor

        ~WorldTaskGroupEnableVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(WorldTaskGroup & a_task_group) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorldTaskGroupEnableVisitor& operator= ( const WorldTaskGroupEnableVisitor &other ); // assignment operator

        WorldTaskGroupEnableVisitor& operator= ( WorldTaskGroupEnableVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<WorldTaskGroupIngredients> ingredients_;

}; // -----  end of class WorldTaskGroupEnableVisitor  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldTaskGroupEnableVisitor_INC  ----- 
