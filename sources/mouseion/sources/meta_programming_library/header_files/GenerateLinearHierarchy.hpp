#ifndef  MOUSEION_GenerateLinearHierarchy_INC
#define  MOUSEION_GenerateLinearHierarchy_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "EmptyType.h"

namespace MPL
{

// =====================================================================================
//        Class:  GenerateLinearHierarchy
//  Description:  The primary template
//  ====================================================================================
template<
         template<typename,typename> typename Unit,
         typename TypeListSize,
         typename TypeList, 
         class Root = EmptyType
        >
class GenerateLinearHierarchy : public Unit<
                                            mpl_front<TypeList>,
                                            GenerateLinearHierarchy<Unit,mpl_rest_size<TypeList>,mpl_rest<TypeList>,Root>
                                           > 
{

}; // -----  end of class GenerateLinearHierarchy  -----



// =====================================================================================
//        Class:  GenerateLinearHierarchy
//  Description:  The end of recursion template.
//  ====================================================================================
template<
         template <typename,typename> class Unit,
         typename TypeList,
         class Root>
class GenerateLinearHierarchy <
                                Unit,
                                mpl_size_1,
                                TypeList,
                                Root
                              > :
    public Unit<mpl_front<TypeList>,Root>
{

};
// -----  end of class GenerateLinearHierarchy  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_GenerateLinearHierarchy_INC  ----- 
