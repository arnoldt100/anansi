/*
 * =====================================================================================
 *
 *       Filename:  PointerInitializationTraits.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/11/2018 10:53:36 AM
 *
 *         Author:  Arnold Tharrington (), arnoldt@ornl.gov
 *   Organization:  National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  PointerInitializationTraits_INC
#define  PointerInitializationTraits_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include<cstddef>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MEMORY_MANAGEMENT
{

template<typename T>
class PointerArrayInitializationTraits
{
    public:
        //===== DATA MEMBERS ===
        static constexpr T zero = nullptr;
        static constexpr char nullchar = '\0';
};

template<>
class PointerArrayInitializationTraits<char>
{
    public:
        //===== DATA MEMBERS ===
        static constexpr char zero = '0';
        static constexpr char nullchar = '\0';
};

template<>
class PointerArrayInitializationTraits<double>
{
    public:
        //===== DATA MEMBERS ===
        static constexpr double zero=0.00;
};

template<>
class PointerArrayInitializationTraits<int>
{
    public:
        //===== DATA MEMBERS ===
        static constexpr int zero=0;
};

template<>
class PointerArrayInitializationTraits<std::size_t>
{
    public:
        //===== DATA MEMBERS ===
        static constexpr std::size_t zero = 0;
};

};
#endif   /* ----- #ifndef PointerInitializationTraits_INC  ----- */
