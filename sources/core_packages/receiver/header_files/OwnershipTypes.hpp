//--------------------------------------------------------//
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
    using TYPE = typename ReceiverResultTraitsType::Sharetype;
};

} // namespace __NAMESPACE__
