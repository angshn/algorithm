#!/bin/sh
if [ -z $1 ];then
    echo "The target file is empty, please give a exist file path."
    exit 1
fi

source /Users/syang/career/algorithm/codeforces/bin/env.sh

# printf "Staring build app = %s\n" $1
cpp_file=$(basename $1)
base_name="${cpp_file%.*}.out"
# echo $base_name

compile () {
    cxxflags="-Wall -Wextra -Wshadow"
    sc=$(g++ -std=c++17 $cxxflags $cpp_file -o $base_name)
}



run () {
    # echo "cat $input > $base_name"
    ret=`cat $input | ./$base_name`
    # $($ret >out.o)
    echo "$ret"

}

compile
run