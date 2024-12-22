#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct strbuf {
    int len;
    int alloc;
    char *buf;
};

void strbuf_grow(struct strbuf *sb, size_t extra)
{
    sb->buf = (char*)realloc(sb->buf,sizeof(char)*(sb->len+extra));
    sb->alloc += extra;
}

void strbuf_add(struct strbuf *sb, const void *data, size_t len)
{
    if(data == NULL)return;
    if(sb->len+len>sb->alloc)
        strbuf_grow(sb,len);
    memcpy(sb->buf+sb->len,(char*)data,len);
    sb->len += len;
}

void strbuf_addstr(struct strbuf *sb, const char *s)
{
    if(s == NULL)return;
    int len = strlen(s);
    if(sb->len+len+1>sb->alloc) // +1是为了放'\0'
    {
        sb->buf = (char*)realloc(sb->buf,((sb->alloc+len+1)*sizeof(char)));
        sb->alloc += len;
    }
    strcpy(sb->buf+sb->len,s);
    sb->len += len;
    *(sb->buf+sb->len) = '\0';
}

void strbuf_init(struct strbuf *sb, size_t alloc)
{
    sb->alloc = alloc;
    sb->len = 0;
    //sb = (strbuf*)malloc(sizeof(strbuf));
    sb->buf = (char*)malloc(sizeof(char)*alloc);
}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc)
{
    if(sb->buf==NULL)strbuf_init(sb,alloc);
    sb->len = len;
    sb->alloc = alloc;
    sb->buf = (char*)str;
}
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len)
{
    if(target_buf==NULL)return NULL;
    char*result = (char*)malloc(sizeof(char)*len+1);
    memmove(result,target_buf+begin,end-begin);
    result[end-begin] = '\0';
    return result;
}

void strbuf_add_split(struct strbuf *sb, const char *s,int len)
{
    if(s == NULL)return;
    if(sb->len+len+1>sb->alloc) // +1是为了放'\0'
    {
        sb->buf = (char*)realloc(sb->buf,((sb->alloc+len+1)*sizeof(char)));
        sb->alloc += len;
    }
    memcpy(sb->buf+sb->len,s,len);
    sb->len += len;
    *(sb->buf+sb->len) = '\0';
}

char *strbuf_split_buf_using(char *target_buf, int begin, int end, int len,int *len_result)
{
    if(target_buf==NULL)return NULL;
    char*result = (char*)malloc(sizeof(char)*len+1);
    memmove(result,target_buf+begin,end-begin);
    result[end-begin] = '\0';
    *len_result = end - begin;
    return result;
}

struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max)
{
    char * str_temp = (char*)malloc(len+1*sizeof(char));
    memcpy(str_temp,str,len+1);
    char * ending = str_temp+len;
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
        //
        int len_result;
        int * p = &len_result;
        char *temp = strbuf_split_buf_using(str_temp,beg,end,strlen(str_temp)+10000,p);
        strbuf_init(sb[count],strlen(temp)+1+100000);
        strbuf_add_split(sb[count++],temp,len_result);
        free(temp);
        //
        beg = end;
    }
    sb[count] = NULL;
    free(str_temp);
    return sb;
}

int main()
{
    for(int i = 0;i<4;i++)
    {
        printf("%s\n",strbuf_split_buf("14 11 12 123",strlen("14 11 12 123"),' ',1024)[i]->buf);
        printf("%d\n",strbuf_split_buf("14 11 12 123",strlen("14 11 12 123"),' ',1024)[i]->len);
        
    }
    return 0;
}


//struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max)
// {
//     char * strt;
//     strcpy(strt,str);
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)+sizeof(char)*(max+1));
//     int beg = 0,end = 0,count = 0;
//     while(str[end]!='\0')
//     {
//         while(str[end]!=terminator)end++;
//         char *temp = strbuf_get_mid_buf(strt,beg,end,strlen(str));
//         strcpy(sb[count++]->buf,temp);
//         free(temp);
//         beg = end + 1;
//     }
//     return sb;
// }



// char * str_temp = (char*)malloc(len+1*sizeof(char));
//     strcpy(str_temp,str);
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)+sizeof(char)*(max+1));
//     int beg = 0,end = 0,count = 0;
//     while(str[end]!='\0')
//     {
//         while(str[end]!=terminator)end++;
//         char *temp = strbuf_get_mid_buf(str_temp,beg,end,strlen(str));
//         strbuf_init(sb[count],strlen(temp)+1);
//         strbuf_addstr(sb[count++],temp);
//         free(temp);
//         beg = end + 1;
//     }
//     sb[count] = NULL;
//     free(str_temp);
//     return sb;


// char * str_temp = (char*)malloc(len+1*sizeof(char));
//     strcpy(str_temp,str);
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)*(max));
//     int beg = 0,end = 0,count = 0;
//     int count_ = 0;
//     for(int i = 0;str_temp[i]!='\0';i++)if(str_temp[i]==terminator&&str_temp[i+1]!=terminator&&str_temp[i+1]!='\0')count_++;
//     if(str_temp[0]!=terminator)count_++;
//     while(str[end]!='\0')
//     {
//         while(str[beg]==terminator&&str[beg]!='\0')beg++;
//         if(count == max||count == count_)
//         {
//             sb[count] = NULL;
//             break;
//         }
//         end = beg;
//         sb[count] = (struct strbuf*)malloc(1000);
//         while(str[end]!=terminator&&str[end]!='\0')end++;
//         char *temp = strbuf_get_mid_buf(str_temp,beg,end,strlen(str));
//         strbuf_init(sb[count],strlen(temp)+1);
//         strbuf_addstr(sb[count++],temp);
//         free(temp);
//         beg = end;
//     }
//     sb[count] = NULL;
//     free(str_temp);
//     return sb;

// char * str_temp = (char*)malloc(len+1*sizeof(char));
//     strcpy(str_temp,str);
//     char * ending = str_temp+len;
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)*(max));
//     int beg = 0,end = 0,count = 0;
//     int count_ = 0;
//     for(int i = 0;&str_temp[i]!=ending;i++)if(str_temp[i]==terminator&&str_temp[i+1]!=terminator&&&str_temp[i+1]!=ending)count_++;
//     if(str_temp[0]!=terminator)count_++;
//     while(&str_temp[end]!=ending)
//     {
//         while(str_temp[beg]==terminator&&&str_temp[beg]!=ending)beg++;
//         if(count == max||count == count_)
//         {
//             sb[count] = NULL;
//             break;
//         }
//         end = beg;
//         sb[count] = (struct strbuf*)malloc(1000);
//         while(str_temp[end]!=terminator&& &str_temp[end]!=ending)end++;
//         char *temp = strbuf_get_mid_buf(str_temp,beg,end,strlen(str_temp));
//         strbuf_init(sb[count],strlen(temp)+1);
//         strbuf_addstr(sb[count++],temp);
//         free(temp);
//         beg = end;
//     }
//     sb[count] = NULL;
//     free(str_temp);
//     return sb;


// char * str_temp = (char*)malloc((len+1)*sizeof(char));
//     memcpy(str_temp,str,len+1);
//     char * ending = str_temp+len;
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf*)*(max));
//     int beg = 0,end = 0,count = 0;
//     int count_ = 0;
//     for(int i = 0;&str_temp[i]!=ending;i++)if(str_temp[i]==terminator&&str_temp[i+1]!=terminator&&&str_temp[i+1]!=ending)count_++;
//     if(str_temp[0]!=terminator)count_++;
//     while(&str_temp[end]!=ending)
//     {
//         while(str_temp[beg]==terminator&&&str_temp[beg]!=ending)beg++;
//         if(count == max||count == count_)
//         {
//             sb[count] = NULL;
//             break;
//         }
//         end = beg;
//         sb[count] = (struct strbuf*)malloc(10000);
//         while(str_temp[end]!=terminator&& &str_temp[end]!=ending)end++;
//         char *temp = strbuf_get_mid_buf(str_temp,beg,end,strlen(str_temp));
//         strbuf_init(sb[count],strlen(temp)+1);
//         strbuf_addstr(sb[count++],temp);
//         free(temp);
//         beg = end;
//     }
//     sb[count] = NULL;
//     free(str_temp);
//     return sb;

// char * str_temp = (char*)malloc(len+1*sizeof(char));
//     memcpy(str_temp,str,len+1);
//     char * ending = str_temp+len;
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)*(max));
//     int beg = 0,end = 0,count = 0;
//     int count_ = 0;
//     for(int i = 0;&str_temp[i]!=ending;i++)if(str_temp[i]==terminator&&str_temp[i+1]!=terminator&&&str_temp[i+1]!=ending)count_++;
//     if(str_temp[0]!=terminator)count_++;
//     while(&str_temp[end]!=ending)
//     {
//         while(str_temp[beg]==terminator&&&str_temp[beg]!=ending)beg++;
//         if(count == max||count == count_)
//         {
//             sb[count] = NULL;
//             break;
//         }
//         end = beg;
//         sb[count] = (struct strbuf*)malloc(1000);
//         while(str_temp[end]!=terminator&& &str_temp[end]!=ending)end++;
//         //
//         char *temp = strbuf_get_mid_buf(str_temp,beg,end,strlen(str_temp)+10000);
//         strbuf_init(sb[count],strlen(temp)+1+100000);
//         strbuf_addstr(sb[count++],temp);
//         free(temp);
//         //
//         beg = end;
//     }
//     sb[count] = NULL;
//     free(str_temp);
//     return sb;

// char * str_temp = (char*)malloc(len+1*sizeof(char));
//     memcpy(str_temp,str,len+1);
//     char * ending = str_temp+len;
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)*(max));
//     int beg = 0,end = 0,count = 0;
//     int count_ = 0;
//     for(int i = 0;&str_temp[i]!=ending;i++)if(str_temp[i]==terminator&&str_temp[i+1]!=terminator&&&str_temp[i+1]!=ending)count_++;
//     if(str_temp[0]!=terminator)count_++;
//     while(&str_temp[end]!=ending)
//     {
//         while(str_temp[beg]==terminator&&&str_temp[beg]!=ending)beg++;
//         if(count == max||count == count_)
//         {
//             sb[count] = NULL;
//             break;
//         }
//         end = beg;
//         sb[count] = (struct strbuf*)malloc(1000);
//         while(str_temp[end]!=terminator&& &str_temp[end]!=ending)end++;
//         //
//         int len_result;
//         int * p = &len_result;
//         char *temp = strbuf_split_buf_using(str_temp,beg,end,strlen(str_temp)+10000,p);
//         strbuf_init(sb[count],strlen(temp)+1+100000);
//         strbuf_add(sb[count++],temp,len_result);
//         free(temp);
//         //
//         beg = end;
//     }
//     sb[count] = NULL;
//     free(str_temp);
//     return sb;

// char * str_temp = (char*)malloc(len+1*sizeof(char));
//     memcpy(str_temp,str,len+1);
//     char * ending = str_temp+len;
//     struct strbuf **sb = (struct strbuf**)malloc(sizeof(struct strbuf)*(max));
//     int beg = 0,end = 0,count = 0;
//     int count_ = 0;
//     for(int i = 0;&str_temp[i]!=ending;i++)if(str_temp[i]==terminator&&str_temp[i+1]!=terminator&&&str_temp[i+1]!=ending)count_++;
//     if(str_temp[0]!=terminator)count_++;
//     while(&str_temp[end]!=ending)
//     {
//         while(str_temp[beg]==terminator&&&str_temp[beg]!=ending)beg++;
//         if(count == max||count == count_)
//         {
//             sb[count] = NULL;
//             break;
//         }
//         end = beg;
//         sb[count] = (struct strbuf*)malloc(sizeof(struct strbuf));
//         while(str_temp[end]!=terminator&& &str_temp[end]!=ending)end++;
//         //
//         int len_result;
//         int * p = &len_result;
        
//         char *temp = strbuf_split_buf_using(str_temp,beg,end,1000000,p);
//         strbuf_init(sb[count],len_result);
//         strbuf_add_split(sb[count++],temp,len_result);
//         free(temp);
//         //
//         beg = end;
//     }
//     sb[count] = NULL;
//     free(str_temp);
//     return sb;