

clean(){
    p=$1
    if [ -z "$p" ];then
        p="."
    fi
    print "clean no using file and directory."
    find $p -not -name "*.cpp" | xargs rm -rf
}