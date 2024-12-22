#include<stdio.h>
struct strbuf {
    int len;
    int alloc;
    char *buf;
};
void strbuf_add(struct strbuf *sb, const void *data, size_t len)
{
    if(data == NULL)return;
    if(sb->len+len>sb->alloc)
        strbuf_grow(sb,len);
    strcpy(sb->buf+sb->len,(char*)data);
    sb->len += len;
}
int main()
{


    
     
 
 
    return 0;
}