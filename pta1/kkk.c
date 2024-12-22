int main()
{
    
}
char * str_temp = (char*)malloc(len+1*sizeof(char));
    memcpy(str_m,str,len+1);
    char * ending = str_temp+len;
    struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)*(max));
    int beg = 0,end = 0,count = 0;
    int count_ = 0;
    for(int i = 0;&str_m[i]!=ending;i++)if(str_m[i]==terminator&&str_m[i+1]!=terminator&&&str_m[i+1]!=ending)count_++;
    if(str_m[0]!=terminator)count_++;
    while(&str_m[end]!=ending)
    {
        while(str_m[beg]==terminator&&&str_m[beg]!=ending)beg++;
        if(count == max||count == count_)
        {
            sb[count] = NULL;
            break;
        }
        end = beg;
        sb[count] = (struct strbuf*)malloc(sizeof(struct strbuf));
        while(str_m[end]!=terminator&& &str_m[end]!=ending)end++;
        //
        int len_result;
        int * p = &len_result;
        
        char *temp = strbuf_split_buf_using(str_temp,beg,end,1000000,p);
        strbuf_init(sb[count],len_result);
        strbuf_add_split(sb[count++],temp,len_result);
        free(temp);
        //
        beg = end;
    }
    sb[count] = NULL;
    free(str_m);
    return sb;