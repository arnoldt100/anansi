#ifndef ANANSI_ControlFilePickle_INC
#define ANANSI_ControlFilePickle_INC
//! \file ControlFilePickle.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! \brief The policy class for pickking and unpickling the Control File.
//!
//! Responsibility: Transforming the ControlFile internal representation, "InternalRepresentation_t",
//! to "PickleType_t" and vice versa. 
class ControlFilePickle
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFilePickle ();   // constructor

        ControlFilePickle (const ControlFilePickle & other);   // copy constructor

        ControlFilePickle (ControlFilePickle && other);   // copy-move constructor

        ~ControlFilePickle ();  // destructor

        // ====================  STATIC        =======================================
        //! \param[in] control_file_keys Contains all of the keys available in the control file.
        //! \param[in] pickled_object The ControlFile class in pickled form.
        //! \tparam InternalRepresentation_t The type of the ControlFile internal representation.
        //! \tparam PickleType_t The type of the pickled ControlFile class.
        //! \return The ControlFile class in its internal representation.
        template<typename InternalRepresentation_t,
                 typename PickleType_t,
                 typename MasterControlFileNodeKeys_t,
                 typename DefaultValue_t> 
        static InternalRepresentation_t unpickle(const MasterControlFileNodeKeys_t & control_file_keys,
                                                 const PickleType_t & pickled_object)
        {
            InternalRepresentation_t ret_value;
            const auto it_keys = control_file_keys.allKeysIterator();
            for (auto it = it_keys.first; it != it_keys.second; ++it)
            {
                const std::string key(*it);
                if ( control_file_keys.isCommentTag(key))
                {
                   continue; 
                }
                
                if (auto search = pickled_object.find(key); search != pickled_object.end() )
                {
                    ret_value.put(key,pickled_object.at(key));
                }
                else
                {
                    ret_value.put(key,DefaultValue_t::VALUE);
                }
            }
            return ret_value;
        }

        static void pickle();

        // ====================  ACCESSORS     =======================================
        
        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFilePickle& operator= ( const ControlFilePickle &other ); // assignment operator

        ControlFilePickle& operator= ( ControlFilePickle && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFilePickle  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFilePickle_INC
