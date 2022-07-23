#! /usr/bin/env bash

# Start of controlfile option help test.
echo "---"
echo "Start of test"
echo "mpirun -n 1 ~/sw/Anansi/bin/md_main --controlfile water_simulation.anansi"
echo "---"
mpirun -n 1 ~/sw/Anansi/bin/md_main --controlfile water_simulation.anansi
echo "---"
echo "End of test"
echo "---"
