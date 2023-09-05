#ifndef  ANANSI_BaseInputFile_INC
#define  ANANSI_BaseInputFile_INC

//! @file BaseInputFile.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! @tparam The derived class of the CRTP.
template<typename Derived,
         typename DerivedTypeTraits>
class BaseInputFile
{
    public:

        using PICKLETYPE = typename DerivedTypeTraits::PICKLETYPE;

    private:
        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to the CRTP derived class.
        constexpr Derived& asDerived_() 
        {
            return *static_cast<Derived*>(this);
        }

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        constexpr Derived const & asDerived_() const
        {
            return *static_cast<Derived const*>(this);
        }

        //! Provides access to the CRTP derived class member methods.
        //!
        //! The goal of this stucture is to better encapsulate (i.e. hide) the
        //! concrete CRTP derived implementation details. The derived classes
        //! implement protected member functions as in Derived::foo_. A
        //! function pointer to the address derived pointer member function is
        //! Derived::foo_ is formed so that we can indirectly call
        //! Derived::foo_.
        struct Accessor_ : public Derived 
        {
            //! Read and store the information from input file.
            template<typename... Types>
            static void read_property_tree(Derived & derived,Types&... args)
            {
                void (Derived::*fn)(Types &... args) = &Accessor_::readPropertyTree_;
                (derived.*fn)(args...);
                return;
            };

            //! Set the file name of the input files.
            static void set_file_name(Derived & derived, const std::string my_file_name)
            {
                void (Derived::*fn)(const std::string) = &Accessor_::setFileName_;
                (derived.*fn)(my_file_name);
                return;
            };

            static void write_to_disk(const Derived & derived, const std::string my_file_name)
            {
                void (Derived::*fn)(const std::string) const = &Accessor_::writeToDisk_;
                (derived.*fn)(my_file_name);
                return;
            };

            static typename DerivedTypeTraits::PICKLETYPE pickle(const Derived & derived)
            {
                typename DerivedTypeTraits::PICKLETYPE (Derived::*fn)() const = &Accessor_::pickle_;
                return (derived.*fn)();
            }

            static void unpickle(const Derived & derived, const typename DerivedTypeTraits::PICKLETYPE & pickleobj)
            {
                void (Derived::*fn) (const typename DerivedTypeTraits::PICKLETYPE &) = &Accessor_::unpickle_;
                return;
            }

        };

    public:

        // ====================  LIFECYCLE     =======================================

        BaseInputFile () // constructor
        {
            return;
        }

        BaseInputFile ( const BaseInputFile &other ) // copy constructor
        {
            if (this != &other)
            {
        
            }
            return;
        } 

        BaseInputFile (BaseInputFile && other) // copy-move constructor
        {
            if (this != &other)
            {
        
            }
            return;
        } 

        virtual ~BaseInputFile()=0;// destructor

        /* ====================  ACCESSORS     ======================================= */
        void writeToDisk(const std::string my_file_name) const
        {
            Accessor_::write_to_disk(this->asDerived_(), my_file_name);

        }

        typename DerivedTypeTraits::PICKLETYPE pickle() const
        {
            return Accessor_::pickle(this->asDerived_());
        }

        /* ====================  MUTATORS      ======================================= */
        void setFileName(const std::string my_file_name)
        {
            Accessor_::set_file_name(this->asDerived_(), my_file_name);
            return;
        }

        template<typename... Types>
        void readPropertyTree(Types&... args)
        {
            Accessor_::read_property_tree(this->asDerived_(),args...);
            return;
        }

        void unpickle( const DerivedTypeTraits::PICKLETYPE & pickle_obj)
        {
            Accessor_::unpickle(this->asDerived_(),pickle_obj);
            return;
        }

        /* ====================  OPERATORS     ======================================= */

        BaseInputFile& operator= ( const BaseInputFile &other ) /* assignment operator */
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        BaseInputFile& operator= ( BaseInputFile && other ) // assignment-move operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment-move operator

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        // ====================  MUTATORS      =======================================

        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class BaseInputFile  ----- */

template<typename Derived,typename DerivedTraits>
BaseInputFile<Derived,DerivedTraits>::~BaseInputFile()
{
    return;
}

}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_BaseInputFile_INC  ----- */
