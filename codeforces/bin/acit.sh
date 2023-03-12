#!/bin/bash


_filename=$1
empty_input () {
    printf "Empty the input txt file %s" $_filename
    > /Users/syang/career/algorithm/codeforces/in.in
}
if [ -z $1 ];then
    empty_input
    exit 0
fi
cpp_file=$(basename $_filename)
base_name="${cpp_file%.*}"

clean () {
    rm -rf $base_name.out

}

move () {
    mv $cpp_file /Users/syang/career/algorithm/codeforces/done
}
empty_input
clean
move
