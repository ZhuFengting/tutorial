import urllib.request
import urllib.parse
import urllib.error
import socket
import requests
import json
import re
#get请求方式

"""response = urllib.request.urlopen("https://www.baidu.com");
print(response.read().decode("utf-8"));

#post请求方式
data = bytes(urllib.parse.urlencode({"world":"hello"}) ,encoding="utf-8")

response = urllib.request.urlopen("http://httpbin.org/post",data=data)
print(response.read())

#超时参数timeout

response = urllib.request.urlopen("http://httpbin.org/get",timeout = 5)
print(response.read())

#超时异常操作 try except
try:
    response = urllib.request.urlopen("http://httpbin.org/get",timeout = 0.1)
except urllib.error.URLError as e:
    if isinstance(e.reason,socket.timeout):
        print("TIME OUT")


#响应
#状态码 响应头
response = urllib.request.urlopen("https://www.python.org")
print(type(response))

#request

response = requests.get("http://www.baidu.com")
print(type(response))
print(response.status_code)
print(type(response.text))
print(response.text)
print(response.cookies)

response = requests.get('http://httpbin.org/get')
print(response.text)
"""
data = {
    'name':"germey",
    'age':22
}

response = requests.get('http://httpbin.org/get',params=data)
print(response.text)

response = requests.get('http://httpbin.org/get')
print(response.json())

#获取二进制文件是content
#添加headers 增加代理

headers = {
    "User-Agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36"
}

response = requests.get("https://www.zhihu.com/explore",headers=headers)
print(response.text)

#post的请求
response = requests.post("http://httpbin.org/post",data=data,headers=headers)
print(response.text)

#获取Cookie
response = requests.get("https://www.baidu.com")
print(response.cookies)
for key,value in response.cookies.items():
    print(key+"="+value)

#会话维持
s = requests.Session()
s.get("https://httpbin.org/cookies/set/number/123456789")
response = s.get("https://httpbin.org/cookies")
print(response.text)

#安全证书  导入一个包可以解决这个问题
response = requests.get("https://www.12306.cn",verify=False)
print(response.status_code)
"""
#代理设置

proxies = {
    "http":"http://user:password@127.0.0.1:9743",
    "https":"https://127.0.0.1:9743"
}

response = requests.get("https://www.taobao.com",proxies=proxies)
print(response.status_code)

"""

