printf()后可能不会立即显示
要加\n或者使用fflush(stdout)
‘=’的运算优先级比‘<’低

//ipcs -s
//ipcrm -sem 信号量编号

kill的时候没执行sleep
ipcs -q查看消息队列，-m查看内存，-s查看信号量　-a查看上述所有信息

共享内存使用时注意读完要memset()否则会被污染

scanf("*[^\n]")//用正则表达读取
fgets()读取文件符
