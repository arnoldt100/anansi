#ifndef ANANSI_ReadPointAtoms_INC
#define ANANSI_ReadPointAtoms_INC
//! \file ReadPointAtoms.h

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
#include "ReadAtoms.h"
#include "CommonMDTaskGroupHeaders.h"
#include "ReadPointAtomsResultsTraits.h"
#include "ReadPointAtomsResultsOwnershipImpl.hpp"
#include "CopyOwnershipPolicy.hpp"
#include "MasterProcess.h"
#include "CommunicatorRank.h"
#include "is_communicator_type.hpp"
#include "InitialConfigurationFilenames.h"
#include "CommandFiles.h"
#include "CommandFileName.h"
#include "NullPickleType.h"
#include "ParticlesConfigurationFiles.h"
#include "PointAtomsInternalNodeKeys.h"
#include  "ConvertGlobalNodeKey.hpp"

namespace ANANSI
{

class ReadPointAtoms :  public RECEIVER::ReceiverInterface<ReadPointAtoms>
{
    private:
        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'r','e','a','d','_','p','o','i','n','t','_','a','t','o','m','s'};

        using my_result_type_ = ReadPointAtomsResultsTraits::result_t;
        using my_copy_type_ = ReadPointAtomsResultsTraits::copy_result_t;
        using my_share_type_ = ReadPointAtomsResultsTraits::share_result_t;
        using my_transfer_type_ = ReadPointAtomsResultsTraits::transfer_result_t;

        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        //! \todo Implement a policy class for the ownership implementation
        using MyOwnershipImpl_ = ReadPointAtomsResultsOwnershipImpl<MyOwnershipImplTraits_>;

        //! The ownership policy for the result.
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;
        
        // \todo Place here the class data members required for doing the task.

    public:

        // ====================  TYPEDEFS     =======================================

        //! \todo Declare an alias the parent task.
        using MyParentTask = ReadAtoms;

        //! \todo Fill in typelist with Generic tasks to
        //!       accomplish the maceo command. Leave typelist empty
        //!       if this is not a macro command.
        using MyComponentReceiverTypelist = MPL::mpl_typelist<>;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = 
        typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<ReadPointAtoms>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ReadPointAtoms>::TASK_LABEL_TYPE(ReadPointAtoms::tmpstr);

        // ====================  LIFECYCLE     =======================================

        ReadPointAtoms ();   // constructor

        ReadPointAtoms (const ReadPointAtoms & other) = delete;   // copy constructor

        ReadPointAtoms (ReadPointAtoms && other);   // copy-move constructor

        ~ReadPointAtoms ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReadPointAtoms& operator= ( const ReadPointAtoms &other ) = delete; // assignment operator

        ReadPointAtoms& operator= ( ReadPointAtoms && other ); // assignment-move operator

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

        constexpr RECEIVER::ReceiverInterface<ReadPointAtoms>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  ReadPointAtoms::TASKLABEL;
        }

        receiver_copy_t_ receiverGetCopyOfResults_() const;

        bool ifEnabled_ () const;

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
        bool enabledStatus_;
        mutable receiver_result_t results_;
        MyOwnershipPolicy_ ownershipPolicy_;
        InitialConfigurationFilenames initialConfigurationFileNames_;
        COMMUNICATOR::MasterProcess masterProcessTag_;
        COMMUNICATOR::CommunicatorRank communicatorRankTag_;

}; // -----  end of class ReadPointAtoms  -----

template<typename... Types>
void ReadPointAtoms::enableReceiver_(Types &... args)
{
    std::cout << "Stud for ReadPointAtoms::enableReceiver_" << std::endl;
    this->enabledStatus_ = true;
    return;
}

template<typename... Types>
void ReadPointAtoms::disableReceiver_(Types &... args)
{
    this->enabledStatus_ = false;
    return;
}

template<typename... Types>
void ReadPointAtoms::receiverDoAction_(Types & ... args) const
{
    const auto filenames = this->initialConfigurationFileNames_();
    for ( auto filename : filenames)
    {
        CommandFileName file_name{filename};
        CommandFiles<Atoms> myConfigurationFile{ReadPointAtomsResultsTraits::ParticlesConfigurationFiles_t()};
        set_CommandFile_filename(myConfigurationFile, file_name);
        read_CommandFile(myConfigurationFile);

        // Read the nunber of particles in the file.
        const  ConvertGlobalNodeKey<PointAtomsInternalNodeKeys> x1;
        const std::string global_key_number_atoms = x1(PointAtomsInternalNodeKeys::Number_Atoms_In_File);
        const std::string number_particles = get_value_CommandFile(myConfigurationFile,global_key_number_atoms);
    }
    return;
}

template<typename... Types>
void ReadPointAtoms::receiverUndoAction_(Types & ... args) const
{
    return;
}

}; // ----- End of namespace ANANSI -----

#endif // ANANSI_ReadPointAtoms_INC
