#!/usr/bin/env bash

form_suffix () {
    # Form the timestamp for the original file name.
    local -r timestamp=$(date -I'minutes')
    local -r my_suffix='.orig.'${timestamp}
    echo ${my_suffix}
}

declare -r file_name=${1}

astyle --project  --verbose --suffix=$(form_suffix) ${1}
