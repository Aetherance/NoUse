char * str_temp = (char*)malloc(len+1*sizeof(char));
    
    int main()
    {
    strcpy(str_temp,str);
    char * ending = str_temp+strlen(str_temp);
    struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)*(max));
    int beg = 0,end = 0,count = 0;
    int count_ = 0;
    for(int i = 0;&str_temp[i]!=ending;i++)if(str_temp[i]==terminator&&str_temp[i+1]!=terminator&&&str_temp[i+1]!=ending)count_++;
    if(str_temp[0]!=terminator)count_++;
    while(&str_temp[end]!=ending)
    {
        while(str_temp[beg]==terminator&&&str_temp[beg]!=ending)beg++;
        if(count == max||count == count_)
        {
            sb[count] = NULL;
            break;
        }
        end = beg;
        sb[count] = (struct strbuf*)malloc(1000);
        while(str_temp[end]!=terminator&& &str_temp[end]!=ending)end++;
        char *temp = strbuf_get_mid_buf(str_temp,beg,end,strlen(str_temp));
        strbuf_init(sb[count],strlen(temp)+1);
        strbuf_addstr(sb[count++],temp);
        free(temp);
        beg = end;
    }
    sb[count] = NULL;
    free(str_temp);
    return sb;
    }