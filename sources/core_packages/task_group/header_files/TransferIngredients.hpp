#ifndef  ANANSI_TransferIngredient_INC
#define  ANANSI_TransferIngredient_INC

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

namespace ANANSI
{

// =====================================================================================
//        Class:  TransferIngredients
//  Description:  
//  =====================================================================================
template < typename taskgroup_ingredients_t >
class TransferIngredients
{
    public:
        // ====================  LIFECYCLE     =======================================

        TransferIngredients ( const taskgroup_ingredients_t & ingredients )   // constructor
        {
            return;
        }

        TransferIngredients (const TransferIngredients & other)   // copy constructor
        {
            if ( this != &other )
            {

            }
            return;
        }

        TransferIngredients (TransferIngredients && other)   // copy-move constructor
        {
            if ( this != &other )
            {

            }
            return;
        }

        ~TransferIngredients ()  // destructor
        {
            return;
        }
        
        // ====================  ACCESSORS     =======================================

        template <typename ingredient_T>
        void one() const
        {
            // auto an_ingredient = ingredients->template giveIngredient<ingredient_T>();
            // a_task_group.addIngredient(std::move(an_ingredient));
            return;
        }

        template <typename taskgroup_t>
        taskgroup_t allIngredients( taskgroup_t && a_task_group) const
        {
            taskgroup_t tmp_task_group = std::move(a_task_group);
            return tmp_task_group;
        }
        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TransferIngredients& operator= ( const TransferIngredients &other ) // assignment operator
        { 
            if ( this != &other )
            {

            }
            return *this;
        }

        TransferIngredients& operator=( TransferIngredients && other ) // assignment-move operator
        {
            if ( this != &other ) 
            {

            }
            return *this;
        }


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        
}; // -----  end of class TransferIngredients  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TransferIngredient_INC  ----- 
