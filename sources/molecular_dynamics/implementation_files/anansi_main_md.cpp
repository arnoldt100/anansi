#include "anansi_main_md.h"

int main( int argc, char** argv )
{
    ANANSI::MolecularDynamics * md_ptr = new ANANSI::AnansiMolecularDynamics;

    if (md_ptr != nullptr)
    {
        delete md_ptr;
        md_ptr=nullptr;
    }

    return 0;
}
