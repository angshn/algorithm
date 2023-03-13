#!/bin/bash


function help() {
    printf "--clean: Cleaning the given directory \n *.dSYM"
}

function newfile () {
    _name=$2
    _path=$1
    echo $_path
    if [ ! -d "/Users/syang/career/algorithm/codeforces/pending/$_path" ];then
        echo "Creating directory /Users/syang/career/algorithm/codeforces/pending/$_path"
        mkdir -p "/Users/syang/career/algorithm/codeforces/pending/$_path"
    fi

    echo "creating file $_name.cpp in /Users/syang/career/algorithm/codeforces/pending/$_path"
    _fi=/Users/syang/career/algorithm/codeforces/pending/$_path/$_name.cpp
    touch $_fi
    cat /Users/syang/career/algorithm/codeforces/templates/template.txt > $_fi
}

function print () {
    # 定义颜色变量, 还记得吧, \033、\e和\E是等价的
    _RED='\033[1;31m'       # 红
    _GREEN='\033[0;1;32m'    # 绿
    _YELOW='\033[1;33m'    # 黄
    _BLUE='\033[1;34m'     # 蓝
    _PINK='\033[1;35m'     # 粉红
    _RES='\033[0m'          # 清除颜色
    case "$1" in
    suc)   echo -e "${_GREEN}$2${_RES}"
        ;;
    error) echo -e "${_RED}$2${_RES}"
        ;;
    info) echo -e "${_BLUE}$2${_RES}"
        ;;
    *)     echo "$1"
        ;;
    esac
}


function compile () {
    cpp_file=$(realpath $1)
    __noSuffixFilename=$(basename $cpp_file)
    base_name="${__noSuffixFilename%.*}.out"
    print info $base_name
    outPath=$(dirname $1)/$base_name
    cxxflags="-g -Wall -Wextra -Wshadow -Wunused-variable"
    printf "============== START COMPILE ================\n"
    g++ -std=c++17 $cxxflags $cpp_file -o $outPath
    printf "============== END   COMPILE ================\n"
}

function run() {
    ret=`cat $1 | $(realpath ./$2)`
    # $($ret >out.o)
    printf "============== START OUTPUT ================\n"
    echo "$ret"
    printf "============== END   OUTPUT ================\n"
}


set -- $(getopt -q f:b: --long clean, -- "$@")
while [ -n "$1" ]
do
    case "$1" in
    -d) round=$2
        shift
        ;;
    -s) problem=$2
        echo "problem sequence is $2"
        shift
        ;;
    -b) echo "build cpp file = $2" #编译目标文件应用
        cppfile=$2
        shift
        ;;
    -clean) clean="clean";
        shift
        ;;
    --);;
    *) shift
        ;;
    esac
    shift
done

if [ -n "$clean" ];then
    print info "Clean the root direcotry"
    kase=("*.dSYM" "*.out")
    for _cake in ${kase[*]}
    do

        num=$(find /Users/syang/career/algorithm -name $_cake | wc -l)
        num=$(echo $num | xargs)
        if [ $num -ne 0 ];then
            print info "Searching for $_cake"
            print info $(find /Users/syang/career/algorithm -name $_cake)
            find /Users/syang/career/algorithm -name "$_cake" | xargs rm -rf
        fi
        # else
            # print info "No matches $_cake found. "
        # fi
    done
fi


if [ -n "$round"  -a -n "$problem"  ];then
    newfile $round $problem
    
    print suc "Create problem file Successfylly."
fi

if [  -n "$cppfile" ];then
    print "开始编译"
    compile $cppfile
    if [ $? -eq 0 ];then
        print suc "> 编译成功,开始运行.\n"
        run "/Users/syang/career/algorithm/codeforces/in.in" $outPath
        print "运行结束"
    else
        print error "编译失败"
    fi
fi
