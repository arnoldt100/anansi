#ifndef ANANSI_NodeKeys_INC
#define ANANSI_NodeKeys_INC
//! \file NodeKeys.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class NodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        NodeKeys();   // constructor

        template<typename T>
        NodeKeys(T && value) :
            valuePtr_( new NodeKeysModel<T>(std::forward<T>(value)) )
        {
            std::cout << "In templated NodeKeys cstr." << std::endl;
            return;
        }

        NodeKeys(const NodeKeys & other);   // copy constructor

        NodeKeys(NodeKeys && other);   // copy-move constructor

        ~NodeKeys();  // destructor

        // ====================  ACCESSORS     =======================================
        NodeKeys* clone() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NodeKeys& operator=( const NodeKeys &other ); // assignment operator

        NodeKeys& operator=( NodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // The concept
        class NodeKeysConcept
        {
            public: 
                // ====================  LIFECYCLE     =======================================
                NodeKeysConcept() = default;
                NodeKeysConcept(const NodeKeysConcept & other) = default;
                NodeKeysConcept(NodeKeysConcept && other) = default;
                virtual ~NodeKeysConcept()=0;

                // ====================  OPERATORS     =======================================
                NodeKeysConcept& operator=(const NodeKeysConcept & other)=default;
                NodeKeysConcept& operator=(NodeKeysConcept && other)=default;

                // ====================  ACCESSORS     =======================================
                virtual std::unique_ptr<NodeKeysConcept> clone() const=0;

                virtual bool doesKeyExist(const std::string key) const=0;

                // ====================  MUTATORS      =======================================

        };

        // The model.
        template <typename T>
        class NodeKeysModel : public NodeKeysConcept
        {
            public:
                // ====================  LIFECYCLE     =======================================
                NodeKeysModel() :
                    NodeKeysConcept(),
                    object_()
                {
                    return;
                };

                NodeKeysModel(const NodeKeysModel & other) :
                    NodeKeysConcept(other),
                    object_(other.object_)
                {
                    if (this != &other)
                    {
                    }
                };

                NodeKeysModel(NodeKeysModel && other) :
                    NodeKeysConcept(std::move(other)),
                    object_(std::move(other.object_))
                {
                    if (this != &other)
                    {
                    }
                };

                explicit NodeKeysModel(const T & in_value) : 
                    object_(in_value)
                {
                    return;
                };

                // ====================  OPERATORS     =======================================
                NodeKeysModel& operator=(const NodeKeysModel & other) 
                {
                    if (this != &other)
                    {
                        NodeKeysConcept::operator=(other);
                        this->object_ = other.value;
                    }
                    return *this;
                }

                NodeKeysModel& operator=( NodeKeysModel && other) 
                {
                    if (this != &other)
                    {
                        NodeKeysConcept::operator=(std::move(other));
                        this->object_ = std::move(other.value);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<NodeKeysConcept> clone() const override
                {
                    return std::make_unique<NodeKeysModel>(*this);
                }

                bool doesKeyExist(const std::string key) const override
                {
                    const bool retval = object_.does_key_exist(object_,key);
                    return retval;
                }

                // ====================  MUTATORS      =======================================

                T object_;
        };
        
        friend bool does_key_exist ( const NodeKeys && node_keys, const std::string key)
        {
            return node_keys.valuePtr_->doesKeyExist(key);
        }
        
        friend bool does_key_exist ( const NodeKeys & node_keys, const std::string key)
        {
            return node_keys.valuePtr_->doesKeyExist(key);
        }
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<NodeKeysConcept> valuePtr_;

}; // -----  end of class NodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_NodeKeys_INC
