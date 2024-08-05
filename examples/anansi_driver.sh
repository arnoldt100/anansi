#! /usr/bin/env bash

# Start of long option help test.
echo "---"
echo "Start of test" 
echo "mpirun -n 2 ~/sw/Anansi/bin/anansi_md --help"
echo "---"

mpirun -n 2 ~/sw/Anansi/bin/anansi_md --help

echo "---"
echo "End of test"
echo "---"

echo ""
echo ""

# Start of short option help test.
echo "---"
echo "Start of test"
echo "mpirun -n 2 ~/sw/Anansi/bin/anansi_md -h"
echo "---"
mpirun -n 2 ~/sw/Anansi/bin/anansi_md -h
echo "---"
echo "End of test"
echo "---"

echo ""
echo ""
echo ""

# Start of short option help test.
echo "---"
echo "Start of test" 
echo "mpirun -n 2 ~/sw/Anansi/bin/anansi_md"
echo "---"
mpirun -n 2 ~/sw/Anansi/bin/anansi_md
echo "---"
echo "End of test"
echo "---"

echo ""
echo ""

# Start of controlfile option help test.
echo "---"
echo "Start of test"
echo "mpirun -n 2 ~/sw/Anansi/bin/anansi_md --controlfile water_simulation.anansi"
echo "---"
mpirun -n 2 ~/sw/Anansi/bin/anansi_md --controlfile water_simulation.anansi
echo "---"
echo "End of test"
echo "---"
