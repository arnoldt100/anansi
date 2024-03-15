#ifndef ANANSI_PointAtomsDecomposer_INC
#define ANANSI_PointAtomsDecomposer_INC
//! \file PointAtomsDecomposer.h
//!
//! \brief Brief description
//!
//! \details  Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AtomsDecomposer.h"
#include "CommonMDTaskGroupHeaders.h"
#include "PointAtomsDecomposerResultsTraits.h"
#include "PointAtomsDecomposerResultsOwnershipImpl.hpp"
#include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

class PointAtomsDecomposer :  public RECEIVER::ReceiverInterface<PointAtomsDecomposer>
{
    private:
        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'d','e','c','o','m','p','o','s','e','_','p','o','i','n','t','_','a','t','o','m','s'};

        //! \! todo Implement a traits class for the results. 
        using my_result_type_ = PointAtomsDecomposerResultsTraits::result_t;
        using my_copy_type_ = PointAtomsDecomposerResultsTraits::copy_result_t;
        using my_share_type_ = PointAtomsDecomposerResultsTraits::share_result_t;
        using my_transfer_type_ = PointAtomsDecomposerResultsTraits::transfer_result_t;

        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        //! \todo Implement a policy class for the ownership implementation
        using MyOwnershipImpl_ = PointAtomsDecomposerResultsOwnershipImpl<MyOwnershipImplTraits_>;

        //! The ownership policy for the result.
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;
        
        // \todo Place here the class data members required for doing the task.

    public:

        // ====================  TYPEDEFS     =======================================

        //! \todo Declare an alias the parent task.
        using MyParentTask = AtomsDecomposer;

        //! \todo Fill in typelist with Generic tasks to
        //!       accopmplish the maceo command. Leave typleist empty
        //!       if this is not a macro command.
        using MyComponentReceiverTypelist = MPL::mpl_typelist<>;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = 
        typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<PointAtomsDecomposer>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<PointAtomsDecomposer>::TASK_LABEL_TYPE(PointAtomsDecomposer::tmpstr);

        // ====================  LIFECYCLE     =======================================

        PointAtomsDecomposer ();   // constructor

        PointAtomsDecomposer (const PointAtomsDecomposer & other) = delete;   // copy constructor

        PointAtomsDecomposer (PointAtomsDecomposer && other);   // copy-move constructor

        ~PointAtomsDecomposer ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PointAtomsDecomposer& operator= ( const PointAtomsDecomposer &other ) = delete; // assignment operator

        PointAtomsDecomposer& operator= ( PointAtomsDecomposer && other ); // assignment-move operator

    private:

        using receiver_copy_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::COPYTYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;

        using receiver_share_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::SHARETYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;

        using receiver_transfer_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::TRANSFERTYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;


    protected:
        // ====================  ACCESSORS     =======================================
        template<typename... Types>
        void receiverDoAction_(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction_(Types &... args) const;

        constexpr RECEIVER::ReceiverInterface<PointAtomsDecomposer>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  PointAtomsDecomposer::TASKLABEL;
        }

        receiver_copy_t_ receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &... arg);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        receiver_share_t_ receiverShareOwnershipOfResults_();
    
        receiver_transfer_t_ receiverTransferOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class PointAtomsDecomposer  -----

template<typename... Types>
void PointAtomsDecomposer::enableReceiver_(Types &... args)
{
    std::cout << "Stud for PointAtomsDecomposer::enableReceiver_" << std::endl;
    return;
}

template<typename... Types>
void PointAtomsDecomposer::disableReceiver_(Types &... args)
{
    std::cout << "Stud for PointAtomsDecomposer::disableReceiver_" << std::endl;
    return;
}

template<typename... Types>
void PointAtomsDecomposer::receiverDoAction_(Types & ... args) const
{
    std::cout << "Stud for PointAtomsDecomposer::receiverDoAction_" << std::endl;
    return;
}

template<typename... Types>
void PointAtomsDecomposer::receiverUndoAction_(Types & ... args) const
{
    std::cout << "Stud for PointAtomsDecomposer::receiverUndoAction_" << std::endl;
    return;
}

}; // ----- End of namespace ANANSI -----

#endif // ANANSI_PointAtomsDecomposer_INC
