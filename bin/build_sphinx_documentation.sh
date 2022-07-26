#! /usr/bin/env bash
cd ${ANANSI_TOP_LEVEL}/sources/core_packages/mouseion/documentation
make clean && make html
if [[ $? != 0 ]]; then
    echo "Failed to create mouseion documentation."
    exit 1
else
    echo "Created mouseion documentation."
    echo ""
    echo ""
fi

cd ${ANANSI_TOP_LEVEL}/documentation
make clean && make html
if [[ $? != 0 ]]; then
    echo "Failed to create Anansi documentation."
    exit 1
else
    echo "Created Anansi documentation."
fi
