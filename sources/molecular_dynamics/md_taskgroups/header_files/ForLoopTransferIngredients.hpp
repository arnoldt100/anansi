#ifndef  ANANSI_ForLoopTransferIngredients
#define  ANANSI_ForLoopTransferIngredients

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <functional>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"

namespace ANANSI
{



// =====================================================================================
//        Class:  ForLoop
//  Description:  
// =====================================================================================


template<int N_initial, 
         int N_final, 
         int N,
         typename needed_ingredients_typelist_t, 
         typename taskgroup_t,
         typename Callable,
         typename transfer_t> 
class ForLoopOverTransferIngredientsNext
{
    public:
        ForLoopOverTransferIngredientsNext(std::function<Callable(int)> op) :
            op_(op)
        {
            return;
        }

        void operator()()
        {
            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                using ingredient_t = MPL::mpl_at_c<needed_ingredients_typelist_t,N>();

                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do functor call.
                // Wrapper member;
                // member .template operator()<N>();
                this->op_(N);
               
                transfer_t my_transfer_op;
                my_transfer_op. template operator()<ingredient_t>();

                // Compute the increment.
                constexpr auto dN = ( N_initial <= N_final ) ? 1 : -1;

                // Call ForLoopOverTransferIngredientsNext for next ieration.
                ForLoopOverTransferIngredientsNext<
                    N_initial,
                    N_final,
                    N+dN,
                    needed_ingredients_typelist_t,
                    taskgroup_t,
                    Callable,
                    transfer_t> a_forloop(this->op_);
                a_forloop();
            }
            return;
        }
    private :
        std::function<Callable(int)> op_;

}; // -----  end of class ForLoopOverTransferIngredientsNext  -----

template<typename needed_ingredients_typelist_t,
         typename taskgroup_t, 
         typename Callable,
         typename transfer_t>
class ForLoopOverTransferIngredients
{
    public:

        ForLoopOverTransferIngredients(std::function<Callable(int)> op) :
            op_(op)
        {
            return;
        }

        void operator()()
        {
            // Compute the bounds of the TypeList. 
            constexpr auto N_initial=0;
            constexpr auto N_final = MPL::mpl_size<needed_ingredients_typelist_t>::value-1;

            // The values of N_initial or N_final can't be negative for it will
            // break the indexing of needed_ingredients_typelist_t. The
            // needed_ingredients_typelist_t uses 0 and positive integers for
            // its indexing.
            if constexpr ( (N_initial < 0) || (N_final < 0) )
            {
                return; 
            }

            // Compute the index for the wrapper functor call.
            constexpr auto N = ( N_initial <= N_final ) ? N_initial : N_final;

            if constexpr ( (N_initial <= N) && (N <= N_final ) )
            {
                using ingredient_t = MPL::mpl_at_c<needed_ingredients_typelist_t,N>();

                this->op_(N);

                transfer_t my_transfer_op;
                my_transfer_op. template operator()<ingredient_t>();

                // Compute the increment.
                constexpr auto dN = ( N_initial <= N_final ) ? 1 : -1;

                // Call ForLoopOverTransferIngredientsNext for next ieration.
                ForLoopOverTransferIngredientsNext<
                    N_initial,
                    N_final,
                    N+dN,
                    needed_ingredients_typelist_t,
                    taskgroup_t,
                    Callable,
                    transfer_t> a_forloop(this->op_);
                a_forloop();
            }
            return;

            //std::shared_ptr<Wrapper> wrapper_; 

        }
    private :
        std::function<Callable(int)> op_;

}; // -----  end of class ForLoopOverTransferIngredients  -----



}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_ForLoopTransferIngredients  ----- */
