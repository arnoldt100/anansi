#ifndef ANANSI_NodeKeys_INC
#define ANANSI_NodeKeys_INC
//! \file NodeKeys.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

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

                virtual bool isCommentKey(const std::string key) const=0;

                virtual std::pair<std::vector<std::string>::const_iterator,
                                  std::vector<std::string>::const_iterator> allKeysIterator() const=0;

                virtual std::array<char,2> separatorChar() const=0;

                virtual std::string defaultNullValue() const=0;

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
                    bool retval = object_.does_key_exist(object_,key);
                    return retval;
                }

                std::pair<std::vector<std::string>::const_iterator,
                          std::vector<std::string>::const_iterator> allKeysIterator() const override
                {
                    return object_.all_keys_iterator(object_);
                }

                std::array<char,2> separatorChar() const override
                {
                   return object_.separator_char(object_);
                }
               
                bool isCommentKey(const std::string key) const override
                {
                    return object_.is_comment_key(object_,key);
                }

                std::string defaultNullValue() const override
                {
                    return object_.default_null_value(object_); 
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
      
        friend std::array<char,2> separator_char(const NodeKeys & node_keys)
        {
            return node_keys.valuePtr_->separatorChar();
        }

        friend bool is_comment_key(const NodeKeys & node_keys, const std::string key)
        {
            return node_keys.valuePtr_->isCommentKey(key);
        }

        friend std::string default_null_value(const NodeKeys & node_keys)
        {
            return node_keys.valuePtr_->defaultNullValue();
        }
        //! \brief Returns iterators to the begin and end of the master list of 
        //! control file node keys. 
        //!
        //! The first  and second member elements are respectively 
        //! constant iterators to the beginning and the end of the list.
        //!
        //! \return std::pair<std::vector<std::string>::const_iterator, std::vector<std::string>::const_iterator>. 
        std::pair<std::vector<std::string>::const_iterator,
                  std::vector<std::string>::const_iterator>
        friend all_keys_iterator(const NodeKeys & node_keys) 
        {
            return node_keys.valuePtr_->allKeysIterator();
        }
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::unique_ptr<NodeKeysConcept> valuePtr_;

}; // -----  end of class NodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_NodeKeys_INC
