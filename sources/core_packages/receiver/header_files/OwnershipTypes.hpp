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

template <OwnershipTypes T,typename W>
struct ReceiverOwnershipType;


template <typename W>
struct ReceiverOwnershipType<OwnershipTypes::COPYTYPE,W>
{
    using TYPE = typename W::Copytype;
};

template <typename W>
struct ReceiverOwnershipType<OwnershipTypes::SHARETYPE,W>
{
    using TYPE = typename W::Sharetype;
};

template <typename W>
struct ReceiverOwnershipType<OwnershipTypes::TRANSFERTYPE,W>
{
    using TYPE = typename W::Sharetype;
};

} // namespace __NAMESPACE__
