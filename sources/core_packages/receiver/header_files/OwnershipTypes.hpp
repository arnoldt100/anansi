#ifndef RECEIVER_ReceiverOwnershipTypes_INC
#define RECEIVER_ReceiverOwnershipTypes_INC
RECEIVER_ReceiverOwnershipTypes_INC//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace RECEIVER {

enum class OwnershipTypes
{
    COPYTYPE,
    SHARETYPE,
    TRANSFERTYPE
}; // -----  end of enum  OwnershipTypes  -----

namespace PRIVATE_NAMESPACE_
{
    template <OwnershipTypes T,typename ReceiverResultTraitsType>
    struct ReceiverOwnershipType;

    template <typename ReceiverResultTraitsType>
    struct ReceiverOwnershipType<OwnershipTypes::COPYTYPE,ReceiverResultTraitsType>
    {
        using TYPE = typename ReceiverResultTraitsType::Copytype;
    };

    template <typename ReceiverResultTraitsType>
    struct ReceiverOwnershipType<OwnershipTypes::SHARETYPE,ReceiverResultTraitsType>
    {
        using TYPE = typename ReceiverResultTraitsType::Sharetype;
    };

    template <typename ReceiverResultTraitsType>
    struct ReceiverOwnershipType<OwnershipTypes::TRANSFERTYPE,ReceiverResultTraitsType>
    {
        using TYPE = typename ReceiverResultTraitsType::Transfertype;
    };
}

template<OwnershipTypes T, 
         typename OwnershipImpl>
struct ReceiverResultOwnershipType
{
    private:
        using MyReceiverOwnershipImplementationTraits_ = typename OwnershipImpl::ReceiverOwnershipImplementationTraits; 

        template<RECEIVER::OwnershipTypes Q>
        using MyReceiverOwnershipTypes_ = PRIVATE_NAMESPACE_::ReceiverOwnershipType<Q,MyReceiverOwnershipImplementationTraits_>;
       
    public:
        using TYPE = typename MyReceiverOwnershipTypes_<T>::TYPE;
};

template<OwnershipTypes T, 
         typename OwnershipImplTraits>
struct ReceiverResultOwnershipType_TraitsVersion
{
    private:
        template<RECEIVER::OwnershipTypes Q>
        using MyReceiverOwnershipTypes_ = PRIVATE_NAMESPACE_::ReceiverOwnershipType<Q,OwnershipImplTraits>;
       
    public:
        using TYPE = typename MyReceiverOwnershipTypes_<T>::TYPE;
};

}; // namespace RECEIVER

#endif // RECEIVER_ReceiverOwnershipTypes_INC
