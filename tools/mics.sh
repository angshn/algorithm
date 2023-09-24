

clean(){
    p=$1
    if [ -z "$p" ];then
        p="."
    fi
    print "clean no using file and directory."
    find $p -name "*.dSYM" | xargs rm -rf
    find $p -type f -not -name "*.cpp" | xargs rm -rf

}