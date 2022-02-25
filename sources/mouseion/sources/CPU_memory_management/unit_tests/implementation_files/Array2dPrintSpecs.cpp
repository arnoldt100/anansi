// =====================================================================================
//
//       Filename:  Array2dPrintSpecs.cpp
//
//    Description:  
//
//         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
//   Organization:  ORNL-National Center of Computational Sciences
//
// =====================================================================================


#include "Array2dPrintSpecs.h"


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================


Array2dPrintSpecs::Array2dPrintSpecs(ArrayLayoutType const layout_type, 
                                     std::string const title,
                                     std::size_t const row_size,
                                     std::size_t const column_size) :
_layoutType(layout_type),
_title(title),
_rowSize(row_size),
_columnSize(column_size),
_widthIndicesColumnHeader(0),
_widthDisplacement(0),
_widthColumnSeparator(5),
_widthPMA(0),
_widthPOA(0),
_indicesColumnHeaderSpec(""),
_displacementSpec(""),
_pmaSpec(""),
_poaSpec("")
{
    std::size_t const width=10;

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Create the boost printf specification for the table column 
    // headers.
    //                                                                 
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    if (layout_type == ArrayLayoutType::column_major)
    {
        this->_indicesColumnHeader = std::string("(column,row)");
    }
    else
    {
        this->_indicesColumnHeader = std::string("(row,column)");
    }

    std::string array_access1;
    if (layout_type == ArrayLayoutType::column_major)
    {
        array_access1 = std::string("A[column][row]");
    }
    else
    {
        array_access1 = std::string("A[row][column]");
    }

    std::string array_access2 = "*(A + displacement)"; 

    std::string const col_sep_spec = this->_columnSeparatorSpec(_widthColumnSeparator);

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Create the boost printf specification for the table column 
    // headers.
    //                                                                 
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    // Define the width to print the array indices..
    std::size_t tmp_width1 = 2*width+3; // row,column
    std::size_t tmp_width2 = this->_indicesColumnHeader.length();
    this->_widthIndicesColumnHeader=( tmp_width1 > tmp_width2  ? tmp_width1 : tmp_width2 );
    this->_indicesColumnHeaderSpec = "(%|-u|,%|-u|)";
  
    // Define the width to print the displacement.
    std::string displacement("Displacement");
    tmp_width1 = width; 
    tmp_width2 = displacement.length();
    this->_widthDisplacement = ( tmp_width1 > tmp_width2  ? tmp_width1 : tmp_width2 );
    this->_displacementSpec = "%|-"+ std::to_string(this->_widthDisplacement) + "i|";

    //Define the width to print the Array value obtained by pointer math,
    std::string pma("*(A+displacement)");
    tmp_width1 = width; 
    tmp_width2 = pma.length();
    this->_widthPMA = ( tmp_width1 > tmp_width2  ? tmp_width1 : tmp_width2 );
    this->_pmaSpec = "%|-"+ std::to_string(this->_widthPMA) + "i|";

    //Define the width to print the Array value obtained by operator access,  A[x][y].
    std::string const poa = this->_headerForPOA(layout_type);
    tmp_width1 = width; 
    tmp_width2 = poa.length();
    this->_widthPOA = ( tmp_width1 > tmp_width2  ? tmp_width1 : tmp_width2 );
    this->_poaSpec = "%|-"+ std::to_string(this->_widthPOA) + "i|" + col_sep_spec;

    return;
}  // -----  end of method Array2dPrintSpecs::Array2dPrintSpecs  (constructor)  ----- 


Array2dPrintSpecs::Array2dPrintSpecs ( const Array2dPrintSpecs &other ) :
_layoutType(other._layoutType),
_title(other._title),
_rowSize(other._rowSize),
_columnSize(other._columnSize),
_indicesColumnHeader(other._indicesColumnHeader),
_widthIndicesColumnHeader(other._widthIndicesColumnHeader),
_widthDisplacement(other._widthDisplacement),
_widthColumnSeparator(other._widthColumnSeparator),
_widthPMA(other._widthPMA),
_widthPOA(other._widthPOA),
_indicesColumnHeaderSpec(other._indicesColumnHeaderSpec),
_displacementSpec(other._displacementSpec),
_pmaSpec(other._pmaSpec),
_poaSpec(other._poaSpec)
{
    if ( this != &other ) 
    {
    }
    return;
}  // -----  end of method Array2dPrintSpecs::Array2dPrintSpecs  (copy constructor)  ----- 


Array2dPrintSpecs::~Array2dPrintSpecs ()
{
    return;
}  // -----  end of method Array2dPrintSpecs::~Array2dPrintSpecs  (destructor)  ----- 


//============================= ACCESSORS ====================================
void Array2dPrintSpecs::printHeaders(std::ofstream & fileObj) const
{
    // Column separator.
    std::string col_sep(this->_widthColumnSeparator,' ');

    // Title header.
    std::string my_title_spec;
    if (this->_layoutType == ArrayLayoutType::column_major)
    {
         my_title_spec += std::string("Column Major Matrix %|-u| x %|-u|\n");
    }
    else
    {
         my_title_spec += std::string("Row Major Matrix %|-u| x %|-u|\n");
    }

    boost::format my_title_frmt(my_title_spec);
    my_title_frmt % this->_rowSize % this->_columnSize;
    fileObj << str(my_title_frmt);

    // Table column header.
    std::string my_table_header_specs;
    my_table_header_specs += "%|-" + std::to_string(this->_widthIndicesColumnHeader) + "s|";
    boost::format my_table_header_frmt(my_table_header_specs);
    my_table_header_frmt % this->_indicesColumnHeader;
    fileObj << str(my_table_header_frmt);

    std::string my_displacement_spec;
    my_displacement_spec += col_sep +  "%|-" + std::to_string(this->_widthDisplacement) + "s|";
    boost::format my_displacement_frmt(my_displacement_spec);
    my_displacement_frmt % "Displacement";
    fileObj << str(my_displacement_frmt);

    std::string my_pma_spec;
    my_pma_spec += col_sep + "%|-" + std::to_string(this->_widthPMA) + "s|";
    boost::format my_pma_frmt(my_pma_spec);
    my_pma_frmt % "*(A+displacement)";
    fileObj << str(my_pma_frmt);

    std::string my_poa_spec;
    my_poa_spec += col_sep + "%|-" + std::to_string(this->_widthPOA) + "s|" + "\n";
    boost::format my_poa_frmt(my_poa_spec);
    my_poa_frmt % this->_headerForPOA(this->_layoutType);
    fileObj << str(my_poa_frmt);
    return;
}

void Array2dPrintSpecs::printErroneousElement(
    std::ofstream & fileObj,
    const std::size_t row_index, 
    const std::size_t column_index,
    const std::size_t displacement,
    const std::size_t value_pma,
    const std::size_t value_poa ) const
{
    std::string const col_sep_spec = this->_columnSeparatorSpec(_widthColumnSeparator);

    // Printing the indices of the errorneous array element.
    boost::format my_table_header_frmt(this->_indicesColumnHeaderSpec);
    std::string aString = str(my_table_header_frmt % row_index % column_index);
    std::string tmp_spec = "%|-" + std::to_string(this->_widthIndicesColumnHeader) + "s|";
    fileObj << str(boost::format(tmp_spec) % aString) << col_sep_spec;

    // Printing the displacement.
    boost::format my_disp_frmt(this->_displacementSpec);
    my_disp_frmt % displacement;
    fileObj << str(my_disp_frmt) << col_sep_spec;

    // Printing the value obtained by pointer math arithmetic.
    boost::format my_pma_frmt(this->_pmaSpec);
    my_pma_frmt % value_pma;
    fileObj << str(my_pma_frmt) << col_sep_spec;

    // Printing the value obtained by pointer array access.
    boost::format my_poa_frmt(this->_poaSpec);
    my_poa_frmt % value_poa;
    fileObj << str(my_poa_frmt) << std::endl;
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

Array2dPrintSpecs&
Array2dPrintSpecs::operator=( const Array2dPrintSpecs &other )
{
    if ( this != &other )
    {
        this->_layoutType=other._layoutType;
        this->_title=other._title;
        this->_rowSize=other._rowSize;
        this->_columnSize=other._columnSize;
        this->_indicesColumnHeader=other._indicesColumnHeader;
        this->_widthIndicesColumnHeader=other._widthIndicesColumnHeader;
        this->_widthDisplacement=other._widthDisplacement;
        this->_widthColumnSeparator=other._widthColumnSeparator;
        this->_widthPMA=other._widthPMA;
        this->_widthPOA=other._widthPOA;
        this->_indicesColumnHeaderSpec=other._indicesColumnHeaderSpec;
        this->_displacementSpec=other._displacementSpec;
        this->_pmaSpec = other._pmaSpec;
        this->_poaSpec = other._poaSpec;
    }
    return *this;
}  // -----  end of method Array2dPrintSpecs::operator=  (assignment operator)  ----- 

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================


std::string
Array2dPrintSpecs::_columnSeparatorSpec(std::size_t const nm_spaces) const
{
    std::string tmp_string(nm_spaces,' '); 
    return tmp_string;
    
}		// -----  end of method Array2dPrintSpecs::_columnSeparatorSpec  ----- 

std::string
Array2dPrintSpecs::_headerForPOA( enum ArrayLayoutType const &  array_layout) const
{
    const std::string aString = ( array_layout == ArrayLayoutType::row_major ? std::string("A[ip][jp]") : std::string("A[jp][ip]") );
    return aString;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


