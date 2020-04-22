import re
import requests

###采用match匹配
#总结 尽量使用泛匹配，使用括号得到的匹配目标，尽量使用非贪婪模式，有换行就用re.S
#缺点 从第一个字母开始匹配，存在不太方便的问题
#泛匹配
conent = "hello 123 4567 World_This is a Regex Demo"
result=re.match("^hello.*Demo$",conent)
print(result)
print(result.span())
print(result.group())

#匹配目标
result = re.match("^hello\s(\d+)\s4567.*Demo$",conent)
print(result)
print(result.span())
print(result.group(1))

#贪婪匹配 尽可能多的匹配
conent = "hello 1234567 World_This is a Regex Demo"
result = re.match("^hello.*(\d+)\s.*Demo$",conent)
print(result)
print(result.span())
print(result.group(1))

#非贪婪匹配 尽可能少的匹配字符
content = "hello 1234567 World_This is a Regex Demo"
result = re.match("^hello.*?(\d+)\s.*Demo$",conent)
print(result)
print(result.span())
print(result.group(1))

#匹配模式 .*不可以匹配换行符 所以要加上匹配模式
content = "hello 1234567 World_This is a Regex Demo"
result = re.match("^he.*?(\d+).*?Demo$",content,re.S)
print(result.group(1))

#转义
content = "price is $5.00"
result = re.match("price is \$5\.00",content)
print(result)

#search
content = "Extra stings Hello 1234567 World_ This is a Regex Demo Extra stings"
result = re.search("Hello.*?(\d+).*?Demo",content, re.S)
print(result)
print(result.group(1))

#re.findall 查取多个结果
#re.sub 字符串替换
#通过结合可以提取出出别的信息
#re.compile 将正则字符串编译成正则表达式对象


#正则表达式的例子
#提取豆瓣图书

headers = {
    "User-Agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36"
}

html = requests.get("https://book.douban.com",headers=headers).text
patten = re.compile('<li.*?cover.*?href="(.*?)".*?title="(.*?)".*?</li>',re.S)
conent = re.findall( patten,html)
print(conent)

