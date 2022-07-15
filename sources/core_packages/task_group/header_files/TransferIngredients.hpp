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
//        Class:  TransferIngredient
//  Description:  
//  =====================================================================================
template < typename taskgroup_ingredients_t,
           typename taskgroup_t >
class TransferIngredient
{
    public:
        // ====================  LIFECYCLE     =======================================

        TransferIngredient ()   // constructor
        {
            return;
        }

        TransferIngredient (const TransferIngredient & other)   // copy constructor
        {
            if ( this != &other )
            {

            }
            return;
        }

        TransferIngredient (TransferIngredient && other)   // copy-move constructor
        {
            if ( this != &other )
            {

            }
            return;
        }

        ~TransferIngredient ()  // destructor
        {
            return;
        }
        
        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TransferIngredient& operator= ( const TransferIngredient &other ) // assignment operator
        { 
            if ( this != &other )
            {

            }
            return *this;
        }

        TransferIngredient& operator=( TransferIngredient && other ) // assignment-move operator
        {
            if ( this != &other ) 
            {

            }
            return *this;
        }

        template <typename ingredient_T>
        void operator()(const std::unique_ptr<taskgroup_ingredients_t> & ingredients,
                        taskgroup_t & a_task_group) const
        {
            auto an_ingredient = ingredients->template giveIngredient<ingredient_T>();
            a_task_group.addIngredient(std::move(an_ingredient));
            return;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TransferIngredient  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TransferIngredient_INC  ----- 
