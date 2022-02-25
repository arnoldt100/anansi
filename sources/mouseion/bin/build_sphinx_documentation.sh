#! /usr/bin/env bash

cd ${MOUSEION_TOP_LEVEL}/documentation
make clean && make html
if [[ $? != 0 ]]; then
    echo "Failed to create Anansi documentation."
    exit 1
else
    echo "Created Anansi documentation."
fi
