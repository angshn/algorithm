int kadane(int *buf,int len){
    int ret = -(1<<30);
    int _max = 0;
    for(int i=0;i<len;i++){
        _max +=buf[i];
        if(_max > ret) ret = _max;
        if(_max < 0) _max = 0;
    }
    return ret;
}

